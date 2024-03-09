#include <bits/stdc++.h>
using namespace std;

const int N = 1000+10;
const int INF = 5e5+10;
int fee[N];
int memo[N][N];
int n;

int dp(int square, int prec_jump){
    if(square == n-1)return fee[square];
    if(square >= n)return INF;
    int &ans = memo[square][prec_jump];
    if(ans != -1)return ans;
    //printf("%d\n", square);

    if(prec_jump > 0 && square - prec_jump >= 0){
        ans = dp(square - prec_jump, prec_jump) + fee[square];
        ans = min(ans, dp(square + prec_jump + 1, prec_jump + 1) + fee[square]);
    }else if(square + prec_jump + 1 <= n-1){
        ans = dp(square + prec_jump + 1, prec_jump + 1) + fee[square];
    }
    return ans;
}

int main()
{
    memset(memo,-1,sizeof(memo));
    scanf("%d",&n);
    for(int i=0; i<n; i++)scanf("%d",&fee[i]);
    printf("%d",dp(1,1));
    return 0;
}
