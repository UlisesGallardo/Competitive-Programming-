
	/*
	Get Parent
	1) 2's Complement
	2) AND it with original Number
	3) Subtract from original Number
	
	Get Next nodes that could be affected	
	1) 2's Complement
	2) AND it with original Number
	3) Add to original Number
	
	*/
	
	struct FenwickTree {
	    vector<int> bit;  // binary indexed tree
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

	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int t; cin>>t;
		while(t--){
			
		}
		
		return 0;
	}