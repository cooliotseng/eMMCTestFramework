/*
 * CType6CommandHandler.h
 *
 *  Created on: Mar 13, 2015
 *      Author: vli
 */

#ifndef COMMANDFACTORY_CTYPE6COMMANDHANDLER_H_
#define COMMANDFACTORY_CTYPE6COMMANDHANDLER_H_

#include "CHandler.h"
#include "../../CommandType/header/CCmdEudaCaseReceiver.h"
#include "../../header/CConcreteCommand.h"

class CEudaCaseHandler: public CHandler {
public:
	CEudaCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu);
	virtual ~CEudaCaseHandler();
	int getCommandType();
	void genCommand(Json::Value value);
};

#endif /* COMMANDFACTORY_CTYPE6COMMANDHANDLER_H_ */
