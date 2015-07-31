/*
 * CType5CommandHandler.h
 *
 *  Created on: Mar 13, 2015
 *      Author: vli
 */

#ifndef COMMANDFACTORY_CGPPCASEHANDLER_H_
#define COMMANDFACTORY_CGPPCASEHANDLER_H_

#include "CHandler.h"
#include "../../CommandType/header/CCmdGppCaseReceiver.h"
#include "../../header/CConcreteCommand.h"

class CGppCaseHandler: public CHandler {
public:
	CGppCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu);
	virtual ~CGppCaseHandler();
	int getCommandType();
	void genCommand(Json::Value value);
};

#endif /* COMMANDFACTORY_CTYPE5COMMANDHANDLER_H_ */
