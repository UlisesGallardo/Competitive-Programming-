
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int n,c; cin>>n>>c;
		map<string, int>m;
		int maximo = -1;
		while(n--){
			string s; cin>>s;
			int pos = 0;
			for(int i=0; i<c; i++)if(s[i]=='*')pos=i;
			for(int i=0; i<26; i++){
				s[pos] = char(i+'a');
				m[s]++;
				if(m[s]>maximo)maximo = m[s];
			}
		}
		string res = "";
		for(int i=0; i<26; i++)res+="z";
		for(auto a:m){
			if(a.second==maximo)if(a.first<res)res = a.first;
		}
		cout<<res<<" "<<maximo<<endl;

		return 0;
	}