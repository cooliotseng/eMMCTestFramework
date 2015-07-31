/*
 * CCmdTypeCReceiver.h
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#ifndef COMMANDTYPE_CCMDREADCASERECEIVER_H_
#define COMMANDTYPE_CCMDREADCASERECEIVER_H_

#include "IReceiver.h"

class CCmdReadCaseReceiver: public IReceiver {
private:
	int mCmdname;
	int mStartAdd;
	int mBlkLength;
	std::string mFileName;
public:
	CCmdReadCaseReceiver(int ,int,int,std::string);
	virtual ~CCmdReadCaseReceiver();
	Json::Value Action();
};

#endif /* COMMANDTYPE_CCMDREADCASERECEIVER_H_ */
