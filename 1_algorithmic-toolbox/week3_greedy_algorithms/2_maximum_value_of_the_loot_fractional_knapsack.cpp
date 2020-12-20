#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();
  vector<double> vpu(n);

  for(int i = 0; i < n; i++) {
      vpu[i] = static_cast<double>(values[i]) / weights[i];
  }

  int i = 0;
  int items_used = 0;
  while(capacity && items_used < n) {
      i = max_element(vpu.begin(), vpu.end()) - vpu.begin();
      if (capacity >= weights[i]) {
          capacity -= weights[i];
          value += values[i];
          vpu[i] = 0;
          items_used++;
      } else {
          value += capacity * vpu[i];
          capacity = 0;
          vpu[i] = 0;
          items_used++;
      }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
