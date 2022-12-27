
	#include <bits/stdc++.h>
	using namespace std;

	typedef long long int ll;
	
	struct SegmentTree{		
		vector<ll>st;
		int n;
		
		SegmentTree(int n) {
			this->n = n;
	        this->st.resize(n*5, 0); /*Enough for a graph*/
	    }
		
		void build(vector<ll> &v, int L, int R, int id){
			if(L == R){st[id] = v[L];return;} 	//id of the node of st
			int mid = (L+R)/2;					//next range
			build(v,L, mid, 2*id); 				//left child
			build(v,mid+1,R,(2*id)+1);			//right child
			st[id] = st[2*id]+st[(2*id)+1];		//sum of ranges
		}
		
		ll query(int L, int R, ll id, int i){
			if(L == R)return st[id];
			
			int mid = (L+R)/2;
			ll ans = 0;
			if(index<=mid){
				ans = query(L, mid, 2*id, i);
			}else{
				ans = query(mid+1, R, 2*id+1, i);
			}
			
			return ans;
		}
		
		void update(int pos, ll value, int L, int R, int id){
			if(L == R){st[id] = value;return;}
			int med = (L+R)/2;
			if(pos<=med)update(pos, value, L, med, 2*id);
			else update(pos, value, med+1, R, 2*id +1);
			st[id] = st[2*id] + st[2*id +1];
		}
		
	};
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

		int n, q; cin>>n>>q;
		vector<ll>v(n+10);
		for(int i=1; i<=n; i++)cin>>v[i];
		
		SegmentTree st(1e5);
		
		int m; cin>>m;
		int i=0; 
		while(m--){
			int type;cin>>type;
			i++;
			
		}
		
		return 0;
	}