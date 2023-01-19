
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		freopen("hard.in","r",stdin);
		freopen("hard.out","w",stdout);
		
		string s; 
		
		vector<vector<string>>conditions(1000+2, vector<string>());
		int i = 0;
		
		while(cin>>s){
			conditions[i].push_back(s);
			if(s == "||")i++;
		}
		vector<vector<string>>nuevo;
		
		unordered_map<short int, bool>ans;
		
		int val = -32768;
		for(int k=val; k<=32767; k++)ans[k] = false;

		int first=0,second=0;		
		int total = 0;
		
		for(int k=0; k<=i; k++){			
			if(conditions[k].size()<=4){
				second++;
				int a = stoi(conditions[k][2]);
				if(conditions[k][1]==">=") for(int j=a; j<=32767; j++)ans[j] = true;
				else for(int j=a; j>=-32768; j--)ans[j] = true;
				
			}else{
				first++;
				int a,b;
				a = stoi(conditions[k][2]);
				b = stoi(conditions[k][6]);
				
				for(int j=a; j<=b; j++)ans[j] = true;
				if(a > b)total++;
			}
		}
		
		int sum = 0;
		for(int k=val; k<=32767; k++)if(ans[k])sum++;
		
		if(sum == 65536)cout<<"true";
		else if(second == 0 && first == total)cout<<"false";
		else{
			int actual = -32768;
			
			int iter = 0;
			if(ans[actual]){
				iter++;
				while(ans[actual]==true && actual<=32767)actual++;
				cout<<"x <= "<<actual-1;
			}
			
			
			int l=-1e9;
			for(int i=actual; i<=32767; i++){
				if(ans[i]==true && l==-1e9){
					l = i;
				}else if(ans[i]==false && l!=-1e9){
					if(iter==0)cout<<"x >= "<<l<<" && x <= "<<i-1;
					else cout<<" ||\nx >= "<<l<<" && x <= "<<i-1;
					
					l=-1e9;
					iter++;
				}
			}	
			
			if(l!=-1e9){
				if(iter==0)cout<<"x >= "<<l;
				else cout<<" ||\nx >= "<<l;
			}
		}
		
		return 0;
	}