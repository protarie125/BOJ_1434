#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll N, M;
vl A, B;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N >> M;

  A = vl(N);
  for (auto&& a : A) cin >> a;
  B = vl(M);
  for (auto&& b : B) cin >> b;

  ll ans = 0;
  ll i = 0;
  ll j = 0;
  ll am = A[0];
  while (i < N) {
    if (j == M) {
      ans += am;
      ++i;
      if (i == N) continue;

      am = A[i];
      continue;
    }

    if (am < B[j]) {
      ans += am;
      ++i;
      if (i == N) continue;

      am = A[i];
      continue;
    }

    am -= B[j];
    ++j;
  }

  cout << ans;

  return 0;
}