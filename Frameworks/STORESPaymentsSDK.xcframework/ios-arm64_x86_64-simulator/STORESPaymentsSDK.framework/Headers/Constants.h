// CommonMPI
// Copyright © Coiney Inc. All rights reserved.
// For licensing information, contact info@coiney.com.

#ifndef Constants_h
#define Constants_h

extern uint8_t const kNadTlvProtocol;
extern uint8_t const kPcbChained;
extern uint8_t const kPcbUnsolicited;
extern uint8_t const kSw1Success;
extern uint8_t const kSw2Success;

extern uint8_t const kLenShortForm;
extern uint8_t const kLenLongForm;

extern size_t const kNadIndex;
extern size_t const kPcbIndex;
extern size_t const kLenIndex;

extern size_t const kPrologueLength; /* nad, pcb, len */
extern size_t const kTrailerLength; /* sw1, sw2 */
extern size_t const kEpilogueLength; /* lrc */

#endif /* Constants_h */
