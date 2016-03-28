#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int N = 1000010;

int main( void ) {

    vector<int> isPrime(N, 1);
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i < N; i++)
        if(isPrime[i])
            for(int j = i * 2; j < N; j += i)
                isPrime[j] = 0;


    vector<int> primeSum(N, 0);
    for(int i = 1; i < N; i++)
        primeSum[i] = primeSum[i - 1] + isPrime[i];

    vector<int> good(N, 0);
    for(int i = 1; i * i < N; i++)
        for(int j = 1; j * j < N; j++) {
            int s = i * i + j * j;
            if(s < N && isPrime[s])
                good[s] = 1;
        }

    for(int i = 1; i < N; i++)
        good[i] += good[i - 1];

    int L, U;
    while(cin >> L >> U) {
        if(L == -1 && U == -1)
            break;

        int countPrimes = (U >= 0 ? primeSum[U] : 0) - (L > 0 ? primeSum[L - 1] : 0);
        int countSquares = (U >= 0 ? good[U] : 0) - (L > 0 ? good[L - 1] : 0);

        cout << L << " " << U << " " << countPrimes << " " << countSquares << endl;
    }
    return 0;
}
