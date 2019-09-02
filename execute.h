#include "utils.h"


int execute(vins instructions){
	//loop for each instruction
	string str=instructions[0].prog;	
	const char *x[]={str.c_str(),NULL};
	//add logic for fork
        int ret=execvp(x[0],(char* const*)x);
        if(ret==-1)
        perror("error:");

	return 0;
}
