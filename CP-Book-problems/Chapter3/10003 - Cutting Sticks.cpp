
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	const int MAXN = 55;
	int cuts[MAXN];
	int n;
	
	int memo[52][52];
	
	int dp(int l, int r){
		//cout<<l<<" "<<r<<"\n";
		if(memo[l][r]!= -1)return memo[l][r];
		if(l+1 == r) return 0;
		
		int ans = 1e9;
		for(int i=l+1; i<r; i++){
			int ans1 = dp(l,i);
			int ans2 = dp(i,r);
			ans = min(ans, ans2+ans1 + (cuts[r]-cuts[l]));
		}
		memo[l][r] = ans;
		return ans;
	}
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int l;
		while(cin>>l){
			memset(memo,-1, sizeof(memo));
			if(l==0)break;
			cin>>n;
			cuts[0] = 0;
			cuts[n+1] = l; 
			for(int i=1; i<=n; i++)cin>>cuts[i];
			cout<<"The minimum cutting is "<<dp(0, n+1)<<".\n";
		}
		
		return 0;
	}