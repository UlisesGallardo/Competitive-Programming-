
	
	#include<bits/stdc++.h>
	using namespace std;
	const int N = 1000000+10;
	int dp[N] = {0};
	long long int M = 1000000000+7;
	
	
	int main(){
		dp[0] = 1;
		for(int i=1; i<=N; i++){
			dp[i] = 0;
			for(int j=1; j<=6; j++){
				if(i-j>=0)dp[i] = ((dp[i]%M) + (dp[i-j])%M)%M;
			}
		}
	
		int n; cin>>n;
		cout<<dp[n];
	}