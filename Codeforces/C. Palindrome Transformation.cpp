
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	int min_steps(char c1, char c2){
		return min(abs(c1-c2),26-abs(c1-c2));
	}
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		int n,p;cin>>n>>p;
		string s; cin>>s;
		
		if(p>=n/2){
			reverse(s.begin(),s.end());
			p = (n-p)+1;
		}
		p--;
		
		int left=-1, right =-1;
		for(int i=0; i<=p; i++){
			if(s[i]!=s[n-1-i]){
				left = i;
				break;
			}
		}
		
		for(int i=(n-1)/2; i>=p; i--){
			if(s[i]!=s[n-1-i]){
				right = i;
				break;
			}
		}
		
		if(left==-1)left = p;
		if(right==-1)right=p;
		
		int res=0;
		if(s[p]!=s[n-1-p]){
			res+=min_steps(s[p],s[n-1-p]);
			s[p]=s[n-1-p];
		}
		
		for(int i=p+1; i<=right; i++){
			if(s[i]!=s[n-1-i]){
				res+=min_steps(s[i],s[n-1-i]);
				s[i] = s[n-1-i];
			}
		}
		if(left!=p){
			for(int i=right-1; i>=left; i--){
				if(s[i]!=s[n-1-i]){
					res+=min_steps(s[i],s[n-1-i]);
					s[i] = s[n-1-i];
				}
			}
		}

		cout<<res + min(p-left, right-p)  + (right-left);
		return 0;
	}