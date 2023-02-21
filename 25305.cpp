#include <algorithm>
#include <iostream>

using namespace std;

int S[1001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, k;
  cin >> N >> k;

  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  nth_element(S, S + N - k, S + N);
  cout << S[N - k];
}