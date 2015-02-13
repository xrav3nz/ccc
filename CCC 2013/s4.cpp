#include <cstdio>
#include <queue>
#include <string.h>

int n, order[8], visit[17000000] = {0};

struct State
{
	int s[8][8], top[8];
};

void outputSeq(State a){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(a.s[i][j]) printf("%d", a.s[i][j]);
		}
		printf(" (%d) ", a.top[i]);
		if(i != n - 1) printf("\t/\t");
		else printf("\n");
	}
	return ;
}

void clearZero(State &temp){
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			temp.s[i][j] = 0;
		}
	}
	return ;
}

int power(int base, int expo){
	int result = 1;
	while(expo--){
		result*=base;
	}
	return result;
}

int toDec(State a){
	int temp = 0, result = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(a.s[i][j] != 0){
				temp += i * power(10, n - a.s[i][j]);
			}
		}
	}
	int expo = n - 1;
	while(temp){
		result += temp%10 * power(n, expo);
		temp /= 10; 
		--expo;
	}
	return result;
}

void BFS(){
	memset(visit, 0, sizeof(visit));
	std::queue<State> q;
	State temp, add, rightSeq;
	clearZero(temp);
	for(int i = 0; i < n; ++i){
		temp.s[i][0] = order[i];
		temp.top[i] = 0;
	}
	q.push(temp);

	clearZero(rightSeq);

	for(int i = 0; i < n; ++i){
		rightSeq.s[i][0] = i + 1;
	}

	int rightDec = toDec(rightSeq);

	while(!q.empty()){
		temp = q.front();
		q.pop();
		int nDec = toDec(temp);
		if(nDec == rightDec){
			printf("%d\n", visit[nDec]);
			return ;
		}
		// printf("temp:\n");
		for(int i = 0; i < n; ++i){
			if(i - 1 >= 0){
				add = temp;
				if(add.top[i-1] == -1 || add.s[i][add.top[i]] < add.s[i-1][add.top[i-1]]){
					int move = add.s[i][add.top[i]];
					add.s[i][add.top[i]] = 0;
					--add.top[i];
					++add.top[i-1];
					add.s[i-1][add.top[i-1]] = move;
					int addDec = toDec(add);
					if(!visit[addDec]){
						visit[addDec] = visit[nDec] + 1;
						q.push(add);
						// outputSeq(add);
						// printf("%d\n", addDec);
					}
				}
			}
			if(i < n - 1){
				add = temp;
				if(add.top[i+1] == -1 || add.s[i][add.top[i]] < add.s[i+1][add.top[i+1]]){
					int move = add.s[i][add.top[i]];
					add.s[i][add.top[i]] = 0;
					--add.top[i];
					++add.top[i+1];
					add.s[i+1][add.top[i+1]] = move;
					int addDec = toDec(add);
					if(!visit[addDec]){
						visit[addDec] = visit[nDec] + 1;
						q.push(add);
						// outputSeq(add);
						// printf("%d\n", addDec);
					}
				}
			}
		}
		// printf("\n");
	}

	printf("IMPOSSIBLE\n");

	return ;
}

int main(){

	// freopen("s4.in", "r", stdin);

	while(scanf("%d", &n) != EOF && n){
		for(int i = 0; i < n; ++i){
			scanf("%d", &order[i]);
		}
		BFS();
	}

	return 0;
}