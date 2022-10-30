
	#include <bits/stdc++.h>
	using namespace std;

	typedef long long int ll;
	
	struct SegmentTree{
		/*Indexado en 1*/
		
		vector<ll>st;
		int n;
		
		SegmentTree(int n) {
			this->n = n;
	        this->st.resize(n*5, 0);
	    }
		
		void build(vector<ll> &v, int L, int R, int id){
			if(L == R){st[id] = v[L];return;} //id of the node of st
			int mid = (L+R)/2;					//next range
			build(v,L, mid, 2*id); 				//left child
			build(v,mid+1,R,(2*id)+1);			//right child
			st[id] = st[2*id]+st[(2*id)+1];
		}
		
		ll query(int L, int R, int id, int LimitLeft, int LimitRight){
			if(LimitLeft<=L && LimitRight>=R)return st[id];
			if(LimitRight<L || R<LimitLeft) return 0;
			
			int mid = (L+R)/2;
			ll ansL = query(L, mid, 2*id, LimitLeft, LimitRight);
			ll ansR = query(mid+1, R, 2*id+1, LimitLeft, LimitRight);
			
			return ansL + ansR;
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
		
		SegmentTree st(n);
		st.build(v,1,n,1);
		
		while(q--){
			int type; cin>>type;
			if(type == 1){
				ll k,v;cin>>k>>v;
				st.update(k,v,1,n,1);
			}else{
				int l,r; cin>>l>>r;
				cout<<st.query(1,n,1,l,r)<<"\n";
			}
		}
		
		return 0;
	}