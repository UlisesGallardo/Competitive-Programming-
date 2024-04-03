#include <bits/stdc++.h>
#define ll long long 
#define MAXN 1000010
#define MAXB 5
#define eps 1e-9

using namespace std;

int b, n;
int w[MAXB + 5], p[MAXB + 5];
int A[MAXN + 5], B[MAXN + 5], C[MAXN + 5];
int memo[MAXB + 5][3 * MAXN + 5];

	double get_area(int i) {
		double s = (A[i] + B[i] + C[i]) / 2.0;
		return sqrt(s * (s - A[i]) * (s - B[i]) * (s - C[i]));
	}
	
	int dp(int idx, int kg) {
		if (kg <= 0) return 0;
		if (idx >= b) return INT_MAX;
		int &ans = memo[idx][kg];
		if (ans != -1) return ans;
		if(w[idx]==0) ans = dp(idx + 1, kg);
		else ans = min(dp(idx + 1, kg), dp(idx, kg - w[idx]) + p[idx]);
		return ans;
	}

	int main() {
		memset(memo, -1, sizeof memo);
		cin >> b >> n;
		for (int i = 0; i < b; i++) cin >> w[i] >> p[i];
		if(n == 0){
			cout<<0;
			return 0;
		}
		for (int i = 0; i < n; i++) cin >> A[i] >> B[i] >> C[i];
		double total = 0;
		int weight = 0, cnt=0;
		for (int i = 0; i < n; i++) total += get_area(i);
		for (int i = 0; i < b; i++) weight+=w[i];
			
		int kg = ceil(total / 30.0);
		
		if (weight == 0 || cnt > 0) cout << -1 << endl;
		else cout << dp(0, kg) << endl;
		
		return 0;
	}