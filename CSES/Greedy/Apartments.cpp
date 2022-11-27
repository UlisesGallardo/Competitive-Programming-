
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		ll n,m,k; cin>>n>>m>>k;
		vector<ll>a(n);
		multiset<ll>b;
		for(int i=0; i<n; i++)cin>>a[i];
		for(int i=0; i<m; i++){
			int x; cin>>x;
			b.insert(x);
		}
		sort(a.begin(), a.end());
		int ans=0;
		for(int i=0; i<n; i++){
			if(b.size()==0)break;
			auto it = b.upper_bound(a[i]-k-1); 
			
			if(it!=b.end() && a[i] -k <= *it && a[i]+k>=*it  ){
				b.erase(it);
				ans++;
			}
			
		}
		cout<<ans;
		return 0;
	}