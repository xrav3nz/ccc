#include <iostream>
#include <string>
#include <stack>

#define OP_FLAG '#'

using namespace std;

string prefix;

bool isOp(char c){
	return c == '+' || c == '-';
}

void solve(){

	stack<char> ops;

	for(int i = 0; prefix[i]; ++i){
		if(prefix[i] == ' ')
			continue;
		if(isOp(prefix[i]))
			ops.push(prefix[i]);
		else{
			cout << prefix[i] << " ";
			while(!ops.empty() && ops.top()==OP_FLAG){
                ops.pop();
                cout << ops.top() << " ";
                ops.pop();
            }
            ops.push(OP_FLAG);
		}
	}
	cout << endl;

	return ;
}

int main(int argc, char const *argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	while(getline(cin, prefix)){
		solve();
	}
	return 0;
}