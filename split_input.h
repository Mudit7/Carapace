#include "utils.h"

vins split_input(string input)
{
	vs args;
	vins instruction_list;
       	//start parsing make the list
	instruction inst;
	//sample
	//string input="cat file1.txt|sort|grep \".*\" > save.txt";
	inst.prog="ls";
	inst.bg_flag=0;

	instruction_list.push_back(inst);
	return instruction_list;
}
