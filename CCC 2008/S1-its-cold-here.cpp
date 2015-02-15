// CCC 2008 S1 - It's Cold Here!

// sorting, STL helps a lot ;D

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<string, int> > city_list;
string city;
int temperature;

bool CompareCities (pair<string, int> &city_a, pair<string, int> &city_b) {
	return city_a.second < city_b.second;
}

int main (int argc, char const *argv[]) {

	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	#endif

	while (cin >> city >> temperature)
		city_list.push_back(make_pair(city, temperature));

	sort (city_list.begin(), city_list.end(), CompareCities);

	cout << city_list[0].first << endl;
	
	return 0;
}