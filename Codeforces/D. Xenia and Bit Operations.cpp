
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	struct SegmentTree{
		int n;
		vector<ll>st;
		
		SegmentTree(int n){
			this->n = n;
			this->st.resize(pow(2,n)*5+10, 0);
		}
		
		void build(vector<ll>&v, int L, int R, int id, int level){
			if(L==R){st[id] = v[L];return;}
			
			int mid = (L+R)/2;
			build(v, L, mid, (2*id)  , level+1);
			build(v, mid+1,R,(2*id)+1, level+1);
			
			if(n%2==0){
				if(level%2==0) st[id] = st[2*id]^st[2*id+1];
				else  st[id] = st[2*id]|st[2*id+1];
			}else{
				if(level%2==0) st[id] = st[2*id]|st[2*id+1];
				else st[id] = st[2*id]^st[2*id+1];
			}
		}
		
		void update(int pos, int L, int R, ll value, int id, int level){
			
			if(L==R){st[id] = value;return;}
			
			int mid = (L+R)/2;
			if(pos<=mid) update(pos, L, mid,value, 2*id, level+1);
			else update(pos,mid+1,R, value, (2*id)+1, level+1);
			
			if(n%2==0){
				if(level%2==0) st[id] = st[2*id]^st[2*id+1];
				else  st[id] = st[2*id]|st[2*id+1];
			}else{
				if(level%2==0) st[id] = st[2*id]|st[2*id+1];
				else st[id] = st[2*id]^st[2*id+1];
			}
		}
		
		ll query(){
			return st[1];
		}
				
	};
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int n,m; cin>>n>>m;
		vector<ll>v(pow(2,n)+10);
		for(int i=1; i<=pow(2,n); i++){
			cin>>v[i];
		}
		
		SegmentTree st(n);
		st.build(v,1,pow(2,n),1,0);
		
		while(m--){
			ll p,b; cin>>p>>b;
			st.update(p,1,pow(2,n),b,1,0);
			cout<<st.query()<<"\n";
		}
		
		return 0;
	}