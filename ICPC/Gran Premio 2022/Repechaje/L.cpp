
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	/*
	Author: Ulises Gallardo
	1.-Find the unique path between A and B
	2.-Visit any node that is connected to this path, excluding 
		the node that has the sign to go to A.
	3.-All the visited nodes will sum twice the final answer.
	*/
	void bfs_path(int start, int end, vector<vector<int>>adj, vector<bool>visited, vector<int> &parent){
		queue<int>q;
		q.push(start);
		while(!q.empty()){
			int node = q.front();
			q.pop();
			for(auto a:adj[node]){
				if(!visited[a]){
					parent[a] = node;
					q.push(a);
					visited[a] = true;
					if(a == end)return;
				}
			}
		}
	}
	
	int bfs2(vector<vector<int>>adj, vector<bool>visited,int node, vector<int> &parent){
		fill(visited.begin(),visited.end(),false);
		int ans = 0;
		int current = 1;
		queue<int>q;
		q.push(1);
		do{	
			ans++;
			visited[current] = true;
			if(parent[current]!=node)q.push(current);
			current = parent[current];
		}while(current!=node);
		
		int nodes = 0;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			for(auto a:adj[node]){
				if(!visited[a]){
					nodes++;
					visited[a] = true;
					q.push(a);
					
				}
			}
		}
		return ans + (nodes*2);
	}
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int n; cin>>n;
		int node; cin>>node;
	
		vector<vector<int>>adj(n+10);
		vector<bool>visited(n+10, false);
		vector<int>parent(n+10,0);
		fill(visited.begin(),visited.end(),false);
		
		for(int i=0; i<n-1; i++){
			int x,y; cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		if(find(adj[1].begin(),adj[1].end(),node) != adj[1].end()){
			cout<<1;
			return 0;
		}
		bfs_path(node, 1, adj, visited, parent);
		int ans = 0;
		
		ans+=(bfs2(adj, visited, node, parent));
		cout<<ans;
		return 0;
	}