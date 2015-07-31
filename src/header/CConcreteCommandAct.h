/*
 * CConcreteCommandAct.h
 *
 *  Created on: Feb 13, 2015
 *      Author: vli
 */

#ifndef CCONCRETECOMMANDACT_H_
#define CCONCRETECOMMANDACT_H_
#include <vector>
#include <stdlib.h>
#include "ICommandAct.h"
#include "ICommand.h"
using namespace std;

class CConcreteCommandAct: public ICommandAct {
private:
	std::vector<ICommand *> mpCommandList;
public:
	CConcreteCommandAct();
	virtual ~CConcreteCommandAct();
	void RegisterCommand(ICommand* pcmd);
	void UnRegisterCommand(ICommand* pcmd);
	void Action();
};

#endif /* CCONCRETECOMMANDACT_H_ */
