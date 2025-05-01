#include <bits/stdc++.h>
using namespace std;

void modify(vector<vector<int>>& adj){
    queue<pair<int, int>> q;
    for(int i = 0; i<adj.size(); i++){
        for(int j = 0; j<adj[0].size(); j++){
            if(adj[i][j] == 0){
                q.push({i, j});
            }
            else{
                adj[i][j] = -1;
            }
        }
    }
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, -1};
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        for(int i = 0; i<4; i++){
            int nr = p.first + dx[i];
            int nc = p.second + dy[i];
            if(nc>=0 && nr>=0 && nr<adj.size() && nc<adj[0].size() && adj[nr][nc]==-1){
                adj[nr][nc] = adj[p.first][p.second]+1;
                q.push({nr, nc});
            }
        }
    }
}

int main(){
    vector<vector<int>> adj = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };
    cout << "Original matrix: " << endl;
    for(int i = 0; i<adj.size(); i++){
        for(int j = 0; j<adj.size(); j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    modify(adj);
    cout << "Distance matrix: " << endl;
    for(int i = 0; i<adj.size(); i++){
        for(int j = 0; j<adj.size(); j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}