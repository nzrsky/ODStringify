// ODStringify.h
//
// Copyright (c) 2009-2015 Alexey Nazaroff, AJR
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

/**
 * Stringify defines as strings
 *
 * @example:
 * ODStringify(var) produces @"var" string, ODStringifyClass(NSObject) produces
 * @"NSObject" string. Unsafe methods does it without any checks. Unwrap for defines.
 */
#define ODStringifyUnsafe(x)            @#x
#define ODStringifyUnwrap(x)            ODStringifyUnsafe(x)

#define __ODStringifyCheck(x)           __unused __typeof (x) __od_str_obj
#define __ODStringifyCheckClass(x)      __unused x *__od_str_obj
#define __ODStringifyCheckProperty(x)   __unused __typeof (self.x) __od_x_prop = self.x

#if DEBUG == 1
    #define ODStringify(obj)            ({ __ODStringifyCheck(obj); ODStringifyUnsafe(obj); })
    #define ODStringifyClass(cls)       ({ __ODStringifyCheckClass(cls); ODStringifyUnsafe(cls); })
    #define ODStringifyProperty(prop)   ({ __ODStringifyCheckProperty(prop); ODStringifyUnsafe(prop); })
#else
    #define ODStringify(obj)            (ODStringifyUnsafe(obj))
    #define ODStringifyClass(cls)       (ODStringifyUnsafe(cls))
    #define ODStringifyProperty(prop)   (ODStringifyUnsafe(prop))
#endif

#define ODStringifySelector(sel)        ({ NSStringFromSelector(@selector(sel)); })

/** 
 * Concatenate defines as strings
 *
 * @example: 
 * ODConcat(od_onceToken, __LINE__) produces 'od_onceTokenN' variable,
 * where N is number of current line in code.
 */
#define __ODConcat(x, y)                x ## y
#define ODConcat(x, y)                  __ODConcat(x, y)

/** Clang ignore diagnostic messages wrapper */
#define __ODStringifyClangPragmaStage0(x)      #x
#define __ODStringifyClangPragmaStage1Ignore(x) __ODStringifyClangPragmaStage0(clang diagnostic ignored x)
#define ODStringifyClangPragmaClangIgnore(x)    __ODStringifyClangPragmaStage1Ignore(#x)

/**
 * Wraps code with clang ignore directive
 * @param type A type of ignored messages
 * @param x    A wrapped code
 * @example ODCompilerIgnorePush(-Wall, x=1/0);
 */
#define ODCompilerIgnore(type, x)                                               \
    _Pragma("clang diagnostic push")                                            \
    _Pragma(ODStringifyClangPragmaClangIgnore(type))                            \
    x                                                                           \
    _Pragma("clang diagnostic pop")

/**
 * Push clang ignore directive
 * @param type A type of ignored messages
 * @example ODCompilerIgnorePush(-Wgnu).
 */
#define ODCompilerIgnorePush(type)                                              \
    _Pragma("clang diagnostic push")                                            \
    _Pragma(ODStringifyClangPragmaClangIgnore(type))

/** Pop current Clang diagnostic message */
#define ODCompilerPop \
    _Pragma("clang diagnostic pop")

/** Current file and line (NSString) */
#define ODCurrentFileAndLine            (@__FILE__ ":" ODStringifyUnwrap(__LINE__))
