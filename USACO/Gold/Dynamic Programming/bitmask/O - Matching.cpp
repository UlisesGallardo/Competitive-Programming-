#include <bits/stdc++.h>
using namespace std;

int matrix[21][21];
int memo[21][(1<<21)];
int n;
const unsigned int M = 1000000007;

int dp(int man, int mask){
    if(man == n) return 1;
    int &a = memo[man][mask];
    if(a!=-1)return a;

    int ans=0;
    for(int i=0; i<n; i++){
        if(mask&(1<<i) && matrix[man][i]){
           ans = (ans+dp(man+1, mask^(1<<i)))%M;
        }
    }
    return a = ans;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>matrix[i][j];

    memset(memo, -1, sizeof(memo));
    int mask = (1<<n)-1;
    cout<<dp(0,mask);

    return 0;
}
