/*
 * CType3CommandHandler.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CSingleFileDiskCaseHandler.h"

CSingleFileDiskCaseHandler::CSingleFileDiskCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu) :
CHandler(_pAct,_pUpdateStatu)  {
	// TODO Auto-generated constructor stub

}

CSingleFileDiskCaseHandler::~CSingleFileDiskCaseHandler() {
	// TODO Auto-generated destructor stub
}

int CSingleFileDiskCaseHandler::getCommandType() {
	// TODO Auto-generated destructor stub
	return singleFileDiskCase;
}

void CSingleFileDiskCaseHandler::genCommand(Json::Value _value) {
	const Json::Value ArgArray = _value["Argument"];

	pCmdRecever = new CCmdSingleFileDiskCaseReceiver(_value["CMDINDEX"].asInt(),ArgArray[0].asCString(),_value["ReadFileName"].asCString());
	pCommand = new CConcreteCommand(this->getCommandAct(),pCmdRecever,this->getUpdateStatus());
}
