#include <cstdio>
#include <vector>

int n, x, y;
long long int count;
std::vector< std::vector<int> > graph;
std::vector<long long int> leadToN;

void readData(){
	scanf("%d", &n);

	graph.assign(n + 1, std::vector<int>(0, 0));
	leadToN.assign(n + 1, -1);
	leadToN[n] = 1;

	while(scanf("%d %d", &x, &y) != EOF && x && y){
		graph[x].push_back(y);
	}
}

// void BFS(){

// 	for(auto i : graph[1]){
// 		if(i == n)
// 			++count;
// 		else
// 			paths.push(i);
// 	}

// 	while(!paths.empty()){
// 		temp = paths.front();
// 		paths.pop();
// 		for(int i = 0; i < graph[temp].size(); ++i){
// 			if(graph[temp][i] == n)
// 				++count;
// 			else
// 				paths.push(graph[temp][i]);
// 		}
// 	}

// 	return ;
// }
long long int temp;

long long int findPath(int start){
	if(leadToN[start] >= 0)
		return leadToN[start];

	long long int total = 0;

	for(auto i : graph[start]){
		temp = findPath(i);
		leadToN[i] = temp;
		total += temp;
	}
	return total;
}

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	readData();

	// BFS();
	count = findPath(1);

	printf("%lld\n", count);


	return 0;
}