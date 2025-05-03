#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int count = 0;
int popcount = 0;
vector<int> topo;

void dfs(int i, vector<vector<int>> adj, vector<pair<int, int>>& vis){
    count++;
    vis[i].first = count;
    for(int j = 0; j<adj[i].size(); j++){
        if(vis[adj[i][j]].first == 0){
            dfs(adj[i][j], adj, vis);
        }
    }
    popcount++;
    vis[i].second = popcount;
    topo.push_back(i);
}

int main(){
    vector<vector<int>> adj = {
        {1, 2},
        {4, 6},
        {5},
        {0, 1, 2, 5, 6},
        {},
        {},
        {4, 5}
    };
    vector<pair<int, int>> vis(adj.size(), {0, 0});
    for(int i = 0; i < adj.size(); i++){
        if(vis[i].first == 0){
            dfs(i, adj, vis);
        }
    }
    cout << "Topological Order: ";
    for(int i = topo.size()-1; i>=0; i--){
        cout << topo[i] << " ";
    }
    cout << endl;
    cout << "Visited Array: " << endl;
    for(int i = 0; i<vis.size(); i++){
        cout << i << " - " << vis[i].first << " | " << vis[i].second << endl;
    }
    cout << endl;
}