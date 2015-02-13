#include <iostream>

using namespace std;

int year, month, day, n;

bool isLegal(){
	if(2007 - year > 18)
		return true;
	if(2007 - year < 18)
		return false;
	if(month < 2)
		return true;
	if(month == 2 && day <= 27)
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);

	ios_base::sync_with_stdio(false);

	cin >> n;

	while(n--){
		cin >> year >> month >> day;
		if(isLegal())
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}