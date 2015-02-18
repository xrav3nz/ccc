#include <iostream>
#include <string>

using namespace std;

string sign;

bool IsLegal () {
	for (auto i : sign) 
		if (i != 'I' && i != 'O' && i != 'S' && i != 'H' && i != 'Z' && i != 'X' && i != 'N')
			return false;
	return true;
}

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> sign;

	if (IsLegal())
		cout << "YES";
	else
		cout << "NO";
	
	return 0;
}