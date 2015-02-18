#include <iostream>

using namespace std;

int n, a, b, antonia = 100, david = 100;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> n;

	while (n--) {
		cin >> a >> b;
		if (a > b)
			david -= a;
		else if (a < b)
			antonia -= b;
	}

	cout << antonia << endl << david << endl;
	
	return 0;
}