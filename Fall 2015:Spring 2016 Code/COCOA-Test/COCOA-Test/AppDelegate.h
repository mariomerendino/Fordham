//
//  AppDelegate.h
//  COCOA-Test
//
//  Created by Mario J Merendino on 11/28/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject <NSApplicationDelegate>{
    NSWindow *window;
    IBOutlet NSTextField *field;
}

-(IBAction)marioiscool;

@property (assign) IBOutlet NSWindow *window;

@end

