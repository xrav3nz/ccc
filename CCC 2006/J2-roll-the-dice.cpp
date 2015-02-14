#include <cstdio>

int a, b, total;

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);

	scanf("%d %d", &a, &b);

	for(int i = 1; i <= a && i < 10; ++i){
		if(10 - i <= b)
			++total;
	}

	printf("There %s %d way%s to get the sum 10.\n", (total == 1) ? "is" : "are", total, (total == 1) ? "" : "s");
	return 0;
}