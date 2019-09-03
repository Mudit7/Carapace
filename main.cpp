#include<iostream>
#include<unistd.h>
#include<string>
#include<vector>

#include "shell_init.h"
#include "shell_start.h"

using namespace std;

int main()
{
	int ret=0;
	string path,home,user,hostname,ps1;   //and others
	ret=shell_init(path,home,user,hostname,ps1);
	
	if(ret==-1){
		cout<<"Error in shell_init.. exiting";
		return -1;
	}

	ret=shell_start(ps1);	//pass apt variables

	if(ret==-1){
		cout<<"\nError:In shell_start.. exiting\n";
		return -1;
	}
	return 0;
}
