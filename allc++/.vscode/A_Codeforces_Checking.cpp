#include<iostream>
using namespace std;

bool check(char c){
    string s = "codeforces";
    for (int i = 0; i < s.size(); i++)
    {
        if (c==s[i])
        {
            return true;
            break;
        }
        
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    
    while (t--)
    {
        char c;
        cin>>c;
        if(check(c)){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    
    
}
return 0;
}