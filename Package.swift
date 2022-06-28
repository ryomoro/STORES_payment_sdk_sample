// swift-tools-version: 5.6
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "STORESPaymentsSDK",
    platforms: [
        .iOS(.v13),
    ],
    products: [
        .library(
            name: "STORESPaymentsSDK",
            targets: ["STORESPaymentsSDK"]),
        .library(
            name: "TCMPayment",
            targets: ["TCMPayment"]),
    ],
    dependencies: [
    ],
    targets: [
        .binaryTarget(name: "STORESPaymentsSDK",
                      path: "./Frameworks/STORESPaymentsSDK.xcframework"
                     ),
        .binaryTarget(name: "TCMPayment",
                      path: "./Frameworks/TCMPayment.xcframework"
                     ),
    ]
)
