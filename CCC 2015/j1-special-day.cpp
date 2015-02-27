#include <iostream>

using namespace std;

int month, day;

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    cin >> month >> day;

    if (month < 2)
        cout << "Before";
    else if (month > 2)
        cout << "After";
    else {
        if (day < 18)
            cout << "Before";
        else if (day > 18)
            cout << "After";
        else
            cout << "Special";
    }
    cout << "\n";
    
    return 0;
}