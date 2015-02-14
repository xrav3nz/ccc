#include <cstdio>
#include <algorithm>

int a[3];

int main(int argc, char const *argv[])
{
	
	scanf("%d %d %d", &a[0], &a[1], &a[2]);

	std::sort(a, a + 3);

	printf("%d\n", a[1]);

	return 0;
}