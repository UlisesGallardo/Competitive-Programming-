
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	//prevcolor = 0 (red), 1 (green)
	int n;
	vector<int>h(205,0);
	
	int memo[205][(int)4e4+10][2];
	
	int solve(int pos, int r, int g, int prevcolor){
		if(pos>n)return 0;
		
		if(prevcolor!=-1 && memo[pos][r][prevcolor] != -1) return memo[pos][r][prevcolor];
		
		int h_prev = h[pos-1];
		int green = 1e9, red = 1e9;
		
		if(g-h[pos]>=0){
			green =0;
			if(prevcolor == 0)green+=min(h_prev, h[pos]);
			green += solve(pos+1, r, g-h[pos], 1);
		} 
		
		if(r-h[pos]>=0){
			red = 0;
			if(prevcolor == 1)red+=min(h_prev, h[pos]);
			red += solve(pos+1, r-h[pos], g, 0);
		} 
		return memo[pos][r][prevcolor]  = min(red, green);
	}
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		
		memset(memo,-1, sizeof(memo));
		int a,b; cin>>n>>a>>b;
		for(int i=1; i<=n; i++)cin>>h[i];
		
		int ans = solve(1,a,b,-1);
		if(ans>=1e9)cout<<-1;
		else cout<<ans;
		return 0;
	}