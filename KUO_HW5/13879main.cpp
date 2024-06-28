#include "13879.h"
#include <vector>
#include <queue>
#include <iostream>
int startnode;

vector<int> graph::bfs(int source) const
{
    int dist[100005] = {};
    std::queue<int> line;
    int been[100005] = {};
    line.push(source);
    been[source] = 1;
    int size = 1;
    while(!line.empty()){
        int k = line.front();
        startnode = k;
        line.pop();
        for(int i = 0;i<adjacent_lists[k].size();i++){
            if(!been[adjacent_lists[k][i]]){
                been[adjacent_lists[k][i]]++;
                line.push(adjacent_lists[k][i]);
                size++;
                dist[adjacent_lists[k][i]] = dist[k]+1;
            }
        }
    }
    vector<int> ans;
    for(int i=0;i<size;i++) ans.push_back(dist[i]);
    return ans;
}

int tree::diameter() const
{
    int start = startnode;
    vector<int> ans = bfs(start);
    return ans[startnode];
}