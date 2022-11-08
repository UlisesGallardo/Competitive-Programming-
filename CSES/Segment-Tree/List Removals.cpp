	/*
	
	The idea was to first see what happens every time we remove a number from the list. 
	Of course, its size is reduced and it affects the range of the remaining nodes. 
	So by updating the ranges that each parent has, it will track the new position of the numbers.
	For this, it is important to save the total number of nodes that the parent has before updating it.
	
	When a in a range lower bound is greater than upper bound, then there is no node ramining in that subtree.	
	
	*/
	#include <bits/stdc++.h>
	using namespace std;

	typedef long long int ll;
	
	struct Range{
		int l,r;
		ll value= -1;
		bool isLeaf = false;
	};
	
	struct SegmentTree{		
		vector<Range>st; //ranges
		int n;
		
		SegmentTree(int n) {
			this->n = n;
	        this->st.resize(n*5); 
	    }
		
		void build(vector<ll> &v, int L, int R, int id){
			Range aux;
			if(L == R){
				aux.value = v[L];
				aux.l = L;
				aux.r = R;
				aux.isLeaf = true;
				st[id] = aux;
				return;
			} 	
			
			int mid = (L+R)/2;					
			build(v,L, mid, 2*id); 				
			build(v,mid+1,R,(2*id)+1);
			
			aux.l = st[2*id].l;
			aux.r = st[2*id+1].r;	
			aux.value = -1;
			st[id] = aux;	//minimun and maximun of each range	
		}
		
		ll query(int pos, int L, int R, int id){
			//cout<<L<<" "<<R<<" "<<id<<"\n";
			//Range aux;
			
			if(st[id].isLeaf){
				//cout<<id<<"<-\n";
				st[id].r--;
				return st[id].value; //I'm a leaf 
			}
			
			ll ans = 0;
			
			int diff = st[2*id].r - st[2*id].l;
			if(diff>=0){
				st[2*id].l = st[id].l;
				st[2*id].r = st[2*id].l + diff;
			}
			
			diff = st[2*id+1].r - st[2*id+1].l;
			if(diff>=0){
				st[2*id+1].r = st[id].r;
				st[2*id+1].l = st[2*id+1].r - diff;
			}
			
			
			if(pos >= st[2*id].l && pos<=st[2*id].r && st[2*id].l<=st[2*id].r){
				ans = query(pos, st[2*id].l, st[2*id].r, 2*id);
			}else{
				ans = query(pos, st[2*id+1].l, st[2*id+1].r, 2*id+1);
			}
			
			st[id].r--; //Important to reduce ranges
			return ans;
		}
	};
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

		int n; cin>>n;
		vector<ll>v(n+10);
		for(int i=1; i<=n; i++)cin>>v[i];
		
		SegmentTree st(n);
		st.build(v,1,n,1);
		
		int t = n;
		while(t--){
			int index;cin>>index;
			cout<<st.query(index,1,n,1)<<" ";
			n--;
		}
		
		return 0;
	}