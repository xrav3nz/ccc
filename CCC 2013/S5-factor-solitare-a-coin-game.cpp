#include <cstdio>
#include <cmath>

int n, cost, a, b;

void findAB(){

	for(int i = 2; i <= sqrt(n); ++i){
		if(n % i == 0){
			a = i;
			b = n / i;
			return ;
		}
	}
	a = n;
	b = 1;
	return ;
}

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);

	scanf("%d", &n);

	while(n > 1){
		findAB();
		cost += a - 1;
		n -= b;
	}

	printf("%d\n", cost);
	
	return 0;
}