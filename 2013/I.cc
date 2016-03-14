#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main( void ) {
    int T;
    cin >> T;

    int n, m;

    while(T--) {
        cin >> n >> m;
        vector< vector<long long> > A(n);
        for(int i = 0; i < n; i++) {
            vector<long long> B(m);
            for(int j = 0; j < m; j++) {
                cin >> B[j];
            }
            A[i] = B;
        }

        long long answer = A[n - 1][m - 1];
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(i + 1 < n) A[i][j] += A[i + 1][j];
                if(j + 1 < m) A[i][j] += A[i][j + 1];
                if(i + 1 < n && j + 1 < m)
                    A[i][j] -= A[i + 1][j + 1];
                answer = max(answer, A[i][j]);
            }
        }

        cout << answer << endl;
    }
    return 0;
}
