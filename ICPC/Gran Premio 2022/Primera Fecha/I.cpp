
#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;
int main(){
	ll N; cin>>N;
	vector<ll>num;
	ll aux = N;
	
	
	while(N!=0){
		num.push_back(N%10);
		N/=10;
	}
	
	int res= 0;
	for(int i=0; i<num.size(); i++){
		if(num[i]!=0 && aux%num[i] == 0)res++;
	}
	cout<<res<<endl;
	
}