#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m, k; cin>>n>>m>>k;

    vector<pair<int,int>>my(n),store(m);
    for(int i=0; i<n; i++){
        cin>>my[i].first;
        my[i].second = i+1;
    }
    for(int i=0; i<m; i++){
        cin>>store[i].first;
        store[i].second = i+1;
    }

    sort(my.begin(),my.end());
    sort(store.begin(),store.end());
    int idx1 = 0;
    int idx2 = 0;
    int day = 0;
    bool flag = false;

    vector<pair<int,int>>res;

    while(true){
        int aux = k;
        while(idx1 < n && my[idx1].first == day && aux>0){
            aux--;
            idx1++;
        }

        if(idx1<n && my[idx1].first == day){
            flag = true;
            break;
        }

        while(idx2<m && store[idx2].first == day && aux>0){
            res.push_back(store[idx2]);
            aux--;
            idx2++;
        }

        if(aux>0){ //compra y consume las que puedas
            while(idx1 < n && aux>0){
            	if(idx2<m  && store[idx2] < my[idx1] )break;
                aux--;
                idx1++;
            }

            while(idx2<m  && aux>0){
                res.push_back(store[idx2]);
                aux--;
                idx2++;
            }
        }

        if(idx1>=n && idx2>=m){
            break;
        }

        while(idx2<m && store[idx2].first == day){
            idx2++;
        }
		//cout<<idx1<<" "<<idx2<<"\n";
        day++;
    }

    if(flag)cout<<-1;
    else{
        cout<<res.size()<<"\n";
        for(auto a:res){
            cout<<a.second<<" ";
        }
    }

}