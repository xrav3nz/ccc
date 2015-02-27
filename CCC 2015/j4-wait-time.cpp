#include <iostream>
#include <vector>

using namespace std;

const int TOTAL_FRIENDS = 100 + 1;

vector<int> wait_time(TOTAL_FRIENDS, -1), is_waiting(TOTAL_FRIENDS, -1);
int m, n, increment;
char action[2];

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    cin >> m;

    for (int i = 0; i < m; ++i) {
        cin >> action >> n;
        if (action[0] == 'W') {
            increment = n;
        } else if (increment > 1) {
            increment = 0;
        } else {
            increment = 1;
        }
        for (int i = 1; i < TOTAL_FRIENDS; ++i) {
            if (is_waiting[i] > -1) {
                is_waiting[i] += increment;
            }
        }
        if (action[0] == 'S') {
            wait_time[n] += (wait_time[n] == -1) + is_waiting[n];
            is_waiting[n] = -1;
        }else if (action[0] == 'R') {
            is_waiting[n] = 0;
            if (wait_time[n] == -1) {
                wait_time[n] = 0;
            }
        } 
    }

    for (int i = 1; i < TOTAL_FRIENDS; ++i) {
        if (wait_time[i] > -1) {
            cout << i << ' ';
            if (is_waiting[i] > -1) {
                cout << -1 << '\n';
            } else {
                cout << wait_time[i] << '\n';
            }
        }
    }
    
    return 0;
}