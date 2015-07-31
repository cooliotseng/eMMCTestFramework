/*
 * CType3CommandHandler.h
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#ifndef CSINGLEFILECASEHANDLER_H_
#define CSINGLEFILECASEHANDLER_H_

#include "CHandler.h"
#include "../../CommandType/header/CCmdSingleFileCaseReceiver.h"
#include "../../header/CConcreteCommand.h"

class CSingleFileCaseHandler: public CHandler {
public:
	CSingleFileCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu);
	virtual ~CSingleFileCaseHandler();
	int getCommandType();
	void genCommand(Json::Value value);
};

#endif /* CTYPE3COMMANDHANDLER_H_ */
