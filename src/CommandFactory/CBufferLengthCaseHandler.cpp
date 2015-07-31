/*
 * CType4CommandHandler.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: vli
 */

#include "header/CBufferLengthCaseHandler.h"

CBufferLengthCaseHandler::CBufferLengthCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu) :
CHandler(_pAct,_pUpdateStatu)  {
	// TODO Auto-generated constructor stub

}

CBufferLengthCaseHandler::~CBufferLengthCaseHandler() {
	// TODO Auto-generated destructor stub
}

int CBufferLengthCaseHandler::getCommandType() {
	return bufferLenth;
}

void CBufferLengthCaseHandler::genCommand(Json::Value _value) {
	const Json::Value ArgArray = _value["Argument"];

	pCmdRecever = new CCmdBufferLengthCaseReceiver (_value["CMDINDEX"].asInt(),ArgArray[0].asInt(),_value["ReadFileName"].asCString());
	pCommand = new CConcreteCommand(this->getCommandAct(),pCmdRecever,this->getUpdateStatus());
}
