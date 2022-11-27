
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int t; cin>>t;
		while(t--){
			ll n,c,d; cin>>n>>c>>d;
			vector<ll>v(n), sum(n), aux(n);
			for(int i=0; i<n; i++){
				cin>>v[i]; 
				if(i==0)sum[i]=v[i];
				else sum[i]=sum[i-1]+v[i];
			}
			
			/*
			int l=0,r=n-1,m;
			while(l<=r){
				m = l + (r-l)/2;
				
				int div = d%(m+1);
				ll s = 0;
				if(div!=0)s+=sum[div-1];
				s+=(d/m)*sum[m];
				
				
				
				if(s>=c){
					l = m;
				}else{
					r = m;
				} 
			}*/
			
			int index = -1;
			for(int i=0; i<n; i++){
				int div = d%(i+1);
				ll s = 0;
				if(div!=0)s+=sum[div-1];
				s+=(d/(i+1))*sum[i];
				aux[i]=s;
				if(i>0 && aux[i]<c && aux[i-1]>=c){
					index = i-1;
					break;
				}
			}
			
			
			
			sort(v.begin(),v.end());
			if(v[n-1]>=c)cout<<"Infinity";
			//else if(d*v[n-1]>=c)cout<<0;
			else if(index==-1)cout<<"Impossible";
			else if(index == 0)cout<<index;
			else cout<<index+1;
			cout<<"\n";
		}
		
		return 0;
	}