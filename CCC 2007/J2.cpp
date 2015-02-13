#include <string>
#include <iostream>

using namespace std;

string input;

int main(int argc, char const *argv[])
{

	freopen("input.in", "r", stdin);
	// freopen("input.out", "w", stdout);
	ios_base::sync_with_stdio(false);

	while(cin >> input){
		if(input == "CU")
			cout << "see you";
		else if(input == ":-)")
			cout << "I'm happy";
		else if(input == ":-(")
			cout << "I'm unhappy";
		else if(input == ";-)") 
			cout << "wink";
		else if(input == ":-P")
			cout << "stick out my tongue";
		else if(input == "(~.~)")
			cout << "sleepy";
		else if(input == "TA")
			cout << "totally awesome";
		else if(input == "CCC")
			cout << "Canadian Computing Competition";
		else if(input == "CUZ")
			cout << "because";
		else if(input == "TY")
			cout << "thank-you";
		else if(input == "YW")
			cout << "you're welcome";
		else if(input == "TTYL"){
			cout << "talk to you later\n";
			return 0;
		}else{
			cout << input;
		}
		cout << "\n";
	}

	return 0;
}