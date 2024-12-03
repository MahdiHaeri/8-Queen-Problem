#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#define N 8

bool check_line(vector<pair<int, int> > map) {
  pair<int, int> current_pair = map.back();
  for (int i = 0; i < (map.size() - 1); i++) {
    if (map[i].first == current_pair.first || map[i].second == current_pair.second || (abs(map[i].first - current_pair.first) == abs(map[i].second - current_pair.second))) {
      return false;
    }
  }
  return true;
}

void print_map(vector<pair<int, int> > map) {
  static int count = 1;
  string main_map[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j == map[i].second) {
        main_map[i][j] = to_string(map[i].second + 1);
      } else {
        main_map[i][j] = '.';
      }
    }
  }
  cout << "solusion: " << count;
  for (int i = 0; i < N; i++) {
    cout << endl;
    for (int j = 0; j < N; j++) {
      cout << main_map[i][j] << ' ';
    }
  }
  count++;
  cout << endl << endl;
}

void select_best_place (vector<pair<int, int> > &map) {
  if (map.size() == N) {
    print_map(map);
    return;
  }
  for (int i = 0; i < N; i++) {
    map.push_back(pair<int, int>(map.size(), i));
    if (check_line(map)) {
      select_best_place(map);
    }
    map.pop_back();
  }
  return;
}

int main(int argc, char const *argv[]) {
  vector<pair<int, int> > map;
  select_best_place(map);
  return 0;
}

