#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 2000

int n, id, treat, max, lastVisit;
unsigned long int distance[MAX_N + 1][MAX_N + 1], lastDist;
std::vector< std::vector<int> > sortedDistance;

struct Location
{
	int x, y;
} neighbours[MAX_N + 1];

void readData();
void initData();
unsigned long int calcDistance(const Location &a, const Location &b);
bool cmpDist(int a, int b);
void solve();
void findNext();

int main(int argc, char const *argv[])
{

	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	readData();

	initData();

	solve();

	printf("%d\n", max);

	return 0;
}

void readData(){

	scanf("%d", &n);

	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &neighbours[i].x, &neighbours[i].y);
	}

	return ;
}

void initData(){

	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= i; ++j){
			distance[i][j] = distance[j][i] = calcDistance(neighbours[i], neighbours[j]);
		}
	}

	// for(int i = 0; i <= n; ++i){
	// 	for(int j = 0; j <= n; ++j){
	// 		printf("%6lu", distance[i][j]);
	// 	}
	// 	printf("\n");
	// }

	sortedDistance.assign(n + 1, std::vector<int>(0, 0));

	for(int i = 1; i <= n; ++i){
		sortedDistance[0].push_back(i);
	}
	id = 0;
	std::sort(sortedDistance[0].begin(), sortedDistance[0].end(), cmpDist);

	for(id = 1; id <= n; ++id){
		for(int j = 1; j <= n; ++j){
			if(id != j) sortedDistance[id].push_back(j);
		}
		std::sort(sortedDistance[id].begin(), sortedDistance[id].end(), cmpDist);
	}

	// for(int i = 0; i <= n; ++i){
	// 	for(auto j : sortedDistance[i]){
	// 		printf("%6d", j);
	// 	}
	// 	printf("\n");
	// }

	return ;
}

bool cmpDist(int a, int b){
	return distance[id][a] > distance[id][b];
}

unsigned long int calcDistance(const Location &a, const Location &b){
	int 
		dx = a.x - b.x,
		dy = a.y - b.y;
	unsigned long int d = (unsigned long int) (dx * dx + dy * dy);
	return d;
}

void solve(){
	for(int i = 0; i < n; ++i){

		treat = 0;
		lastVisit = sortedDistance[0][i];
		lastDist = distance[0][ lastVisit ];

		printf("(%d, %d) -> (%d, %d)", neighbours[0].x, neighbours[0].y, neighbours[lastVisit].x, neighbours[lastVisit].y);
		printf(" - yes\n");

		while(lastVisit != -1){
			++treat;
			findNext();
		}

		if(treat > max) 
			max = treat;
		printf("\n");

	}

	return ;
}

void findNext(){
	int total = sortedDistance[lastVisit].size();
	for(int i = 0; i < total; ++i){
		if(distance[lastVisit][ sortedDistance[lastVisit][i] ] < lastDist){
			printf("(%d, %d) -> (%d, %d)", neighbours[lastVisit].x, neighbours[lastVisit].y, neighbours[sortedDistance[lastVisit][i]].x, neighbours[sortedDistance[lastVisit][i]].y);
			printf(" - yes\n");
			lastDist = distance[lastVisit][ sortedDistance[lastVisit][i] ];
			lastVisit = sortedDistance[lastVisit][i];
			return ;
		}
	}
	lastVisit = -1;
	return ;
}