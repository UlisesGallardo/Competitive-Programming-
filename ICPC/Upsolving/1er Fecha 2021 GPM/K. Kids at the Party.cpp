
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;

	
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		
		int t; cin>>t;
		while(t--){
			string s; cin>>s;
			int n = s.size();
			int sum = 0;
			for(int i=0; i<n; i++)sum+=s[i]-'0';
		
			vector<int>ans;
			int final = s[s.size()-1] - '0';
			if(final%2 == 0)ans.push_back(2);	
			if(sum%3 == 0)ans.push_back(3);
			if(s.size()-2 >=0 ){
				char a = s[s.size()-2], b = s[s.size()-1];
				string aux = "";
				aux.push_back(a);
				aux.push_back(b);
				if(stoi(aux)%4==0)ans.push_back(4);
			}
			
			if(final == 0 || final == 5)ans.push_back(5);
			if(sum%3 == 0 && final%2 == 0)ans.push_back(6);
			
			if(ans.size()==0){
				cout<<-1<<"\n";
				continue;
			}
			for(int i=0; i<ans.size(); i++){
				if(i<ans.size()-1)cout<<ans[i]<<" ";
				else cout<<ans[i];
			}
			cout<<"\n";
		}		
	}