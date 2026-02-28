/**
 * atcoder: 447-a
 * Language: C++
 * Created with Code Forge
 */

#include <cmath>
#include <iostream>

using namespace std;

int main() {

  double N, M;

  cin >> N >> M;

  if (N == 1 && M == 1) {
    cout << "Yes" << endl;
    return 0;
  }

  N = round(N / 2);

  if (N >= M) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
