#include <iostream>
#include <string>

using namespace std;

string areaCode, localNumber;
int areaCodeLen, localNumberLen;

bool valid(){
	if(areaCodeLen != 3 || localNumberLen != 7)
		return false;
	if(areaCode == "416" || areaCode == "647" || areaCode == "437")
		return true;
	return false;
}

int main(){

	cin >> areaCode >> localNumber;
	areaCodeLen = areaCode.size();
	localNumberLen = localNumber.size();

	if(!valid())
		cout << "invalid" << endl;
	else if(areaCode == "416")
		cout << "valuable" << endl;
	else
		cout << "valueless" << endl;

}