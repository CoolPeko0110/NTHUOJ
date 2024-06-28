#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    stack<ll> idx;
    stack<ll> height;
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        ll max = -1;
        for(int i=0;i<n;i++){
            ll h; cin>>h;
            if(!i){
                idx.push(0);
                height.push(h);
            }
            else{
                if(h>=height.top()){
                    idx.push(i);
                    height.push(h);
                }
                else{
                    int id;
                    while(!height.empty()&&height.top()>h){
                        ll area = height.top()*(i-idx.top());
                        max = area>max?area:max;
                        height.pop();
                        id = idx.top();
                        idx.pop();
                    }
                    idx.push(id);
                    height.push(h);
                }
            }
        }
        while(!height.empty()){
            ll area = height.top()*(n-idx.top());
            max = area>max?area:max;
            height.pop();
            idx.pop();
        }
        cout<<max<<endl;
    }
    return 0;
}