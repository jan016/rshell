
#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <direct.h>
#include <fcntl.h>
#include <math.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
//#include <sys/wait.h>
//#include <unistd.h>
#include <io.h>
using namespace std;
 
#define WORDLEN 10
 
int main()
{
/*	char *word[50];
    char buf[500] = "\0";
    int i, k=0;
    cin.getline(buf, 500); 
 
    word[k] = strtok(buf, " ");
    
    while (word[k++] != NULL) {
        word[k] = strtok(NULL, " ");
    }
 	char checking_first = *word[0];
	pid_t pid;
	pid = fork();
	if(pid == 0)
	{
		if(k<=3  && word[0] != "exit"){
			string cmd("./src./single_command.sh ");
			cmd += word[0];
			cmd += " ";
			cmd += word[1];
			system(cmd.c_str());
			perror("invalid input");
		}								//run for single_command.sh
		else if(checking_first == '#'){
			string cmd("./src./comment_command.sh ");
			system(cmd.c_str());		//run for comment_command.sh
			perror("invalid input");
		}
		else if(word[0] == "exit"){
			string cmd("./src./exit.sh ");
			cmd += word[0];
			system(cmd.c_str());
			perror("invalid input");
		}								//run for exit.sh
		else	{
			int initial = 0; 
			int hold_number = 0;
			int hold_other_number = 0;
			int ret[20];
			int v[20];

			while(initial <= k){
			string cmd("./src./multi_command.sh ");
				if(word[initial] == "|"|| word[initial] == "&" || word[initial][strlen(word[initial]-1)] == ';'){
					if(hold_number < initial){
						while(hold_number <initial){
						cmd += word[hold_number];
						hold_number++;
						}
						ret[hold_other_number] = system(cmd.c_str());
						v[hold_other_number] = WEXITSTATUS(ret[hold_other_number]);
					}
				}
				initial++;
			}
		}
		int status = 0;
		waitpid(pid, status, WNOHANG);
		if(status != 1){
			perror("fail to close child process");
		}

	}
	else if(pid == -1){
		cout<<"fork error!"<<endl;
	}
	else{
		cout<<"Should not be in parents"<<endl;
	}
*/
//top of part is for homework 01 which does not working so i made it as comment
	system("./src./test.sh");//this variable goes into src-> test.sh to test
	

		system("pause");
	return 0;
}
