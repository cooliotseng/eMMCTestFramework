//============================================================================
// Name        : eMMCTester.cpp
// Author      : Coolio
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "./header/commond.h"
int CreatEnv();
void ReleaseEnv();

int main(int argc, char *argv[]) {
	 //system("sudo rm -rf /var/www/html/emmc/statusFiles/2015*");
	 system("sudo umount ~/debugfs");


	 Json::Reader reader;
	 Json::Value value;
	 fstream infile;
	 std::vector<std::string> stringArgv;


	 if (argc > 1) {
	     stringArgv.assign (argv + 1, argv + argc);
	 } else {
		 std::cout << "No arguments" << std::endl;
		 return -1;
	 }

     CConcreteCommandAct *pAct = new CConcreteCommandAct();
     CCommandFactory *mCmdFactory = new CCommandFactory(pAct, stringArgv[0]);
	 char jsonbuf[4096];

	 if (CreatEnv() != 0){
		 return 1;
	 };

	 string raw;
	 //read command file
	 infile.open(stringArgv[1].c_str(),ios::in);
	 infile.read(jsonbuf, 4096);
	 raw.assign(jsonbuf);
	 //parser json data
	 if (reader.parse(raw, value)) {
		 //std::cout << "parsing: " << value ;
		 //create command sequence
		 mCmdFactory->CreatCommandList(value);
	 }

	 infile.close();

	 //run command sequence
	pAct->Action();
	ReleaseEnv();

	 return 0;
}

int CreatEnv(){
	char Shellbuf[4096];
	string tShellbuf;
	FILE *pp;

	system ("cat /dev/null > /var/www/html/emmc/statusFiles/myEclipseLog.log");

	///////////////////////creat ~/debugfs/////////////////////
	if((pp=popen("ls ~/ | grep debugfs","r")) == NULL){
		std::cout << "Popen() error: " << std::endl;
	}

	if(fgets(Shellbuf,sizeof(Shellbuf),pp) == NULL){
		system("mkdir ~/debugfs");
	}

	///////////////////////mount debugfs////////////////////////////////
	if((pp=popen("sudo ls ~/debugfs/ | wc -l","r")) == NULL){
		std::cout << "Popen() error: " << std::endl ;
	}

	if (atoi(fgets(Shellbuf,sizeof(Shellbuf),pp)) == 0){
		system("sudo mount -t debugfs debug ~/debugfs");
	} else{
		return 1;
	}

	//////////////////////ummount mmcblk0/////////////////////////////////
	if((pp=popen("df | grep mmcblk0 |awk '{printf $6 \"\\n\"}'","r")) == NULL){
		std::cout << "Popen() error: " << std::endl;
	}

	if ( fgets(Shellbuf,sizeof(Shellbuf),pp) != NULL) {
		tShellbuf.assign("sudo umount ").append(fgets(Shellbuf,sizeof(Shellbuf),pp));
		system( tShellbuf.c_str());

		/*
			tShellbuf.assign("sudo umount ").append(fgets(Shellbuf,sizeof(Shellbuf),pp));
			if(strlen(Shellbuf) != 0){
				system ("sudo umount /etc/mmcblk0");
				//system( tShellbuf.append(Shellbuf).c_str());
			}
		*/
	}

	//////////////////////rmmod mmc_block/////////////////////////////////
	if((pp=popen("lsmod | grep mmc_block |wc -l","r")) == NULL){
		          		 std::cout << "Popen() error: " << std::endl;
	}

	if (atoi(fgets(Shellbuf,sizeof(Shellbuf),pp)) != 0){
		system("sudo rmmod mmc_block");
	}

     //////////////////////rmmod mmc_test/////////////////////////////////
	if((pp=popen("lsmod | grep mmc_test |wc -l","r")) == NULL){
		std::cout << "Popen() error: " << std::endl;
	}

	if (atoi(fgets(Shellbuf,sizeof(Shellbuf),pp)) != 0){
		system("sudo rmmod mmc_test");
	}

	//////////////////////rmmod mmc_test/////////////////////////////////
	if((pp=popen("find /var/www -name mmc_test.ko","r")) == NULL){
		std::cout << "Popen() error: " << std::endl;
	}

	tShellbuf.assign("sudo insmod ").append(fgets(Shellbuf,sizeof(Shellbuf),pp));
	system(tShellbuf.c_str());

	system("sudo dmesg -c >/dev/null");
	system("sudo chown -R www-data:www-data ~/debugfs");

	pclose(pp);

	return 0;
}

void ReleaseEnv(){
	system("sudo umount ~/debugfs");
	system ("sudo rmmod mmc_block");
	//system("sudo rm -rf /var/www/html/emmc/statusFiles/2015*");
	//system("sudo rmmod mmc_test");
	//system("sudo insmod /lib/modules/3.19.3/kernel/drivers/mmc/card/mmc_block.ko");
}
