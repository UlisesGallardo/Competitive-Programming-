	#include<bits/stdc++.h>
	using namespace std;
	
	struct FenwickTree {
	    vector<int> bit;  
	    int n;
	
	    FenwickTree(int n) {
	        this->n = n;
	        bit.assign(n, 0);
	    }
	
	    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
	        for (size_t i = 0; i < a.size(); i++)
	            add(i, a[i]);
	    }
	
	    int sum(int r) {
	        int ret = 0;
	        for (; r >= 0; r = (r & (r + 1)) - 1)
	            ret += bit[r];
	        return ret;
	    }
	
	    int sum(int l, int r) {
	        return sum(r) - sum(l - 1);
	    }
	
	    void add(int idx, int delta) {
	        for (; idx < n; idx = idx | (idx + 1))
	            bit[idx] += delta;
	    }
	};

	int main(){
		int n, q; cin>>n>>q;
		//FenwickTree BIT(n);
		vector<int>events;
		bool visited[q+1];
		memset(visited,false, sizeof(visited));
		unordered_map<int,int>m;
		int ans = 0;
		for(int i=0; i<q; i++){
			int type; cin>>type;
			if(type == 1){
				int u; cin>>u;
				u--;
				events.push_back(u);
				ans++;
				m[u]++;
			}else if(type == 2){
				int u; cin>>u;
				u--;
				for(int j=0; j<(int)events.size(); j++){
					if(events[j] == u){
						visited[j] = true;
					}
				}
				ans-=m[u];
				m[u]=0;
			}else if(type == 3){
				int t; cin>>t;
				for(int j=0; j<t; j++){
					if(!visited[j]){
						visited[j] = true;
						ans--;
					}
				}
			}
			cout<<ans<<"\n";
			//cout<<BIT.sum(n-1)<<"\n";
		}
	}