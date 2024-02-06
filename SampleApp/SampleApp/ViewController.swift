//
//  ViewController.swift
//  SampleApp
//
//  Created by hey, inc. on 2022/05/06.
//

import UIKit
import STORESPaymentsSDK

final class ViewController: UIViewController {
    @IBAction private func loginButtonTapped(_ sender: Any) {
        /*
         STORES 決済のログイン画面を表示します
         */
        STP.login(presentOn: self) { result in
            print("STP.login result = \(result)")
        }
    }

    @IBAction private func logoutButtonTapped(_ sender: Any) {
        guard STP.isLoggedIn else { return }
        STP.logout()
    }

    @IBAction private func paymentButtonTapped(_ sender: Any) {
        /*
         決済処理の前に設定をします。
         このメソッドを呼ばない場合は以下のデフォルト値で動作します。
         デフォルト値:
            isPrintReceiptEnabled: false
            isSendReceiptMailEnabled: false
            mode: .staffOperation
         */
        STP.setup(.init(
            isPrintReceiptEnabled: true,
            isSendReceiptMailEnabled: true,
            mode: .staffOperation)
        )

        /*
         決済処理を実行します
         */
        STP.payment(
            presentOn: self, 
            amount: 100,
            memo: "Memo") { transactionType in
                /*
                 決済が完了したタイミングで呼ばれます。
                 このタイミングではSTORES Payments SDK の画面は表示されています。
                 */
                print("Payment Finished type = \(transactionType)")
            } receiptPrintingStartHandler: {
                /*
                 SDKの決済完了画面でレシート印刷が開始されたタイミングで呼ばれます
                 */
                print("Receipt print start")
            } completion: { [weak self] result in
                /*
                 STORES Payments SDK の画面を閉じたタイミングで呼ばれます。
                 */
                switch result {
                case let .success(transactionType):
                    print("Payment Completion type = \(transactionType)")
                    self?.displayTransactionDetail(type: transactionType)
                    /*
                     TransactionType から レシート画像を取得できます。

                     let receiptImage = transactionType.receiptImage(with: 300)
                     */
                    /*
                     TransactionType から 取引番号文字列を取得できます。

                     let humanReadableIdentifier = transactionType.humanReadableIdentifier
                     */
                case let .failure(error):
                    print("Payment Error = \(error)")
                }
            }
    }

    private func displayTransactionDetail(type: TransactionType) {
        /*
         売り上げ情報画面を表示します
         この画面を表示することで売り上げ取り消し・返品処理を実行することも可能です
         */
        STP.presentTransactionViewController(
            on: self, transactionIdentifier: type.identifier,
            shouldAllowRefunding: true,
            shouldAutoTransitionToRefund: false) { [weak self] result in
                /*
                 shouldAutoTransitionToRefund に trueを渡した場合など
                 売り上げ詳細が画面から売り上げ取り消し・返品処理を実行した結果が
                 このクロージャに返ります
                 このタイミングではSTORES Payments SDK の画面は表示されています。
                 */
                switch result {
                case let .success(type):
                    let isRefunded = self?.isRefunded(type: type) ?? false
                    print("Refund Success = \(isRefunded)")
                case let .failure(error):
                    print("Refund Error = \(error)")
                }
            } receiptPrintingStartHandler: {
                /*
                 SDKの売り上げ詳細画面でレシート印刷が開始されたタイミングで呼ばれます
                 */
                print("Receipt print start")
            } dismissCompletion: { [weak self] result in
                /*
                 STORES Payments SDK の画面を閉じたタイミングで呼ばれ
                 表示した最新の売り上げ情報が返ります
                 売り上げ取り消し・返品処理を実施した場合は、statusが refunded に更新されています
                 */
                switch result {
                case let .success(type):
                    let isRefunded = self?.isRefunded(type: type) ?? false
                    print("Display Transaction Success: type = \(type) isRefunded = \(isRefunded)")
                case let .failure(error):
                    print("Display Transaction Detail Error = \(error)")
                }
            }
    }

    private func isRefunded(type: TransactionType) -> Bool {
        switch type {
        case let .card(transaction),
            let .weChatPay(transaction):
            return transaction.status == .refunded
        case .emoney:
            /* 電子マネー決済は売り上げ取り消し・返品に対応していません　*/
            return false
        @unknown default:
            fatalError()
        }
    }
}

