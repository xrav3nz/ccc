#include <iostream>
#include <set>

using namespace std;

set<int> d;
int n, di;

int main(){

	ios_base::sync_with_stdio(false);

	cin >> n;

	while(n--){
		cin >> di;
		d.insert(di);
	}

	cout << d.size() << endl;

	return 0;
}