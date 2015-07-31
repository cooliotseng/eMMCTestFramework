/*
 * CCmdType3Receiver.h
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#ifndef COMMANDTYPE_CCMDINITIALIZATIONRECEIVER_H_
#define COMMANDTYPE_CCMDINITIALIZATIONRECEIVER_H_

#include "IReceiver.h"

class CCmdInitializationReceiver: public IReceiver {
private:
	int mCmdname;;
	std::string mFileName;
public:
	CCmdInitializationReceiver(int ,std::string);
	virtual ~CCmdInitializationReceiver();
	Json::Value Action();
};

#endif /* COMMANDTYPE_CCMDTESTCASERECEIVER_H_ */
