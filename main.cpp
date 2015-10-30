#include <iostream>
#include <string>

using namespace std;



int main(){
	int return_value = 0;
	int test = 0;
	string var1;
	string var2;
while(test != 4)
{
	cout<<"1.single_command"
	cout<<"2.multi_command"
	cout<<"3.comment_command"
	cout<<"4.exit"
	cin>> test;
	switch(test)
	{
		case 1:
				cin>> var1;
				cin>> var2;
				system(" ~./src./single_command.sh var1 var2");
				break;
		case 2:
				getline(cin, var1);
				system(" ~./src./multip_command.sh ""var1");
				break;
		case 3:
				system(" ~./src./comment_command.sh");
				break;
		case 4:
				system(" ~./src./exit.sh");
				break;
		default:	cout<<"error"<<endl;
				break;
	}
}
return 0;
}
