#include <iostream>

using namespace std;

int arr[1001];
int heap[1001];
int heap_leaf = 0;

void heap_push(int x) {
  heap[heap_leaf] = x;

  // bottom up
  int p = heap_leaf;
  while (p > 0) {
    int pp = (p - 1) / 2;

    if (heap[pp] <= heap[p])
      break;

    swap(heap[p], heap[pp]);
    p = pp;
  }

  heap_leaf++;
}

int heap_pop() {
  int ret = heap[0];
  swap(heap[0], heap[--heap_leaf]);

  // top down
  int p = 0;
  while (true) {
    int l = p * 2 + 1;
    int r = p * 2 + 2;

    if (l < heap_leaf && heap[p] > heap[l]) {
      if (r < heap_leaf && heap[r] < heap[l]) {
        swap(heap[p], heap[r]);
        p = r;
      } else {
        swap(heap[p], heap[l]);
        p = l;
      }
    } else if (r < heap_leaf && heap[p] > heap[r]) {
      swap(heap[p], heap[r]);
      p = r;
    } else {
      break;
    }
  }

  return ret;
}

void do_sort(int N) {
  for (int i = 0; i < N; i++)
    heap_push(arr[i]);

  for (int i = 0; i < N; i++)
    arr[i] = heap_pop();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    arr[i] += 1001;
  }

  do_sort(N);

  for (int i = 0; i < N; i++) {
    cout << arr[i] - 1001 << '\n';
  }
}
