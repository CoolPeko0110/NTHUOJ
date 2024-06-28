#include "13879.h"
#include "13879main.cpp"

#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> edges(n - 1);
    for (vector<pair<int, int>>::iterator itr = edges.begin(); itr != edges.end(); itr++)
    {
        int &a = itr->first, &b = itr->second;
        cin >> a >> b;
    }
    tree t(n, edges);
    vector<int> d = t.bfs(0);
    for (auto itr = d.begin(); itr != d.end(); itr++)
        cout << *itr << ' ';
    cout << '\n'
         << t.diameter() << '\n';
    return 0;
}
