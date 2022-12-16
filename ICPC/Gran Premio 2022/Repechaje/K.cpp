
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int n,q; cin>>n>>q;
		map<string,int>m;
		
		for(int i=0; i<n; i++){
			string s, digits=""; cin>>s;
			
			for(auto a:s){
				int v = (a-'a');

				if(v>=15 && v<=18) v=7;
				else if(v>=19 && v<=21) v = 8;
				else if(v>=22) v = 9;
				else v = v/3 + 2;
				
				digits+=to_string(v);
			}
			//cout<<digits<<" \n";
			m[digits]++;
		}
		
		while(q--){
			string code; cin>>code;
			cout<<m[code]<<endl;
		}
		
		return 0;
	}