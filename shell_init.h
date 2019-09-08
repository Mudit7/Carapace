#include "headers.h"
#include "func_utils.h"
#define RCFILE "/home/mudit/OS/Myshell/myrc"
using namespace std;

void putvar(string key,string value)
{
	ofstream rcfile_w;
	rcfile_w.open(RCFILE, std::ios::app);
	rcfile_w<<key<<"="<<value<<"\n";
	rcfile_w.close();
}

int shell_init(string &path,string &home,string &user,string &hostname,string &ps1)
{
	ofstream rcfile_w;
	rcfile_w.open(RCFILE, std::ios::trunc);
	rcfile_w.close();	
	putvar("USER","mudit");
	putvar("HOME","/Users/mudit");
	putvar("PATH","/bin");
	putvar("HOSTNAME","local");
	putvar("PS1","$");
	return 0;
}
