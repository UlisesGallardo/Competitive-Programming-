
	#include <bits/stdc++.h>	
	using namespace std;
	typedef long long int ll;
	
	int solve(int last_renewal, int day_created){
		if(day_created == 1){
			last_renewal+=30;
			if(last_renewal>=0)return last_renewal;
			day_created = 3;
		}
		if(day_created == 3){
			last_renewal+=32;
			if(last_renewal>=0)return last_renewal;
			day_created = 0;
		}
		ll aux = -1*last_renewal;
		last_renewal = -(aux%91);
		
		if(day_created == 0){
			last_renewal+=30;
			if(last_renewal>=0)return last_renewal;
			last_renewal+=30;
			if(last_renewal>=0)return last_renewal;
			last_renewal+=31;
			return last_renewal;
		}
		if(day_created == 2){
			last_renewal+=30;
			if(last_renewal>=0)return last_renewal;
			last_renewal+=31;
			if(last_renewal>=0)return last_renewal;
			last_renewal+=30;
			return last_renewal;
		}
		if(day_created == 4){
			last_renewal+=31;
			if(last_renewal>=0)return last_renewal;
			last_renewal+=30;
			if(last_renewal>=0)return last_renewal;
			last_renewal+=30;
			return last_renewal;
		}
	}
	
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		
		string m[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat","Sun"};
		map<string,int>days;
		for(int i=0; i<7;i++) days[m[i]] = i;
		
		
		string today; cin>>today;
		int deposits; cin>>deposits;
		vector<ll>v(deposits);
		for(int i=0; i<deposits; i++)cin>>v[i];
		
		
		int hoy = days[today];
		/*
				Day_created
				L->Mi 
				Ma->J
				Mi->V
				J->S->L  +2
				V->D->L  +1
				
				L->Mi->V->L 91
				Ma->J->(L)
				Mi->V->L->Mi 91
				J->(L)
				V->L->Mi->V 91
		*/
		ll ans = 1e10;
		for(int i=0; i<deposits; i++){
			int day_created = ((hoy-v[i])%7 + 7)%7;
			//cout<<day_created<<" ";
			ll last_renewal = 0;
			if(v[i]==0){
				if(hoy<=2)last_renewal+=30;
				if(hoy==3)last_renewal+=32;
				if(hoy==4)last_renewal+=31;
			}else{
				last_renewal = solve(-v[i], day_created);
			}
			ans = min(ans, last_renewal);
		}
		cout<<ans<<"\n";
		return 0;
	}