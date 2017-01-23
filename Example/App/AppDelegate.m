//
//  ViewController.m
//  Weakify
//
//  Created by Alexey Nazaroff on 01/06/2017.
//  Copyright (c) 2017 Alexey Nazaroff. All rights reserved.
//

@import UIKit;
#import <ODStringify.h>

#define MAX_FOO 10

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (strong, nonatomic) UIWindow *window;
@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    NSLog(@"%@", ODStringify(MAX_FOO));
    NSLog(@"%@", ODStringify(self));
    NSLog(@"%@", ODStringifyClass(UIApplication));
    NSLog(@"%@", ODStringifyProperty(window));
    return YES;
}

@end
