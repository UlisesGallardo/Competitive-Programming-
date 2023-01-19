
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	#define MAXN 1010
	vector<vector<int>>adj(MAXN);
	bool visited[MAXN];
	int winning [MAXN];
	int tiempo [1010];
	
	void bfs_define_time(){
		queue<int>q;
		q.push(1);
		visited[1] = true;
		tiempo[1] = 0;
		while(!q.empty()){
			int u = q.front();
			q.pop(); 
			for(auto v:adj[u]){
				if(!visited[v]){
					visited[v] = true;
					tiempo[v] = tiempo[u] + 1;
					q.push(v);
				}
			}
		}
	}
	
	void dfs_best_choice(int u){
		winning[u] = tiempo[u]%2; //0 (Par) Nikolay, 1 (Impar) Vladimir
		vector<int>who_wins;
		for(auto v:adj[u]){
			if(tiempo[v] == tiempo[u]+1){
				dfs_best_choice(v);
				if(winning[v] == !(tiempo[u]%2))winning[u] = !(tiempo[u]%2);
				 //Si hay al menos un camino que el contrincante pude tomar, entonces perderá.
			}
		}
	}
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		
		int n,m; cin>>n>>m;
		
		memset(winning, 0, sizeof(winning));
		memset(visited, 0, sizeof(visited));
		memset(tiempo, 0, sizeof(tiempo));
		
		for(int i=0; i<m; i++){
			int x,y; cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		bfs_define_time();
		dfs_best_choice(1);
		(winning[1]) ? cout<<"Vladimir" : cout<<"Nikolay";
		return 0;
	}