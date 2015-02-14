#include <cstdio>
#include <iostream>
#include <climits>

using namespace std;

#define MAX 5000

int visited[MAX + 1], nCities, tRoutes, kStores, a, b, c, d;
long long dist[MAX + 1], routes[MAX + 1][MAX + 1];

void dijsktra(){
	int source = 0, minDistance, mark;
	for(int i = 0; i <= nCities; ++i)
		dist[i] = routes[i][source];

	dist[source] = 0;

	for(int i = 0; i < nCities; ++i){
		minDistance = INT_MAX;
		for(int j = 0; j <= nCities; ++j){
			if(!visited[j] && minDistance > dist[j]){
				minDistance = dist[j];
				mark = j;
			}
		}
		if(minDistance == INT_MAX)
			break;
		visited[mark] = 1;
		for(int j = 0; j < nCities; ++j)
			if(!visited[j] && dist[j] > dist[mark] + routes[mark][j])
				dist[j] = dist[mark] + routes[mark][j];
	}

	if(dist[d] != INT_MAX)
		cout << dist[d] << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);

	freopen("input.in", "r", stdin);

	cin >> nCities >> tRoutes;

	for(int i = 0; i <= nCities; ++i)
		for(int j = 0; j <= nCities; ++j)
			routes[i][j] = INT_MAX;

	for(int i = 0; i < tRoutes; ++i){
		cin >> a >> b >> c;
		routes[a][b] = routes[b][a] = c;
	}

	cin >> kStores;

	for(int i = 0; i < kStores; ++i){
		cin >> a >> c;
		routes[0][a] = routes[a][0] = c;
	}

	cin >> d;

	dijsktra();

	return 0;
}