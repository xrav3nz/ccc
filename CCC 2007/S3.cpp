#include <cstdio>

#define MAX_N 10000

int friends[MAX_N], n, x, y, count, temp;

void readData(){

	scanf("%d", &n);

	while(n--){
		scanf("%d %d", &x, &y);
		friends[x] = y;
	}

	return ;
}

bool solve(int a, int b){
	temp = a;
	count = 0;
	while(friends[temp] && friends[temp] != a){
		if(friends[temp] == b){
			return true;
		}
		temp = friends[temp];
		++count;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	readData();

	while(scanf("%d %d", &x, &y) != EOF && x && y){
		if(solve(x, y))
			printf("Yes %d\n", count);
		else if(solve(y, x))
			printf("Yes %d\n", count);
		else
			printf("No\n");
	}

	return 0;
}