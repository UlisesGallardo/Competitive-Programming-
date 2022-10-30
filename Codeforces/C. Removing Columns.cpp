
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	string s[100+5];
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int n,m; cin>>n>>m;
		for(int i=0; i<n; i++)cin>>s[i];
		int ans = 0;
		while(true){
			if(s[0].size()==0)break;
			int i=0;
			while(i<n-1){
				if(s[i]>s[i+1])break;
				i++;
			}
			if(i==n-1)break;
			ans++;
			int j=0;
			
			while(true){
				if(s[i][j]>s[i+1][j])break;
				j++;
			}
			
			for(i=0;i<n; i++){
				s[i].erase(s[i].begin() + j);
			}
		}
		cout<<ans;
		return 0;
	}