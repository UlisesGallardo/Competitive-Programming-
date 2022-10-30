#include <bits/stdc++.h>
	using namespace std;
	#define INF 999999999999999;
 
	typedef long long int ll;
	
	struct SegmentTree{
		vector<ll>st;
		int n;
		
		SegmentTree(int n) {
			this->n = n;
	        this->st.resize(n*5, 0);
	    }
		
		void build(vector<ll> &v, int L, int R, int id){
			//cout<<L<<" "<<R<<"\n";
			if(L == R){st[id] = v[L];return;} //id of the node of st
			int mid = (L+R)/2;					//next range
			build(v,L, mid, 2*id); 				//left child
			build(v,mid+1,R,(2*id)+1);			//right child
			st[id] = min(st[2*id],st[(2*id)+1]);
		}
		
		ll query(int L, int R, int id, int LimitLeft, int LimitRight){
			if(LimitLeft<=L && LimitRight>=R)return st[id];
			if(LimitRight<L || R<LimitLeft) return INF;
			
			int mid = (L+R)/2;
			ll ansL = query(L, mid, 2*id, LimitLeft, LimitRight);
			ll ansR = query(mid+1, R, 2*id+1, LimitLeft, LimitRight);
			
			return min(ansL, ansR);
		}
		
	};
	
	
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int n, q; cin>>n>>q;
		vector<ll>v(n+10);
		for(int i=1; i<=n; i++)cin>>v[i];
		
		SegmentTree st(n);
		st.build(v,1,n,1);
		
		while(q--){
			int l,r; cin>>l>>r;
			cout<<st.query(1,n,1,l,r)<<"\n";
		}
		
		return 0;
	}
	