#include <fstream>
#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::vector;

int main(){

	int T = 0;

	cin >> T;

	for(int i = 0; i < T; ++i){

		int N = 0;

		cin >> N;

		vector<int> cars(N), branch;

		for(int j = 0; j < N; ++j){
			int x = 0;
			cin >> x;
			cars[j] = x;
		}


		for(int j = 1, finish = 0; j <= N; ++j){

			if(branch.size() != 0){
				if(branch[branch.size() - 1] == j){
					branch.pop_back();
					finish = j;
					continue;
				}
			}

			for(int k = cars.size(); k >= 1; --k){

				if(cars[k - 1] == j){
					cars.pop_back();
					finish = j;
					break;
				}else{
					branch.push_back(cars[k - 1]);
					cars.pop_back();
				}

			}

			if (finish != j) 
				break;

		}


		if(cars.size() == 0 && branch.size() == 0){
			cout << "Y";
		}else{
			cout << "N";
		}

		cout << endl;

	}

	return 0;
}