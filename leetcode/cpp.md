# cpp
## tips
* size_t 不是适合做双指针比较，因为非负的原因
* [ ] 字符串排序 sort(t.begin(),t.end());
'''
static bool cmp(pair<int, int>& m, pair<int, int>& n) {
  return m.second > n.second;
}
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
'''

## string
* str.push_back(char a);
* [ ] str.substr(pos, len);
## set
* set.insert(vec.begin(), vec.end());
## priorty_queue

*
'''
struct Status {
  int val;
  ListNode *ptr;
  bool operator < (const Status &rhs) const {
    return val > rhs.val;
  }
};

priority_queue <Status> q;
'''
* pq.push();
* pq.pop();
* pq.top();
* pq.size();
* [ ] pq.empty();
