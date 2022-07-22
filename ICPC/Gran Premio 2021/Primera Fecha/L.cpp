
	#include <iostream>
	using namespace std;
	typedef unsigned long long int ll;

int main()
{
    int Q;
    cin>>Q;
    while(Q--){
    	string s = "(2)^2";
       ll x; cin>>x;
       if(x==1){
       	cout<<2<<"\n";
       	continue;
       }
   		ll con = 2;
   		bool entrar = false;
   		if(x%2!=0){
   			x--;
   			entrar = true;
   		}
   		while(con<x){
   			con*=2;
   			s = "("+s+")^2";
   		}
		if(entrar) cout<<"(2*"+s+")";	
		else cout<<s;
       cout<<"\n";
    }
}