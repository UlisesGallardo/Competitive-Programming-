
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		ll n, q;cin>>n>>q;
		
		vector<ll>v(n), sum(n);
		for(int i=0; i<n; i++)cin>>v[i];
	
		
		sort(v.begin(),v.end());
		
		for(int i=0; i<n; i++){
			if(i==0)sum[0] = v[0];
			else sum[i] = sum[i-1] + v[i];
		}
		
		while(q--){
			ll limit;cin>>limit;
			auto it = lower_bound(v.begin(),v.end(),limit);
			ll pos = it - v.begin();
			//cout<<it - v.begin()<<"\n";
			if(pos == 0){
				cout<<limit*n<<endl;
			}else{
				pos--;
				cout<<limit * (n-1-pos) +  sum[pos]<<endl;
			}
			
		}
		
		return 0;
	}