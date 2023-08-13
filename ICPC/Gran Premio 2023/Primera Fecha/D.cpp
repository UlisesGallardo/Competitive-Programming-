
	#include <bits/stdc++.h>	
	using namespace std;
	typedef long long int ll;
	
	int main(){
		int n,m; 
		scanf("%d %d",&n,&m);
		vector<ll>v(n);
		for(int i=0; i<n; i++) scanf("%lld",&v[i]);
		sort(v.begin(),v.end());
		
		while(m--){
			int type; scanf("%d",&type);
			if(type == 1){
				ll k; scanf("%lld",&k);
				int pos = lower_bound(v.begin(),v.end(),k) - v.begin();
				if(v[pos] != k){
					if(k > v[v.size()-1])v.push_back(k);
					else{
						int new_pos = upper_bound(v.begin(),v.end(),k) - v.begin();
						v[new_pos] = k;
					}	
				}
			}else{
				ll a,b; scanf("%lld %lld",&a,&b);
				int l,r; 
				l = lower_bound(v.begin(),v.end(),a) - v.begin();
				r = upper_bound(v.begin(),v.end(),b) - v.begin();
				printf("%d\n",r-l);
			}
		}
		
		return 0;
	}