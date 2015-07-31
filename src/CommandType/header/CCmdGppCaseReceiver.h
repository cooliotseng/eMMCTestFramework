/*
 * CCmdTypeCReceiver.h
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

//#ifndef COMMANDTYPE_CCMDGPPCASERECEIVER_H_
//#define COMMANDTYPE_CCMDGPPCASERECEIVER_H_

#include "IReceiver.h"

class CCmdGppCaseReceiver: public IReceiver {
private:
	int mCmdname;
	int mSizeMult;
	int mEnhancedAttr;
	std::string mFileName;



public:
	CCmdGppCaseReceiver(int ,int,int,std::string);
	virtual ~CCmdGppCaseReceiver();
	Json::Value Action();
};

//#endif /* COMMANDTYPE_CCMDERASECASERECEIVER_H_ */
