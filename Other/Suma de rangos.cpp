#include <iostream>
using namespace std;
typedef unsigned long long int ll;

const int N = 1e6+10;
ll arr[N];

int main() {
  ll tam = 0;
  cin >> tam;
  for (int i = 0; i < tam; i += 1) {
    arr[i] = i + 1;
  }
  ll suma_base = (tam * (tam + 1)) / 2;
  ll sumota = 0;

  for (int i = 0; i < tam - 1; i++) {
    sumota += suma_base + arr[tam - 2 - i] - i;
    suma_base = suma_base + arr[tam - 2 - i] - i;
  }

  cout << sumota;
  return 0;
}
