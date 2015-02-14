#include <cstdio>

int maze[26][26], r, c, k, a, b;

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);

	scanf("%d %d %d", &r, &c, &k);

	while(k--){
		scanf("%d %d", &a, &b);
		maze[a][b] = -1;
	}

	for(int i = 1; i <= r; ++i){
		if(maze[i][1] == -1)
			break;
		maze[i][1] = 1;
	}

	for(int j = 1; j <= c; ++j){
		if(maze[1][j] == -1)
			break;
		maze[1][j] = 1;
	}

	for(int i = 2; i <= r; ++i){
		for(int j = 2; j <= c; ++j){
			if(maze[i][j] == -1)
				break;
			if(maze[i - 1][j] != -1 && maze[i][j - 1] != -1)
				maze[i][j] = maze[i - 1][j] + maze[i][j - 1];
			else if(maze[i - 1][j] != -1 && maze[i][j - 1] == -1)
				maze[i][j] = maze[i - 1][j];
			else if(maze[i][j - 1] != -1 && maze[i - 1][j] == -1)
				maze[i][j] = maze[i][j - 1];
			else
				break;
		}
	}

	printf("%d\n", maze[r][c]);

	return 0;
}