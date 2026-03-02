/**
 * atcoder: 400-c
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <cmath>

#define ll long long
using namespace std;


/*
    ll googNumber(ll a,ll  b, ll N) {
        ll X = pow(2LL, a) * pow(b, 2LL);

        for ( ll i=1LL; i<=N; i++){
            if (X == i) {
                return X;
            }
        }

        return -1LL;
    }
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N;
    if (cin >> N) {
        ll impares = sqrtl(N / 2); // si N=20 entnoces count_odd_a = 4 porque sqrt(20/2) = sqrt(10) = 3.1622776601683795

        //  y^2 <= N
        ll pares = sqrtl(N) /2;
        // y <= raiz(N)/2
        ll result = pares + impares;

        cout << result;
    }

    return 0;
}
