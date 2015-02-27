#include <iostream>
#include <stack>

using namespace std;

stack<int> sum;
int input, k, answer;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	// #ifndef ONLINE_JUDGE
	// freopen("input.in", "r", stdin);
	// #endif

	cin >> k;

	while (k--) {
		cin >> input;
		if (input == 0) {
			if (!sum.empty())
				sum.pop();
		} else
			sum.push(input);
	}

	while (!sum.empty()) {
		answer += sum.top();
		sum.pop();
	}

	cout << answer << endl;
	
	return 0;
}