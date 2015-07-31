/*
 * CType2CommandHandler.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: vli
 */

#include "header/CTestCaseHandler.h"

CTestCaseHandler::CTestCaseHandler(CConcreteCommandAct *_pAct,IUpdateStatus *_pUpdateStatu) :
CHandler(_pAct,_pUpdateStatu) {
	// TODO Auto-generated constructor stub

}

CTestCaseHandler::~CTestCaseHandler() {
	// TODO Auto-generated destructor stub
}

int CTestCaseHandler::getCommandType() {
	return testCase;
}

void CTestCaseHandler::genCommand(Json::Value _value) {
	const Json::Value ArgArray = _value["Argument"];
	pCmdRecever = new CCmdTestCaseReceiver(_value["CMDINDEX"].asInt(), _value["ReadFileName"].asCString());
	pCommand = new CConcreteCommand(this->getCommandAct(),pCmdRecever,this->getUpdateStatus());
}
