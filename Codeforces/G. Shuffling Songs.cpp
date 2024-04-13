#include <bits/stdc++.h>
using namespace std;


struct song{
	int g,w;
};

vector<song>m;
unordered_map<string,int>compress;

int memo[(1<<16)][16];
int n;

int dp(int mask, int prev){
	if(mask==0)return 0;

	int &a = memo[mask][prev];
	if(a!=-1)return a;
	int ans = 0;

	for(int i=0; i<n; i++){
        if(mask&(1<<i)){
            if(m[prev].g == m[i].g || m[prev].w == m[i].w){ //O(N)
                ans = max(ans, dp((mask^(1<<i)), i) + 1);
            }
        }
	}
	return a = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	memset(memo,-1,sizeof(memo));
    	m.clear();
    	compress.clear();
		cin>>n;
		int j = 0;
		for(int i=0; i<n; i++){
			string g,w; cin>>g>>w;
			if(compress.find(g)==compress.end()){
                    compress[g] = j;
                    j++;
            }
            if(compress.find(w)==compress.end()){
                    compress[w] = j;
                    j++;
            }
			song a;
			a.g = compress[g];
			a.w = compress[w];
			m.push_back(a);
		}
		int mask = (1<<n)-1;
		int ans = 0;
		for(int i=0; i<n; i++){
			ans = max(ans,dp((mask^(1<<i)), i)+1);
		}
		cout<<n-ans<<"\n";
    }

    return 0;
}
