#include <cstdio>

int bcase[11] = {0, 100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000}, n, a, offer;

int main(){
	freopen("input.in", "r", stdin);

	scanf("%d", &n);

	for(int i = 0; i < n; ++i){
		scanf("%d", &a);
		bcase[a] = 0;
	}

	a = 0;
	for(int i = 0; i < 11; ++i)
		a += bcase[i];

	scanf("%d", &offer);

	printf("%s\n", (a > offer * (10 - n)) ? "no deal" : "deal");

	return 0;
}