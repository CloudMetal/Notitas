//
//  MNOAppDelegate.m
//  Notitas
//
//  Created by Adrian on 7/21/09.
//  Copyright akosma software 2009. All rights reserved.
//

#import "MNOAppDelegate.h"
#import "MNORootController.h"
#import "MNOHelpers.h"

@interface MNOAppDelegate ()

@property (nonatomic) CFTimeInterval lastTime;

@end


@implementation MNOAppDelegate

#pragma mark - Application lifecycle

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window.rootViewController = self.rootController;
    [self.window makeKeyAndVisible];

    // Check for 'notita' files opened from other applications
    NSURL *openedURL = launchOptions[UIApplicationLaunchOptionsURLKey];
    if (openedURL != nil)
    {
        if ([openedURL isFileURL])
        {
            return NO;
        }
    }
    
    return YES;
}

- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url 
{
    if ([[url scheme] isEqualToString:@"notitas"])
    {
        if ([[url path] isEqualToString:@"/new"])
        {
            NSString *parameter = [url query];
            CFStringRef clean = CFURLCreateStringByReplacingPercentEscapes(kCFAllocatorDefault, 
                                                                           (CFStringRef)parameter, 
                                                                           CFSTR(""));
            
            [self.rootController createNewNoteWithContents:(__bridge NSString *)clean];
            CFRelease(clean);
            return YES;
        }
        return NO;
    }
    else if ([url isFileURL])
    {
        NSDictionary *dict = [NSDictionary dictionaryWithContentsOfURL:url];
        [[MNOCoreDataManager sharedMNOCoreDataManager] createNoteFromDictionary:dict];
        return YES;
    }
    return NO;
}

- (void)applicationWillTerminate:(UIApplication *)application 
{
    [[MNOCoreDataManager sharedMNOCoreDataManager] save];
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    [[MNOCoreDataManager sharedMNOCoreDataManager] save];
}

@end
