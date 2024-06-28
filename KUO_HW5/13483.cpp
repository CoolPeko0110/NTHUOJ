#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;

int main(){
    int N; cin>>N;
    while(N--){
        int n, k; cin>>n>>k;
        int list;
        ll prefix = 0;
        int ans = 0;
        unordered_map<ll, int> check;
        check[0]++;
        for(int i=0;i<n;i++){
            cin>>list;
            prefix += list;
            ll target = prefix-k;
            if(check.find(target)!=check.end()){
                ans += check[target];
            }
            check[prefix]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}