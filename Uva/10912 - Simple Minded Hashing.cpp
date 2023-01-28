
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	int ans;
	int memo[27][352][27];
	
	int dp(int length, int sum, int c){
		if(sum<0)return 0;
		if(length<0)return 0;
		if(length == 0 && sum == 0) return 1;
		if(memo[length][sum][c] != -1)return memo[length][sum][c];
		
		int res = 0;
		for(int i = c+1; i<27;i++){
			res+=dp(length-1, sum-i, i);
		}
		memo[length][sum][c] = res;
		return res;
	}
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int l,s; 
		int t=1; 
		memset(memo, -1, sizeof(memo));
		
		while(cin>>l){
			cin>>s;
			if(l==0 && s == 0)break;
			ans = 0;
			if(!(l>26 || s>351))ans = dp(l,s,0);
			cout<<"Case "<<t<<": "<<ans<<"\n";
			t++;
		}
		
		return 0;
	}