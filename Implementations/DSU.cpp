
	#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;

	class dsu{
	public:
	    dsu(int n)
	    {
	        p.resize(n + 1);
	        s.resize(n + 1);
	        for (int i = 1; i <= n; i++)
	            p[i] = i, s[i] = 1;
	    }
	    vector< int > p, s;
	 
	    int find(int x)
	    {
	        if (x != p[x])
	            p[x] = find(p[x]);
	        return p[x];
	    }
	    void merge(int x, int y)
	    {
	        x = find(x); y = find(y);
	        if(x==y) return;
	        p[x] = y;
	        s[y] += s[x];
	    }
	};
	int main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		int t; cin>>t;
		
		while(t--){
			
		}
	}