/*
 * CType5CommandHandler.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CGppCaseHandler.h"

CGppCaseHandler::CGppCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu) :
CHandler(_pAct,_pUpdateStatu)  {
	// TODO Auto-generated constructor stub

}

CGppCaseHandler::~CGppCaseHandler() {
	// TODO Auto-generated destructor stub
}

int CGppCaseHandler::getCommandType() {
	// TODO Auto-generated destructor stub
	return gppCase;
}

void CGppCaseHandler::genCommand(Json::Value _value) {
	const Json::Value ArgArray = _value["Argument"];

	pCmdRecever = new CCmdGppCaseReceiver (_value["CMDINDEX"].asInt(),ArgArray[0].asInt(),ArgArray[1].asInt(),_value["ReadFileName"].asCString());
	pCommand = new CConcreteCommand(this->getCommandAct(),pCmdRecever,this->getUpdateStatus());
}
