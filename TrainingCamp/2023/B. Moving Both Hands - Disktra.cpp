
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	typedef pair<ll,int> ii;
	typedef vector<ii> vii;
	typedef vector<ll> vi;
	
	#define MAXN 200010
	#define INF 1e17
	
	vector<vector<pair<int,ll>>>adj(MAXN);
	
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		
		int n,m,x,y; cin>>n>>m;
		ll w;
		for(int i=1;  i<=n; i++) adj[i].push_back({i+n,0});
		for(int i=0; i<m; i++){
			cin>>x>>y>>w;
			adj[x].push_back({y,w});
			adj[y+n].push_back({x+n,w});
		}
		
		vi dist(MAXN,INF); dist[1] = 0;
		priority_queue<ii, vii, greater<ii>>pq;
		pq.emplace(0,1); 
		
		while(!pq.empty()){
			auto [d,u] = pq.top(); pq.pop();
				
			if(d>dist[u])continue;
			for(auto &[v,w] : adj[u]){
				if(dist[u]+w >= dist[v])continue;
				dist[v] = dist[u] + w;
				pq.emplace(dist[v],v);
			}
		}
		
		for(int i=2; i<=n; i++){
			if(dist[i]<INF || dist[i+n]<INF)cout<<min(dist[i],dist[i+n])<<" ";
			else cout<<"-1 "; 
		}
	}