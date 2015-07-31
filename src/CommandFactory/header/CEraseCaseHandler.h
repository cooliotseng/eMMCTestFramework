/*
 * CType4CommandHandler.h
 *
 *  Created on: Mar 13, 2015
 *      Author: vli
 */

#ifndef COMMANDFACTORY_CERASECASEHANDLER_H_
#define COMMANDFACTORY_CERASECASEHANDLER_H_

#include "CHandler.h"
#include "../../CommandType/header/CCmdEraseCaseReceiver.h"
#include "../../header/CConcreteCommand.h"

class CEraseCaseHandler: public CHandler {
public:
	CEraseCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu);
	virtual ~CEraseCaseHandler();
	int getCommandType();
	void genCommand(Json::Value value);
};

#endif /* COMMANDFACTORY_CTYPE4COMMANDHANDLER_H_ */
