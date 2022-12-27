
	#include <bits/stdc++.h>
	#include <ext/pb_ds/assoc_container.hpp>
	#include <ext/pb_ds/trie_policy.hpp>
	 
	using namespace std;
	using namespace __gnu_pbds;

	typedef long long int ll;
	
	typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
	
	//more : https://codeforces.com/blog/entry/11080
	//comparator less<int> , ascending order
	//comparator greater<int> , descending order
	
	/* 
	
		To use order-statistics on a multiset: Use:: tree<int, null_type, less_equal, rb_tree_tag, tree_order_statistics_node_update> s;

        find_by_order and order_of_key work the same as for a set.

    	However for searching, lower_bound and upper_bound work oppositely. Also, let's say you want to erase x, use s.erase(s.upper_bound(x)) (as upper bound is considered as lower bound)
	*/
	
	
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		pbds A;
		
		int m; cin>>m;
		vector<ll>v(1e5+10, 0);
		int i=0;
		
		while(m--){
			int type; cin>>type;
			i++;
			if(type == 1){
				ll x; cin>>x;
				v[i] = x;
				A.insert(x);
			}else if(type==2){
				int index; cin>>index;
				A.erase(A.upper_bound(v[index]));
			}else if(type==3){
				int index; ll x; cin>>index>>x;
				A.erase(A.upper_bound(v[index]));
				v[index]+=x;
				A.insert(v[index]);
			}else if(type == 4){
				int index; cin>>index;
				cout<<A.order_of_key(v[index])<<endl; 
			}
		}
		
		return 0;
	}