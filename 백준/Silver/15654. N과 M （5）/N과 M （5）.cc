#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];
int ans[9];
bool check[9];

void go(int idx, int n, int m)
{
	if (idx > m)
	{
		for (int i = 1; i <= m; i++)
		{
			cout << ans[i];
			if (i != m)
				cout << ' ';
			else
			{
				cout << '\n';
				return;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == true)
		{
			ans[idx] = arr[i];
			check[i] = false;
			go(idx + 1, n, m);
			check[i] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m; cin >> n; cin >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		check[i] = true;
	}
	sort(&arr[1], &arr[n+1]);
	go(1, n, m);
}