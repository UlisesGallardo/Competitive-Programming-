	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int t; cin>>t;
		while(t--){
			int q; cin>>q;
			ll s[27],t[27];
			memset(s,0,sizeof(s));
			memset(t,0,sizeof(t));
			s[0]=t[0]=1;
			ll sumS=1,sumT=1;
			while(q--){
				int type,k; cin>>type>>k;
				string ss; cin>>ss;
				if(type == 1)for(int i=0; i<ss.size(); i++){s[ss[i]-'a']+=k;sumS+=k;}
				else for(int i=0; i<ss.size(); i++){t[ss[i]-'a']+=k;sumT+=k;}
				bool flag = false;
				bool f = true;
				for(int i=25; i>=1; i--){
					if(t[i]!=0){
						flag = true;
					}
					if(s[i]!=0){
						f = false;
					}
				}
				
				if(flag)cout<<"YES";
				else{
					if(f){
						if(sumS<sumT)cout<<"YES";
						else cout<<"NO";
					}else cout<<"NO";
				}
				cout<<"\n";
			}
		}
		
		return 0;
	}