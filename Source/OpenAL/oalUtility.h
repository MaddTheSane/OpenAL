//
//  oalUtility.hpp
//  OpenALOpenSource
//
//  Created by C.W. Betts on 8/17/20.
//

#ifndef oalUtility_hpp
#define oalUtility_hpp

#include <CoreFoundation/CoreFoundation.h>
#include <CoreAudio/AudioHardwareBase.h>

CFDataRef __nullable copyDataContentsOfFileAtURL(CFURLRef __nonnull theSrc) CF_RETURNS_RETAINED;
OSStatus GetDefaultDevice(AudioObjectPropertySelector inOrOut, AudioObjectID * _Nonnull outID);

#endif /* oalUtility_hpp */
