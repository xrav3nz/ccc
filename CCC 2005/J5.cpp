#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string input;
int size, i;

bool isMonkeyLang();

bool isMonkeyLang(){
	int ana = input.find("ANA");
	int bas = input.find("BAS");
	while(ana > -1 || bas > -1){
		while(ana > -1){
			input.replace(ana, 3, "A");
			ana = input.find("ANA");
		}
		while(bas > -1){
			input.replace(bas, 3, "A");
			bas = input.find("BAS");
		}
		ana = input.find("ANA");
		bas = input.find("BAS");
	}
	return (input == "A");
}

int main(){

	freopen("input.in", "r", stdin);

	while(cin >> input && input[0] != 'X'){
		size = input.size();
		if(isMonkeyLang())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}