/*
 * CTypemEnhancedAttr6CommandHandler.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CEudaCaseHandler.h"

CEudaCaseHandler::CEudaCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu) :
CHandler(_pAct,_pUpdateStatu)  {
	// TODO Auto-generated constructor stub

}

CEudaCaseHandler::~CEudaCaseHandler() {
	// TODO Auto-generated destructor stub
}

int CEudaCaseHandler::getCommandType() {
	// TODO Auto-generated destructor stub
	return eudaCase;
}

void CEudaCaseHandler::genCommand(Json::Value _value) {
	const Json::Value ArgArray = _value["Argument"];

	pCmdRecever = new CCmdEudaCaseReceiver (_value["CMDINDEX"].asInt(),ArgArray[0].asUInt(),ArgArray[1].asInt(),ArgArray[2].asInt(), _value["ReadFileName"].asCString());
	pCommand = new CConcreteCommand(this->getCommandAct(),pCmdRecever,this->getUpdateStatus());
}
