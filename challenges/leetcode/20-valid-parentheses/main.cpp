/**
 * leetcode: 20-valid-parentheses
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    // string s = "()[]{}";
    string s = "[({])}";
    bool found = true;
    int large = s.size();
    // string s;
    // cin >> s;
    if (large == 0){
        cout<<found<<endl;
        return 0;
    }
    if (large % 2 != 0)
    {
        found = false;
        cout<<found<<endl;
        return 0;
    }

    // for (int i=0; i<large; i++){
    //     for (int j=0; j<large; j++){

    //     }
    // }

    map<char, char> parentesis = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
        {')', '('},
        {']', '['},
        {'}', '{'},
    };

    int pivot = (large / 2) - 1;
   
    int i = 0;
    cout<<"Hola"<<endl;
    

    while (!(s[0] == '0' && s[large - 1] == '0') )
    {
        cout<<"entro al while"<<endl;
        if (pivot == large-1){
            i=0;
            pivot=0;
            continue; 
        }
        if (s[pivot] == '0'){
            pivot++;
            // cout<<"xd"<<endl;
            
            continue; // esto hace que 
        }
        if(pivot + (i*-1) < 0 || pivot + (i*-1) >= s.size()) {
                found = false;
                cout << found << endl;
                return 0;
            }
        // hacia la derecha
        if (parentesis[s[pivot]] == ')' || parentesis[s[pivot]] == ']' || parentesis[s[pivot]] == '}')
        {   
            i++;
            // cout<<"paso por la derecha"<<pivot<<s<<endl;
            if(pivot + i < 0 || pivot + i >= s.size()) {
                found = false;
                cout << found << endl;
                return 0;
            }

            
            if ((parentesis[s[pivot]]  != s[pivot + i]) && (pivot + i == large) )
            {
                found = false;
                cout << found << endl;
                return 0;
            }
            if ((parentesis[s[pivot]] == s[pivot + i])&& (i%2 == 0)){
                found = false;
                cout << found << endl;
                return 0;
            }
            if (parentesis[s[pivot]] == s[pivot + i]){
                s[pivot] = '0';
                s[pivot + i] = '0'; 
                pivot++; 
                i=0;
            }
            

            // cout<<"paso por la derecha salio"<<pivot<<s<<endl;
  
        }
        // hacia la izquierda
        else
        {   
            i++;
            // cout<<"paso por la izquierda"<<pivot<<s<<i<<s[pivot + (i*-1)]<<endl;
            if (pivot + (i*-1) < 0 || pivot + (i*-1) >= s.size()) {
                found = false;
                cout << found << endl;
                return 0;
            }
            if ((parentesis[s[pivot]]  != s[pivot +(i*-1)]) && (pivot +(i*-1) == -1) )
            {
                found = false;
                cout << found << endl;
                return 0;
            }
            if ((parentesis[s[pivot]] == s[pivot + (i*-1)])&& (i%2 == 0)){
                found = false;
                cout << found << endl;
                return 0;
            }
            if (parentesis[s[pivot]]  == s[pivot + (i*-1)]){
                s[pivot] = '0';
                s[pivot + (i*-1)] = '0';  
                pivot--;
                i=0;
            }
            
            cout<<"paso por la izquierda salio"<<pivot<<s<<endl;
   
            

        }
        
    }
    cout << found << endl;
    // cout<<parentesis['[']<<endl;



    return 0;
}
