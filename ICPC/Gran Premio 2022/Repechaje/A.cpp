	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
			int x; cin>>x;
			int minutes = 0,steps = 0;
			while(minutes < 15 && steps < 3000){
				steps+=x;
				minutes++;
			}
			cout<<minutes<<endl;
		
		return 0;
	}