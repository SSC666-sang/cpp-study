//题目一
/*输入：
nums = [2, 7, 11, 15], target = 9
输出：
[0, 1]
解释：
因为 nums[0] + nums[1] == 9 ，返回[0, 1] 。*/
/*#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap; // 1. 定义哈希表  
        for (int i = 0; i < nums.size(); ++i) { // 2. 遍历数组
            int complement = target - nums[i]; // 3. 计算需要找的补数           
            // 4. 检查补数是否在哈希表中
            if (hashMap.find(complement) != hashMap.end()) {
                return { hashMap[complement], i }; // 5. 找到就返回下标
            }
            hashMap[nums[i]] = i; // 6. 没找到就把当前元素存入哈希表
        }
        return {};
    }
};
拿 ?nums = [2, 7, 11, 15]，target = 9? 演示

先明确两个变量含义

- complement?：和当前数字相加等于9的另一个数

- hashMap?：只存放已经遍历过的旧数字*********

- i?：当前正在遍历的数字下标

第一轮循环 i = 0，当前数字 nums[i] = 2

1.?计算需要找的数：?9 - 2 = 7

2.?去哈希表里找7，此时表里空空的，没找到

3.?所以?if?里面的return不会执行

4.?执行存数据：?hashMap[2] = 0
现在哈希表记录：数字2 对应下标0

第二轮循环 i = 1，当前数字 nums[i] = 7

1.?计算需要找的数：?9 - 7 = 2

2.?去哈希表里找2，表里存在这个数，找到了

3.?进入if代码块

- hashMap[complement]? 就是数字2对应的下标：0

- i? 是当前数字7的下标：1

- 直接返回结果[0, 1]

4.?一旦return，函数直接结束，下面存数据的代码不会运行*/


//题目二
/*给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
示例:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

输出 : [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]*/
// 引入需要的头文件
/*#include<iostream>
#include <vector>   // 用于使用vector（动态数组）
#include <string>   // 用于使用string（字符串）
#include <unordered_map> // 用于使用unordered_map（哈希表）
#include <algorithm> // 用于使用sort（排序函数）
using namespace std; // 使用std命名空间，避免每次写std::
class Solution { // 定义Solution类，这是LeetCode题目的常规写法
public:
    // 定义主函数groupAnagrams，参数是字符串数组strs，返回二维字符串数组
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 定义哈希表groups
// key：排序后的字符串（作为异位词的统一标识）
// value：该组异位词的原始字符串列表
        unordered_map<string, vector<string>> groups;
        // 遍历输入的每个字符串s（引用传递避免拷贝，更高效）
        for (string& s : strs) {
            // 复制原字符串s到key，不修改原字符串
            string key = s;
            // 对key的字符进行排序
            sort(key.begin(), key.end());
            // 把原字符串s加入到key对应的分组中
            groups[key].push_back(s);
        }
        // 定义结果二维数组
        vector<vector<string>> result;
        // 遍历哈希表中的每一对（key, 分组列表）
        for (auto& pair : groups) {
            // 把每个分组列表添加到结果中
            result.push_back(pair.second);
        }
        // 返回最终结果
        return result;
    }
};
int main()
 {
     // 创建解题对象
     Solution sol;
     // 测试样例
     vector<string> testStr = {"eat","tea","tan","ate","nat","bat"};
     // 调用分组函数
     vector<vector<string>> ans = sol.groupAnagrams(testStr);
     // 控制台打印结果
     cout<< "异位词分组结果：" <<endl;
     for (auto& group : ans)
     {
         for (string& word : group)
         {
             cout << word << "  ";
         }
         cout << endl;
     }
     return 0;}*/

//题目三
/*给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
示例 1：

输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。*/
/*#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;
        
        for (int num : numSet) {
            // 只有当num是序列起点时才开始统计
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentLen = 1;
                
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLen++;
                }
                
                maxLen = max(maxLen, currentLen);
            }
        }
        
        return maxLen;
    }
};*/