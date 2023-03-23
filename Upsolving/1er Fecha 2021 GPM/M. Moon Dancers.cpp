
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	struct disjointSet{
		int N;
		vector<short int> rank;
		vector<int> parent, count;
		disjointSet(int N): N(N), rank(N),parent(N), count(N){}
		
		void makeSet(int v){
			count[v] = 1;
			parent[v] = v;
		}
		int findSet(int v){
			if(v == parent[v]) return v;
			return parent[v] = findSet(parent[v]);
		}
		void unionSet(int a, int b){
			a = findSet(a), b = findSet(b);
			if(a == b) return;
			if(rank[a] < rank[b]){
				parent[a] = b;
				count[b] += count[a];
			}else{
				parent[b] = a;
				count[a] += count[b];
				if(rank[a] == rank[b]) ++rank[a];
			}
		}	
	};


	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		
		int n; cin>>n; 

		vector<int>dancers(n),v(360,0);
		for(int i=0; i<n; i++)	{
			cin>>dancers[i];
			v[dancers[i]]=1;
		}
			
		int ans = 0;
		for(int k=1; k<=359; k++){
			int answer=0;
			
			disjointSet s(360);
			for(int i=0; i<360; i++)s.makeSet(i);
			
			bool used[360]={0};
			for(int j=0; j<n; j++){
				int pair = (dancers[j] + k)%360;
				if(v[pair] == 1)s.unionSet(dancers[j], pair);
			}
			
			for(int i=0; i<360; i++){
				int parent = s.findSet(i);
				if(!used[parent]){
					answer+=(s.count[parent]/2);
					used[parent]=true;
				}
			}
			ans=max(ans,answer);
		}
		cout<<ans;
	}