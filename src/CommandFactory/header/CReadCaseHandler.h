/*
 * CType4CommandHandler.h
 *
 *  Created on: Mar 13, 2015
 *      Author: vli
 */

#ifndef COMMANDFACTORY_CREADCASEHANDLER_H_
#define COMMANDFACTORY_CREADCASEHANDLER_H_

#include "CHandler.h"
#include "../../CommandType/header/CCmdReadCaseReceiver.h"
#include "../../header/CConcreteCommand.h"

class CReadCaseHandler: public CHandler {
public:
	CReadCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu);
	virtual ~CReadCaseHandler();
	int getCommandType();
	void genCommand(Json::Value value);
};

#endif /* COMMANDFACTORY_CTYPE4COMMANDHANDLER_H_ */
