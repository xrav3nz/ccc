#include <iostream>
#define MAX 11

using namespace std;

char input[MAX];
int father[5], mother[5], N;

bool isPossible(){

	for(int i = 0; i < 5; ++i){
		if(input[i] >= 'A' && input[i] <= 'Z' && father[i] == 0 && mother[i] == 0){
			return false;
		}else if(input[i] >= 'a' && input[i] <= 'z' && (father[i] >= 2 || mother[i] >= 2)){
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	cin >> input;

	for(int i = 0; i < 10; i += 2){
		if(input[i] >= 'A' && input[i] <= 'Z')
			++father[i / 2];
		if(input[i + 1] >= 'A' && input[i + 1] <= 'Z')
			++father[i / 2];
	}

	cin >> input;

	for(int i = 0; i < 10; i += 2){
		if(input[i] >= 'A' && input[i] <= 'Z')
			++mother[i / 2];
		if(input[i + 1] >= 'A' && input[i + 1] <= 'Z')
			++mother[i / 2];
	}

	cin >> N;

	while(N--){
		cin >> input;
		if(isPossible())
			printf("Possible baby.\n");
		else
			printf("Not their baby!\n");
	}

	return 0;
}