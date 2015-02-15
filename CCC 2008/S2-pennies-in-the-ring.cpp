// CCC 2008 S2 - Pennies in the Ring

// a circle can be divided into four equivalent parts along 
// the x-axis and y-axis, PLUS the origion piece

// count how may coins lies within or on the circle in one parts,
// multiply by four and add one, and we get our answer

// use pythagorean theorem to determine whether or not the coin
// lies within or on the point, that is its distance from the origin
// is less or equal to the radius

#include <iostream>

using namespace std;

int r, total

int pennies(){
	total = 0;
	for(int i = 1; i <= r; ++i){
		for(int j = 0; j <= r; ++j){
			if(i * i + j * j <= r * r)
				++total;
			else
				break;
		}
	}
	return 1 + 4 * total;
}

int main(){

	ios_base::sync_with_stdio(false);

	freopen("input.in", "r", stdin);

	while(cin >> r && r)
		cout << pennies() << endl;

	return 0;
}