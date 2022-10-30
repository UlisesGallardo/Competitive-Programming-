
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
		}
		
		void update(ll value, int L, int R, int id, int LimitLeft, int LimitRight){
			if(LimitLeft<=L && LimitRight>=R){st[id]+=value;return;}
			if(LimitRight<L || R<LimitLeft) return;
			
			int mid = (L+R)/2;
			update(value,L, mid, 2*id, LimitLeft, LimitRight);
			update(value,mid+1, R, 2*id+1, LimitLeft, LimitRight);
		}
		
		ll query(int pos,int L, int R, int id){
			if(L==R){return st[id];}
			int med = (L+R)/2;
			ll ans = st[id];
			if(pos<=med)ans+=query(pos, L, med, 2*id);
			else ans+=query(pos, med+1, R, 2*id +1);
			return ans;
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
				ll a,b,v;cin>>a>>b>>v;
				st.update(v,1,n,1,a,b);
			}else{
				int k; cin>>k;
				cout<<st.query(k,1,n,1)<<"\n";
			}
		}
		
		return 0;
	}