
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
		
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int n,q,c; cin>>n>>q>>c;
		
		int cnt_b [11][110][110];
		memset(cnt_b, 0, sizeof(cnt_b));
		
		for(int i=0; i<n; i++){
			int x,y,brillo; cin>>x>>y>>brillo;
			cnt_b[brillo][y][x] += 1;
		}
		
		//prefix sum2d 
		for(int b=0; b<=10; b++){
			for (int j = 0; j < 110; j++) {
		        for (int i = 1; i <110; i++) {
		            cnt_b[b][i][j] += cnt_b[b][i-1][j]; //vertical
		        }
		    }
		}
	    
	    for(int b=0; b<=10; b++){
		    for (int i = 0; i < 110; i++) {
		        for (int j = 1; j < 110; j++) {
		            cnt_b[b][i][j] += cnt_b[b][i][j-1]; //horizontal
		        }
		    }
	    }
	    
		c++;//incluir c
		while(q--){
			ll t; cin>>t;
			
			int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
			
			int ans = 0;
			for(int b=0;b<=10; b++){
				int sum = cnt_b[b][y2][x2] - cnt_b[b][y2][x1-1] - cnt_b[b][y1-1][x2] + cnt_b[b][y1-1][x1-1];
				ans+=((b+t)%c) * sum;
			}
			cout<<ans<<"\n";
		}
		
		return 0;
	}