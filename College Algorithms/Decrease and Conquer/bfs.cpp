#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int count = 0;

void bfs(int i, vector<vector<int>>& adj, vector<int>& vis){
    queue<int> q;
    q.push(i);
    count++;
    vis[i] = count;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int j = 0; j<adj[p].size(); j++){
            if(vis[adj[p][j]] == 0){
                q.push(adj[p][j]);
                count++;
                vis[adj[p][j]] = count;
            }
        }
    }
}

int main(){
    vector<vector<int>> adj = {
        {1, 2}, // 0
        {0, 3, 4, 6}, // 1
        {0, 5}, // 2
        {1}, // 3
        {1}, // 4
        {2}, // 5
        {1}
    };
    vector<int> vis(7, 0);
    for(int i = 0; i<7; i++){
        if(vis[i] == 0){
            bfs(i, adj, vis);
        }
    }
    cout << "Order of DFS" << endl;
    for(int i = 0; i<7; i++){
        cout << "Vertex " << i << " visisted at order " << vis[i] << endl;
    }
}