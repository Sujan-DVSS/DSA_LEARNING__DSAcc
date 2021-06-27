#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& graph, int src, int dest){
 graph[src].push_back(dest);
}
void BFS(vector<vector<int>>& graph, int node){
	vector<int> visited(graph.size(),false);
	queue<int> Q;
	
	Q.push(node);
	while(!Q.empty()){
		int front = Q.front();
		Q.pop();
		
		if(!visited[front]){
			cout << front << " ";
			visited[front] = true;
		}
		for(auto it = graph[front].begin(); it != graph[front].end(); it++){
			if(!visited[*it]){
				Q.push(*it);
			}
		}
	}
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n;
cin >> n;
vector<vector<int>> graph(n);
int src, dest;
while(1){
	cin >> src >> dest;
	if(src == -1 or dest == -1) break;
	addEdge(graph,src,dest);
}
BFS(graph,0);
return 0;
}
