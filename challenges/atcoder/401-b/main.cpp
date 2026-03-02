/**
 * atcoder: 401-b
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
using namespace std;


enum Action { LOGIN, LOGOUT, PRIVATE, PUBLIC };

Action strToAction(const string& s) {
    if (s == "login") return LOGIN;
    if (s == "logout") return LOGOUT;
    if (s == "private") return PRIVATE;
    return PUBLIC;
}


int main() {
    int N;
    cin>>N;
    string S;

    bool authenticated = false;

    int contFails = 0;

    for (int i = 0; i < N; i++) {

        cin>> S;
/*
if (S== "login"){
     authenticated = true;
 }
 else if (S== "logout") {
     authenticated = false;
 }

 else if (S== "private") {
     if (authenticated== false) {
         contFails++;
     }
 }
 else {
     ;
 }
 */

        switch (strToAction(S)) {
            case Action::LOGIN:
                authenticated = true;
                break;
            case Action::LOGOUT:
                authenticated = false;
                break;
            case Action::PRIVATE:
                if (authenticated== false) {
                    contFails++;
                }
                break;
            default:
                break;
        }
    }

    cout << contFails;

    return 0;
}
