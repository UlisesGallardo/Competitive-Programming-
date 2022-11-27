
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		ll n, k; cin>>n>>k;
		multiset<ll>ms;
		for(int i=0; i<n; i++){
			ll v; cin>>v;
			ms.insert(v);
		}
		int res = 0;
		while(ms.size()>0){
			ll x = *ms.begin();
			auto it = ms.upper_bound(k - x);
			if(it!=ms.begin())it--;
			if(*(it) + x <= k && ms.begin()!=it){
				ms.erase(it);
				ms.erase(ms.begin());
			}else{
				ms.erase(ms.begin());
			}
			res++;
		}
		cout<<res;
		return 0;
	}