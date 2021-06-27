#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& graph, int src, int dest){
graph[src].push_back(dest);
}

void allPaths(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& path, int s){
 static vector<bool> visited(graph.size(),false);
  path.push_back(s);
  visited[s] = true;
  
  if(s == graph.size()-1) res.push_back(path);
  else{
  for(auto it = graph[s].begin(); it != graph[s].end(); it++){
   if(!visited[*it]){
    allPaths(graph,res,path,*it); 
   }
  }
  }
  path.pop_back();
  visited[s] = false;
}





int main(){
ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> graph(n);
  int src,dest;
  while(1){
   cin >> src >> dest;
    if(src == -1 or dest == -1) break;
    addEdge(graph,src,dest);
  }
  vector<vector<int>> res;
  vector<int> path;
  allPaths(graph,res,path,0);
  for(auto vec: res){
   for(int i = 0; i < vec.size(); i++){
    cout << vec[i];
     if(i == vec.size()-1) continue;
     cout << "-> ";
   }
    cout << "\n";
  }
  return 0; 
}
