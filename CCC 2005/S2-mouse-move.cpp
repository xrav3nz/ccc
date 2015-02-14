#include <cstdio>

int c, r, x, y, a, b;

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	scanf("%d %d", &c, &r);

	while(scanf("%d %d", &x, &y) != EOF && (x || y)){
		a += x;
		b += y;
		if(a < 0)
			a = 0;
		else if(a > c)
			a = c;
		if(b < 0)
			b = 0;
		else if(b > r)
			b = r;
		printf("%d %d\n", a, b);
	}
	return 0;
}