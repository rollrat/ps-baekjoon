#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <queue>

using namespace std;

vector<int> map[10001];
stack<int> stk;
int d[10001];
int scc_group[10001];
int id = 1;
int scc_count = 1;

int scc(int v) {
    int ret = d[v] = id++;
    stk.push(v);
    
    for (auto vv : map[v]) {
        if (d[vv] == 0)
            ret = min(ret, scc(vv));
        else if (scc_group[vv] == 0)
            ret = min(ret, d[vv]);
    }

    if (ret == d[v]) {
         while (true) {
            auto t = stk.top();
            stk.pop();
            scc_group[t] = scc_count;
            if (t == v) break;
         }
         scc_count++;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;
    
    for (int i = 1; i <= E; i++) {
        int A, B;
        cin >> A >> B;

        map[A].push_back(B);
    }

    for (int i = 1; i <= V; i++) {
        if (d[i] == 0)
            scc(i);
    }

    set<int> scc_visit;
    queue<int> scc_next_print;

    for (int i = 1; i <= V; i++) {
        if (scc_visit.find(scc_group[i]) != scc_visit.end()) {
            continue;
        }

        scc_visit.insert(scc_group[i]);
        scc_next_print.push(scc_group[i]);
    }

    cout << scc_visit.size() << '\n';

    while (!scc_next_print.empty()) {
        auto q = scc_next_print.front();
        scc_next_print.pop();

        for (int i = 1; i <= V; i++) {
            if (scc_group[i] != q)
                continue;

            cout << i << ' ';
        }

        cout << "-1\n";
    }
}
