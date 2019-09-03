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
	int fds[2];
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
		
		instruction_list.push_back(inst);
	}
	return instruction_list;
}

int execute(vins instructions){
	
	//if only one cmd
	if(instructions.size()==0) return 0;

	if(instructions.size()==1){
			const char* str=instructions[0].prog.c_str();	
			
			char *argv[1000];

			int j;
			for(j=0;j<instructions[0].params.size();j++){
				argv[j]=new char[instructions[0].params[j].size()+1];
				strcpy(argv[j],instructions[0].params[j].c_str());
			}

			argv[j]=(char*)NULL;
			instructions[0].fds[0]=0;
			instructions[0].fds[1]=1;
			pid_t pid = fork();  
		    if (pid == 0) { 
		        if (execvp(argv[0], (char* const*)argv) < 0) { 
		        	perror("error");
		            return -1; 
		        } 
		        exit(0); 
		    }
			wait(NULL); 
			//cout<<"\n";
	}
	else{ //logic for PIPED commands
		int i;
		int count=instructions.size();
		int (*pipes)[2]=new int[count-1][2];
		//make pipe connections
		instructions[0].fds[0]=0;
		for(i=0;i<count-1;i++){
			
			if(pipe(pipes[i])==-1)
			{
				perror("pipe");
			}
			instructions[i].fds[1]=pipes[i][1];
			instructions[i+1].fds[0]=pipes[i][0];
			
		}
		instructions[count-1].fds[1]=1;
		// cout<<"**";
		// cout<<instructions[count-1].fds[0];
		// cout<<instructions[count-1].fds[1];
		// cout<<"**\n";
		for(i=0;i<count;i++){
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
				if(instructions[i].fds[0]!=0)
				dup2(instructions[i].fds[0],0);

				if(instructions[i].fds[1]!=1)
				dup2(instructions[i].fds[1],1);
				
		        if (execvp(argv[0], (char* const*)argv) < 0) { 
		        	perror("error");
		            return -1; 
		        } 
		        exit(0); 
		    }
			//free(argv);
			//wait(NULL); 
			
			//cout<<"\n";
	    }
		for(i=0;i<count-1;i++){
			close(pipes[i][1]);
			close(pipes[i][0]);
			
		}
		free(pipes);
		
	}

	return 0;
}

// main logic
int shell_start(string ps1)
{
	//read input as string
	while(1){
		//execute forever
	string input= readcmd();

	//parse input and split it for exectution
	vins instructions = split_input(input);

	//exectute the list
	int ret = execute(instructions);
	//cout<<"ret:"<<ret;
	if(ret==-1) {
		cout<<"Error, exiting";
		return ret;
		}
	}	
	
	return 0;
}
