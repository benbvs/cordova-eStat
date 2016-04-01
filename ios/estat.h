#import <Cordova/CDV.h>

@interface estat : CDVPlugin

- (void)initEstat:(CDVInvokedUrlCommand*)command;
- (void)sendHitEstat:(CDVInvokedUrlCommand*)command;

@end