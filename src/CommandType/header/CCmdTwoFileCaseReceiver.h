/*
 * CCmdWriteCaseReceiver.h
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#ifndef COMMANDTYPE_CCMDTWOFILECASERECEIVER_H_
#define COMMANDTYPE_CCMDTWOFILECASERECEIVER_H_

#include "IReceiver.h"

class CCmdTwoFileCaseReceiver: public IReceiver {
private:
	int mCmdname;;
	std::string mIofilename1;
	std::string mIofilename2;
	std::string mFileName;
public:
	CCmdTwoFileCaseReceiver(int ,std::string , std::string, std::string);
	virtual ~CCmdTwoFileCaseReceiver();
	Json::Value Action();
};

#endif /* COMMANDTYPE_CCMDSINGLEFILECASERECEIVER_H_ */
