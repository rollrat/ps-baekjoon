#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int K;
  cin >> K;

  stack<int> stk;

  for (int i = 0; i < K; i++) {
    int c;
    cin >> c;

    if (c == 0)
      stk.pop();
    else
      stk.push(c);
  }

  int sum = 0;

  while (!stk.empty()) {
    sum += stk.top();
    stk.pop();
  }

  cout << sum;
}