
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int n; cin>>n;
		string s; cin>>s;
		
		int res=0;
		for(int i=0; i<n; i++){
			if(s[i]=='a'){
				bool flag = false;
				if((i+1<n && s[i+1]=='a') || (i-1>=0 && s[i-1]=='a'))flag= true;
				if(flag)res++;
			}
		}
		cout<<res<<endl;
		return 0;
	}