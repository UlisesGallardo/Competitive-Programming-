#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef vector<long long> vi;

class FenweekTree{
private:
    vi ft;
public:
    FenweekTree(int m){ft.assign(m+10,0);}
    long long rsq(int j){
        long long sum = 0;
        for(;j;j-=LSOne(j)){
            sum += ft[j];
        }
        return sum;
    }

    int rsq(int i, int j){return rsq(j) + rsq(i-1);}
    void update(int idx, long long value){
        for(;idx < (int)ft.size(); idx += LSOne(idx)){
            ft[idx] += value;
        }
    }
};

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    FenweekTree ft(n);

    while(q--){
        char type; scanf(" %c",&type);
        if(type == '+'){
            int idx; long long value; scanf("%d %lld", &idx, &value);
            ft.update(idx+1,value);
        }else{
            int right;scanf("%d",&right);
            right++;
            if(right == 1) printf("%d\n",0);
            else printf("%lld\n",ft.rsq(right-1));
        }
    }
    return 0;
}
