#include <cstdio>
#include <vector>
#include <climits>

#define MAX 1025

std::vector< std::vector<long int> > 
	a(MAX, std::vector<long int>(MAX, 0)),
	b(MAX, std::vector<long int>(MAX, 0)),
	sum(MAX, std::vector<long int>(MAX, 0));

int N, r1, c1, r2, c2, iNew, jNew;

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	scanf("%d", &N);

	N -= 2;

	scanf("%d %d", &r1, &c1);
	for(int i = 0; i < r1; ++i){
		for(int j = 0; j < c1; ++j){
			scanf("%ld", &a[i][j]);
		}
	}

	scanf("%d %d", &r2, &c2);
	for(int i = 0; i < r2; ++i){
		for(int j = 0; j < c2; ++j){
			scanf("%ld", &b[i][j]);
		}
	}

	for(int i = 0; i < r1; ++i){
		for(int j = 0; j < c1; ++j){
			for(int x = 0; x < r2; ++x){
				for(int y = 0; y < c2; ++y){
					iNew = i * r2 + x;
					jNew = j * c2 + y;
					sum[iNew][jNew] = a[i][j] * b[x][y];
				}
			}
		}
	}

	r1 *= r2;
	c1 *= c2;

	while(N--){
		scanf("%d %d", &r2, &c2);
		for(int i = 0; i < r2; ++i){
			for(int j = 0; j < c2; ++j){
				scanf("%ld", &b[i][j]);
			}
		}
		a = sum;

		for(int i = 0; i < r1; ++i){
			for(int j = 0; j < c1; ++j){
				for(int x = 0; x < r2; ++x){
					for(int y = 0; y < c2; ++y){
						iNew = i * r2 + x;
						jNew = j * c2 + y;
						sum[iNew][jNew] = a[i][j] * b[x][y];
					}
				}
			}
		}

		r1 *= r2;
		c1 *= c2;

	}

	long int 
		max = LONG_MIN,
		min = LONG_MAX,
		max_row = LONG_MIN,
		min_row = LONG_MAX,
		max_col = LONG_MIN,
		min_col = LONG_MAX,
		temp;
	for(int i = 0; i < r1; ++i){
		temp = 0;
		for(int j = 0; j < c1; ++j){
			temp += sum[i][j];
			if(sum[i][j] > max)
				max = sum[i][j];
			if(sum[i][j] < min)
				min = sum[i][j];
		}
		if(temp > max_row)
			max_row = temp;
		if(temp < min_row)
			min_row = temp;
	}

	for(int j = 0; j < c1; ++j){
		temp = 0;
		for(int i = 0; i < r1; ++i){
			temp += sum[i][j];
		}
		if(temp > max_col)
			max_col = temp;
		if(temp < min_col)
			min_col = temp;
	}

	printf("%ld\n%ld\n%ld\n%ld\n%ld\n%ld\n", max, min, max_row, min_row, max_col, min_col);

	return 0;
}