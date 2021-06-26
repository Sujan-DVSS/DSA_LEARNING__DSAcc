#include<bits/stdc++.h>
using namespace std;

void addEdge(unordered_map<int,vector<int>>& adjList, int src, int dest){
 adjList[src].push_back(dest);   
}

void DFS_iter(unordered_map<int,vector<int>>& adjList, int node){
 stack<int> s;
   unordered_map<int,bool> visited1;
    s.push(node);
    while(!s.empty()){
     int top = s.top();
        s.pop();
        
        if(!visited1[top]){
         cout << top << " ";
            visited1[top] = true;
        }
        for(auto it = adjList[top].begin(); it != adjList[top].end(); it++){
         if(!visited1[*it]){
          s.push(*it);   
         }
        }
    }
}

void DFS_rec(unordered_map<int,vector<int>>& adjList, int node){
 static unordered_map<int,bool> visited; 
    visited[node] = true;
    cout << node << " ";
    
    for(auto it = adjList[node].begin(); it != adjList[node].end(); it++){
     if(!visited[*it]){
      DFS_rec(adjList,*it);   
     }
    }
}


int main(){
   unordered_map<int,vector<int>> adjList;
    int src, dest;
    while(1){
     cin >> src >> dest;
        if(src == -1) break;
        addEdge(adjList,src,dest);
    }
    DFS_iter(adjList,0); // DFS_rec(adjList,0);
    return 0;
}
