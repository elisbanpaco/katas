/**
 * atcoder: 400-a
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
using namespace std;

int main() {
    int A;
    cin>>A;

    int  result ;

    if(400%A == 0) {
        result =  400/A;
        cout << result;
        return 0;
    }else{
        cout << -1;
        return 0;
    }

    return 0;
}
