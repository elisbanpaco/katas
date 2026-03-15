/**
 * leetcode: 13-roman-to-integer
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <map>
using namespace std;
int main() {
    // numero  romanos : I, V, X, L, C, M
    // I             1
    // V             5
    // X             10
    // L             50
    // C             100
    // D             500
    // M             1000
    //
    string S;
    cin>>S;
    map<char , int> numbersRomans = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int suma=0;
    for (int i=1; i<=S.size(); i++){
        //cout<<numbersRomans[S[i]]<<"\n";

        if (numbersRomans[S[i-1]] < numbersRomans[S[i]]){
            suma += -numbersRomans[S[i-1]];
        }else{
            suma += numbersRomans[S[i-1]];
        }

        //cout<<S[i]<<suma<<"\n";

    }

    cout<<suma;

    return 0;
}
