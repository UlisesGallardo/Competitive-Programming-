#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;

int main() {
   //ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m;
  //cin >> n >> m;
  scanf("%d %d", &n, &m);
  vector<ll> v(n), suma(n, 0);
  
  for (int i = 0; i < n; i++) {
    //cin >> v[i];
    scanf("%lld", &v[i]);
    if (i == 0)
      suma[i] = v[i];
    else
      suma[i] = ((suma[i - 1])%mod + (v[i])%mod) % mod;
  }

  vector<ll> suma_acumulada(n);
  vector<ll> aux(n);
  for (int i = 0; i < n; i++) {
  	if (i + 1 < n)
      aux[i] = ((v[i]%mod) * ((suma[n - 1] - suma[i])+mod)%mod) % mod;
    else
      aux[i] = v[i];
  	
    if (i == 0) {
      suma_acumulada[i] = aux[i];
    } else {
      suma_acumulada[i] = (suma_acumulada[i - 1]%mod + aux[i]%mod) % mod;
    }
  }

  while (m--) {
    int l, r;
    //cin >> l >> r;
    scanf("%d %d", &l, &r);
    l--;
    r--;
    if (l == r) {
      //cout << v[l] << endl;
      printf("%lld",v[l]);
      continue;
    }
    ll res = 0;
    if (l - 1 >= 0)
      res = ((suma_acumulada[r] - suma_acumulada[l - 1])+mod) % mod;
    else
      res = suma_acumulada[r];
    ll suma_1 = 0;
    if (l - 1 < 0)
      suma_1 = suma[r];
    else
      suma_1 = ((suma[r] - suma[l - 1])+mod) % mod;

    ll suma_2 = 0;
    if (r == n - 1)
      res = ((res - v[n - 1])+mod) % mod;
    suma_2 = ((suma[n - 1] - suma[r])+mod) % mod;
    //cout << ((res - (suma_1%mod * suma_2%mod))+mod) % mod << endl;
    printf("%lld\n", ((res - (suma_1%mod * suma_2%mod))+mod) % mod);
  }
}