
	#include<bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	const int n = 1e6;
	
	
	
	
	int main(){
		cin.tie(0);
        ios_base::sync_with_stdio(0);
        
        
		bool prime[n + 1];
    	memset(prime, true, sizeof(prime));
 
	    for (int p = 2; p * p <= n; p++)
	    {
	        if (prime[p] == true)
	        {
	        	cout<<p<<" ";
	            for (int i = p * p; i <= n; i += p)
	                prime[i] = false;
	        }
	    }
		
        
        /*
        int t; cin>>t;
        while(t--){
        	int x,y; cin>>x>>y;
        	int con = 0;
        	for(int i=x; i<=y; i++){

			//busqueda binaria
        	}
        	cout<<con<<"\n";
        }*/
		return 0;	
	}