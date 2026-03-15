/**
 * leetcode: 3-longest-substring-without-repeating-characters
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <vector>
using namespace std;
int main() {
  string s;
  cin >> s;

  vector<int> ultimaPosicion(128, -1);

  int maxLength = 0;
  int izquierda = 0;
  for (int i = 0; i < s.size(); i++) {
    char letraActual = s[i];

    if (ultimaPosicion[letraActual] >= izquierda) {

      izquierda = ultimaPosicion[letraActual] + 1;
    }


    int tamañoVentana = i - izquierda + 1;


    maxLength = max(maxLength, tamañoVentana);

    ultimaPosicion[letraActual] = i;
  }

  cout << maxLength;
  return 0;
}
