/**
 * atcoder: 447-b
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<char> maxMap(map<char, int> T){
    vector<char> maxChars;
    int maxCount = 0;

    for (auto it = T.begin(); it != T.end(); it++) {
        if (it->second > maxCount) {
            maxCount = it->second;
            maxChars.clear();
            maxChars.push_back(it->first);
        } else if (it->second == maxCount) {
            maxChars.push_back(it->first);
        }
    }

    return maxChars;
}

string removeAllMaxRecorrence(string S, vector<char> T){
    string result;
    for (int i=0; i<S.size(); i++){
        bool found = false;
        for (char c : T){
            if (S[i] == c){
                found = true;
                break;
            }
        }
        if (!found){
            result = result + S[i];
        }
    }
    return result;
}


int main() {
    string S;
    cin >> S;

    map<char, int> T;
    int cont =0;

    for (int i=0; i<S.size(); i++) {

        for (int j=0; j<S.size(); j++){
            if (S[i] == S[j]) {
                cont++;
            }
        }

        T[S[i]] = cont;
        cont = 0;
    }

    vector<char> maxChars = maxMap(T);

    string result = removeAllMaxRecorrence(S, maxChars);
    cout <<result;

    return 0;
}
