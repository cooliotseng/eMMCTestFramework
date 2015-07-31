/*
 * IReceiver.h
 *
 *  Created on: Feb 13, 2015
 *      Author: vli
 */

#ifndef IRECEIVER_H_
#define IRECEIVER_H_
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <json/json.h>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <unistd.h>
#include <time.h>

using namespace std;


const int WRITE = 0;

const int ERASE = 0;
const int TRIM = 1;
const int DISCARD = 2;

const int READ  = 1;
const int openEnd = 0;
const int preDefined_non_reliable = 1;
const int preDefined_reliable = 2;

const int programming_key = 0;
const int single_frame_read = 1;
const int multiple_frame_read = 2;

const int RPMB_write_single_frame_data = 0;
const int RPMB_write_multiple_frame_data = 1;

const int RPMB_read_single_frame_data = 0;
const int RPMB_read_multiple_frame_data = 1;

class IReceiver {
public:
	IReceiver();
	virtual ~IReceiver();
	virtual Json::Value Action() = 0;
};

#endif /* IRECEIVER_H_ */
