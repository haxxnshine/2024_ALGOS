#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;

typedef long long ll;

struct Result {
	ll x;
	ll y;
	ll g;
};

Result extended_gcd(ll a, ll b) {

	if (b == 0)  return { 1, 0, a };

	Result res = extended_gcd(b, a%b);

	return { res.y, res.x - (a / b * res.y), res.g };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll N, A;
	cin >> N >> A;
  
	cout << N - A << " ";

	Result res = extended_gcd(A, N);

	if (res.g != 1 || res.x == 0) cout << "-1";
	else {
		while (res.x < 0) res.x += N;
		cout << res.x;
	}

	return 0;
}
