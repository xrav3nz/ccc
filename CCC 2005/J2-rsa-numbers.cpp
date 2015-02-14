#include <cstdio>
#include <cmath>

int i, j, k, total;

bool isRSA(){
	int count = 0;
	for(int temp = 1; temp <= sqrt(k) && count <= 4; ++temp){
		if(k % temp)
			continue;
		if(k / temp == temp)
			++count;
		else
			count += 2;
	}
	return (count == 4);
}

int main(){

	freopen("input.in", "r", stdin);

	scanf("%d %d", &i, &j);

	for(k = i; k <= j; ++k){
		total += isRSA();
	}

	printf("The number of RSA numbers between %d and %d is %d\n", i, j, total);

	return 0;
}