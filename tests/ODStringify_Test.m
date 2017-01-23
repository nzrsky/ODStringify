//
//  ODXCore_Test.m
//  ODX.Core
//
//  Created by Alex Nazaroff on 12.01.10.
//  Copyright © 2009-2015 AJR. All rights reserved.
//

#import <XCTest/XCTest.h>
#import <ODStringify.h>

@interface ODStringify_Test : XCTestCase
@end

@implementation ODStringify_Test

- (void)testFileAndLine {
    // Don't move this line ;-)
    XCTAssert([ODCurrentFileAndLine rangeOfString:@"ODStringify_Test.m:19"].location != NSNotFound);
}

- (void)testStringify {
    int var;
    XCTAssert([ODStringify(var) isEqualToString:@"var"]);
    XCTAssert([ODStringifyClass(ODStringify_Test) isEqualToString:@"ODStringify_Test"]);
    
#define TEST_STRING var
    XCTAssert([ODStringifyUnwrap(TEST_STRING) isEqualToString:@"var"]);
    XCTAssert([ODStringifyUnsafe(TEST_STRING) isEqualToString:@"TEST_STRING"]);
    XCTAssert([ODStringify(TEST_STRING) isEqualToString:@"var"]);
}

- (void)testConcat {
    NSString *ODConcat(_, var) = @"test";
    XCTAssert([_var isEqualToString:@"test"]);
}

- (void)testIgnore {
    ODCompilerIgnorePush(-Wall)
    int x; // No 'unusing' warning here!
    ODCompilerPop
    
    ODCompilerIgnore(-Wall, int y); // No 'unusing' warning here!
}

@end
