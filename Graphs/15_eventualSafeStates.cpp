#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, vector<int>& vis, vector<vector<int>> adj, vector<int>& path, vector<int>& check){
    vis[i] = 1;
    path[i] = 1;
    check[i] = 0;
    for(auto it:adj[i]){
        if(!vis[it]){
            if(dfs(it, vis, adj, path, check) == true){
                check[i] = 0;
                return true;
            }
        }
        else if(path[it]){
            check[i] = 0;
            return true;
        }
    }
    check[i] = 1;
    path[i] = 0;
    return false;
}

int main(){
    vector<vector<int>> adj = {
        {1, 2},
        {3},
        {5},
        {0},
        {5},
        {},
        {},
        {0}
    };
    vector<int> vis(adj.size(), 0);
    vector<int> path(adj.size(), 0);
    vector<int> check(adj.size(), 0);
    for(int i = 0; i<adj.size(); i++){
        if(!vis[i]) dfs(i, vis, adj, path, check);
    }
    cout << "Safe Nodes: ";
    for(int i = 0; i<adj.size(); i++){
        if(check[i]==1){
            cout << i << " ";
        }
    }
    return 0;
}