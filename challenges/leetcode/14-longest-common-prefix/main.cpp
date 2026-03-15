/**
 * leetcode: 14-longest-common-prefix
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string compareStrings(string a, string b){
    int sizeString ;
    string word ="";

    if (a.size() <= b.size()){
        sizeString = a.size();
    }else{
        sizeString = b.size();
    }
    for (int i=0; i<sizeString; i++){
        if (a[i]== b[i]){
            word += a[i];
        }
        else{
            break;

        }
    }
    return word;

}

int main() {
    int n;
    cin>>n;
    vector<string> strs;
    string temp ;
    for (int i=0; i<n; i++){
        cin>>temp;
        strs.push_back(temp);
    }

    if (strs.size()==1){
        cout<<strs[0];
        return 0;
    }

    string result = strs[0];

    for (int i=0; i<strs.size()-1; i++){
        result =compareStrings(result, strs[i+1]);

        if (result== ""){
            break;
        }
    }

    cout<<result;

    return 0;
}
