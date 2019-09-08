#include "headers.h"

// main logic

int shell_start(string ps1)
{	int ret=0;
	//fflush(stdin);
	while(1){
	//execute forever
	
	string input= readcmd();
	if(input=="exit") {
		kill(0,1);
		break;
		}
	if(input=="echo $?") {
		cout<<ret<<endl;
		continue;
		}
	//cout<<"next cmd: "<<input<<endl;
	//parse input and split it for exectution
	vins instructions = split_input(input);

	//exectute the list
	ret = execute(instructions);

	}	
	
	return 0;
}
