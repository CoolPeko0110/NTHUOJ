#include <iostream>
#include <set>
#include <queue>
using namespace std;
#define iter multiset<int>::iterator

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, T, R; cin >> N >> T >> R;
    int ans = 0;
    multiset<int> line;
    int x, y;
    queue<int> out;
    for(int i=0;i<N;i++){
        cin >> x >> y;
        if(x<=T) line.insert(x);
    }
    iter r = line.begin();
    int t;
    for(t=1;t<=T&&!line.empty();t++){
        if(!out.empty()){
            out.pop();
            ans++;
        }
        if(t>=*r){
            out.push(*r);
            r=line.erase(r);
        }
    }
    if(t<=T&&!out.empty()){
        out.pop();
        ans++;
    }
    cout << ans;
    return 0;
}