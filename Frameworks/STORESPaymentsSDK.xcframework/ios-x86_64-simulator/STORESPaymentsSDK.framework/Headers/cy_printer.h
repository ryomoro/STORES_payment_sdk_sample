#include <stddef.h>
#include <stdint.h>

#ifndef CY_PRINTER_H
#define CY_PRINTER_H

// Bitmaps should have a width that is a multiple of the below value
#define CY_PRINTER_PAGE_WIDTH_INCREMENT (24)

enum cy_printer_type {
    cy_invalid_printer,
    cy_escpos2_printer,     // Standard ESC/P 2 (Epson printers)
    cy_sm_mobile_printer,   // Star Micronics mobile printers (ESC/P + proprietary extensions)
    cy_sm_desktop_printer,  // Star Micronics desktop printer (ESC/P + proprietary extensions)
    cy_sm_star_prnt_printer // StarPRNT compatible printers (ESC/P + proprietary extensions)
};

enum cy_printer_trait {
    cy_paper_cut    = 1 << 31,
    cy_jis2_read    = 1 << 30,
    cy_variable_paper_width = 1 << 29,
};

enum cy_printer_paper_width {
    cy_paper_unknown,
    cy_paper_58mm,
    cy_paper_80mm,
};

// Lowest 16 bits occupied by printer type,
// Next 3 by the number of newlines required to clear cutter (Maximum of 7 newlines)
// The rest(13 bits) by feature mask
typedef int32_t cy_printer;
#define CY_PRINTER_TYPE(printer) ((enum cy_printer_type)((printer) & 0xffff))
#define CY_CUTTER_NL(count) (((count) & 0x7) << 16)

// Star Micronics
#define CY_SM_TSP_650II  (cy_sm_desktop_printer | CY_CUTTER_NL(5) | cy_paper_cut)
#define CY_SM_S210I      (cy_sm_mobile_printer  | CY_CUTTER_NL(2) | cy_jis2_read) // Actually SM-S214i, but there is no way to tell the 2 apart
#define CY_SM_L200       (cy_sm_star_prnt_printer | CY_CUTTER_NL(3))
#define CY_SM_MC_PRINT3  (cy_sm_star_prnt_printer | CY_CUTTER_NL(3) | cy_paper_cut)

// Epson
#define _CY_EPSON_PORTABLE (cy_escpos2_printer | CY_CUTTER_NL(5)) // TMP60II and TMP20BI
#define CY_EPSON_TMT20II   (cy_escpos2_printer | CY_CUTTER_NL(2) | cy_paper_cut | cy_variable_paper_width)
#define CY_EPSON_TMM10     (cy_escpos2_printer | CY_CUTTER_NL(1) | cy_paper_cut)
#define CY_EPSON_TMM30     (cy_escpos2_printer | CY_CUTTER_NL(1) | cy_paper_cut | cy_variable_paper_width)

// Seiko Instruments
#define CY_SII_MPB20 (cy_escpos2_printer | CY_CUTTER_NL(3))

struct cy_color_pixel {
#ifdef CY_USE_RGBA
    uint8_t r,g,b,a;
#else
    uint8_t b,g,r,a;
#endif
};

uint8_t *cy_pos_text_to_cmd(cy_printer printer,
                            const char *str, size_t len,
                            size_t *out_len);
uint8_t *cy_pos_bitmap_to_cmd(cy_printer printer,
                              const uint8_t *pixels,
                              size_t width, size_t height,
                              size_t *out_len);

uint8_t *cy_pos_papercut(cy_printer printer, size_t *out_len);
uint8_t *cy_pos_request_paper_width(cy_printer printer, size_t *out_len);
enum cy_printer_paper_width cy_pos_paper_width_from_response(const uint8_t *response, size_t len);
uint8_t *cy_pos_magstripe_jis2_header(cy_printer printer, size_t *out_len);
uint8_t *cy_pos_enable_magstripe_reading(cy_printer printer, size_t *out_len);
uint8_t *cy_pos_cancel_magstripe_reading(cy_printer printer, size_t *out_len);

// Returns newlines for passing the cutter on the printer
// (Some printers have quite a bit of distance between the print head and the cutter)
uint8_t *cy_pos_cutter_newlines(cy_printer printer, size_t *out_len);

uint8_t *cy_convert_to_luma(const struct cy_color_pixel *pixels, size_t width, size_t height);
void cy_atkinson_dither(uint8_t *pixels, size_t width, size_t height);

#endif
