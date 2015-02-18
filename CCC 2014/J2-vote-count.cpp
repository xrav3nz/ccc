#include <iostream>
#include <string>

using namespace std;

int vote_count[2], v;
string input;

int main (int argc, char const *argv[]) {
	
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	cin >> v >> input;

	for (auto i : input) 
		++vote_count[i - 'A'];

	if (vote_count[0] > vote_count[1])
		cout << "A";
	else if (vote_count[0] < vote_count[1])
		cout << "B";
	else
		cout << "Tie";

	cout << endl;
	
	return 0;
}