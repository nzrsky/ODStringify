//
//  Copyright (c) 2015-2022 Alexey Nazarov. All rights reserved.
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
