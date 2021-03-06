/*
 Copyright (c) 2013, OpenEmu Team

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

#import "NSResponder+OEHIDAdditions.h"
#import "OEHIDEvent.h"

@implementation NSResponder (OEHIDAdditions)

- (void)handleHIDEvent:(OEHIDEvent *)anEvent
{
        switch([anEvent type])
        {
            case OEHIDEventTypeAxis :
                [self axisMoved:anEvent];
                break;
            case OEHIDEventTypeAccelerometer :
                [self accelerometerMoved:anEvent];
                break;
            case OEHIDEventTypeIR :
                [self IRMoved:anEvent];
                break;
            case OEHIDEventTypeWiimoteExtension :
                [self wiimoteExtensionChanged:anEvent];
                break;
            case OEHIDEventTypeTrigger :
                if([anEvent hasOffState])
                    [self triggerRelease:anEvent];
                else
                    [self triggerPull:anEvent];
                break;
            case OEHIDEventTypeButton :
                if([anEvent hasOffState])
                    [self buttonUp:anEvent];
                else
                    [self buttonDown:anEvent];
                break;
            case OEHIDEventTypeHatSwitch :
                [self hatSwitchChanged:anEvent];
                break;
            case OEHIDEventTypeKeyboard :
                if([anEvent hasOffState])
                    [self HIDKeyUp:anEvent];
                else
                    [self HIDKeyDown:anEvent];
                break;
            default:
                break;
        }
}

#define FORWARD_MESSAGE(name, type) \
- (void)name:(type)arg \
{ \
    if(_nextResponder != nil) \
        [_nextResponder name:arg]; \
}

FORWARD_MESSAGE(axisMoved, OEHIDEvent *)
FORWARD_MESSAGE(accelerometerMoved , OEHIDEvent *)
FORWARD_MESSAGE(IRMoved , OEHIDEvent *)
FORWARD_MESSAGE(wiimoteExtensionChanged , OEHIDEvent *)
FORWARD_MESSAGE(triggerPull, OEHIDEvent *)
FORWARD_MESSAGE(triggerRelease, OEHIDEvent *)
FORWARD_MESSAGE(buttonDown, OEHIDEvent *)
FORWARD_MESSAGE(buttonUp, OEHIDEvent *)
FORWARD_MESSAGE(hatSwitchChanged, OEHIDEvent *)
FORWARD_MESSAGE(HIDKeyDown, OEHIDEvent *)
FORWARD_MESSAGE(HIDKeyUp, OEHIDEvent *)

@end
