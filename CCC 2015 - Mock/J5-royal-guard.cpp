#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Location
{
	int x, y;
	void read(){
		scanf("%d %d", &x, &y);
		return ;
	}
} building, preLocation, curLocation;

vector<Location> orderByX, orderByY;
vector<Location>::iterator low, high;
int n, m;
long long answer, dist;

bool cmp_orderByX(const Location &a, const Location &b){
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

bool cmp_orderByY(const Location &a, const Location &b){
	if(a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);

	scanf("%d", &n);

	for(int i = 0; i < n; ++i){
		building.read();
		orderByY.push_back(building);
		orderByX.push_back(building);
	}

	sort(orderByX.begin(), orderByX.end(), cmp_orderByX);
	sort(orderByY.begin(), orderByY.end(), cmp_orderByY);

	scanf("%d", &m);

	curLocation.read();

	for(int i = 1; i < m; ++i){
		preLocation = curLocation;
		curLocation.read();
		if(preLocation.x == curLocation.x){
			low = lower_bound(orderByX.begin(), orderByX.end(), preLocation, cmp_orderByX);
			high = lower_bound(orderByX.begin(), orderByX.end(), curLocation, cmp_orderByX);
		}else{
			low = lower_bound(orderByY.begin(), orderByY.end(), preLocation, cmp_orderByY);
			high = lower_bound(orderByY.begin(), orderByY.end(), curLocation, cmp_orderByY);
		}
		building = curLocation;
		if(low > high){
			swap(low, high);
			building = preLocation;
		}
		if(high == low && ((high->x == curLocation.x && high->y == curLocation.y) || (low->x == preLocation.x && low->y == preLocation.y)))
			++answer;
		else if(high->x == building.x && high->y == building.y)
			++answer;
		dist = (long long) (high - low);
		answer += dist;
	}

	cout << answer << endl;
	
	return 0;
}