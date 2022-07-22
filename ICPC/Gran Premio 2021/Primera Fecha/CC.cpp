
	#include <bits/stdc++.h>
	using namespace std;

	vector<int>pp;
	void sieve(int n){
		bool prime[n + 1];
		memset(prime, true, sizeof(prime));
	
		for (int p = 2; p * p <= n; p++){
			if (prime[p] == true){
				pp.push_back(p);
				for (int i = p * p; i <= n; i += p)
					prime[i] = false;
			}
		}
	
		for (int p = 2; p <= n; p++)
			if (prime[p])
				pp.push_back(p);
	}
	
	int binarySearch(int l, int r, int x)
	{
		int m;
	    while (l <= r) {
	         m = l + (r - l) / 2;
	        if (pp[m] == x) return m+1;
	        if (pp[m] < x) l = m + 1;
	        else r = m - 1;
	    }
	    return m;
	}

	int main(){
		int n = 1000000 +1;
		sieve(n);
		 int t; cin>>t;
        while(t--){
        	int x,y; cin>>x>>y;
        	int pos = binarySearch(0,pp.size()-1,x);
        	int pos1 = binarySearch(0,pp.size()-1,y);
        	if(pp[pos-1]==x)pos--;
			cout<<pos1-pos<<"\n";
     }
		return 0;
	}
