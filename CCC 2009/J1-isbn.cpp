// CCC 2009 J1 - ISBN

// simple math.

// the total sum is the 1-3-sum of first 10 given,
// and the 1-3-sum of the three integers input

#include <iostream>

using namespace std;

char first_ten[11] = "9780921418";
int a, b, c, sum;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> a >> b >> c;

	for (int i = 0; first_ten[i]; ++i) {
		sum += (first_ten[i] - '0') * ((i % 2 == 0) ? 1 : 3);
	}

	sum += a + b * 3 + c;

	cout << "The 1-3-sum is " << sum << endl;

	
	return 0;
}