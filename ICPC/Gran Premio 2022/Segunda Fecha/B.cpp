
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	bool isPow2(ll n){
		if(n == 0)return false;
		return !(n&(n-1));
	}
	
	ll solve(ll n){
		if(n<=0)return 1;
		if(n<=1)return 2;
		if(n<=2)return 3;
		int digits = 0;
		ll aux = n;
		int pos_second = 0;
		int iter = 0;
		int ones = 0;
		string s = "";
		while(aux>0){
			s = to_string(aux%2) + s;
			aux/=2;
			digits++;
		}
		ll total = 0;
		cout<<s<<"\n";
		if(isPow2(n))digits--;
		else{
				int m = s.size()-1;
				s[m] = '1';
				
				for(int i=0; i<=m/2; i++){
					if(s[i]!=s[m-i]){
						s[i] = '0';
						s[m-i] = '0';
					}
				}
				
				for(int i=1; i<=m/2; i++){
					if(s[i]=='1')ones++;
				}
				//cout<<"final->"<<s<<" ";
				if(ones>0){
					//if(s.size()%2==1 && s[m/2] == '1')total+=pow(2,ones-1)*2;
					//else
					total+=pow(2,ones);
				}else total++;
				//cout<<total<<"! ";
				digits--;
			
		}
		
		
		while(digits>2){
			int k = digits-2;
			if(k%2==0)total+=pow(2,k/2);
			else if(k==1)total+=2;
			else total+=pow(2,(k-1)/2)*2;
			digits--;
		}
		return total+3;
	}
	
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int t; cin>>t;
		while(t--){
			ll a,b; cin>>a>>b;
			a--;
			cout<<solve(a)<<" ";
			cout<<solve(b)<<endl;
		}
		
		return 0;
	}