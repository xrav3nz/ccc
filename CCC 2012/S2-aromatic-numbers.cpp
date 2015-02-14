#include <cstdio>

int baseToValue(char base){
	if(base == 'I')
		return 1;
	if(base == 'V')
		return 5;
	if(base == 'X')
		return 10;
	if(base == 'L')
		return 50;
	if(base == 'C')
		return 100;
	if(base == 'D')
		return 500;
	if(base == 'M')
		return 1000;
	return 0;
}

int main(){

	//freopen("s2.in", "r", stdin);

	char input[22];

	scanf("%s", input);

	int total = 0;

	for(int i = 0; input[i]; i += 2){
		int a = input[i] - '0', r = baseToValue(input[i+1]);
		if(input[i+2]){
			if(r < baseToValue(input[i+3])){
				total -= a * r;
				continue;
			}
		}
		total += a * r;
	}

	printf("%d\n", total);

	return 0;
}