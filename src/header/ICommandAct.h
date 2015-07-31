/*
 * ICommandAct.h
 *
 *  Created on: Feb 13, 2015
 *      Author: vli
 */
#ifndef ICOMMANDACT_H_
#define ICOMMANDACT_H_
#include "ICommand.h"

class ICommandAct {
public:
	ICommandAct();
	virtual ~ICommandAct();
	virtual void RegisterCommand(ICommand *)=0;
	virtual void UnRegisterCommand(ICommand *)=0;
	virtual void Action()=0;
};

#endif /* ICOMMANDACT_H_ */
