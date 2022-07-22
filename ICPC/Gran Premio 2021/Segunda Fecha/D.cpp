	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	ll C,R,S;
	
	ll maximo(){
		ll res = 0;
		if(C%S!=0 && C/S!=0)res++;
		res+=C/S;
	    return res;
	}
	
	ll minimo() {
		if(R==0){
			return maximo();
		}

		ll res = 0;
	    C-= R*(S-1);
	    if(C<1)return 0;
	    if(C%S!=0)res++;
	    res+=C/S;
	    return res;
	}
	
	int main() {
	    ios_base::sync_with_stdio(0);
	    int Q;
	    cin>>Q;
	    while(Q--)
	    {
	        cin>>C>>R>>S;
	        cout<<maximo()<<" "<<minimo()<<"\n";
	    }
	}