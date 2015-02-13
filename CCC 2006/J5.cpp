#include <cstdio>

#define MAX 9

#define BLACK 2
#define WHITE 1

int board[MAX][MAX], bCount, wCount, n, r, c,
	moves[8][2] = {
		-1, -1,
		-1, 0,
		-1, 1,
		0, -1,
		0, 1,
		1, -1,
		1, 0,
		1, 1
	};
char choice[2];

void configBoard(){
	if(choice[0] == 'a'){
		bCount = wCount = 2;
		board[4][4] = WHITE;
		board[5][5] = WHITE;
		board[4][5] = BLACK;
		board[5][4] = BLACK;
	}else if(choice[0] == 'b'){
		bCount = wCount = 8;
		for(int i = 1, j = 1; i <= 8 && j <= 8; ++i, ++j){
			board[i][j] = BLACK;
			board[i][MAX - j] = WHITE;
		}
	}else{
		bCount = wCount = 16;
		for (int i = 1; i <= 8; ++i)
		{
			board[i][3] = BLACK;
			board[i][4] = BLACK;
			board[i][5] = WHITE;
			board[i][6] = WHITE;
		}
	}
}

void outputBoard(){
	printf("black: %d white: %d\n\n", bCount, wCount);
	for(int i = 1; i < MAX; ++i){
		for(int j = 1; j < MAX; ++j){
			printf("%2d", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool isLegal(int row, int col, int disc, int k){
	int oppo = disc + 1;
	if(oppo > 2) oppo -= 2;
	if(row < 1 || col < 1 || row > 8 || col > 8 || board[row][col] != oppo)
		return false;
	for(int i = row + moves[k][0], j = col + moves[k][1]; i < MAX && j < MAX && i > 0 && j > 0; i += moves[k][0], j += moves[k][1]){
		if(board[i][j] == disc) return true;
	}
	return false;
}

void addDisc(int disc){
	int count = 0;
	board[r][c] = disc;

	if(disc == WHITE) ++wCount;
	else ++bCount;

	for(int k = 0; k < 8; ++k){
		if(isLegal(r + moves[k][0], c + moves[k][1], disc, k)){
			count = 0;
			for(int i = r + moves[k][0], j = c + moves[k][1]; i < MAX && j < MAX && i > 0 && j > 0 && board[i][j] != disc; i += moves[k][0], j += moves[k][1]){
				board[i][j] = disc;
				++count;
			}
			if(disc == WHITE){
				wCount += count;
				bCount -= count;
			}else{
				bCount += count;
				wCount -= count;
			}
		}
	}
}

int main(int argc, char const *argv[])
{

	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	scanf("%s %d", choice, &n);

	configBoard();
	// outputBoard();

	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &r, &c);
		addDisc(i % 2 + 1);
		// outputBoard();
	}

	printf("%d %d\n", bCount, wCount);
	// outputBoard();
	return 0;
}