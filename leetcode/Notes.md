# Contents

## question list ##

== questions ==
-: 暂时忽略
X: 偏基本功，注意边界条件和基本写法，适合快速复习
#: 偏基本功，可以从多种解法的角度来写。
*: coding熟悉，需要完整的写一遍
+: 重点复习，包括思路的考量

R: 抽时间细看
#: 利用leisuretime写一下
o: others

===med===
### 1-100 ###
1 [-] two sum: easy
2 [-] 两数相加: easy，对于多个链表操作的场景，可以考虑多用？：在while循环中简化写法
# q3
3 [X-#] 无重复字符的最长子串: DP的转换方程, 按照长度更新
4 [*] 寻找两个正序数组的中位数
# q5
5 [X] 最长回文子串:👍👍👍👍👍👍👍👍👍👍dp遍历顺序是初始字符串长度，也就是初始化条件是长度为1的子字符串，然后从长度为2的字符串判断走起（遍历到长度为len）。
6 [X] Z字形变换: Done用公式
7 [X] 整数反转,负数和corner case.
8 [ ]  字符串转换整数 (atoi)
9 [X]  数字回文，数字不用字符串stack的做法是构造这个数字。
10 [ ] ==========================有空再看
11 [X] 最多水的容器: ------------------贪心的分析方法，枚举后优化递进的方法。
12 [X] 数转罗马数字: ------------------区间的玩法。
13 [X] 数转罗马数字: ------------------区间的玩法。
14 [X] 最长公共前缀，可以简单看一下题解的说明
15 [X] 三数之和 : 16 18 注意终止条件，方便提速
16 [*] 接近的三数之和
17 [X] 电话号码的字母组合
18 [*] 四数之和
19 [X] 除链表的倒数第 N 个结点:
20 [-] 有效的括号.
21 [X] 合并两个有序链表
# q22
22 [*] 括号生成 dp
23 [ ] 合并K个升序链表
# q递归链表
24 [+] 两两交换链表中的节点 递归的设计方法:交换链表中的节点
25 [+] K 个一组翻转链表: 递归的设计方法：交换链表中的节点
# q26
26 [X] 基本功：删除有序数组中的重复项
27 [X] 基本功：同27
28 [ ] 实现 strStr()
29 [-] 两数相除: 有空就看看吧，定义比较麻烦
# q30
30 [#] 串联所有单词的子串：tips值得看一下滑动窗口的不同尺度（字符，单词），降低复杂度
31 [ ] 下一个排列 =================没看懂
32 [+] 最长有效括号，状态：+++++++++++++++++++++了解一下遍历顺序
# q33
33 [X] 搜索旋转排序数组:下一个排列 --------快速看看边界条件
# q34
34 [+] 有重复元素排序数组中查找元素的第一个和最后一个位置，结合binarysearch看一下设计跳转的条件
'''
int binarySearch(vector<int>& nums, int target, bool lower) {
  int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
  while (left <= right) {
    int mid = (left + right) / 2;
		// lower 控制了nums[mid]==target场景下的不同行为:
		// 搜寻左侧节点时，==的时候挪右侧指针，搜寻右侧节点时，==的时候挪左侧指针。
    if (nums[mid] > target || (lower && nums[mid] >= target)) {
      right = mid - 1;
      ans = mid;
    } else {
      left = mid + 1;
    }
  }
  return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
  int leftIdx = binarySearch(nums, target, true);
  int rightIdx = binarySearch(nums, target, false) - 1;
  if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
    return vector<int>{leftIdx, rightIdx};
  }
  return vector<int>{-1, -1};
}
'''
# q35
35 [ ] 查找可能不存在的有序数组，最关键的是一点是要记录当前挪动到mid指针的状态，并记录记录记录。
# q36
36 [X] ------------有效的数独，参考一下map的设计方法。
37 [ ] 解数独
38 [X] 外观数列-----最后一哆嗦
39 [X] 组合总和 -----参考一下分析方法而已
40 [X] 组合总和 II
41 [+] 缺失的第一个整数，可以看看分析，主要是终止条件。
42 [+] 接雨水
43 [X] 字符串相乘
44 [R] 通配符匹配
45 [X] [*] 跳跃游戏 II ----------------主要能达成最远和最大步数的差异，用来设置两个终止条件，还是要优化自己的思路。学习一下倒追算法 ([#55](#55))
46 [X] 排列 和组合的差异就是在于按照顺序遍历的时候，组合是按照选和不选做两种遍历，排列是每次选走随机一个，然后做组合。
47 [X] 排列 II
48 [X] 旋转图像:  注意转置，镜像都是操作一半的数据，并不是全员
49 [X] 母异位词分组，就是看看如何编码。
50 [ ] Pow(x, n)
51 [ ] N皇后
52 [ ] N皇后II
# q53
53 [X] 最大子数组和
54 [#] 螺旋矩阵
# q55
55 [*] 跳跃游戏: 最大到达点和步数要分别维护`
56 [*] 值得参考的写法： 先增加，根据iterate到的item去修改上一个，比在iterate的时候动态触发新增item更强一些.
57 [*] 插入区间
58 [X] 最后一个单词的长度
59 [X] 螺旋矩阵 II
60 [#] 排序序列-字典序
61 [X] 翻转链表: ---------------利用快慢指针的时候，快速指针寻尾的时候终止条件是fast->next != nullptr
62 [-] easy - 不同路径
63 [X] 不同路径 II
64 [-] easy - 最小路径和
65 [ ] 有效数字
66 [X] 加一：easy
67 [X] 二进制求和：easy - reverse这个helper
68 [ ] Text justification
69 [ ] X的平方根
70 [X] 爬楼梯
71 [ ] 简化路径
72 [X] 编辑距离
73 [X] 矩阵置零
# q74
74 [R] 检索二维矩阵
75 [X] 颜色分类: 最基础的方法容易，可以考虑熟悉一下
'''
具体地，我们使用一个指针 ptr 表示「头部」的范围，ptr 中存储了一个整数，表示数组 nums 从位置 00 到位置 ptr-1 都属于「头部」。ptr 的初始值为 00，表示还没有数处于「头部」。
在第一次遍历中，我们从左向右遍历整个数组，如果找到了 00，那么就需要将 00 与「头部」位置的元素进行交换，并将「头部」向后扩充一个位置。在遍历结束之后，所有的 00 都被交换到「头部」的范围，并且「头部」只包含 00。
在第二次遍历中，我们从「头部」开始，从左向右遍历整个数组，如果找到了 11，那么就需要将 11 与「头部」位置的元素进行交换，并将「头部」向后扩充一个位置。在遍历结束之后，所有的 11 都被交换到「头部」的范围，并且都在 00 之后，此时 22 只出现在「头部」之外的位置，因此排序完成。
'''
76 [ ] 最小覆盖子串
77 [*] 组合：看一下注释
78 [*] 子集：看一下和77的差异
79 [R] 单词搜索dfs 写法
# q80
80 [*] 删除有序数组中的重复项 II ([#q26](#q26)) https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/solution/shan-chu-pai-xu-shu-zu-zhong-de-zhong-fu-yec2/
2其实就是窗口长度的意思
def removeDuplicates(self, nums: List[int]) -> int:
    cur = 2
    for end in range(2, len(nums)):
        if nums[end] != nums[cur - 2]:
            nums[cur] = nums[end]
            curj += 1  //更新到下一个待更新的节点，所以才会支持上面两行中!=j-2其实就是窗口长度的意思，每次都更新到待更新地点，然后和窗口前的比较即可。
    return cur
81 [*] 搜索旋转排序数组 II 边界条件存在各种相等的情况，这个时候指针按照1个挪动
# q82
82 [ ] 删除排序链表中的重复元素 II
# q83
83 [X] 删除排序链表中的重复元素
84 [ ] 柱状图中的最大举行
85 [ ] 最大举行
86 [X] 分隔链表
87 [ ] 扰乱字符串
88 [X] 合并两个有序数组
89 [ ] 格雷编码
90 [ ] 子集 II
91 [X] 解码方法
92 [ ] 反转链表 II
93 [ ] 复原 IP 地址
94 [X] 二叉树中序遍历
95 [X] 不同的二叉搜索树 II =========================树的递归回溯的写法，可以当成参考模板进行复习。
96 [X] 不同的二叉搜索树
# q97
97 [*] 交错字符串
98 [*] 验证二叉搜索树 long long lastval = LONG_MIN;
99 [X] 恢复二叉搜索树
100 [X] 相同的树

93 [X] 验证二叉搜索树 ======================搜索树的中递归
94 [X] ============================== isBSTTree 容易写错, bst必然和遍历相关，所以状态比较可以从这个角度来说。
95 [X] 恢复二叉搜索树============================== 有两个元素错位了，写出来了，但是边界条件较为注意，一个是要注意遍历树是递归的，需要有个保险的方式终止循环。还有一个cornercase是最小值的问题（INT_MIN），注意画图确保前一个和后一个。另外就是手动画一下放错的两个元素相邻与不相邻的情况。

#### 101-200 ####
101 [X] 对称二叉树：快速复习一下写法，用递归的组合想问题
102 [X] 二叉树层序遍历：可以熟悉一下写法而已
103 [X] 二叉树的锯齿形层序遍历：基本同上
104 [X] 二叉树的最大深度
105 [ ] 从前序与中序遍历序列构造二叉树
106 [ ] 从中序与后序遍历序列构造二叉树
107 [X] 二叉树的层序遍历 II trickone
108 [X] 将有序数组转换为二叉搜索树
109 [ ] 有序链表转换二叉搜索树
110 [ ] 平衡二叉树
111 [ ] 二叉树最小深度
112 [-] 路径总和 easy
113 [-] 路径总和 II easy
114 [ ] 二叉树展开为链表
# q115
115 [*] 不同的子序列 dp
116 [X] 填充每个节点的下一个右侧节点指针 easy
117 [X] 填充每个节点的下一个右侧节点指针II easy 不用队列更快，所以实现中时间还是管用的
118 [X] 杨辉三角 easy
119 [X] 杨辉三角II easy
120 [X] 三角形最小路径和 ===========triangle 最小路径（注意写法）
121 [X] 买卖股票的最佳时机 写的小心些。
122 [X] 买卖股票的最佳时机II dp
123 [X] 买卖股票的最佳时机III dp
124 [*] 二叉树中的最大路径和=========细心的看一下
125 [-] 验证回文串 =====考虑two pointer，还有更麻烦一些的字符串isalnum tolower
# q126
126 [*] 单词接龙 II 图更好
127 [*] 单词接龙
# q128
128 [X] 最长连续序列 : 👍👍👍👍👍👍👍👍👍👍判断区间存在的方法比较好，先看看有没有前驱来确定是不是第一个元素，然后再去判断连续性，
129 [-] easy 求根节点到叶节点数字之和
130 [*] 被围绕的区域 ===dfs+bfs的标准写法
# q131
131 [*] 分割回文串: 回溯的写法, dp用来加速回文的判断过程
# q132
132 [*] 分割回文串 II :递推法对应的状态方程
133 [X] 克隆图: 练习一下遍历
134
135 [*] 分发糖果 *****************可以类比成双边限制条件下的策略。
136 [-] easy 出现一次的数字不会抑或
137
138
[#](#) q139
139 [X] 单词改写：dp 写一下: 注意一定要break，不然会被重复改写
141 [X] 环形链表
142
143 [ ] 熟悉一下写法吧
146 [ ] 好好学习一下
147:148 : ******************************** 链表排序大成 *********快慢指针、merge链表、分治***链表处理头节点可以用个dummyHeader临时处理一下。****** 需要好好想一下downTOTop的设计流程
150 [X] easy
# q151
151 [*] 反转字符串中的单词 *************官方写法写的很干净
'''
while left <= right:
    if s[left] != ' ':
        output.append(s[left])
    elif output[-1] != ' ':
        output.append(s[left])
    left += 1
'''
152 [X] dp, *******************注意状态转换别漏了
153 [ ] ] : 二分查找，注意边界条件
155 [ ] 设计设计设计设计
156 [-] 放弃
159 [*] twopointer，hashmap存位置,注意滑动窗口的模板。
160 [X] 相交链表： 看一下实现
161 [X] ] : 踏实的实现，cpp利用递归实现参数交换复制（switch）
162 [-] 这个条件很tricky nums[-1] = nums[n] = -∞
165 [ ] cpp的2 pointers实现split扫描
166
167 [-] EASY
169 [-] 多数元素 EASY 多数元素这个点可以考虑排序后，排在[n/2]的位置，这个点比较重要，👍👍👍👍👍👍👍👍👍👍有空看看Boyer-Moore 投票算法
171 [-] Excel 表列序号
172 [ ] ======== 定义sort函数:
173 [ ] 叉搜索树迭代器
174 [ ] 地下城游戏
175 [-] sql
176 [-] sql
177 [-] sql
178 [-] sql
179 [ ] 大数:******熟悉一下如何定义sort函数*******
180 [-] sql
187 [L] easy dna, 直接写
188 [ ] 买卖股票的最佳时机 IV
189 [X] ========= 数组挪动和反转的trick
190 [-] easy
192 [-] sql 统计词频
193 [-] bash 有效电话号码
194 [-] bash 转置文件
195 [-] bash 第十行
196 [-] sql 删除重复的电子邮箱
197 [-] sql 上升的温度
198 [ ] easy dp
199 [-] easy
200 [X] 岛屿数量

==== 2?? ====
201 [#] 数字范围按位与 整理公共前缀的方法不错。
202 [-] easy 快乐数
203 [X] easy 移除链表元素
# q204
204 [X] easy 计数质数 计数最好都考虑一下归纳或者dp
205 [X] easy 双向 同构字符串
206 [X] 翻转链表=========递归的思路
207 [X] 课程表 好好写一下topsort
209 [X] ***注意终止条件。
213 [X] 打家劫舍 II ====easy
215 [*] 数组中的第K个最大元素
217 [-] 重复元素
226 [X] 反转二叉树 ： 注意递归
229 [X] 多数元素 II ******注意边界条件
230 [X] 二叉搜索树中第K小的元素******注意递归如何有效终止。
231 [-] 2的n次幂
236 [*] 二叉树的最近公共祖先  ******** 看看递归的思路
237 [-] 删除链表中的节点
238 [ ] 单回忆一下
239 [ ] 滑动窗口最大值：
’‘’
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
        vector<int> results(nums.size()-k+1);
        //queue存的可是位置
        deque<int> maxqueue;
        //1. 先初始化，少放一个，这样在正式循环中可以补充数字。[0,k-1)
        for(int i=0; i < k-1; i++){
            while(maxqueue.size()>0 && nums[maxqueue.back()]<nums[i]){
                maxqueue.pop_back();
            }
            maxqueue.push_back(i);
            //printf("pos size top: %d %d %d %d\n", i, maxqueue.size(), maxqueue.front(),nums[maxqueue.front()]);
        }
        //2. 正式循环中可以补充数字.
        //   字符串循环区间是：[k-1, n)
        //   写入位置是(i-k+1,可以从初始点推导出来)
        for(int i=k-1; i < nums.size(); i++){
            while (maxqueue.size()>0 && nums[i]>nums[maxqueue.back()]){
                maxqueue.pop_back();
            }
            maxqueue.push_back(i);
            //printf("pos size top: %d %d %d %d\n", i, maxqueue.size(), maxqueue.front(),nums[maxqueue.front()]);
            while(maxqueue.front()<=(i-k)){
                maxqueue.pop_front();
            }
            //printf("set: %d %d %d\n", i-k, maxqueue.front(),nums[maxqueue.front()]);
            results[i-k+1]=nums[maxqueue.front()];
        }

        return results;
    }
};
‘’‘
240 [X] 二维有序矩阵的查找…………
241 [*] 为运算表达式设计优先级…………
242 [-] 有效的字母异位词： *********** hash与sort可以有效结合
243 [X] 最短单词距离，一遍扫描
246 [X] 中心对称数： size_t 不是适合做双指针比较，因为非负的原因
247 [X] 中心对称数 II：容易一些。
# q254
254 [*] 因子的组合
263 [-] 丑数 <=非丑数
# q264
264 [*] 丑数 II *************
266 [-] 回文排列
# q279
279 [X] dp, *******************注意状态转换别漏了
283 [-] 移动零： 注意corner cases
298 [X] ======注意cache
299 [X] ======简单记忆一下
300 [X] 最长递增子序列

==== 3?? ====
315 [*] 计算右侧小于当前元素的个数 ([#q315](#q315))
337 [*] 打家劫舍III
347 [X] 前K个高频元素
365 [X] ************* 再仔细理解一下搜索 *********************
394 [X] =================进出栈的算法流程再熟悉一下。
395 [*] 至少有 K 个重复字符的最长子串:=================dfs+分治（其实也是递归）

==== 4?? ====
401 [-] 二进制手表
404 [-] 左叶子之和 看看递归的写法
409 [-] 最长回文串
413 [X] 等差数列划分 dp的题意似乎有些歧义
437 [*] 路径总和 III 👍👍👍👍👍👍👍👍👍👍有没有root和前缀和的关系,还有递归的设计也很棒
#q448
448 [X] 找到所有数组中消失的数字 基础trick
461 [-] 汉明距离
462 [ ] 最少移动次数使数组元素相等 II
463 [-] 岛屿的周长
464 - 473 [ ]
474 [ ] 一和零
475 - 484 [ ]
485 [-] 最大连续 1 的个数
486 [ ] 预测赢家
487 [X] 最大连续1的个数 II： dp转化的思想需要验证一下（dp）
488 [ ] 祖玛游戏
489 [*] 扫地机器人： 可以check一下
490 [X] 迷宫 DFS BFS练习一下
491 [X] 递增子序列
492 [-] 构造矩形
493 [ ] 区间和
493 [*] 翻转对 ([#q493](#q493))
# q494
494 [*] 目标和 ：回溯的方法相对简单，转化的思想（dp）要debug一下
495 [X] easy
496 [X] 下一个更大的元素 I
497 [ ] 非重叠矩形中的随机点
498 [X] 对角线遍历还好
499 [ ] 迷宫III
500 [X] easy

=== 50? ===
501 [ ] binary search tree中序遍历其实就是从小到大排序遍历
502 [ ]  ????
503 [X] 用stack构建一个< >排序的方法......
543 [-] 二叉树的直径： 深刻理解递归
560 [X] 和为 K 的子数组 :注意这个优化策略，随着求前缀和直接判断结果，因为子区间的和意味着在某个位置i前面所有的元素已经决定了当前的解，所以随着前缀和的计算，已经可以统计已经满足需求的值了。
# q581
581 [X] 最短无序连续子数组, https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leet-yhlf/ 方法二没看懂
# q583
583 [X] 两个字符串的删除操作 dp

=== 60? ===
617 [-] 合并二叉树

# q1143
1143 [X]最长公共子串


## todo
* union find
* bfs
* dfs
* sort

* math
'''
#include <algorithm>
std::max
'''
==== cpp ====
* [X] 如何定制sort函数 sort(vector<?>.begin, vector<?>.end);

### 算法和实现方式
* 常见写法 128 [X] 最长连续序列 : 判断区间存在的方法比较好，先看看有没有前驱来确定是不是第一个元素，然后再去判断连续性，👍👍👍👍👍👍👍👍👍👍
* [ ] priorty_queue的用法 347
* 单调栈 496

### 基本功 ###
字符串和数组相同元素处理: ([#q151](#q151))
* merge sort

### 排列组合
* question list:

* 全排列-每个元素必须出现，每个元素没有重复，顺序不同算不同组合。
([#q46](#q46))
'''
// No need to using pos
void backtrack(candidates, results, item, int len){
  //结果剪枝
  if( xxx ){
    results.push_back(item);
    return;
  } else if (failed){
    return;
  }
  // 因为是排列，通过visited去重，避免重复出现，而且每次都从数组起始元素进行组合
  for(int i=0; i < len; i++){
    if(visited(candidate[i])){
      continue;
    }

    item.push_back(candidates[i]);
    visited[i]=true;
    // ?????????????????????后面结论待定：这里其实也可以把起始位置加一（位置是candidates中的位置），和visited等价，类似于：
    // ?????????????????????后面结论待定：backtrack(candidates, results, item, len); 不过这个时候for循环的起始值就变了
    backtrack(candidates, results, item, len);
    visited[i]=false;
    item.pop_back(candidates[i]);
  }
}
* 全排列-每个元素必须出现，元素有重复，顺序不同算不同组合，但是因为有重复元素，所以1，1等价于1，1。
([#q47](#q47))
保证在填第 idx 个数的时候重复数字只会被填入一次即可。而在本题解中，我们选择对原数组排序，保证相同的数字都相邻，然后每次填入的数一定是这个数所在重复数集合中「从左往右第一个未被填过的数字」，即如下的判断条件

** 一定要对元素进行排序
** i>0 && nums[i] == nums[i-1]表示在处理排在一起重复的元素
** !vis[i-1] 隐含了对顺序的限制，也就是必须vis[i-1]上一个元素被访问了再访问当前元素才行，这样可以去重
if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
    continue;
}

链接：https://leetcode.cn/problems/permutations-ii/solution/quan-pai-lie-ii-by-leetcode-solution/
https://leetcode.cn/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/

链接：https://leetcode.cn/problems/permutations-ii/solution/quan-pai-lie-ii-by-leetcode-solution/
/*vis[i]：当前数字是否出现过
 *如果当前数字与前一个数字相同（nums[i] == nums[i - 1]），
 *并且前一个数字还没有出现的话（vis[i - 1] == false），
 *[ ] 那么就不能选择当前数字（continue），
 *如果前面的数字已经出现过（vis[i] == true），则可以
 *选择当前数字
 */

* [ ] 组合: 元素可选可不选，无重复，顺序不重要
([#q77](#q77)) 选固定的元素组合，这道题特点是限定最小自己个数
([#q78](#q78)) 和77类似，只是终止条件不同
'''
void backtrack(candidates, results, item, int pos, int len){
  //结果剪枝
  if( cmp(pos, len) ){
    results.push_back(item);
    return;
  } else if (failed){
    return;
  }

  //不加某个元素
  backtrack(candidates, results, item, pos+1, len);
  //加某个元素
  item.push_back(candidates[pos]);
  backtrack(candidates, results, item, pos+1, len);
  item.pop_back(candidates[pos]);
}




* 组合出目标值，每个元素不限制选择次数，也可以不选，选取次数一样的时候为重复
void backtrack(candidates, results, item, int pos, int len){
  //结果剪枝
  if( xxx ){
    results.push_back(item);
    return;
  } else if (failed){
    return;
  }

  //这个循环保障了写法一里面的不增加当前元素的选项生效,不用单独再写一下不加这个当前元素的组合求解。
  // 重点是pos开始
  for(int i = pos; i < len; i++){
    item.push_back(candidates[pos]);
    // 错误:backtrack(candidates, results, item, pos+1, len);
    // 正确如下，从i开始,这里的i从pos开始表示对应的的元素可以选多次，每次回溯都是通过i++，这样就可以遍历某个值选从0到上限的各种情况从i开始
    backtrack(candidates, results, item, i, len);
    item.pop_back(candidates[pos]);
  }
}

/****************************  maybe wrong <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<</
<  某元素可以重复选取的组合: 顺序重要 ???????????
'''
void backtrack(candidates, results, item, int len){
  //结果剪枝
  if( xxx ){
    results.push_back(item);
    return;
  } else if (failed){
    return;
  }
  //这个循环保障从0开始，似乎就是排列了
  for(int i=0; i < len; i++){
    if(target is failed){
      continue;
    }

    item.push_back(candidates[i]);
    backtrack(candidates, results, item, len);
    item.pop_back(candidates[i]);
  }
}
/>>>>>>>>>>>>>>>>>>>>>>>>>>>>> maybe wrong ***********************************/
### 递归 ###
([#q递归链表](#q递归链表))

### binary search ###
* [X] 旋转后的检索方法。([#q33](#q33))
* [X] 如何在查找元素中有重复的场景下进行O(logN)类型的检索\如何处理等于条件下上下边界的调整方法，分成两段检索。([#q34](#q34)).
* [ ] 查找可能不存在元素的定位要注意。([#q35](#q35)).
* [ ] 二维快速检索复习一下边界条件 74 ([#74](#74))

#### 数组 ####

2数之和
3数之和
4数之和

#### 排序+双指针+滑动窗口 ####
滑动窗口的复习入口：   https://leetcode.cn/problems/longest-substring-without-repeating-characters/solution/hua-dong-chuang-kou-by-powcai/

([#q30](#q30))
#### 数组中重复
数组用buffer+双指针的位置迭代解决
([#q26](#q26)) ([#q80](#q80)) ([#q3](#q3))
#### 链表中重复
链表的搬家方式是改指针的链接方式，所以更麻烦一些
([#q82](#q82)) ([#q83](#q83))

### dfs bfs topsort union find ###
#### dfs ####
写法练习
79 基础练习
200 快速复习一下边界条件

#### 回溯 ####
([#q131](#q131))

#### bfs ####

#### topsort ####

#### union find ####


debug:
494

区间和:
493， 327
归并排序   看形状貌似是二叉树的后续遍历（也就是先处理左右子节点，在处理根节点，从这个角度类比比较合理）.
框架
‘’‘
那我先在excel上面登机一a
public class MergeSort {
    private int[] temp;

    public void sort(int[] nums) {
        temp = new int[nums.length];
        sort(nums, 0, nums.length - 1);
    }
    // 分
    private void sort(int[] nums, int lo, int hi) {
        if (lo == hi) return ;
        int mid = lo - (lo - hi) / 2;
        sort(nums, lo, mid);
        sort(nums, mid + 1, hi);
        merge(nums, lo, mid, hi);
    }
    // 治
    // 等价于两个有序数组合并 [lo..mid] 和 [mid+1..hi]
    private void merge(int[] nums, int lo, int mid, int hi) {
				//先把原始结果保存下来
        for (int i = lo; i <= hi; i++) temp[i] = nums[i];
        int cnt = lo;
        int i = lo, j = mid + 1;
				// 分别从数组的两个起始位置进行循环，开始形成排序
        while (i <= mid || j <= hi) {
            if (i > mid) nums[cnt++] = temp[j++];
            else if (j > hi) nums[cnt++] = temp[i++];
            else if (temp[i] <= temp[j]) nums[cnt++] = temp[i++];
            else nums[cnt++] = temp[j++];
        }
    }
}
链接：https://leetcode.cn/problems/count-of-range-sum/solution/by-lfool-pkli/

几个拓展参考link如下：
https://leetcode.cn/problems/count-of-range-sum/solution/by-lfool-pkli/

* 对q315的扩展
#q315
使用了count[]这个数组存储结果，初始化为0。
定义了新的数据结构记录原始位置和值的绑定关系。
只有在merge函数内部修改count值，因为sort函数是个分治过程，实际的元素移动和大小判断都在merge函数中进行。
由于是需要得出小于目标值的数量，因此每次都在更新前半段移动坐标的时候去更新count值，因为移动前半段的坐标表示小于某个分界线的情况由变化。
重点问题：这里使用+=更新count值，同时会发现每次都是增加的右侧区间的偏移，也就是每次把右侧变化（也就是新纳入到已经排序数据中的外来户进行一下登记，左侧已经排序好的不需要增加），所以避免了重复计数

#q493
重点问题：这里使用+=更新最大值，同时会发现每次都是增加的右侧区间的偏移，也就是每次把右侧变化（也就是新纳入到已经排序数据中的外来户进行一下登记+1，左侧已经排序好的不需要增加），所以避免了重复计数

’‘’
新手记住这句话，线段树一般在区间求和，最大最小值有用，而树形数组则是查询前缀和的利器。我觉得不要排斥学习新的数据结构，而每次学新的时候，要仔细体会其妙处，反向思考其特别之处，能用于什么样的场景，举一反三，然后脑海里留一个这样的印象就够了。


# 最优化策略的一些tips
数组、字符串去掉某些元素的最小（大）值：检测到下降就去除掉前一个元素

# trick
## 基数相关
👍👍👍👍👍👍👍👍👍👍([#q448](#q448))

## 链表
* 快慢指针
* 两个链表来回指向判断交叉
* 新建一个的dummy的头
* [ ] 处理两个链表，可以在代码中通过？：字符来优化算法的写法，避免循环后不同链表长度不一的各种corner cases ([#q2](#q2))



## 套题
### 递归
101 对称二叉树

### 路径和
112 路径总和 easy
113 路径总和 II easy
437 路径总和 III 👍👍👍👍👍👍👍👍👍👍有没有root和前缀和的关系
666 路径总和 IV

跟进
4
10
215
416
494
581 [X] 最短无序连续子数组, https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leet-yhlf/ 方法二没看懂
### 背包问题的汇总
💪💪💪💪💪💪💪💪💪💪💪💪 https://github.com/CyC2018/CS-Notes/blob/master/notes/Leetcode%20%E9%A2%98%E8%A7%A3%20-%20%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92.md#0-1-%E8%83%8C%E5%8C%85
[q416](q416) q494 q474 q322 q518 q139 q377
