
	#include <bits/stdc++.h>
	using namespace std;
	
	void solve(){
		string s; cin>>s;
		if(s.size()==1){
			cout<<0;
			return;
		}
		int c,v,n=s.size();
		c=v=0;
		for(int i=0; i<n; i++){
			if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')v++;
			else c++;
		}
		if(c==0 || v==0)cout<<n;
		else{
			int res1 = 0, res2 = 0;
			map<char,int>m;
			
				
				//escoger una vocal y cambiarla a esa vocal
				for(int i=0; i<n; i++){
					if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
						res1+=2;
						m[s[i]]++;
					}else res1++;
				}
				int maximo = INT_MIN;
				//buscar la vocal más repetida
				for(auto [a,b]:m) if(b>maximo)maximo = b;
				res1-=(2*maximo);//menos la vocal que he cambiado
				//cout<<"maximo1:      "<<maximo<<"\n";
				
				
				
				
				m.clear();
				for(int i=0; i<n; i++){
				if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')res2+=1;
					else{
						res2+=2;
						m[s[i]]++;
					} 
				}
				 maximo = INT_MIN;
				for(auto [a,b]:m) if(b>maximo)maximo = b;
				res2-=(2*maximo);
				//cout<<"maximo2"<<maximo<<"\n";
				//buscar la consonante m
			//cout<<res2<<" "<<res1<<" ";
			cout<<min(res2,res1);	
		}
	}
	
	int main(){
		int t; cin>>t;
		int con=1;
		while(t--){
			cout<<"Case #"<<con<<": ";
			con++;
			solve();
			cout<<"\n";
		}
	}