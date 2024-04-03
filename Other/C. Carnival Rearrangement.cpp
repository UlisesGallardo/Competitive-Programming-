
	#include <bits/stdc++.h>	
	using namespace std;

	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		int t; cin>>t;
		
		while(t--){
			int n; cin>>n;
			vector<int>v(n);
			for(int i=0; i<n; i++)cin>>v[i];
			int changes = 0;
			for(int i=0; i<n; i++){
				if(i<-1 >=0 && i+1<v.size()){
					if(v[i-1] != v[i] && v[i-1] == v[i+1]){
						changes++;
						v[i] = v[i-1];
					}
				}
			}
			cout<<changes<<" ";
		}
		
		return 0;
	}