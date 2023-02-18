#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr[32001];
bool visit[32001];

void dfs(vector<int>& result, int node) {
	visit[node] = true;

	for (auto n : arr[node]) {
		if (!visit[n])
			dfs(result, n);
	}

	result.push_back(node);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (; M; M--) {
		int x; cin >> x;
		int y; cin >> y;

		arr[x].push_back(y);
	}

	vector<int> result;
	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;
		dfs(result, i);
	}

	for (auto i = result.rbegin(); i != result.rend(); i++) {
		cout << *i << ' ';
	}

	return 0;
}
