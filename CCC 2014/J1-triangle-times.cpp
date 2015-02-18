#include <iostream>

using namespace std;

int a, b, c;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> a >> b >> c;

	if (a + b + c != 180)
		cout << "Error";
	else if (a == b && b == c)
		cout << "Equilateral";
	else if (a == b || b == c || a == c)
		cout << "Isosceles";
	else
		cout << "Scalene";
	
	return 0;
}