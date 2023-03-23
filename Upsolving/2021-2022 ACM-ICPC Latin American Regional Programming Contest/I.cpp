	
		#include <bits/stdc++.h>	
		using namespace std;
		typedef long long int ll;
		
		int main(){
			ios_base::sync_with_stdio(false); cin.tie(NULL);
			string days[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat","Sun"};
			map<string,int>m;
			for(int i=0; i<7;i++){
				m[days[i]] = i+1;
			}
			
			/*
				L->Ma 
				Ma->J
				Mi->V
				J->S->L +2
				V->D->L +1
				No se puede S->L 
				No se puede D->Ma 
			*/
			
			string today; cin>>today;
			int deposits; cin>>deposits;
			vector<ll>v(deposits);
			for(int i=0; i<deposits; i++)cin>>v[i];
			
			ll ans = 1e17;
	
			for(int j=0; j<deposits; j++){
				ll day_created  = m[today];
				
				ll limit = v[j];
				ll i=0;
				for(; i<=(limit%30); i++){ 
					if(day_created-1<0)day_created=6;
					else day_created--;
				}
				
				ll renewal = v[j]/30;
				ll last_renewal = (day_created + renewal)%7;
				
				ll wait = 30;
				if(last_renewal < m[today])wait-=abs(m[today] - last_renewal);
				else wait+=abs(last_renewal - m[today]);
				
				if(last_renewal == 3)wait+=2;
				if(last_renewal == 4)wait+=1;
				wait++;
				
				ll final_day = last_renewal;
				limit = 30;
				i=0;
				for(; i<=limit; i++){ //%modulo 7 para saber cuando empezaste
					//cout<<days[hoy]<<" "<<i<<"\n";
					final_day = (final_day+1)%7;
				}

				if(v[j]%30 == 0 && v[j]!=0)ans = 0;
				if(wait < ans)ans = wait;
			}
			cout<<ans;
			
			/*
			int hoy = 3;
			int limit = 30;
			int i=0;
			for(; i<=limit; i++){ //%modulo 7 para saber cuando empezaste
				cout<<days[hoy]<<" "<<i<<"\n";
				hoy = (hoy+1)%7;
			}*/
			/*
			int hoy = 5;
			int limit = 5;
			int i=0;
			for(; i<=(limit%30); i++){ 
				cout<<days[hoy]<<" "<<i<<"\n";
				if(hoy-1<0)hoy = 6;
				else hoy--;
			}*/
			
			/*
				L->Mi 
				Ma->J
				Mi->V
				J->S->L 
				V->D->L
				
				¿Cuantas veces se repite un ciclo de 30 días?
				(cada ciclo terminará en el día qué empezó + 2)%6
				cada 7 cambios se reinicia el ciclo... 
			*/
			
			
			return 0;
		}