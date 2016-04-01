//
//  eStatStreamingTagger.h
//  eStatTaggerSDK
//
//  Created by Kevin Delannoy on 8/01/14.
//  Copyright (c) 2014 Tapptic. All rights reserved.
//

#import "eStatTagger.h"
#import "eStatStreamingTaggerDelegate.h"
#import "eStatStreamingConfig.h"


@interface eStatStreamingTagger : eStatTagger

#pragma mark - Initialization
////////////////////////////////////////////////////////////////////////////////

+(instancetype)eStatStreamingTaggerWithSerial:(NSString *)serial
                                withMediaName:(NSString*)mediaName
                              withMediaVolume:(NSInteger)mediaVolume
                                 withMediaURL:(NSString*)mediaURL
                              withMediaLength:(NSInteger)mediaLength
                            withStreamingType:(eStatStreamingType)streamingType
                       withConfigurationBlock:(void(^)(eStatStreamingConfig* config))configurationBlock;

////////////////////////////////////////////////////////////////////////////////



#pragma mark - Readonly properties
////////////////////////////////////////////////////////////////////////////////

@property (nonatomic, readonly) eStatStreamingType streamingType;

@property (nonatomic, readonly) NSString* level1;
@property (nonatomic, readonly) NSString* level2;
@property (nonatomic, readonly) NSString* level3;
@property (nonatomic, readonly) NSString* level4;
@property (nonatomic, readonly) NSString* level5;

////////////////////////////////////////////////////////////////////////////////

#pragma mark - Read/Write properties
////////////////////////////////////////////////////////////////////////////////

@property (nonatomic, copy) NSString* mediaName; // Default is nil
@property (nonatomic, copy) NSString* mediaGenre; // Default is nil
@property (nonatomic, copy) NSString* mediaProvider; // Default is nil
@property (nonatomic, copy) NSString* mediaURL; // Default is nil
@property (nonatomic) NSInteger mediaVolume; // Default is 0
@property (nonatomic) NSInteger mediaLength; // Default is 0

@property (nonatomic, weak) id<eStatStreamingTaggerDelegate> delegate;

@property (nonatomic) eStatSendingMode sendingMode; //Default is eStatSendingMode_Full if internet connection is available

////////////////////////////////////////////////////////////////////////////////



#pragma mark - Event notification
////////////////////////////////////////////////////////////////////////////////

- (void) notifyEvent:(eStatStreamingEvent)event;
- (void) notifyEvent:(eStatStreamingEvent)event withPosition:(NSInteger)position;

////////////////////////////////////////////////////////////////////////////////

@end
