//
//  oalUtility.cpp
//  OpenALOpenSource
//
//  Created by C.W. Betts on 8/17/20.
//

#include "oalUtility.h"

CFDataRef createDataFromURL(CFURLRef theSrc)
{
	CFReadStreamRef readRef = CFReadStreamCreateWithFile(kCFAllocatorDefault, theSrc);
	CFMutableDataRef toRet;
	CFStreamStatus streamStatus;
	CFIndex readDat = 16 * 1024;
	UInt8 *datVal= NULL;
	
	if (!readRef) {
		goto fail1;
	}
	if (!CFReadStreamOpen(readRef)){
		goto fail2;
	}
	streamStatus = CFReadStreamGetStatus(readRef);
	if (streamStatus == kCFStreamStatusError) {
		goto fail2;
	}
	toRet = CFDataCreateMutable(kCFAllocatorDefault, 0);
	if (!toRet) {
		goto fail2;
	}
	datVal = (UInt8 *)malloc(readDat);
	if (!datVal) {
		goto fail3;
	}
	do {
		readDat = ::CFReadStreamRead(readRef, (UInt8*)datVal, 16 * 1024);
		
		if (readDat == 0) {
			break;
		} else if (readDat == -1) {
			goto fail4;
		}
		CFDataAppendBytes(toRet, datVal, readDat);
	} while (true);
	
	
	return toRet;
	
	fail4:
	free(datVal);
	fail3:
	CFRelease(toRet);
	fail2:
	CFRelease(readRef);
	fail1:
	return nullptr;
}
