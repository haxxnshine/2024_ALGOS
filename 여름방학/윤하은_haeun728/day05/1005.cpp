#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <stdio.h> 
#include <string>
#include <memory.h> 
#include <algorithm>
#include <cmath>

#include <queue>
#include <vector>
using namespace std;

int t, n, k, w;
vector<int> TIME(1001);
vector<int> inDegree(1001);
vector<int> graph[1001];
queue<int> q;
int dp[1001]{ 0, };

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		int time; cin >> time;
		TIME[i] = time;
	}

	for (int i = 0; i < k; i++)
	{
		int s, e; cin >> s >> e;
		graph[s].push_back(e);
		inDegree[e]++;
	}

	cin >> w;
}

void topology()
{

	for (int i = 1; i <= n; i++)
	{
		if (!inDegree[i]) q.push(i);
		dp[i] = TIME[i];
	}

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int j = 0; j < graph[now].size(); j++)
		{
			int next = graph[now][j];
			inDegree[next]--;
			dp[next] = max(dp[next], dp[now] + TIME[next]);

			if (!inDegree[next]) q.push(next);
		}
	}
}


void SOLVE()
{
	cin >> t;
	while (t--)
	{

		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
			inDegree[i] = 0;
			dp[i] = 0;
		}
		INPUT();


		topology();

		cout << dp[w] << '\n';
	}
	
}

int main()
{
	SOLVE();
}
