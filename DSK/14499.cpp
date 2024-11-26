#include <iostream>
#include <vector>
using namespace std;

const int maxn = 500001;
int lca[maxn][12], n, q;
short dep[maxn];
vector<int> v[maxn];

void dfs(int x, int par){
    for(auto i : v[x])
        if(i != par){
            dep[i] = dep[x] + 1;
            lca[i][0] = x;
            dfs(i, x);
        }
}

void build_lca(){
    for(int j = 1; j < 12; ++j)
        for(int i = 1; i <= n; ++i){
            lca[i][j] = lca[lca[i][j-1]][j-1];
        }
}

int qry(int x, int y, int k){
    int a = x, b = y;
    if(dep[x] > dep[y]) swap(x, y);
    for(int dis = dep[y] - dep[x], c = 0; dis; ++c, dis = dis >> 1) if(dis & 1) y = lca[y][c];
    int LCA;
    if(x == y) LCA = x;
    else{
        for(int i = 11; i >= 0; --i){
            if(lca[x][i] != lca[y][i]){
                x = lca[x][i];
                y = lca[y][i];
            }
        }
        LCA = lca[x][0];
    }
    int dist = dep[a] + dep[b] - (dep[LCA]<<1);
    int distL = dep[a] - dep[LCA];
    int distN = dep[b] - dep[LCA];
    if(k > dist) return -1;
    if(k == dist) return b;
    int ret;
    if(k > distL){
        ret = distN - (k - distL);
        for (int i = 0; ret > 0 && b != 0; ++i, ret >>= 1) {
            if(ret & 1) b = lca[b][i];
        }
        return b;  
    }else{
        ret = k;
        for (int i = 0; ret > 0 && a != 0; ++i, ret >>= 1) {
            if(ret & 1) a = lca[a][i];
        }
        return a; 
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> q;
    int x, y, k;
    for(int i = 1; i < n; ++i){
        cin >> x >> y;
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    lca[1][0] = 1;
    dfs(1, 0);
    build_lca();
    while(q--){
        cin >> x >> y >> k;
		if(!k) cout << x << '\n';
        else cout << qry(x, y, k) << '\n';
    }
    return 0;
}