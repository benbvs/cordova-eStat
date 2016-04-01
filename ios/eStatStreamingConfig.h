//
//  eStatStreamingConfig.h
//  eStatTaggerSDK
//
//  Created by Arnaud Bultot on 17/01/14.
//  Copyright (c) 2014 Tapptic. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface eStatStreamingConfig : NSObject

@property (nonatomic, copy) NSString* level1;
@property (nonatomic, copy) NSString* level2;
@property (nonatomic, copy) NSString* level3;
@property (nonatomic, copy) NSString* level4;
@property (nonatomic, copy) NSString* level5;
@property (nonatomic, copy) NSString* customerData;

@property (nonatomic, copy) NSString* mediaGenre; // Default is nil
@property (nonatomic, copy) NSString* mediaProvider; // Default is nil

@end
