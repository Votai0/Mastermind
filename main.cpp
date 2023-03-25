#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

int create_num(int digit_num);
int input_check(string input, int digit_count);
int main(int num,char *digit[]){
	int i;/*controls total user input*/
	if((strcmp(digit[0],"./mastermind")) && (strcmp(digit[0],"mastermind"))){/*checks if application name is not mastermind*/
		cout << "E0" << endl;
		return 0;
	}
	if(num!=3){/*check if there is any more or less input in parameters*/
		cout << "E0" << endl;
		return 0;
	}

	
	if(!strcmp(digit[1],"-r")){

		for (i = 0; digit[2][i]!='\0'; i++){/*checks input num is between 1 and 9 if it is not prints error*/
			if(digit[2][i]>'9' || digit[2][i]<'1'){/*checks input num is between 1 and 9 if it is not prints error*/
				cout << "E0" << endl;
				return 0;
			}
		}
		
		srand(time(NULL));
		int digit_of_num=atoi(digit[2]);/*number of digit for creating number*/
		int num=create_num(digit_of_num);/*creating number*/
		int cont;/*for the check input is false*/
		string str_num=to_string(num);/*changes number integer to string so easily control the input*/
		//cout << endl << str_num << endl;/*prints the number if u want know the number*/

		string input;
		int right_nums,place_wrong_nums;
		
		for (i = 0; i < 100; i++){/*game itself*/	
			right_nums=0,place_wrong_nums=0;
			input.clear();
			cin>>input;
			cont=input_check(input,digit_of_num);/*checking input if there is a wrong or esktra input*/
			if (cont==-1){
				cout << "E1" << endl;
				return 0;
			}
			if (cont==-2){
				cout << "E2" << endl;
				return 0;
			}
			
			

			for(int x=0;x<str_num.size();x++){/*checks input and prints place right and place wrong count*/
				for (int y = 0; y < str_num.size(); y++){
					if(x==y && str_num[x]==input[y])right_nums++;
					else if(str_num[x]==input[y])place_wrong_nums++;
				}
			}
			cout << right_nums << ' ' << place_wrong_nums<<endl;

			if(input==str_num){/*if user find the number*/
				cout<<"FOUND " << i+1 << endl;
				break;
			}	
		}		
	}
	else if(!strcmp(digit[1],"-u")){

		if(digit[2][0]=='0'){/*checks if -u input's first digit is 0*/
			cout << "E0" << endl;
			return 0;
		}
		for (i = 0; digit[2][i]!='\0'; i++){/*checks input number digit's is between 1 and 9 if it is not prints error*/
			for (int j = i+1; digit[2][j]!='\0'; j++){
				if(digit[2][i]==digit[2][j]){
					cout << "E0" << endl;
					return 0;
				}
			}
			if(digit[2][i]<'0' || digit[2][i]>'9'){
				cout << "E0" << endl;
				return 0;
			}
		}

		string given_num(digit[2]);
		string input;
		int right_nums,place_wrong_nums,digit_of_num=0,cont;

		while (digit[2][digit_of_num]!='\0'){/*counts digit number of -u xxx number so we can control inputs and if user enter different digit num we can give error*/
			digit_of_num++;
		}
		

		for (i = 0; i < 100; i++){/*game itself if user enter >100 input give error*/
			right_nums=0,place_wrong_nums=0;
			input.clear();
			cin>>input;
			cont=input_check(input,digit_of_num);/*checking input if there is a wrong or esktra input*/
			if (cont==-1){/*if user enters different digit count number then call number*/
				cout << "E1" << endl;
				return 0;
			}
			if (cont==-2){
				cout << "E2" << endl;
				return 0;
			}

			for(int x=0;x<given_num.size();x++){/*compares input and program call number and prints place right and place wrong numbers*/
				for (int y = 0; y < given_num.size(); y++){
					if(x==y && given_num[x]==input[y])right_nums++;
					else if(given_num[x]==input[y])place_wrong_nums++;
				}
			}
			cout << right_nums << ' ' << place_wrong_nums<<endl;

			if(input==given_num){
				cout<<"FOUND " << i+1 <<endl;
				break;
			}
		}
	}
	else{
		cout << "E0" << endl;
	}
	if(i>=100)cout << "FAILED"<<endl;
	return 0;
}


/*create_num function creates a number that every digit is different*/
int create_num(int digit_num){
	int num=(rand()%9)+1;/*creation first digit of number for no going to be zero*/
	char numeral[]="0123456789";/*created numeral 0 to 9 for not choose again same numeral */
	numeral[num]='x';
	int line,i=1;/*line:queue of the random numeral. i:current queue of num digit*/

	while (i<digit_num){/*choosing the digits of number*/
		line=rand()%10;
		if(numeral[line]<='9' && numeral[line]>='0'){
			num*=10;
			num+=line;
			numeral[line]='x';
			i++;
		}
	}
	return num;
}


int input_check(string input ,int digit_count){/*control if in user input there is a non number digit or digit counts is different*/
	int i;
	for (i = 0; input[i]!='\0'; i++){
		if(input[i]>'9' || input[i]<'0' || input[i]==' '){
			return -2;
		}
	}
	if (digit_count!=i){
		return -1;
	}
	return 0;
	
}

