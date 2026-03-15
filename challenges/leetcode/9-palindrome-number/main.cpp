/**
 * leetcode: 9-palindrome-number
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
using namespace std;

int invertirNumero(int x) {
    int inverso = 0;
    while (x > 0) {
        int d = x % 10;          // 1. Extraer último dígito
        inverso = (inverso * 10) + d; // 2. Construir el nuevo número
        x = x / 10;              // 3. Eliminar el último dígito
    }
    return inverso;
}

int contarDijitos (int x){
    if (x==0){ return 1;}
    x = abs(x);
    int cont=0;
    while (x>0){
        x= x/10;
        cont++;
    }
    return cont;
}
int main() {
    int x;
    cin>>x;
    x = abs(x);
    bool isPalimdromo= false;

    int invertNum = invertirNumero(x);

    if (x== invertNum){
        isPalimdromo = true;
    }

    cout<<isPalimdromo;

    return 0;
}
