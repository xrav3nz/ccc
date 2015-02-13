#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back

using namespace std;

vector<int> locations {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};

int a, b, n, temp, answer, total, dist;

void dfs(int stop){

	if(stop == total - 1){
		++answer;
		return ;
	}

	for(int i = stop + 1; i < total; ++i){
		dist = locations[i] - locations[stop];
		if(dist < a)
			continue;
		if(dist > b)
			return ;
		dfs(i);
	}
	return ;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);

	freopen("input.in", "r", stdin);

	cin >> a >> b >> n;

	while(n--){
		cin >> temp;
		locations.pb(temp);
	}

	sort(locations.begin(), locations.end());

	total = locations.size();

	dfs(0);

	cout << answer << endl;

	return 0;
}