#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);    
    int m, n;
    cin >> m >> n;

    queue<vector<int>> cute;
    for(int i=0; i<m; i++){
        vector<int> temp;
        int num; cin >> num;
        for(int j=0;j<num;j++){
            int type; cin >> type;
            temp.emplace_back(type);
        }
        cute.push(temp);
    }

    multimap<int, int> job;
    for(int i=0;i<n;i++){
        int type; cin >> type;
        job.insert(make_pair(type, i));
    }

    multimap<int, int> ans;
    int skip = -1;
    int cur = 0;
    while(skip==-1&&!cute.empty()){
        ++cur;
        vector<int> temp = cute.front();
        cute.pop();

        for(auto r:temp){
            auto tmp = job.find(r);
            if(tmp!=job.end()){
                ans.insert(make_pair(tmp->second, cur));
                job.erase(tmp);
            }
            else{
                skip = cur;
                break;
            }
        }
    }

    auto r = ans.begin();
    for(int i=0;i<n;i++){
        if(r!=ans.end()){
            if(r->first == i){
                if(r->second != skip) cout << r->second<<"\n";
                else cout << "0\n";
                r++;
            }
            else cout << "0\n";
        }
        else cout << "0\n";
    }

    return 0;
}