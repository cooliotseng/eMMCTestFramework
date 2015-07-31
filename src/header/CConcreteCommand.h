/*
 * CConcreteCommand.h
 *
 *  Created on: Feb 13, 2015
 *      Author: vli
 */

#ifndef CCONCRETECOMMAND_H_
#define CCONCRETECOMMAND_H_

#include "ICommand.h"
#include "ICommandAct.h"
#include "../CommandType/header/IReceiver.h"
#include "../UpdateMethod/header/IUpdateStatus.h"
#include <iostream>
using namespace std;

class CConcreteCommand: public ICommand {
private:
	ICommandAct *mpCommandAct;
	IReceiver *mpCmdRecever;
	IUpdateStatus *mpUpdateMethod;
public:
	CConcreteCommand(ICommandAct *pCommandAct);
	CConcreteCommand(ICommandAct *pCommandAct,IReceiver *pCmdRecever,IUpdateStatus *pUpdateMethod);
	virtual ~CConcreteCommand();
	void Execute();
};

#endif /* CCONCRETECOMMAND_H_ */
