#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/* membership in set of letters */
int flag[26];

/* jump logic */
void jump(vector<char> &A, int seconds) {
    int i = 0;
    for(; i < (int)A.size(); i++)
    if(flag[ A[i] - 'A' ] == 0) {
        flag[ A[i] - 'A' ] = 1;
        break;
    }

    while(seconds--) {
        if(i < (int)A.size() - 1) {
            swap(A[i], A[i + 1]);
            i = i + 1;
        }
        else {
            int x = A[i];
            A.insert(A.begin(), x);
            A.pop_back();
            i = 0;
        }
    }
}

/* permutation p raised to the eth power */
vector<int> power(vector<int> p, int e) {
    if(e == 0) {
        vector<int> id((int)p.size());
        for(int i = 0; i < (int)p.size(); i++)
            id[i] = i;
        return id;
    }
    vector<int> q((int)p.size());
    vector<int> tmpP = power(p, e / 2);

    for(int i = 0; i < (int)p.size(); i++)
        q[i] = tmpP[ tmpP[i] ];

    if(e % 2 == 1) {
        for(int i = 0; i < (int)p.size(); i++)
            q[i] = p[ q[i] ];
    }

    return q;
}

int main( void ) {
    int testCase = 1;
    int n;

    while(cin >> n) {
        if(n == 0)
            break;

        cout << testCase++ << ". ";

        string s;
        cin >> s;

        vector<char> A;
        for(auto c: s)
            A.push_back(c);

        for(int i = 0; i < 26; i++)
            flag[i] = 0;

        /* find string after X jumps where X is string length */
        for(int i = 0; i < min((int)A.size(), n); i++)
            jump(A, i + 1);

        if(n <= (int)A.size()) {
            for(auto c: A)
                putchar(c);
            cout << endl;
            continue;
        }

        /* find permutation corresponding to above sequence of jumps */
        vector<int> perm;
        for(int i = 0; i < (int)s.size(); i++)
            for(int j = 0; j < (int)A.size(); j++)
                if(s[i] == A[j])
                    perm.push_back(j);

        /* apply permutation to itself */
        int e = n / (int)s.size();
        int rest = n % (int)s.size();

        perm = power(perm, e);

        string newS = s;
        for(int i = 0; i < (int)perm.size(); i++)
            newS[ perm[i] ] = s[i];

        A.clear();
        for(int i = 0; i < (int)newS.size(); i++)
            A.push_back(newS[i]);

        for(int i = 0; i < 26; i++)
            flag[i] = 0;

        int seconds = 1;
        while(rest--)
            jump(A, seconds++);

        for(auto c: A)
            putchar(c);
        cout << endl;
    }

    return 0;
}
