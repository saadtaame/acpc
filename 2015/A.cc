#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main( void ) {
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    vector<string> A(n);
    for(int i = 0; i < n; i++)
        cin >> A[i];

    long long ans = 0;

    for(int i = 0; i < n; i++) {
        long long rowCnt = 0;
        for(int j = 0; j < n; j++) {
            if(A[i][j] == 'C')
                rowCnt += 1;
        }
        ans += (rowCnt * (rowCnt - 1)) / 2;
    }

    for(int i = 0; i < n; i++) {
        long long colCnt = 0;
        for(int j = 0; j < n; j++) {
            if(A[j][i] == 'C')
                colCnt += 1;
        }
        ans += (colCnt * (colCnt - 1)) / 2;
    }

    cout << ans << endl;
    return 0;
}
