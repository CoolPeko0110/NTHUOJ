#include <iostream>
using namespace std;

int main(){
    int god[200005] = {}, value[200005] = {};
    int n; cin>>n;
    value[0] = 1e9+1;
    for(int i=1;i<=n;i++){
        cin>>value[i];
        if(value[i-1]>value[i]) god[i] = i-1;
        else{
            int t = i-1;
            while(value[i]>=value[god[t]]){
                t = god[t];
            }
            god[i] = god[t];
        }
        cout<<god[i]<<" ";
    }
    cout<<"\n";
    return 0;
}