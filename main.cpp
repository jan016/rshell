#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <vector>

using namespace std;
int info_RF(char* dirName);
int info_D(char* dirName);
int info_CS(char* dirName);
int info_BS(char* dirName);
int info_S(char* dirName);
int info_SL(char* dirName);
int info_R(char* dirName);
int info_W(char* dirName);
int info_X(char* dirName);
int main()
{
	char *word[50];
    char buf[500] = "\0";
    int i, k=0;
	struct stat sb;
	cin.getline(buf, 500); 
 
    word[k] = strtok(buf, " ");
    
    while (word[k++] != NULL) {
        word[k] = strtok(NULL, " ");
    }
 	string checking = word[0];
/*	pid_t pid;
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
		if(checking == "[" || checking == "test"){
			if(checking_first == '-'){
	char checking_first = *word[1];
	char checking_second = *word[2];
	string check_file = word[2];
	if(stat ( word[2], &sb) != 0 && (checking_first != '-' || checking_second != '-')){
		cout<<"input does not exist. filename entered: " <<check_file<<endl;
		return -1;
	}
				//All functions need that file exist
					checking = word[1];
					vector<char *> dirlist;
					dirlist.push_back(word[2]);
					cout<<dirlist.front()<<endl;
					if(checking == "-a" || checking == "-e"){ //True if <file> exist
						cout<<"file exist"<<endl;
					}
					else if(checking == "-f"){//True if <file> exist and is regular file
						info_RF(dirlist.front());
					}
					else if(checking == "-d"){//True if <file> exist and is a directory
						info_D(dirlist.front());
					}
					else if(checking == "-c"){//True if <file> exist and is character special file
						info_CS(dirlist.front());
					}	
					else if(checking == "-b"){//True if <file> exist and is block special file
						info_BS(dirlist.front());
					}
					else if(checking == "-p"){//True if <file> exist and is named pipe
						// need to 
					}
					else if(checking == "-S"){//True if <file> exist and is socket file
						info_S(dirlist.front());
					}
					else if(checking == "-L" || checking == "-h"){//True if <file> exist and is symbolic link
						info_SL(dirlist.front());
					}
					else if(checking == "-g"){//True if <file> exist and is sgid bit set
						// need to	
					}	
					else if(checking == "-u"){//True if <file> exist and is suid bit set
						// need to
					}
					else if(checking == "-r"){//True if <file> exist and is readable
						info_R(dirlist.front());
					}
					else if(checking == "-w"){//True if <file> exist and is writeable
						info_W(dirlist.front());
					}
					else if(checking == "-x"){//True if <file> exist and is excutable
						info_X(dirlist.front());
					}
					else if(checking == "-s"){//True if <file> exist and size of file is bigger than 0 (not empty)
						//need to	
					}
					else if(checking == "-t"){//True if file descriptor <fd> is open and refers to a terminal
						//need to
					}
					else
						cout<<"invalid command"<<endl;
			}
	/*		checking_first = *word[2];
			if(checking_first == '-'){ // there is two files to compare 
				if(*word[2] == '-nt'){// True if <file1> is newer than <file2>

				}
				else if(*word[2] == '-ot'){// True if <file1> is older than <file2>

				}
				else if(*word[2] == '-ef'){// True if <file1> and <file2> refer to the same device and inode numbers.

				}
			}*/
		}
	return 0;
}
int info_RF(char* dirName){//regular file
	struct stat sb;
    if(stat(dirName, &sb)==-1)
    {
        perror("stat");
    }

	if((sb.st_mode & S_IFREG)){
		cout<<"file exist. its regular file"<<endl;
		return 1;
	}
		cout<<"file exist. but not its regular file"<<endl;
	return 0;
}
int info_D(char* dirName){
	struct stat sb;
    if(stat(dirName, &sb)==-1)
    {
        perror("stat");
    }

	if((sb.st_mode & S_IFDIR)){
		cout<<"file exist. its directory"<<endl;
		return 1;
	}
		cout<<"file exist. but not its directory"<<endl;
	return 0;
}
int info_CS(char * dirName){
	struct stat sb;
    if(stat(dirName, &sb)==-1)
    {
        perror("stat");
    }

	if((sb.st_mode & S_IFCHR)){
		cout<<"file exist. character special"<<endl;
		return 1;
	}
		cout<<"file exist. but not character special"<<endl;
	return 0;
}
int info_BS(char * dirName){
	struct stat sb;
    if(stat(dirName, &sb)==-1)
    {
        perror("stat");
    }

	if((sb.st_mode & S_IFBLK)){
		cout<<"file exist. block special "<<endl;
		return 1;
	}
		cout<<"file exist. but not block special "<<endl;
	return 0;
}
int info_S(char * dirName){
	struct stat sb;
    if(stat(dirName, &sb)==-1)
    {
        perror("stat");
    }

	if((sb.st_mode & S_IFSOCK)){
		cout<<"file exist. socket file"<<endl;
		return 1;
	}
		cout<<"file exist. but not socket file"<<endl;
	return 0;
}
int info_SL(char * dirName){
	struct stat sb;
    if(stat(dirName, &sb)==-1)
    {
        perror("stat");
    }

	if((sb.st_mode & S_IFLNK)){
		cout<<"file exist. symbolic link"<<endl;
		return 1;
	}
		cout<<"file exist. but not symbolic link"<<endl;
	return 0;
}
 int info_R(char * dirName){//read
	 struct stat sb;
    if(stat(dirName, &sb)==-1)
    {
        perror("stat");
    }

	 if((sb.st_mode & S_IRUSR)){
		cout<<"file exist. readable"<<endl;
		return 1;
	 }
		cout<<"file exist. but not readable"<<endl;
	 return 0;
 }
int info_W(char * dirName){
	struct stat sb;
    if(stat(dirName, &sb)==-1)
    {
        perror("stat");
    }

	if((sb.st_mode & S_IWUSR)){
		cout<<"file exist. writeable"<<endl;
		return 1;
	}
		cout<<"file exist. but not writeable"<<endl;
	return 0;
}
int info_X(char * dirName){
	struct stat sb;
    if(stat(dirName, &sb)==-1)
    {
        perror("stat");
    }

	if((sb.st_mode & S_IXUSR)){
		cout<<"file exist. excutable"<<endl;
		return 1;
	}
		cout<<"file exist. but not excutable"<<endl;
	return 0;
}