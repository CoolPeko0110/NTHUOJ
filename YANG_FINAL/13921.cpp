#include <iostream>
#include <set>
using namespace std;
#define iter set<int>::iterator

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin>>T;
    set<int> point;
    while(T--){
        int ans = -1;
        int command; cin>>command;
        int x; cin>>x;
        if(command == 1){
            iter r = point.find(x);
            if(r == point.end()) point.insert(x);
            else point.erase(x);
        }
        else{
            iter r = point.upper_bound(x);
            iter l = point.lower_bound(x);
            if(r==point.begin()){
                cout<<-1<<"\n";
            }
            else if(r!=point.end()){
                if(*l>x){
                    --l;
                    cout<<*r-*l<<"\n";
                }
                else {
                    cout<<*r-*l<<"\n";
                }
            }
            else cout<<-1<<"\n";
        }
    }
    return 0;
}