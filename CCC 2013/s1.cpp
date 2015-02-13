#include <cstdio>

int main(){

	int n, count = 0;

	scanf("%d", &n);

	//for(int a = 1; a <= 90; ++a){
		for(int b = 1; b < n; ++b){
			for(int c = 1; c < b; ++c){
				for(int d = 1; d < c; ++d){
					count++;
				}
			}
		}
	//}

	printf("%d\n", count);

	return 0;
}