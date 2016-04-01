//
//  eStatStreamingTaggerDelegate.h
//  eStatTaggerSDK
//
//  Created by Kevin Delannoy on 8/01/14.
//  Copyright (c) 2014 Tapptic. All rights reserved.
//

#import <Foundation/Foundation.h>

extern int const eStatStreamingTaggerUnknownLocation;

@class eStatStreamingTagger;
@protocol eStatStreamingTaggerDelegate <NSObject>

- (NSInteger) currentPositionForStreamingTagger:(eStatStreamingTagger *)tagger;

@end
