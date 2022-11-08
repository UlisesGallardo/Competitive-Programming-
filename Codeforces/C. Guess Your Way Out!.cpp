
	/*
	author: Ulises Gallardo
	
	My process was first see what happend to each level of a binary
	tree when I try to reach node n, and after thinking with wrong approaches, 
	I tried to see the problem as the operation of seeking a node in a query that is performed 
	to update a specific leaf in a Segment Tree, but with the restriction that 
	we have to visit a left or right child depending of the command.
	
	With this approach it is possible count the nodes that will be visited if
	the range of the current node doen't contain node 'n', so it is not neccesary visit all the children.
	And we don't care about the commands in that scenario because eventually
	those nodes will be visited and it will return to the parent of the current node.
	
	Thus, this search is done in O(log(2^n)) time and it is possible without recursion. 
	
	*/


	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	ll h,n;
	
	ll ans=0;
	ll get_children(ll high){
		ll total = 0;
		for(int i=0; i<=high; i++)total+=pow(2,i);
		return total;
	}
	
	bool found = false;	
	
	void solve(ll L, ll R, int altura, char command){
		//cout<<L<<" "<<R<<"\n";
		if(!(n>=L && n<=R)){
			//cout<<L<<" -  "<<R<<" "<<get_children(h-altura)<<" \n";
			ans+=get_children(h-altura);
			return;
		}
		if(L==R) {found=true; return;}
		ans++;
		
		ll med = (L+R)/2;
		
		if(command=='R'){
			if(!found)solve(L,med, altura+1,'L');
			if(!found)solve(med+1,R, altura+1,'R');
		}else{
			if(!found)solve(med+1,R, altura+1,'R');
			if(!found)solve(L,med, altura+1,'L');
		}
	}
	
	int main(){
		cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
		
		cin>>h>>n;
		
		ll leafs = pow(2,h);
		solve(1,leafs,0,'R');
		cout<<ans;
		return 0;
	}