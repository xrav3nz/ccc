#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main(){

	//freopen("s2.in", "r", stdin);

	int n;
	map<string, string>pairs;
	char names[31][20];

	scanf("%d", &n);

	for(int i = 0; i < n; ++i){
		scanf("%s", names[i]);
	}


	bool valid = true;
	for(int i = 0; i < n; ++i){
		char temp[20];
		scanf("%s", temp);
		pairs[names[i]] = temp;
	}

	for(int i = 0; i < n; ++i){
		if(pairs[pairs[names[i]]] != names[i] || pairs[names[i]] == "" || pairs[names[i]] == names[i]){
			valid = false;
			break;
		}
	}

	printf("%s\n", valid ? "good" : "bad");


	return 0;
}