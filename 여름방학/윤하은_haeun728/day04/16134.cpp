#include <iostream>
#define ll long long
using namespace std;

ll mod = 1e9 + 7;
ll mul(ll x, ll N)
{
	if (N == 1) return x;
	ll res = mul(x, N / 2);
	res *= res; res %= mod;
	if (N % 2 == 1) res *= x;
	return res % mod;
}

ll fact[1010101] = { 0 };
void init()
{
	fact[0] = 1;
	for (ll i = 1; i <= 1000000; i++)
		fact[i] = fact[i - 1] * i % mod;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll N, K;

	cin >> N >> K;
	init();
	cout << fact[N] * mul((fact[K] * fact[N - K]) % mod, 1e9 + 5) % mod;
}
