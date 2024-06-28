#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;

int N[200000];
unordered_map<int, int> chart;

int main(){
    int T; cin>>T;
    while(T--){
        ios::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        chart.clear();
        int n, q; cin>>n>>q;
        for(int i=1;i<=n;i++){
            cin>>N[i];
        }
        int L = 0, R = 0;
        int ans = 0;
        while(q--){
            if(!L&&!R){
                cin>>L>>R;
                for(int j=L;j<=R;j++){
                    chart[N[j]]++;
                    if(chart[N[j]]>1) ans++;
                } 
            }
            else{
                int tempL, tempR;
                cin>>tempL>>tempR;
                for(;L<tempL;L++){
                    if(chart[N[L]]>1) ans--;
                    chart[N[L]]--;
                }
                for(++R;R<=tempR;++R){
                    chart[N[R]]++;
                    if(chart[N[R]]>1) ans++;
                }
                R--;
            }
            cout<<ans<<endl;
        }
        cout<<endl;
    }
    return 0;
}