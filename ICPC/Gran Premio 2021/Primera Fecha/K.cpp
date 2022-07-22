	#include <bits/stdc++.h>
	using namespace std;
	
	void solve(){
		vector<int>res;
		string s; cin>>s;
		int n = s.size()-1;
		if((s[n]-'0')%2==0) res.push_back(2);
		
		int suma =0;
		for(int i=0; i<(int)s.size(); i++) suma+=s[i] -'0';
		if(suma%3==0)res.push_back(3);
		
		if((int)s.size()>1){
			string aux = "";
			stringstream ss;
			ss << s[n-1];
			ss << s[n];
			ss>> aux;
			if(stoi(aux)%4==0 || aux=="00"){
				res.push_back(4);
			}
		}
		
		if(s[n]=='0' || s[n]=='5')res.push_back(5);
		
		if(res.size()==0){
			cout<<-1<<"\n";
			return;
		}
		int con=0;
		for(int i=0; i<(int)res.size(); i++){
			if(res[i]==2 || res[i]==3)con++;
			if(i!=res.size()-1) cout<<res[i]<<" ";
			else cout<<res[i];
		}
		if(con==2)cout<<" "<<6;
		cout<<"\n";
	}
	
	int main(){
		int t; cin>>t;
		while(t--){
			solve();
		}
	}