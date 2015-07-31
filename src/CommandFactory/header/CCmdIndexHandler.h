/*
 * CType1CommandHandler.h
 *
 *  Created on: Feb 24, 2015
 *      Author: vli
 */

#ifndef CCMDINDEXHANDLER_H_
#define CCMDINDEXHANDLER_H_

#include "CHandler.h"
#include "../../CommandType/header/CCmdIndexReceiver.h"
#include "../../header/CConcreteCommand.h"

class CCmdIndexHandler: public CHandler {
public:
	CCmdIndexHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu);
	virtual ~CCmdIndexHandler();
	int getCommandType();
    void genCommand(Json::Value value);
};

#endif /* CTYPE1COMMANDHANDLER_H_ */
