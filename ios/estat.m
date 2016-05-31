#import "estat.h"
#import <Cordova/CDV.h>
#import "eStatAudienceTagger.h"

@implementation estat

- (void)initEstat:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSString* serial = [command.arguments objectAtIndex:0];

    if (serial != nil && [serial length] > 0) {
		eStatAudienceTagger* audienceTagger = [eStatAudienceTagger eStatAudienceTaggerWithSerial:serial withCustomerData:@""];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:serial];
		NSLog(@"Hello %@!", eStatVersion);
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
    }

    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)sendHitEstat:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
	/* NSArray  *levels = [command.arguments objectAtIndex:0]; */
	NSString* level1 = [command.arguments objectAtIndex:0];
	[audienceTagger sendHitWithLevel1:level1];
	
    if (echo != nil && [echo length] > 0) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:echo];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
    }

    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end
