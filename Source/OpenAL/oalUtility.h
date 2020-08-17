//
//  oalUtility.hpp
//  OpenALOpenSource
//
//  Created by C.W. Betts on 8/17/20.
//

#ifndef oalUtility_hpp
#define oalUtility_hpp

#include <CoreFoundation/CoreFoundation.h>

#ifdef __cplusplus
extern "C" {
#endif

CFDataRef copyDataContentsOfFileAtURL(CFURLRef theSrc);

#ifdef __cplusplus
}
#endif

#endif /* oalUtility_hpp */
