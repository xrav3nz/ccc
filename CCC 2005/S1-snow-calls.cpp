#include <cstdio>

char charToN[27] = "22233344455566677778889999", input[41];
int N;

int main(int argc, char const *argv[])
{
	// freopen("input.in", "r", stdin);
	// freopen("output.out", "w", stdout);

	scanf("%d", &N);

	while(N--){
		scanf("%s", input);
		for(int i = 0, count = 0; input[i] && count < 12; ++i){
			if(count == 3 || count == 7){
				printf("-");
				++count;
			}
			if(input[i] >= '0' && input[i] <= '9'){
				printf("%c", input[i]);
				++count;
			}else if(input[i] >= 'A' && input[i] <= 'Z'){
				printf("%c", charToN[input[i] - 'A']);
				++count;
			}
		}
		printf("\n");
	}
	return 0;
}