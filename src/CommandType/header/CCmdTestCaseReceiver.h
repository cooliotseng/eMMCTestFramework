/*
 * CCmdType3Receiver.h
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#ifndef COMMANDTYPE_CCMDTESTCASERECEIVER_H_
#define COMMANDTYPE_CCMDTESTCASERECEIVER_H_

#include "IReceiver.h"

class CCmdTestCaseReceiver: public IReceiver {
private:
	int mCmdname;;
	std::string mFileName;
public:
	CCmdTestCaseReceiver(int ,std::string);
	virtual ~CCmdTestCaseReceiver();
	Json::Value Action();
};

#endif /* COMMANDTYPE_CCMDTESTCASERECEIVER_H_ */
