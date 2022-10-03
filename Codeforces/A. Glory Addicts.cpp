
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	ll solve(vector<ll>a, vector<ll>b){
		int p1=0,p2=0;
		int u=a.size(),v=b.size(); 

		ll res=0;
		res+=a[u-1];
		a.pop_back();

		vector<int>types;
		types.push_back(0);
		
		int turno = 1;
		while(p1<a.size()){
			//cout<<p1<<"\n";
			if(p2<b.size() && turno%2 == 1){
				if(types[types.size()-1]==0)res+=(2*b[p2]);
				else res+=b[p2];
				types.push_back(1);
				p2++;
			}else{
				if(types[types.size()-1]==1)res+=(2*a[p1]);
				else res+=a[p1];
				types.push_back(0);
				p1++;
			}
			turno++;
		}
				
		while(p2<b.size()){
			if(types[types.size()-1]==0)res+=2*b[p2];
			else res+=b[p2];
			types.push_back(1);
			p2++;
		}
		cout<<res<<"\n";
	}
	
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int t; cin>>t;
		while(t--){
			int n; cin>>n;
			vector<int>t(n);
			vector<ll>a,b;
			for(int i=0; i<n; i++){
				cin>>t[i];
			}
			for(int i=0; i<n; i++){
				ll x; cin>>x;
				if(t[i]==0)a.push_back(x);
				else b.push_back(x);
			}
			sort(a.begin(),a.end(), greater<ll>());
			sort(b.begin(),b.end(), greater<ll>());
			int u=a.size(),v=b.size(); 
			
			ll res=0;
			if(u==v){
				if(a[u-1]>b[v-1]) solve(b,a);
				else solve(a,b);
			}else if(u>v){
				solve(a,b);
			}else{
				solve(b,a);
			}
		}
		
		return 0;
	}