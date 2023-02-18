#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int V, E;

vector<int> Vs[10001];
vector<int> VsI[10001];

stack<int> stk;
bool dfs_1_visit[10001];

void dfs_1(int node) {
	if (dfs_1_visit[node]) return;
	dfs_1_visit[node] = true;

	for (auto v : Vs[node]) {
		dfs_1(v);
	}

	stk.push(node);
}

bool dfs_2_visit[10001];
int scc_group_count = 0;

vector<vector<int>> scc;

void dfs_2(int node) {
	if (dfs_2_visit[node]) return;
	dfs_2_visit[node] = true;

	scc[scc_group_count].push_back(node);

	for (auto v : VsI[node]) {
		dfs_2(v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int A, B;
		cin >> A >> B;

		Vs[A].push_back(B);
		VsI[B].push_back(A);
	}

	for (int i = 1; i <= V; i++) {
		dfs_1(i);
	}

	scc.push_back(vector<int>());

	while (!stk.empty()) {
		int top = stk.top();
		stk.pop();

		if (dfs_2_visit[top]) continue;

		dfs_2(top);

		scc_group_count++;
		scc.push_back(vector<int>());
	}

	scc.pop_back();

	for (int i = 0; i < scc_group_count; i++) {
		sort(scc[i].begin(), scc[i].end());
	}

	sort(scc.begin(), scc.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[0] < b[0];
	});

	cout << scc_group_count << '\n';

	for (auto& cc : scc) {
		for (auto v : cc) {
			cout << v << ' ';
		}
		cout << "-1\n";
	}
}
