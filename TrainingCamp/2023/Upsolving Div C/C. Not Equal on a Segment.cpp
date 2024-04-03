#include <bits/stdc++.h>
using namespace std;

struct Query{
    int l,r,x,i;
    Query(int l_, int r_, int x_, int i_){
        l = l_;
        r = r_;
        x = x_;
        i = i_;
    }
};

unordered_map<int,vector<Query>>m;
const int N = 1e6+10;

int find_value(int x, set<int>const &s){
        auto lt = lower_bound(s.begin(),s.end(),x); //log(n)
        if (lt != s.begin() && *lt != x) {
            lt--;
        }
        return *lt;
}

void solve_queries(vector<vector<int>>&del, vector<int>&ans, vector<int>&v, vector<Query>&q, set<int>&s, int x){
    for(auto pos:del[x]) s.erase(s.find(pos)); //log(n)

    for(Query query:q){
        if(query.l == query.r){
            if(v[query.l] == x) ans[query.i] = -1;
            else ans[query.i] = query.l;
        }else{
            int r = find_value(query.r, s);
            if(r >= query.l  && r <= query.r){
                ans[query.i] = r;
            }else{
                ans[query.i] = -1;
            }
            //cout<<x<<" "<<r<<" "<<r<<"\n";
        }
    }
    for(auto pos:del[x])s.insert(pos); //log(n)
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>>del(N);

    int n,q; cin>>n>>q;
    vector<int>v(n+1);
    set<int>s;
    vector<int>ans(q+1);
    for(int i=1; i<=n; i++) {
        cin>>v[i];
        s.insert(i);
        del[v[i]].push_back(i);
    }

    for(int i=0; i<q; i++){
        int l,r,x; cin>>l>>r>>x;
        m[x].push_back(Query(l,r,x,i));
    }

    for(auto [a,b]:m){
        solve_queries(del, ans, v, b, s, a);
    }

    for(int i=0; i<q; i++){
        cout<<ans[i]<<"\n";
    }

    return 0;
}
