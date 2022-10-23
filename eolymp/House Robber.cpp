
		#include<bits/stdc++.h>
		using namespace std;
		typedef long long int ll;
		int n; 
		const int N = 1000000+100;
		ll v[N], memo[N];
		bool visited[N];
		
		ll dp(int pos){
			if(pos>=n)return 0;
			if(visited[pos])return memo[pos];
			visited[pos] = true;
			memo[pos] = max(v[pos] + dp(pos+2), dp(pos+1));
			return memo[pos];
		}
		
		int main(){
				cin>>n;		
				for(int i=0;i<n; i++) cin>>v[i];
				cout<<dp(0);
		}