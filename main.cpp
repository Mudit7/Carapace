#include "headers.h"

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
		//cout<<"\nEnter valid command.. \n";
		exit(0);
	}
	return 0;
}
