/*
 * CType3CommandHandler.h
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#ifndef CTWOFILECASEHANDLER_H_
#define CTWOFILECASEHANDLER_H_

#include "CHandler.h"
#include "../../CommandType/header/CCmdTwoFileCaseReceiver.h"
#include "../../header/CConcreteCommand.h"

class CTwoFileCaseHandler: public CHandler {
public:
	CTwoFileCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu);
	virtual ~CTwoFileCaseHandler();
	int getCommandType();
	void genCommand(Json::Value value);
};

#endif /* CTYPE3COMMANDHANDLER_H_ */
