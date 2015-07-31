/*
 * CCmdTypeCReceiver.h
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#ifndef COMMANDTYPE_CCMDERASECASERECEIVER_H_
#define COMMANDTYPE_CCMDERASECASERECEIVER_H_

#include "IReceiver.h"

class CCmdEraseCaseReceiver: public IReceiver {
private:
	int mCmdname;
	int mStartAdd;
	int mBlkLength;
	std::string mFileName;
public:
	CCmdEraseCaseReceiver(int ,int,int,std::string);
	virtual ~CCmdEraseCaseReceiver();
	Json::Value Action();
};

#endif /* COMMANDTYPE_CCMDERASECASERECEIVER_H_ */
