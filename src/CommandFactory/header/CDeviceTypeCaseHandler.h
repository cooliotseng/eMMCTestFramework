/*
 * CType2CommandHandler.h
 *
 *  Created on: Feb 24, 2015
 *      Author: vli
 */

#ifndef CDEVICETYPECASEHANDLER_H_
#define CDEVICETYPECASEHANDLER_H_

#include "CHandler.h"
#include "../../CommandType/header/CCmdDeviceTypeCaseReceiver.h"
#include "../../header/CConcreteCommand.h"

class CDeviceTypeCaseHandler: public CHandler {
public:
	CDeviceTypeCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu);
	virtual ~CDeviceTypeCaseHandler();
	int getCommandType();
	void genCommand(Json::Value value);
};

#endif /* CTYPE2COMMANDHANDLER_H_ */
