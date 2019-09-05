#include "headers.h"

// main logic
int shell_start(string ps1)
{
	//read input as string
	while(1){
	//execute forever
	
	string input= readcmd();
	if(input=="exit") break;

	//parse input and split it for exectution
	vins instructions = split_input(input);

	//exectute the list
	int ret = execute(instructions);
	}	
	
	return 0;
}
