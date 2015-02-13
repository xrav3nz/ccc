#include <cstdio>
#include <vector>

using namespace std;

#define WIN 3
#define TIE 1

typedef vector<int> vi;
typedef vector< vi > vii;

int t, g, a, b, sa, sb, answer;
vi scores(5);
vii played(5, vi(5));

bool hiScore(vi nScores){
	int tScore = nScores[t];
	for(int i = 1; i < 5; ++i){
		if(i == t)
			 continue;
		if(tScore <= nScores[i])
			return false;
	}
	return true;
}

void dfs(int games, vi nScores){
	
	for(int i = 1; i < 4 && games < 6; ++i){
		for(int j = i + 1; j < 5; ++j){
			if(!played[i][j]){
				played[i][j] = 1;

				nScores[i] += WIN;
				dfs(games + 1, nScores);
				nScores[i] -= WIN;

				nScores[j] += WIN;
				dfs(games + 1, nScores);
				nScores[j] -= WIN;

				nScores[i] += TIE;
				nScores[j] += TIE;
				dfs(games + 1, nScores);
				nScores[i] -= TIE;
				nScores[j] -= TIE;

				played[i][j] = 0;
				return ;
			}
		}
	}

	if(hiScore(nScores))
		++answer;

	return ;
}

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);

	scanf("%d %d", &t, &g);

	for(int i = 0; i < g; ++i){
		scanf("%d %d %d %d", &a, &b, &sa, &sb);
		played[a][b] = played[b][a] = 1;
		if(sa > sb)
			scores[a] += WIN;
		else if(sa == sb)
			scores[a] += TIE, scores[b] += TIE;
		else
			scores[b] += WIN;
	}

	dfs(g, scores);

	printf("%d\n", answer);

	return 0;
}