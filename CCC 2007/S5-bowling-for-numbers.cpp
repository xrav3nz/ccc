#include <cstdio>
#include <cstring>

#define MAX_N 30000
#define MAX_K 500
#define MAX(a, b) (a)>(b)?(a):(b)

int t, n, k, w, pins[MAX_N + 1], sum[MAX_N + 1];
unsigned long int dp[MAX_K + 1][MAX_N + 1];

void readData(){

	scanf("%d %d %d", &n, &k, &w);

	memset(sum, 0, sizeof(sum));

	for(int i = 0; i < n; ++i){
		scanf("%d", &pins[i]);
	}

	for(int i = 0; i < n; ++i){
		for(int j = i; j < i + w && j < n; ++j){
			sum[i] += pins[j];
		}
	}

	// for(int i : sum){
	// 	if(!i) break;
	// 	printf("%6d", i);
	// }
	// printf("\n");

	return ;
}

void solve(){
	for(int j = 1; j < n; ++j){
		dp[0][j] = 0;
	}	

	for(int i = 1; i <= k; ++i)
		for(int j = 1; j < n; ++j)
			dp[i][j] = -1;

	for(int ball = 1; ball <= k; ++ball){
		for(int i = n - 1; i >= 0; --i){
			if(i >= n - w)
				dp[ball][i] = sum[i];
			else
				dp[ball][i] = MAX(dp[ball - 1][i + w] + sum[i], dp[ball][i + 1]);
		}
	}
}


int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	scanf("%d", &t);
	
	while(t--){
		readData();
		solve();
		printf("%lu\n", dp[k][0]);
	}

	return 0;
}