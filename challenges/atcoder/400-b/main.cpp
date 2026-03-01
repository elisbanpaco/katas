/**
 * atcoder: 400-b
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long N, M;
    cin>> N >> M;

    long operacion = 0;
    double n = 1e9;

    for (long i = 0; i <= M; i++) {
        operacion = operacion + pow(N, i );
    }
    if (operacion <= n && operacion >= 0){
        cout << operacion;
    }else {
        cout << "inf";
    }

    return 0;
}
