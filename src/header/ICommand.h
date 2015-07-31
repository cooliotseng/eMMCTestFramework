/*
 * ICommand.h
 *
 *  Created on: Feb 13, 2015
 *      Author: vli
 */

#ifndef ICOMMAND_H_
#define ICOMMAND_H_

class ICommand {
public:
	ICommand();
	virtual ~ICommand();
	virtual void Execute()=0;
};

#endif /* ICOMMAND_H_ */
