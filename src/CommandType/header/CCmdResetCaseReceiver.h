/*
 * CCmdType3Receiver.h
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#ifndef COMMANDTYPE_CCMDRESETCASERECEIVER_H_
#define COMMANDTYPE_CCMDRESETCASERECEIVER_H_

#include "IReceiver.h"

class CCmdResetCaseReceiver: public IReceiver {
private:
	int mCmdname;;
	std::string mFileName;
public:
	CCmdResetCaseReceiver(int ,std::string);
	virtual ~CCmdResetCaseReceiver();
	Json::Value Action();
};

#endif /* COMMANDTYPE_CCMDTESTCASERECEIVER_H_ */
