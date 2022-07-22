
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	int main(){
		ll n; cin>>n;
		vector<pair<ll,ll>>v(n);
		for(int i=0; i<n; i++) cin>>v[i].first>>v[i].second;
		
		ll con = 0;
		bool visited[n] = {false};
		
		ll res = 0;
		while(con<n){
			if(!visited[con]){
				ll dir = v[con].second;
				ll last;
				last = v[con].first+10;
				visited[con] = true;
			
				ll pos = con;
				for(int i=con+1; i<n; i++ ){
					if(v[i].first>last && v[i].second==dir) break;
					if(v[i].second==dir){
						last = v[i].first +10;
						visited[i] = true;
						pos =i;
					}
				}				
				if(con==0) res+=last;
				else {
					res+=10;
				}
				con++;
			}else{
				con++;
			}
		}
		cout<<res<<"\n";

	}