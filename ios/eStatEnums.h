//
//  eStatEnums.h
//  eStatTaggerSDK
//
//  Created by Kevin Delannoy on 8/01/14.
//  Copyright (c) 2014 Tapptic. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum eStatLoggingMode_e {
    eStatLoggingMode_Verbose,
    eStatLoggingMode_Warning,
    eStatLoggingMode_Error,
    eStatLoggingMode_NoLogging
} eStatLoggingMode;

typedef enum eStatSendingMode_e {
    eStatSendingMode_Compact,
    eStatSendingMode_Full,
    eStatSendingMode_Disconnected
} eStatSendingMode;

typedef enum eStatStreamingEvent_e {
    eStatStreamingEvent_Playing,
    eStatStreamingEvent_Paused,
    eStatStreamingEvent_Stopped,
    estatStreamingEvent_None
} eStatStreamingEvent;

typedef enum eStatStreamingType_e {
    eStatStreamingType_Replay,
    eStatStreamingType_LiveWithoutTimeshifting,
    eStatStreamingType_LiveWithTimeshifting
} eStatStreamingType;
