#include <bits/stdc++.h>
using namespace std;

const int N  = 1e6+10;
int divs[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);

	int n; cin>>n;
	for(int i=0; i<n; i++){
		int x; cin>>x;	
		const int d = sqrt(x);
		for(int j=1; j<=d; j++){
			if(x%j == 0){
				divs[j]++;
				if(x/j != j){
					divs[x/j]++;
				}
			}
		}
	}
	for(int i=N; i>=1; i--){
		if(divs[i] >= 2){
			cout<<i;
			break;
		}
	}
	
}