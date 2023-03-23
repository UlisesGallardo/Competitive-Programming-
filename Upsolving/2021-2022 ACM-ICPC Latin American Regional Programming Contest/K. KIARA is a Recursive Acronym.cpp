
	#include <bits/stdc++.h>	
	using namespace std;
	
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		
		int n; cin>>n;
		vector<string>v(n);
		bool exist[27] = {false};
		for(int i=0; i<n; i++){
			cin>>v[i];
			exist[v[i][0]-'A'] = true;
		}
		
		for(int i=0; i<n; i++){
			bool flag = true;
			for(auto a:v[i]){
				if(!exist[a-'A']){
					flag = false;
					break;
				}
			}
			if(flag){
				cout<<"Y";
				return 0;
			}
		}
		cout<<"N";
		return 0;
	}