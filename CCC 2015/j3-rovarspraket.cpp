#include <iostream>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

int 
    vowels[5] {'a', 'e', 'i', 'o', 'u'},
    min_difference,
    closest_vowel;
bitset<26> is_vowel;
string input;

int main (int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    #endif

    cin >> input;

    for (auto v : vowels) {
        is_vowel[v - 'a'] = true;
    }

    for (auto c : input) {
        cout << c;
        if (is_vowel[c - 'a']) {
            continue;
        }
        min_difference = 27;
        for (auto v : vowels) {
            if ( abs(c - v) < min_difference ) {
                closest_vowel = v;
                min_difference = abs(c - v);
            }
        }
        cout << (char)closest_vowel;
        while (c != 'z' && is_vowel[++c - 'a']);
        cout << c; 
    }
    cout << "\n";
    
    return 0;
}