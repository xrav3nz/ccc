#include <iostream>

using namespace std;

int n_pie, k_people, ways[251][251][251];

int HowManyWays (int k, int n, int last) {

    if (k == 1 || n == k) {
        return 1;
    } else if (ways[k][n][last] == 0) {
        for (int i = last; i * k <= n; ++i) {
            ways[k][n][last] += HowManyWays(k - 1, n - i, i);
        }
    }
    return ways[k][n][last];
}

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    cin >> n_pie >> k_people;

    cout << HowManyWays(k_people, n_pie, 1) << endl;
    
    return 0;
}