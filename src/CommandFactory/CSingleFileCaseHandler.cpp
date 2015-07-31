/*
 * CType3CommandHandler.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CSingleFileCaseHandler.h"

CSingleFileCaseHandler::CSingleFileCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu) :
CHandler(_pAct,_pUpdateStatu)  {
	// TODO Auto-generated constructor stub

}

CSingleFileCaseHandler::~CSingleFileCaseHandler() {
	// TODO Auto-generated destructor stub
}

int CSingleFileCaseHandler::getCommandType() {
	// TODO Auto-generated destructor stub
	return singleFileCase;
}

void CSingleFileCaseHandler::genCommand(Json::Value _value) {
	const Json::Value ArgArray = _value["Argument"];

	pCmdRecever = new CCmdSingleFileCaseReceiver(_value["CMDINDEX"].asInt(),ArgArray[0].asCString(),_value["ReadFileName"].asCString());
	pCommand = new CConcreteCommand(this->getCommandAct(),pCmdRecever,this->getUpdateStatus());
}
