
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	//Estados:
	//pos, Restrictions to add new numbers to the right, Restrictions to add new numbers to the left, isEmtpy
	//log3(10^18) -> max 30
	//flag -> me pasé del límite para R?
	//flag2 -> me pasé del límite para L?
	//isEmptyleft -> Construí 0's a la izquierda:
	
	int memo[60][2][2][2]; 
	
	string base_3(ll x){
		string s; 
		while(x>0){
			s = to_string(x%3) + s;
			x/=3;
		}
		return s;
	}
	
	int dp(string &l, string &r,int pos, int flag, int flag2,int isEmptyleft){
		if(pos >= (int)r.size())return 0;
		if(memo[pos][flag][flag2][isEmptyleft]!=-1)return memo[pos][flag][flag2][isEmptyleft];	
		int answer = 0;
		
		for(int i=0; i<3; i++){
			int new_flag = flag;
			int new_flag2 = flag2;
			int new_empty = 0;
			
			if(i>l[pos]-'0') new_flag2 = 0;
			if(i<r[pos]-'0')new_flag = 0;
			
			if(i<l[pos]-'0' && flag2==1)continue;
			if(i>r[pos]-'0' && flag==1)continue;
			if(i==0 && isEmptyleft==1)new_empty = 1;	
	        int suma = i+1;
	        if(i==0 && isEmptyleft == 1)suma = 0;
			answer = max(answer,suma+dp(l,r,pos+1,new_flag,new_flag2,new_empty));
		}
		memo[pos][flag][flag2][isEmptyleft] = answer;
		return memo[pos][flag][flag2][isEmptyleft];
	}
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int t; cin>>t;
		while(t--){
			ll l,r; cin>>l>>r;	
			string s_l = base_3(l);
			string s_r = base_3(r);	
			while(s_l.size()<s_r.size()) s_l = "0"+s_l;
			memset(memo,-1,sizeof(memo));
			//cout<<s_l<<" "<<s_r<<"\n";
			int ans = dp(s_l,s_r,0,1,1,1);
			cout<<ans<<"\n";
		}
		
		return 0;
	}