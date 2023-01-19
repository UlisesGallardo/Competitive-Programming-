
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	int coins[13];
	int n; 
	
	int dp(vector<int>& coins, vector<int>&memo,  int amount){ //estado -> amount		
		/*casos base*/
        if(memo[amount]!=-1) return memo[amount];

		if(amount == 0) return 0;
		
		int ans = 1e9;
		for(int i=0; i<coins.size(); i++){
			if(amount - coins[i]>=0){
				ans = min(ans, 1+dp( coins, memo,  amount - coins[i])); //transición a otro estado
			}
		}
        memo[amount] = ans;
		return ans;
	}
	
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		return 0;
	}