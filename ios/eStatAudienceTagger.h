//
//  eStatAudienceTagger.h
//  eStatTaggerSDK
//
//  Created by Kevin Delannoy on 8/01/14.
//  Copyright (c) 2014 Tapptic. All rights reserved.
//

#import "eStatTagger.h"

@interface eStatAudienceTagger : eStatTagger

#pragma mark - Initialization
////////////////////////////////////////////////////////////////////////////////

+ (instancetype) eStatAudienceTaggerWithSerial:(NSString *)serial
                              withCustomerData:(NSString *)customerData;

////////////////////////////////////////////////////////////////////////////////


#pragma mark - Hit Methods
////////////////////////////////////////////////////////////////////////////////

- (void) sendHitWithLevel1:(NSString *)level1;

- (void) sendHitWithLevel1:(NSString *)level1
                withLevel2:(NSString *)level2;

- (void) sendHitWithLevel1:(NSString *)level1
                withLevel2:(NSString *)level2
                withLevel3:(NSString *)level3;

- (void) sendHitWithLevel1:(NSString *)level1
                withLevel2:(NSString *)level2
                withLevel3:(NSString *)level3
                withLevel4:(NSString *)level4;

////////////////////////////////////////////////////////////////////////////////


@end
