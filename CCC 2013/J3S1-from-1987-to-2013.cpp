#include <iostream>
#include <cstring>

using namespace std;

int year, digits[10];

bool DistinctDigits (int n) {
	memset(digits, 0, sizeof(digits));

	while (n > 0) {
		if (digits[n % 10])
			return false;
		digits[n % 10] = true;
		n /= 10;
	}

	return true;
}

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> year;

	while(!DistinctDigits(++year));

	cout << year;
	
	return 0;
}