#include <iostream>

using namespace std;

bool visit[1001];

int main() {
  int K, N;
  cin >> N >> K;

  int print_count = 0;
  int i = 0;

  cout << '<';

  while (print_count < N) {
    for (int j = 0; j < K;) {
      if (visit[i] == false) {
        j++;

        if (j == K)
          break;
      }

      i = (i + 1) % N;
    }

    cout << i + 1;

    visit[i] = true;
    print_count++;

    if (print_count < N)
      cout << ", ";
  }

  cout << '>';
}