#include <cstdio>

int house[24][24], width, height, w2, h2, step, facing,
	moves[4][2] = {
		0, 1,
		1, 0,
		0, -1,
		-1, 0
	},
	moveOrder[4][3] = {
		{3, 0, 1},
		{0, 1, 2},
		{1, 2, 3},
		{2, 3, 0}
	};
	
	/*
		[0] => right
		[1] => down
		[2] => left
		[3] => up
	*/

bool isLegal(int i, int j){
	return house[i][j] == 0;
}

void fillHouse(int i1, int j1, int i2, int j2, int fill){
	for(int i = i1; i < i2; ++i){
		for(int j = j1; j < j2; ++j){
			house[i][j] = fill;
		}
	}
}

void outputHouse(){
	for (int i = 1; i <= height; ++i)
	{
		for (int j = 1; j <= width; ++j)
		{
			printf("%d", house[i][j]);
		}
		printf("\n");
	}
}

void walkHouse(){
	int iStart = 1, jStart = 1 + w2;
	facing = 0;
	while(step--){
		for(int k = 0; k < 3; ++k){
			int temp = moveOrder[facing][k];
			if(house[iStart + moves[temp][0]][jStart + moves[temp][1]] == 0){
				facing = temp;
				house[iStart][jStart] = 2;
				iStart += moves[temp][0];
				jStart += moves[temp][1];
				// outputHouse();
				// printf("\n");
				// printf("%d %d %d\n", iStart, jStart, facing);
				break;
			}
		}
	}
	printf("%d\n%d\n", jStart, iStart);
}

int main(int argc, char const *argv[])
{
	// freopen("input.in", "r", stdin);
	// freopen("output.out", "w", stdout);

	scanf("%d %d %d %d %d", &width, &height, &w2, &h2, &step);

	fillHouse(0, 0, 22, 22, 1);
	fillHouse(1, 1 + w2, height + 1, width - w2 + 1, 0);
	fillHouse(h2 + 1, 1, height - h2 + 1, width + 1, 0);

	walkHouse();
	// outputHouse();
	return 0;
}