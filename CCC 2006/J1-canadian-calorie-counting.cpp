#include <cstdio>

int a[4][4] = {
	461, 431, 420, 0,
	100, 57, 70, 0,
	130, 160, 118, 0,
	167, 266, 75, 0
}, b, total;

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);
	for(int i = 0; i < 4; ++i){
		scanf("%d", &b);
		total += a[i][b - 1];
	}
	printf("Your total Calorie count is %d.\n", total);
	return 0;
}