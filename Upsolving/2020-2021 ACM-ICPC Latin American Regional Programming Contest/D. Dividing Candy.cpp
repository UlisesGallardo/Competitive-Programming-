
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;

	bool isPowerOfTwo(int x){
	    return x && (!(x & (x - 1)));
	}
	
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		int n; cin>>n;
		
		int v[(int)1e5+10] = {0};
		
		for(int i=0; i<n; i++){
			int x; cin>>x;
			v[x]++;
		}
			
		if(n==1){
			cout<<"N";
			return 0;
		}else if(n==2){
			cout<<"Y";
			return 0;
		}
		
		for(int i=0; i<=(int)1e5;i++){
			if(v[i] > 0){
				v[i+1] += (v[i]/2);
				v[i] = (v[i]%2);
			}
		}
		
		int cnt = 0, isPower = 0;
		for(int i=0; i<=(int)1e5+5;i++){
			if(v[i] > 0){
				if(isPowerOfTwo(v[i]))isPower++;
				cnt++;
			}
		}
		//cout<<isPower<<" ";
		if(cnt<=2 && isPower == cnt)cout<<"Y";
		else cout<<"N";
	}