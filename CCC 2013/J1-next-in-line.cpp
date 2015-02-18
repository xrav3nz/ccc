#include <iostream>

using namespace std;

int a, b;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> a >> b;

	cout << b + b - a << endl;
	
	return 0;
}