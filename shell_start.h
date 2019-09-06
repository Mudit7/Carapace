#include "headers.h"

// main logic

int shell_start(string ps1)
{	int ret=0;
	//read input as string
	while(1){
	//execute forever
	
	string input= readcmd();
	if(input=="exit") break;
	if(input=="echo $?") {
		cout<<ret<<endl;
		continue;
		}

	//parse input and split it for exectution
	vins instructions = split_input(input);

	//exectute the list
	ret = execute(instructions);

	}	
	
	return 0;
}
