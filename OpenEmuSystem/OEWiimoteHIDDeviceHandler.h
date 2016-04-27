/*
 Copyright (c) 2012, OpenEmu Team

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of the OpenEmu Team nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY OpenEmu Team ''AS IS'' AND ANY
 EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL OpenEmu Team BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Cocoa/Cocoa.h>
#import "OEHIDDeviceHandler.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : unsigned char {
    OEWiimoteDeviceHandlerLED1   = 0x10,
    OEWiimoteDeviceHandlerLED2   = 0x20,
    OEWiimoteDeviceHandlerLED3   = 0x40,
    OEWiimoteDeviceHandlerLED4   = 0x80,
    OEWiimoteDeviceHandlerLEDAll = 0xF0,
} OEWiimoteDeviceHandlerLED;

typedef enum {
    OEWiimoteExpansionTypeNotConnected,
    OEWiimoteExpansionTypeNunchuck,
    OEWiimoteExpansionTypeClassicController,
    OEWiimoteExpansionTypeBalanceBoard,
    OEWiimoteExpansionTypeWiiUProController,
    OEWiimoteExpansionTypeFightingStick,

    OEWiimoteExpansionTypeUnknown
} OEWiimoteExpansionType;

typedef enum {
    OEWiimoteReportTypeCoreButtons = 0x30,
    OEWiimoteReportTypeCoreAccel = 0x31,
    OEWiimoteReportTypeCore8Expan = 0x32,
    OEWiimoteReportTypeCoreAccel12IR = 0x33,
    OEWiimoteReportTypeCore19Expan = 0x34,
    OEWiimoteReportTypeCoreAccel16Expan = 0x35,
    OEWiimoteReportTypeCore10IR9Expan = 0x36,
    OEWiimoteReportTypeCoreAccel10IR6Expan =0x37,
    OEWiimoteReportType21Expan = 0x3d,
} OEWiimoteReportType;

typedef enum {
    OEWiimoteIRModeBasic    = 0x01,
    OEWiimoteIRModeExtended = 0x03,
    OEWiimoteIRModeFull     = 0x05,
} OEWiimoteIRMode;

extern NSString *const OEWiimoteDeviceHandlerDidDisconnectNotification;

@interface OEWiimoteHIDDeviceHandler : OEHIDDeviceHandler

@property(nonatomic) OEWiimoteDeviceHandlerLED illuminatedLEDs;
@property(readonly) BOOL lowBatteryWarning;

@property(nonatomic, getter=isRumbleActivated)                 BOOL rumbleActivated;
@property(nonatomic, getter=isExpansionPortEnabled)            BOOL expansionPortEnabled;
@property(nonatomic, getter=isExpansionPortAttached, readonly) BOOL expansionPortAttached;

@end

NS_ASSUME_NONNULL_END
