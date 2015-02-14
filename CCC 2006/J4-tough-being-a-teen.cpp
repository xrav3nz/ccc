#include <cstdio>

#define MAX 8

int map[MAX][MAX], indegree[MAX], x, y, topoOrder[MAX], count;

void topoSort(){
	//go through n times, find a vertex each time
	for(int i = 1; i < MAX; ++i){
		//find a vertex with indegree zero
		for(int j = 1; j < MAX; ++j){
			if(indegree[j] == 0){
				--indegree[j];
				topoOrder[count++] = j;
				//decrease the indegree of nodes associate with j
				for(int k = 1; k < MAX; ++k){
					if(map[j][k] == 1){
						--indegree[k];
					}
				}
				break;	//this break would make sure the ouput is in ascending order
			}
		}
	}
	return ;
}

int main(int argc, char const *argv[])
{

	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	map[1][7] = 1;
	++indegree[7];
	map[1][4] = 1;
	++indegree[4];
	map[2][1] = 1;
	++indegree[1];
	map[3][4] = 1;
	++indegree[4];
	map[3][5] = 1;
	++indegree[5];

	while(scanf("%d %d", &x, &y) != EOF && (x || y)){
		//in case of repetition
		if(!map[x][y]){
			map[x][y] = 1;
			++indegree[y];
		}
	}

	topoSort();

	if(count != MAX - 1)
		printf("Cannot complete these tasks. Going to bed.\n");
	else
		for(int i = 0; i < MAX - 1; ++i)
			printf("%d%c", topoOrder[i], " \n"[i == MAX - 2]);

	return 0;
}