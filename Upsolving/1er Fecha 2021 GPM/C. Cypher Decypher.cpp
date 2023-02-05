
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;

	const int n = 1e6+10;
	
	vector<int> primeSieve(int n){
		vector<bool>is(n+1,true);
		vector<int>primes = {2};
		is[0]=is[1]=false;
		
		for(int i=4; i<=n; i+=2)is[i] = false;
			
		for(int i=3; i<=n; i+=2){
			if(is[i]){
				primes.push_back(i);
				if((ll)i*i <=n){
					for(int j=i*i; j<=n; j+=2*i){
						is[j] = false;
					}
				}
			}
		}
		return primes;
	}
	
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		
		vector<int>primes = primeSieve(n);
		int t; cin>>t;
		
		while(t--){
			int i,j;cin>>i>>j;
			int it1 = lower_bound(primes.begin(),primes.end(),i) - primes.begin();
			int it2 = lower_bound(primes.begin(),primes.end(),j) - primes.begin();
			if(it2 > 0 && primes[it2]>j)it2--;
			cout<<(it2-it1)+1<<"\n";
		}
	}