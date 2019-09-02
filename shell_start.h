#include<iostream>
#include<unistd.h>
#include<string>
#include<string.h>
#include<vector>
#include <sys/types.h>
#include <sys/wait.h>
#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

typedef struct instruction{
	string prog;
	vs params;
	bool bg_flag;
}instruction;

typedef vector<instruction> vins;

string readcmd()
{
	string input;
    getline(cin,input);
	return input; 
	// trie to be implemented	
}

vins split_input(string input)
{
	vs args;
	vins instruction_list;
       	//start parsing make the list
	instruction inst;
	//sample
	//string input="cat file1.txt|sort|grep \".*\" > save.txt";
	stringstream X(input);
	string S1;
	while(getline(X,S1,'|'))
	{
		inst.params.clear();
		stringstream Y(S1);
		string S2;
		while(getline(Y,S2,' '))
		{
			inst.params.push_back(S2);
		}
		inst.prog=inst.params[0];
		inst.bg_flag=0;
		
		//cout<<inst.prog<<" ";
		instruction_list.push_back(inst);
	}
	return instruction_list;
}

int execute(vins instructions){
	//loop for each instruction

	if(instructions.size()>0){
		int i;

		for(i=0;i<instructions.size();i++){
			cout<<"size: "<<instructions.size();
			const char* str=instructions[i].prog.c_str();	
			
			char *argv[1000];

			int j;
			for(j=0;j<instructions[i].params.size();j++){
				argv[j]=new char[instructions[i].params[j].size()+1];
				strcpy(argv[j],instructions[i].params[j].c_str());
			}

			argv[j]=(char*)NULL;
			
			pid_t pid = fork();  
		    if (pid == 0) { 
		    	printf("--------------");
		        if (execvp(argv[0], (char* const*)argv) < 0) { 
		        	perror("error: ");
		            return -1; 
		        } 
		        exit(0); 
		    } 
			
	    }     
	}
	return 0;
}

// main logic
int shell_start(string ps1)
{
	//read input as string
	string input= readcmd();

	//parse input and split it for exectution
	vins instructions = split_input(input);

	//exectute the list
	int ret = execute(instructions);

		
	return ret;
}
