
	#include <bits/stdc++.h>
	using namespace std;
	#define INF 999999999999999;

	typedef long long int ll;
	
	struct SegmentTree{
		vector<pair<ll,int>>st;
		int n;
		
		SegmentTree(int n) {
			this->n = n;
	        this->st.resize(n*5, make_pair(-1, -1));
	    }
		
		void build(vector<ll> &v, int L, int R, int id){
			if(L == R){st[id] = {v[L],L};return;} //id of the node of st
			int mid = (L+R)/2;					//next range
			build(v,L, mid, 2*id); 				//left child
			build(v,mid+1,R,(2*id)+1);			//right child
			
			if(st[2*id].first>=st[2*id+1].first)st[id] =  st[2*id];
			else st[id] = st[(2*id)+1];
		}
		
		pair<ll,int> query(ll value, int L, int R, int id){
			//cout<<L<<" "<<R<<"\n";
			if(L == R){
				if(st[id].first-value>=0)return st[id];
				else return {-1,2e5+10};
			}
			
			int mid = (L+R)/2;
			pair<ll,int> childL = st[2*id];
			pair<ll,int> childR = st[2*id+1];
			ll a = childL.first - value;	//Left is always lower, always first
			ll b = childR.first - value;
			//cout<<childL.first<<" "<<childR.first<<"\n";
			if(a>=0){
				return query(value, L, mid, 2*id);
			}else if(b>=0){
				return query(value, mid+1, R, 2*id+1);
			}
			
			return {-1,2e5+10}; 
		}
		
		void update(int pos, ll value, int L, int R, int id){
			if(L == R){st[id] = {value,L};return;}
			int med = (L+R)/2;
			if(pos<=med)update(pos, value, L, med, 2*id);
			else update(pos, value, med+1, R, 2*id +1);
			
			if(st[2*id].first>=st[2*id+1].first)st[id] =  st[2*id];
			else st[id] = st[(2*id)+1];
		}
		
	};
	
	
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int n, m; cin>>n>>m;
		vector<ll>v(n+10);
		for(int i=1; i<=n; i++)cin>>v[i];
		
		SegmentTree st(n);
		st.build(v,1,n,1);
		
		for(int i=0; i<m; i++){
			ll h; cin>>h;
			pair<ll,int>res = st.query(h,1,n,1);
			if(res.first==-1){
				cout<<0<<" ";
			}else{
				cout<<res.second<<" ";
				st.update(res.second, res.first-h,1,n,1);
			}
		}
	
		return 0;
	}