/*
 This source is part of UnitKit, a unit test framework for Mac OS X 
 development. You can find more information about UnitKit at:
 
 http://x180.net/Code/UnitKit
 
 Copyright (c)2004 James Duncan Davidson
 
 Contributions by Michael Milvich, Mark Dalrymple
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 
 The use of the Apache License does not indicate that this project is
 affiliated with the Apache Software Foundation.
 */

#import <Foundation/Foundation.h>

@interface UKTestHandler : NSObject
{
	id delegate;
	int testsPassed;
	int testsFailed;
	int exceptionsReported;
	BOOL quiet;
}


/** @taskunit Initialization */


+ (UKTestHandler *)handler;


/** @taskunit Controlling Test Result Reporting */


- (void)setDelegate: (id)aDelegate;
- (void)setQuiet: (BOOL)isQuiet;
/**
 * If we have a delegate, then by all means use it. If we don't, then check to
 * see if we have any errors which should be reported off to std out.
 */
- (void)reportStatus: (BOOL)cond
              inFile: (const char *)filename
                line: (int)line
             message: (NSString *)msg;
/**
 * Reports an uncaught exception and a hint that represents the context in
 * which the exception arised (e.g. -init on a test object).
 *
 * By default, forwards the message to the delegate if there is one, otherwise
 * uses -reportWarning: to print the exception reason.
 */
- (void)reportException: (NSException *)exception
                inClass: (Class)testClass
                   hint: (NSString *)hint;
- (void)reportWarning: (NSString *)message;


/** @taskunit Test Results */


- (int)testsPassed;
- (int)testsFailed;
/**
 * Returns the current number of exceptions caught by UKRunner and reported to
 * the test handler.
 *
 * See -reportException:inClass:hint:.
 */
- (int)exceptionsReported;


/** @taskunit Test Assertions */


- (void)passInFile: (const char *)filename line: (int)line;

- (void)failInFile: (const char *)filename line: (int)line;

- (void)testTrue: (BOOL)cond inFile: (const char *)filename line: (int)line;

- (void)testFalse: (BOOL)cond inFile: (const char *)filename line: (int)line;

- (void)testNil: (void *)ref inFile: (const char *)filename line: (int)line;

- (void)testNotNil: (void *)ref inFile: (const char *)filename line: (int)line;

- (void)testInt: (int)a equalTo: (int)b inFile: (const char *)filename line: (int)line;

- (void)testInt: (int)a notEqualTo: (int)b inFile: (const char *)filename line: (int)line;

- (void)testFloat: (float)a equalTo: (float)b delta: (float)delta inFile: (const char *)filename line: (int)line;

- (void)testFloat: (float)a notEqualTo: (float)b delta: (float)delta inFile: (const char *)filename line: (int)line;

- (void)testObject: (id)a kindOf: (id)b inFile: (const char *)filename line: (int)line;

- (void)testObject: (id)a equalTo: (id)b inFile: (const char *)filename line: (int)line;

- (void)testObject: (id)a notEqualTo: (id)b inFile: (const char *)filename line: (int)line;

- (void)testObject: (id)a sameAs: (id)b inFile: (const char *)filename line: (int)line;

- (void)testObject: (id)a notSameAs: (id)b inFile: (const char *)filename line: (int)line;

- (void)testString: (NSString *)a equalTo: (NSString *)b inFile: (const char *)filename line: (int)line;

- (void)testString: (NSString *)a notEqualTo: (NSString *)b inFile: (const char *)filename line: (int)line;

- (void)testString: (NSString *)a contains: (NSString *)b inFile: (const char *)filename line: (int)line;

- (void)testString: (NSString *)a doesNotContain: (NSString *)b inFile: (const char *)filename line: (int)line;

- (void)raisesException: (NSException *)exception inFile: (const char *)filename line: (int)line;

- (void)doesNotRaisesException: (NSException *)exception inFile: (const char *)filename line: (int)line;

- (void)raisesException: (NSException *)exception named: (NSString *)expected inFile: (const char *)filename line: (int)line;

- (void)raisesException: (id)raisedObject class: (Class)expectedClass inFile: (const char *)filename line: (int)line;

@end
