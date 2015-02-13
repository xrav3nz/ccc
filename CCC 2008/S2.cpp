#include <iostream>

using namespace std;

int r;

long long pennies(){
	long long total = 0;
	for(int i = 1; i <= r; ++i){
		for(int j = 0; j <= r; ++j){
			if(i * i + j * j <= r * r)
				++total;
			else
				break;
		}
	}
	return 1 + 4 * total;
}

int main(){

	ios_base::sync_with_stdio(false);

	freopen("input.in", "r", stdin);

	while(cin >> r && r)
		cout << pennies() << endl;

	return 0;
}