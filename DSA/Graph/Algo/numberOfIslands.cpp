#include <bits/stdc++.h>
using namesapce std;

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == '0' or visited[i][j] == true){
            return ;
        }
        visited[i][j] = true;
        dfs(grid,visited,i+1,j); // bottom
        dfs(grid,visited,i-1,j); //  top
        dfs(grid,visited,i,j+1); // left
        dfs(grid,visited,i,j-1); //right
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(); // row size                                                   
        int col = grid[0].size(); // column size
        vector<vector<bool>> visited(row, vector<bool>(col,false));
        int num = 0;
        for(int i = 0; i < row ; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1' and visited[i][j] == false){
                    num += 1;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return num;
    }

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m; // n-row size, m - col size
  cin >> n >> m;
  vector<vector<char>> grid(n,vector<char>(m,' '));
  for(int i = 0; i < n ;i++){
    for(int j = 0; j < m ; j++){
      cin >> grid[i][j];
    }
  }
  cout << numIslands(grid) << "\n";
  return 0;
}
