
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	const int N =100000+10;
	bool tiempo[N] = {false};
	
	int main(){
		
		int t,total,c; cin>>t>>total>>c;
		for(int i=0; i<c; i++){
			int x; cin>>x;
			tiempo[x-1] = true;
		}
		int desc = 0;	
		int con = 0;	
		for(int i=0; i<total; i++){
			if(tiempo[i]){
				desc = max(desc,con);
				con = 0;
			}else{
				con++;
			}
		}
		desc = max(desc,con);
		//cout<<desc<<" ";
		if(desc>=t)cout<<"Y";
		else cout<<"N";
		cout<<"\n";
	}