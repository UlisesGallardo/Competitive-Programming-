
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		bool flag =  false;
		for(int i=0; i<8; i++){
			int x; cin>>x;
			if(x>1)flag = true;
		}
		if(flag)cout<<"F"<<endl;
		else cout<<"S"<<endl;
		
		return 0;
	}