#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

int create_num(int digit_num);

int main(int num,char *digit[]){

	if(!strcmp(digit[1],"-r")){
		srand(time(NULL));
		int digit_of_num=atoi(digit[2]);
		int num=create_num(digit_of_num);
		string str_num=to_string(num);
		cout <<endl<< str_num<<endl;
		
		string input;
		int right_nums,place_wrong_nums;
		for (int i = 0; i < 100; i++){
			right_nums=0,place_wrong_nums=0;
			input.clear();
			cin>>input;
			for(int x=0;x<str_num.size();x++){
				for (int y = 0; y < str_num.size(); y++){
					if(x==y && str_num[x]==input[y])right_nums++;
					else if(str_num[x]==input[y])place_wrong_nums++;
				}
			}
			cout << "right nums:" << right_nums<<" place wrong nums: "<<place_wrong_nums<<endl;
			if(input==str_num){
				cout<<"congrats"<<endl;
				break;
			}	
		}		
	}
	else if(!strcmp(digit[1],"-u")){
		string given_num(digit[2]);
		string input;
		int right_nums,place_wrong_nums;
		for (int i = 0; i < 100; i++){
			right_nums=0,place_wrong_nums=0;
			input.clear();
			cin>>input;
			for(int x=0;x<given_num.size();x++){
				for (int y = 0; y < given_num.size(); y++){
					if(x==y && given_num[x]==input[y])right_nums++;
					else if(given_num[x]==input[y])place_wrong_nums++;
				}
			}
			cout << "right nums:" << right_nums<<" place wrong nums: "<<place_wrong_nums<<endl;
			if(input==given_num){
				cout<<"congrats"<<endl;
				break;
			}	
		}
	}
	else{

	}
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

