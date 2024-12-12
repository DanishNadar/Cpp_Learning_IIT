#include <iostream>
using namespace std;

int main(){
	int user_num;
	do{
		cout << "Enter your number: ";
		cin >> user_num;
		tables();
	}
	while(user_num != -1){
		tables();
	}
int tables(){
	for(int i=0;i<12;i++){
		cout << user_num << "+" << i+1 << "=" << user_num*(i+1) << std::endl;
	}
	cout << "\n"
	cout << "Enter your number: ";
	cin >> user_num;
}
}
