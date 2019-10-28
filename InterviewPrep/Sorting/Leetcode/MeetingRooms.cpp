#include <iostream>
#include <vector>
using namespace std;

class interval {
public:
  int start;
  int end;
  interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

bool compare(interval *i1, interval *i2) {
  return i1->end < i2->end;
}

class Solution
{
public:
  bool canAttendMeetings(vector<vector<int>> &intervals)
  {
      interval **arr = new interval*[intervals.size()];
      for(int i = 0; i < intervals.size(); i++) {
          arr[i] = new interval(intervals[i][0], intervals[i][1]);
      }
      sort(arr, arr + intervals.size(), compare);
      for(int i = 1; i < intervals.size(); i++) {
          if(arr[i]->start < arr[i-1]->end) return false;
      }
      return true;
  }
};


int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}
