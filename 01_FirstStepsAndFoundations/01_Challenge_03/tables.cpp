#include <iostream>
using namespace std;

int user_num = 0;

int tables(){
	for(int i=0;i<12;i++){
		cout << user_num << "+" << i+1 << "=" << user_num*(i+1) << std::endl;
	}
	cout << "\n";
	cout << "Enter your number: ";
	cin >> user_num;
}

int main(){
	do{
		cout << "Enter your number: ";
		cin >> user_num;
		tables();
	}
	while(user_num != -1);
}
