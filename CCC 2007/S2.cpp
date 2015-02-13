#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back

using namespace std;

int n, m;
bool found;

struct Dimension
{
	int a, b, c, volume;
	bool operator < (const Dimension &d) const {
		return a <= d.a && b <= d.b && c <= d.c;
	}
	int getVolume(){
		if(!volume)
			volume = a * b * c;
		return volume;
	}
	void order(){
		int temp;
		if(b < a)
			swap(a, b);
		if(c < a)
			swap(a, c);
		if(c < b)
			swap(b, c);
	}
} temp;

bool orderBoxes(Dimension &a, Dimension &b) {
	return a.getVolume() < b.getVolume();
}

vector<Dimension> boxes;

int main(){

	freopen("input.in", "r", stdin);

	ios_base::sync_with_stdio(false);

	cin >> n;

	while(n--){
		cin >> temp.a >> temp.b >> temp.c;
		temp.order();
		boxes.pb(temp);
	}

	sort(boxes.begin(), boxes.end(), orderBoxes);

	cin >> m;

	while(m--){
		found = false;
		cin >> temp.a >> temp.b >> temp.c;
		temp.order();
		for(auto box : boxes){
			if(temp < box){
				cout << box.getVolume() << "\n";
				found = true;
				break;
			}
		}
		if(!found)
			cout << "Item does not fit.\n"; 
	}


	return 0;
}