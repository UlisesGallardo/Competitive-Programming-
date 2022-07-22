
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	void solve(){
		ll x; cin>>x;
		string res = "";
		vector<string>izq,der;
		while(x>1){
			if(x<=1)break;
			if(x%2==0){
				izq.push_back("(");
				der.push_back(")^2");
				x/=2;
			}else{
				izq.push_back("(2*");
				der.push_back(")");
				x--;
			}
		}
		
		
		for(int i=0; i<(int)izq.size();i++){
			cout<<izq[i];
		}
		cout<<2;
		for(int i=(int)der.size()-1; i>=0;i--){
			cout<<der[i];
		}
	}
	
	int main(){
		
		int t; cin>>t;
		while(t--){
			solve();
			cout<<"\n";
		}
		return 0;
     }