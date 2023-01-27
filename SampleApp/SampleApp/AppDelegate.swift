//
//  AppDelegate.swift
//  SampleApp
//
//  Created by hey, inc. on 2022/05/06.
//

import UIKit
import STORESPaymentsSDK

@main
class AppDelegate: UIResponder, UIApplicationDelegate {
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        /*
         アプリケーションを登録した際に発行されたTokenをご利用ください
         */
        let token = "d7e871f8-3bee-45c8-9f4f-2439de91e9f3"
        /*
         アプリケーション起動時に configure methodを呼んでください
         tokenが間違っている場合はエラーが返り、STORES Payments SDK は動作しません
         */
        STP.configure(applicationToken: token) { result in
            print("STP.configure result = \(result)")
        } terminalErrorHandler: { terminalError in
            /*
             決済端末初期化エラーなどが発生した際にはこちらのクロージャが呼ばれます
             */
            print("\(terminalError.title)")
        }

        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }
}

