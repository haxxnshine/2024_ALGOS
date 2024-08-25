#include <iostream>
#include <queue>
using namespace std;

struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		if (a.first > b.first)
			return true;
		else
			return false;
	}
};
int N, x, y, a, b, ret;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		pq.push({ x, y });
	}

	while (pq.size())
	{
		x = pq.top().first;
		y = pq.top().second;
		pq.pop();


		if (a == 0 && b == 0)
		{
			a = x;
			b = y;
			ret = y - x;
			continue;
		}

		if (x == a)
		{
			ret += (y - b);
			b = y;
		}

		else if (x > b)
		{
			ret += (y - x);
			a = x;
			b = y;
		}

		else if (y > b)
		{
			ret += (y - b);
			a = x;
			b = y;
		}
	}

	cout << ret;

	return 0;
}
