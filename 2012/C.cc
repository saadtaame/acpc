#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main( void ) {
    int T;
    cin >> T;

    while( T-- ) {
        string s, t;
        cin >> s >> t;

        vector<int> cntS(26, 0), cntT(26, 0);
        for(int i = 0; i < (int)t.size(); i++)
            cntT[ t[i] - 'a' ] += 1;

        for(int i = 0; i < (int)t.size(); i++)
            cntS[ s[i] - 'a' ] += 1;

        if(cntS == cntT) {
            puts("YES");
            continue;
        }

        for(int i = (int)t.size(); i < (int)s.size(); i++) {
            if(cntS == cntT) {
                break;
            }
            cntS[ s[i - (int)t.size()] - 'a' ] -= 1;
            cntS[ s[i] - 'a' ] += 1;
        }

        if(cntS == cntT) {
            puts("YES");
            continue;
        }

        puts("NO");
    }
    return 0;
}
