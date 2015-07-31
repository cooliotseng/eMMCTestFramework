/*
 * CUpdateStatus.h
 *
 *  Created on: Feb 13, 2015
 *      Author: vli
 */

#ifndef CUPDATESTATUS_H_
#define CUPDATESTATUS_H_
#include <iostream>
#include "IUpdateStatus.h"
#include <stdlib.h>
using namespace std;
class CUpdateStatus: public IUpdateStatus {
private:
	std::string mFilePath;
public:
	CUpdateStatus(std::string);
	virtual ~CUpdateStatus();
	void Update(Json::Value value);
};

#endif /* CUPDATESTATUS_H_ */
