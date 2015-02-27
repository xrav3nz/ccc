#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int num_j, num_a, num, ans;
bool used[1000001];
string size;
char j[1000002];

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	// #ifndef ONLINE_JUDGE
	// freopen("input.in", "r", stdin);
	// #endif

	cin >> num_j >> num_a;

	memset(j, ' ', sizeof(j));

	for (int i = 1; i <= num_j; ++i) {
		cin >> size;
		j[i] = size[0];
	}

	for (int i = 0; i < num_a; ++i) {
		cin >> size >> num;
		if (!used[num] && (j[num] == size[0] || j[num] == 'L' || (j[num] == 'M'  && size[0] != 'L'))) {
			++ans;
			used[num] = true;
		}
	}

	cout << ans;

	return 0;
}