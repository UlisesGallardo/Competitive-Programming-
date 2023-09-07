#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 1e5+5;
vector<vector<pair<int,ll>>>adj(N);
vector<ll>distances(N, LLONG_MAX);
vector<pair<bool,bool>>processed(N,{false,false});
int n,m;

ll disktra(int start){
	priority_queue<pair<ll, pair<int,bool>>>pq;
	distances[start] = 0;
	pq.push({0,{start,false}});
	while(!pq.empty()){
		int a = pq.top().second.first; 
		bool used = pq.top().second.second;
		pq.pop();
		
		if(a == n && processed[a].second == true)return distances[a];
		if (processed[a].first) continue;
		processed[a].first = true;
		for (auto u : adj[a]) {
			int b = u.first;
			ll w = u.second;
			
			if(!used){
				if (distances[a] + (w/2) < distances[b]) {
					distances[b] = distances[a]+(w/2);
					pq.push({-distances[b], {b,true}});
					processed[b].second = true;
				}
		
			if (distances[a] + w < distances[b]) {
				distances[b] = distances[a]+w;
				pq.push({-distances[b], {b,false}});
				processed[b].second = false;
			}
		}
	}
	return distances[n];
}

int main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u,v; cin>>u>>v;
		long long int w; cin>>w;
		adj[u].push_back({v,w});
	}
	cout<<disktra(1);
}