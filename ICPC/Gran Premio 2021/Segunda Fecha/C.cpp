
	#include <bits/stdc++.h>
	using namespace std;
	
	int main(){
		int t; cin>>t;
		while(t--){
			string s; cin>>s;
			int a,b; 
			a=b=0;
			int pos =0;
			for(int i=0; i<s.size(); i++){
				if(s[i]=='R')a++;
				else b++;
				if(b<a){
					a=b=0;
					pos=i+1;
				}
			}
			cout<<pos<<"\n";
		}
		
	}