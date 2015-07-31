/*
 * CHandler.h
 *
 *  Created on: Feb 24, 2015
 *      Author: vli
 */

#ifndef CHANDLER_H_
#define CHANDLER_H_
#include <string>
#include <stdio.h>
#include <iostream>
#include <json/json.h>

#include "../../header/ICommand.h"
#include "../../CommandType/header/IReceiver.h"
#include "../../UpdateMethod/header/CUpdateStatus.h"
#include "../../header/CConcreteCommandAct.h"
#include "../../header/ICommandAct.h"

enum cmdTYpe {cmdIndex = 1, testCase, writeCase, readCase, eraseCase
				, gppCase, eudaCase, resetCase, bufferLenth, deviceTypeCase
				, singleFileCase, twoFileCase, singleFileDiskCase};

class CHandler {
protected:
	CHandler *pmNextHandler;
	IUpdateStatus *pmUpdateStatus;
    ICommandAct  *pAct;
	IReceiver *pCmdRecever;
	ICommand *pCommand;
public:
	CHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatus);
	virtual ~CHandler();
	virtual int getCommandType() = 0;
	virtual void genCommand(Json::Value value) = 0;
	void CommandCreatHandler(Json::Value value);
	void setNext(CHandler *_pNextHandler);
	CHandler * getHandler();
	IUpdateStatus * getUpdateStatus();
	void setUpdateStatus(CUpdateStatus *);
	ICommandAct * getCommandAct();
	void setCommandAct(ICommandAct * );
	IReceiver * getReceiver();
	void setReceiver(IReceiver *);
	ICommand * getCommand();
	void setCommand(ICommand *);
};

#endif /* CHANDLER_H_ */
