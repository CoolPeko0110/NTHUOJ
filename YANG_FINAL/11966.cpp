#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    /*ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); */   
    int T; cin >> T;
    getchar();
    char c;
    for(int i=1;i<=T;i++){
        stack<char> par;
        string str;
        c = getchar();
        while(c!='\n'&&c!=EOF){
            str += c;
            c = getchar();
        }
        int flag = 1;
        for(auto r:str){
            if(!par.empty()){
                if(r=='}' && par.top()=='{') par.pop();
                else if(r==']' && par.top()=='[') par.pop();
                else if(r==')' && par.top()=='(') par.pop();
                else if(r=='>' && par.top()=='<') par.pop();
                else if(r!='}' && r!=']' && r!=')' && r!='>') par.push(r);
                else{
                    flag = 0;
                    break;
                }
            }
            else if(r!='}' && r!=']' && r!=')' && r!='>') par.push(r);
            else{
                flag = 0;
                break;
            }
        }
        if(par.empty()&& flag) cout<<"Case "<<i<<": Yes\n";
        else cout<<"Case "<<i<<": No\n";
    }
    return 0;
}