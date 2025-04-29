#include<iostream>
#include<vector>
using namespace std;

int count = 0;

void dfs(int i, vector<vector<int>>& adj, vector<int>& vis){
    count++;
    vis[i] = count;
    for(int j = 0; j<adj[i].size(); j++){
        if(vis[adj[i][j]] == 0){
            dfs(adj[i][j], adj, vis);
        }
    }
}

int main(){
    vector<vector<int>> adj = {
        {1, 2}, // 0
        {0, 3, 4}, // 1
        {0, 5}, // 2
        {1}, // 3
        {1}, // 4
        {2}, // 5
    };
    vector<int> vis(6, 0);
    for(int i = 0; i<6; i++){
        if(vis[i] == 0){
            dfs(i, adj, vis);
        }
    }
    cout << "Order of DFS" << endl;
    for(int i = 0; i<6; i++){
        cout << "Vertex " << i << " visisted at order " << vis[i] << endl;
    }
}