# ODStringify

[![Build Status](https://app.travis-ci.com/nzrsky/ODStringify.svg?branch=master)](https://app.travis-ci.com/nzrsky/ODStringify)
[![codecov.io](https://codecov.io/github/nzrsky/ODStringify/coverage.svg?branch=master)](https://codecov.io/github/nzrsky/ODStringify?branch=master)
[![CocoaPods Compatible](https://img.shields.io/cocoapods/v/ODStringify.svg)](https://img.shields.io/cocoapods/v/ODStringify.svg)
[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)
[![Platform](https://img.shields.io/cocoapods/p/ODStringify.svg?style=flat)](http://cocoadocs.org/docsets/ODStringify)
[![Twitter](https://img.shields.io/badge/twitter-@nzrsky-blue.svg?style=flat)](http://twitter.com/nzrsky)


## Usage

With ODStringify you can make strings from classes, properties, defines and functions
using one function. Safely. 
And all things will be done compile time.
No more runtime overhead and calls like NSStringFromClass 
(despite of for this function it was very small).

First of all you can make strings from defined value. It's crazy. For example:
```objective-c
#define MAX_NUMBER_OF_SOMETHING 10
#define DEFAULT_HI_STRING @"hello"

NSLog(@"Hi string:%@", ODStringify(DEFAULT_HI_STRING)); // > @"hello" (@"@\"hello\"")
NSLog(@"Max number:%@", ODStringify(MAX_NUMBER_OF_SOMETHING)); // > 10 (@"10")
```
<p align="center" >
  <img src="https://github.com/nzrsky/ODStringify/blob/master/assets/1.png?raw=true" alt="ODStringify">
</p>

### ODStringifyClass
Class's name string with compile time type check.
```objective-c
NSLog(@"Valid class:%@", ODStringifyClass(AppDelegate)); // AppDelegate
NSLog(@"Invalid class:%@", ODStringifyClass(App_Delegate)); // Error
```
<p align="center" >
  <img src="https://github.com/nzrsky/ODStringify/blob/master/assets/2.png?raw=true" alt="ODStringify">
</p>

### ODStringifyProperty
Pretty same thing for properties.
NB. You need to be inside of class implementation (and have `self`)
```objective-c
// AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    NSLog(@"Valid property:%@", ODStringifyProperty(window)); // window
    NSLog(@"Invalid property:%@", ODStringifyProperty(window_)); // Error
    return YES;
}
```

### ODConcat
Allows us to concat any things. For example how it works in `ODWeakify` pod –
we concat name of variable with _weak_ suffix to get new another one.

```objective-c
#define od_weakify(obj)  __weak __typeof(obj) ODConcat(obj, _weak_)
```

### ODCurrentFileAndLine
Just current file and line as NSString

### ODCompilerIgnorePush & ODCompilerPop
Two defines for simplifying compiler pragma pushes. Actually, maybe, will be better to move it in another pod :-)

```objective-c
ODCompilerIgnorePush(-Wgnu).
// some code
ODCompilerIgnorePop.
```

## Installation
ODStringify supports multiple methods for installing the library in a project.

## Installation with CocoaPods

[CocoaPods](http://cocoapods.org) is a dependency manager for Objective-C and Swift, which automates and simplifies the process of using 3rd-party libraries like ODStringify in your projects. You can install it with the following command:

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

You can install Carthage with [Homebrew](http://brew.sh/) using the following command:

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
