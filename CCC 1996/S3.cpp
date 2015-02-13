#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int t, n, k;

int main(){

	freopen("input.in", "r", stdin);

	ios_base::sync_with_stdio(false);

	cin >> t;

	while(t--){
		cin >> n >> k;
		string output(n, '0');
		for(int i = 0; i < k; ++i)
			output[i] = '1';

		cout << "The bit patterns are\n";
		do{
			cout << output << "\n";
		}while(prev_permutation(output.begin(), output.end()));
		if(t) cout << "\n";
	}

	return 0;
}