/*
 * CType3CommandHandler.h
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#ifndef CSINGLEFILEDISKCASEHANDLER_H_
#define CSINGLEFILEDISKCASEHANDLER_H_

#include "CHandler.h"
#include "../../CommandType/header/CCmdSingleFileDiskCaseReceiver.h"
#include "../../header/CConcreteCommand.h"

class CSingleFileDiskCaseHandler: public CHandler {
public:
	CSingleFileDiskCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu);
	virtual ~CSingleFileDiskCaseHandler();
	int getCommandType();
	void genCommand(Json::Value value);
};

#endif /* CTYPE3COMMANDHANDLER_H_ */
