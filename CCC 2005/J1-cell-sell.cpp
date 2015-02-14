#include <cstdio>

int day, night, weekend, a, b;

int main(){

	freopen("input.in", "r", stdin);
	// freopen("input.out", "w", stdout);

	scanf("%d %d %d", &day, &night, &weekend);

	a = (day - 100) * 25;
	if(a < 0) a = 0;
	a += night * 15 + weekend * 20;

	b = (day - 250) * 45;
	if(b < 0) b = 0;
	b += night * 35 + weekend * 25;

	printf("Plan A costs %.2f\n", 1.0 * a / 100);
	printf("Plan B costs %.2f\n", 1.0 * b / 100);
	
	if(a == b)
		printf("Plan A and B are the same price.\n");
	else
		printf("Plan %c is cheapest.\n", (a < b) ? 'A' : 'B');

	return 0;
}