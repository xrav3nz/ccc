#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int answer, n;
vector<int> cards(4);
string ops = "+-*/";

void readData(){
	for(int i = 0; i < 4; ++i){
		scanf("%d", &cards[i]);
	}
	return ;
}

int evaluate(int a, int b, char op){
	if(op == '+')
		return a + b;
	else if(op == '-')
		return a - b;
	else if(op == '*')
		return a * b;
	return a / b;
}

void solve(vector<int> input){
	int size = input.size();
	if(size == 1){
		if(input[0] <= 24 && input[0] > answer)
			answer = input[0];
		return ;
	}
	vector<int> permutation = input;
	do {
		for(int i = 0; i < 4; ++i){
			if(i == 3 && (permutation[1] == 0 || permutation[0] % permutation[1] != 0))
				continue;
			vector<int> newCards(size - 1);
			newCards[0] = evaluate(permutation[0], permutation[1], ops[i]);
			for(int j = 1; j < size - 1; ++j){
				newCards[j] = permutation[j + 1];
			}
			solve(newCards);
		}
	}while(next_permutation(permutation.begin(), permutation.end()));
	return ;
}

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	scanf("%d", &n);

	while(n--){
		readData();
		answer = 0;
		sort(cards.begin(), cards.end());
		solve(cards);
		printf("%d\n", answer);
	}

	return 0;
}