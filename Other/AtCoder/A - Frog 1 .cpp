
	#include <iostream>	
	#include <vector>
	#include <cstring>

	using namespace std;
	
	int n;
	vector<int>h;
	
	int memo[100010];
	
	int dp(int pos){
		if(memo[pos]!=-1)return memo[pos];
		if(pos == n-1)return 0;
		if(pos >= n)return 1e5;
		int a = dp(pos+1) + abs(h[pos] - h[pos+1]);
		int b = dp(pos+2) + abs(h[pos] - h[pos+2]);
		int ans = min(a,b);
		memo[pos] = ans;
		return ans;
	}
	
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		cin>>n;
		h.resize(n);
		for(int i=0;i<n;i++)cin>>h[i];
		memset(memo,-1,sizeof(memo));
		cout<<dp(0);
		return 0;
	}