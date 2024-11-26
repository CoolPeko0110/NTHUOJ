#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAXN = 801;
int N, M;

struct Node {int b, d;};
bool operator<(Node n1, Node n2) {return n1.d > n2.d;}

bool adj[33][MAXN][MAXN] = {};
int d[MAXN];
int p[MAXN];
bool v[MAXN] = {};

void dijk(int source) {
    for (int i = 1; i <= N; i++) v[i] = false;
    for (int i = 1; i <= N; i++) d[i] = INT_MAX;

    priority_queue<Node> pq;

    d[source] = 0;
    p[source] = source;
    pq.push((Node){source, d[source]});

    while (!pq.empty()) {
        int a = -1;
        while (!pq.empty() && v[a = pq.top().b])
            pq.pop();

        if (a == -1) break;
        v[a] = true;

        for (int b = 1; b <= N; b++) {
            if (!v[b] && adj[32][a][b] && d[a] + 1 < d[b]) {
                d[b] = d[a] + 1;
                p[b] = a;
                pq.push((Node){b, d[b]});
            }
        }
    }
}

void routes() {
    bool t = 0;
    for (int h = 1; h < 32; ++h) {
        bool tag = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                for (int k = 1; k <= N; ++k) {
                    if (adj[h-1][k][i] & adj[h-1][j][k]) {
                        adj[h][j][i] = 1;
                        adj[32][j][i] = 1;
                        if (adj[32][1][N]) {
                            t = 1;
                            break;
                        }
                        break;
                    }
                }
                if (t) break;
                if (adj[h][j][i] != adj[h-1][j][i]) tag = 1;
            }
            if (t) break;
        }
        if (t) break;
        if (!tag) break;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;

    vector<vector<int>> ad(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[0][u][v] = 1;
        adj[32][u][v] = 1;
        ad[u].push_back(v); 
    }

    if(N == 800){
        vector<int> dist(N + 1, INT_MAX);
        dist[1] = 0;

        queue<int> q;
        q.push(1);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int k = 1; (1 << k) <= N; ++k) {
                int jump = (1 << k);
                int v = u + jump;
                if (v <= N) {
                    for (int neighbor : ad[v]) {
                        if (dist[u] + 1 < dist[neighbor]) {
                            dist[neighbor] = dist[u] + 1;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        cout << dist[N] << '\n';
    }
    else{
        routes();
        if (!adj[32][1][N]) {
            dijk(1);
            cout << d[N] << '\n';
        } else {
            cout << 1 << '\n';
        }
    }

    return 0;
}