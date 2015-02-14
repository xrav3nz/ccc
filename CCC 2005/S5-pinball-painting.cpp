#include <algorithm>
#include <list>
#include <cstdio>

#define MAX 100010

using std::sort;
using std::lower_bound;
using std::list;

int T, n, total;

list<int> scores;
list<int>::iterator rank;

bool descOrder(const int a, const int b){
	return a > b;
}

int main(){

	freopen("input.in", "r", stdin);
	// freopen("output.out", "w", stdout);

	scanf("%d", &T);

	for(int i = 0; i < T; ++i){
		scanf("%d", &n);
		// scores.push_back(n);
		// sort(scores.begin(), scores.end(), descOrder);
		rank = lower_bound(scores.begin(), scores.end(), n, descOrder);
		scores.insert(rank, n);
		// for(auto i : scores){
		// 	printf("%d\n", i);
		// }
		// printf("\n");
		// printf("\n%d\n", (rank - scores.begin() + 1));
		total += (std::distance(scores.begin(), rank));
	}

	printf("%.2f\n", total * 1.0 / T);
	// printf("%d\n", total);

	return 0;
}