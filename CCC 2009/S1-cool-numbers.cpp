// CCC 2009 S1 - Cool Numbers

// Iterating in the range a to b and find their respective square root and cube root
// would be too low, considering 1 <= a, b <= 1e8

// However, the range of actual values of square root and cube root is managable,
// considering, 1 <= sqrt(a), sqrt(b) <= 1e4, 1 <= cbrt(a), cbrt(b) <= ~464

#include <iostream>
#include <cmath>

using namespace std;

int a, b, sqrt_end, cbrt_end, answer;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> a >> b;

	sqrt_end = sqrt(b);
	cbrt_end = cbrt(b);

	for(int i = sqrt(a); i <= sqrt_end; ++i){
		for(int j = cbrt(a); j <= cbrt_end; ++j){
			if(i * i == j * j * j)
				++answer;

			// the cube root is already greater than the square root
			// no longer nessecary to continue
			if(j * j * j > i * i)
				break;
		}
	}

	cout << answer << endl;
	
	return 0;
}