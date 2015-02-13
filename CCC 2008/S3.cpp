#include <cstdio>
#include <queue>
#include <cstring>

#define MAXRC 20

using std::queue;

struct Location
{
	int r, c, count;
}start, add;

int t, row, col,
	moves[4][2] = {
		0, 1,
		0, -1,
		1, 0,
		-1, 0
	};

char maze[MAXRC + 2][MAXRC + 2];
bool visited[MAXRC + 2][MAXRC + 2];
queue<Location> paths;

void clear( std::queue<Location> &q )
{
   std::queue<Location> empty;
   std::swap( q, empty );
}

void readData(){

	scanf("%d %d", &row, &col);

	for(int i = 0; i < row; ++i){
		scanf("%s", maze[i]);
	}

	return ;
}

bool isLegal(const Location &a){
	if(a.r >= 0 && a.c >= 0 && a.r < row && a.c < col && maze[a.r][a.c] != '*' && !visited[a.r][a.c]){
		visited[a.r][a.c] = true;
		return true;
	}
	return false;
}

void solve(){

	memset(visited, false, sizeof(visited));
	clear(paths);

	start.r = 0;
	start.c = 0;
	start.count = 1;

	paths.push(start);

	while(!paths.empty()){
		start = paths.front();
		paths.pop();
		if(start.r == row - 1 && start.c == col - 1){
			printf("%d\n", start.count);
			return ;
		}
		if(maze[start.r][start.c] == '+' || maze[start.r][start.c] == '-')
			for(int k = 0; k < 2; ++k){
				add.r = start.r + moves[k][0];
				add.c = start.c + moves[k][1];
				add.count = start.count + 1;
				if(isLegal(add))
					paths.push(add);
			}
		if(maze[start.r][start.c] == '+' || maze[start.r][start.c] == '|')
			for(int k = 2; k < 4; ++k){
				add.r = start.r + moves[k][0];
				add.c = start.c + moves[k][1];
				add.count = start.count + 1;
				if(isLegal(add))
					paths.push(add);
			}
	}

	printf("-1\n");

	return ;
}

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);
	// freopen("output.out", "w", stdout);

	scanf("%d", &t);

	while(t--){
		readData();

		solve();
	}

	return 0;
}