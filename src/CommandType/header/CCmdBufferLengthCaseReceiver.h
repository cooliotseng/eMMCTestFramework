/*
 * CCmdTypeCReceiver.h
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#ifndef COMMANDTYPE_CCMDBUFFERLENGTHCASERECEIVER_H_
#define COMMANDTYPE_CCMDBUFFERLENGTHCASERECEIVER_H_

#include "IReceiver.h"

class CCmdBufferLengthCaseReceiver: public IReceiver {
private:
	int mCmdname;
	int mBufferLength;
	std::string mFileName;
public:
	CCmdBufferLengthCaseReceiver(int ,int, std::string);
	virtual ~CCmdBufferLengthCaseReceiver();
	Json::Value Action();
};

#endif /* COMMANDTYPE_CCMDREADCASERECEIVER_H_ */
