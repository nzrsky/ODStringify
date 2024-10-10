# ODStringify

[![Build Status](https://app.travis-ci.com/nzrsky/ODStringify.svg?branch=master)](https://app.travis-ci.com/nzrsky/ODStringify)
[![codecov.io](https://codecov.io/github/nzrsky/ODStringify/coverage.svg?branch=master)](https://codecov.io/github/nzrsky/ODStringify?branch=master)
[![CocoaPods Compatible](https://img.shields.io/cocoapods/v/ODStringify)](https://cocoapods.org/pods/ODStringify)
[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)
[![Platform](https://img.shields.io/cocoapods/p/ODStringify?style=flat)](http://cocoadocs.org/docsets/ODStringify)
[![Twitter](https://img.shields.io/badge/twitter-@nzrsky-blue.svg?style=flat)](http://twitter.com/nzrsky)

## Usage

With ODStringify, you can create strings from classes, properties, defines, and functions using one function—safely.
And everything is done at compile time.
No more runtime overhead and calls like `NSStringFromClass` (although for this function, it was very small).

First of all, you can create strings from defined values. It's amazing. For example:

```objective-c
#define MAX_NUMBER_OF_SOMETHING 10
#define DEFAULT_HI_STRING @"hello"

NSLog(@"Hi string:%@", ODStringify(DEFAULT_HI_STRING)); // > @"hello" (@"@\"hello\"")
NSLog(@"Max number:%@", ODStringify(MAX_NUMBER_OF_SOMETHING)); // > 10 (@"10")
```

<p align="center">
  <img src="https://github.com/nzrsky/ODStringify/blob/master/assets/1.png?raw=true" alt="ODStringify">
</p>

### ODStringifyClass

Class name string with compile-time type checking.

```objective-c
NSLog(@"Valid class:%@", ODStringifyClass(AppDelegate)); // AppDelegate
NSLog(@"Invalid class:%@", ODStringifyClass(App_Delegate)); // Error
```

### ODStringifyProtocol

Protocol name string with compile-time type checking.

```objective-c
NSLog(@"Valid protocol:%@", ODStringifyProtocol(NSCopying)); // NSCopying
NSLog(@"Invalid protocol:%@", ODStringifyProtocol(NSCopiing)); // Error
```

<p align="center">
  <img src="https://github.com/nzrsky/ODStringify/blob/master/assets/2.png?raw=true" alt="ODStringify">
</p>

### ODStringifyProperty

Pretty much the same thing for properties.

**Note:** You need to be inside a class implementation (and have access to `self`).

```objective-c
// AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    NSLog(@"Valid property:%@", ODStringifyProperty(window)); // window
    NSLog(@"Invalid property:%@", ODStringifyProperty(window_)); // Error
    return YES;
}
```

## Installation

ODStringify supports multiple methods for installing the library in a project.

### Installation with CocoaPods

[CocoaPods](http://cocoapods.org) is a dependency manager for Objective-C and Swift, which automates and simplifies the process of using third-party libraries like ODStringify in your projects. You can install it with the following command:

```bash
$ gem install cocoapods
```

#### Podfile

To integrate ODStringify into your Xcode project using CocoaPods, specify it in your `Podfile`:

```ruby
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '12.0'

target 'TargetName' do
  pod 'ODStringify'
end
```

Then, run the following command:

```bash
$ pod install
```

### Installation with Carthage

[Carthage](https://github.com/Carthage/Carthage) is a decentralized dependency manager that builds your dependencies and provides you with binary frameworks.

You can install Carthage with [Homebrew](http://brew.sh/) using the following commands:

```bash
$ brew update
$ brew install carthage
```

To integrate ODStringify into your Xcode project using Carthage, specify it in your `Cartfile`:

```ogdl
github "nzrsky/ODStringify" ~> 1.1
```

Run `carthage` to build the framework and drag the built `ODStringify.framework` into your Xcode project.

## Author

Alexey Nazarov, alexx.nazaroff@gmail.com

## License

ODStringify is available under the MIT license. See the LICENSE file for more info.
