
	#include <bits/stdc++.h>	
	#include <ext/pb_ds/assoc_container.hpp>
	#include <ext/pb_ds/tree_policy.hpp>
	
	#define INF 1000000000000000000LL
	#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
	#define FORC(cont, it) \
	  for (decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
	#define pb push_back
	#define _                                               \
	  if (argc == 2 && ((string)argv[1]) == "USE_IO_FILES") \
	    freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
	
	using namespace std;
	using namespace __gnu_pbds;
	
	typedef long long ll;
	typedef pair<int, int> ii;
	typedef pair<ll, ll> pll;
	typedef vector<int> vi;
	typedef vector<ii> vii;
	typedef vector<vi> vvi;
	typedef tree<int,        // key
	             null_type,  // value
	             less<int>, rb_tree_tag, tree_order_statistics_node_update>
	    ordered_set;
	    
	//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
	/*
	  How to use ordered_set:
	  ordered_set X;
	  X.insert(1);
	  X.erase(1);
	  X.find_by_order(1); // This gives an iterator.
	  X.order_of_key(-5); // Lower bound, 0 based position.
	*/

	
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		int t; cin>>t;
		
		while(t--){
			
		}
		
		return 0;
	}