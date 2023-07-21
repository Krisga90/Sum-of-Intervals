#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

#include <vector>
#include <utility>

int sum_intervals(std::vector<std::pair<int, int>>& intervals) {
  std::sort(intervals.begin(), intervals.end());

  int sum = 0;
  int begin = intervals[0].first;
  int end = intervals[0].second;
  for (auto pair: intervals)
  {
    if(pair.first > end)
    {
      sum += end - begin;
      begin = pair.first;
      end = pair.second;
    }
    if(pair.second > end)
      end = pair.second;
  }
  sum += end - begin;

  return sum;
}

void print()
{
  std::vector<std::pair<int, int>> intervals;
  intervals = {{1, 4}, {7, 10}, {3, 5}};

  sum_intervals(intervals);
  
  for (auto pair: intervals)
  {
    std::cout << "[ " << pair.first << ", " << pair.second << "]\n";
  }
}


int main() {
  std::vector<std::pair<int, int>> intervals;
  intervals = {{1, 4}, {7, 10}, {3, 5}};
  assert(sum_intervals(intervals) == 7);

  intervals = {{1, 5}, {6, 10}};
  assert(sum_intervals(intervals) == 8);

  intervals = {{0, 20}, {-100000000, 10}, {30, 40}};
  assert(sum_intervals(intervals) == 100000030);
  std::cout << "tests passed\n";
  return 0;
}
