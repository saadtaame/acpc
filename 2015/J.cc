#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

string read_str( void ) {
    string s;
    do {
        cin >> s;
    } while(s == "");
    return s;
}


int main() {
    int n;
    cin >> n;

    map<string, string> dict;
    for(int i = 0; i < n; i++) {
        string s, t;
        s = read_str();
        read_str();
        t = read_str();
        dict[s] = t;
    }

    int t;
    cin >> t;
    while( t-- ) {
        int k;
        cin >> k;
        vector<string> words;
        while( k-- ) words.push_back(dict[read_str()]);
        cout << words[0];
        for(int i = 1; i < (int)words.size(); i++)
            cout << " " << words[i];
        cout << endl;
    }
    return 0;
}

