#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;

  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int B[Q];
  for (int i = 0; i < Q; i++) {
    int L, R, X;
    cin >> L >> R >> X;

    for (int j = L; j <= R; j++) {
      A[j] = A[j] ^ X;
    }

    int or_result = 0;
    for (int j = L; j <= R; j++) {
      or_result = or_result | A[j];
    }

    B[i] = or_result;
  }

  for (int i = 0; i < Q; i++) {
    cout << B[i] << endl;
  }

  return 0;
}