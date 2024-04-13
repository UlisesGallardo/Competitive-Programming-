
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 1e5+10;
ll memo[N][1<<7];
ll a[N],player[N][7], n_idx[N];
int n,p,k;

bool comparar(int x, int y){
    return (a[x] > a[y]);
}

ll dp(int person, int mask){
    int bit_set = __builtin_popcount(mask);
    if(person == n) {
        if(bit_set==p)return 0;
        return -1e18;
    }

    ll &ans = memo[person][mask];
    if(ans != -1)return ans;

    int idx = n_idx[person];
    int totalAudience = person - bit_set;
    if(totalAudience < k){
        ans = dp(person+1, mask) + a[idx];
    }else{
        ans = dp(person+1, mask);
    }

    for(int i=0; i<p; i++){
        if(!(mask&(1<<i))){
            ans = max(ans, dp(person+1, mask|(1<<i)) + player[idx][i] );
        }
    }
    return ans;
}

int main(){
    memset(memo, -1, sizeof(memo));
    cin>>n>>p>>k;
    for(int i=0; i<n; i++) {
            cin>>a[i];
            n_idx[i] = i;
    };

    for(int i=0; i<n; i++){
       for(int j=0; j<p; j++){
            cin>>player[i][j];
        }
    }

    sort(n_idx, n_idx + n , comparar);

    //int mask = (1<<p)-1;
    cout<<dp(0,0);
    return 0;
}
