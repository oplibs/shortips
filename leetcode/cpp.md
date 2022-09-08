# cpp
## tips
* size_t 不是适合做双指针比较，因为非负的原因
* 字符串排序 sort(t.begin(),t.end());
'''
static bool cmp(pair<int, int>& m, pair<int, int>& n) {
  return m.second > n.second;
}
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
'''

## string
* str.push_back(char a);
* str.substr(pos, len);
* int isalnum(int c);int  判断是不是字符+数字
* int tolower(int c); 转小写字母
## set
* set.insert(vec.begin(), vec.end());
## priorty_queue

*
'''
static bool cmp(pair<int, int>& m, pair<int, int>& n) {
  return m.second > n.second;
}
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
'''
* pq.push();
* pq.pop();
* pq.top();
* pq.size();
* pq.empty();
* priority_queue<int, vector<int>, greater<int>> qg; //小顶堆
* priority_queue<int, vector<int>, less<int>> qg; //大顶堆
