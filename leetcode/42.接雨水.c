/*
 * @lc app=leetcode.cn id=42 lang=c
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (47.10%)
 * Likes:    687
 * Dislikes: 0
 * Total Accepted:    38.8K
 * Total Submissions: 82.3K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */

// @lc code=start

int trap(int *height, int heightSize)
{
    if(height == NULL || heightSize <= 1){
        return 0;
    }
    int first = 0;
    int last = heightSize - 1;
    int fistMax = height[first];
    int lastMax = height[last];
    int res = 0;
    while(first < last){
        if(height[first] < height[last]){
            if(height[first] < fistMax){
                res += fistMax - height[first];
            }else{
                fistMax = height[first];
            }
            first++;
        }else{
            if(height[last] < lastMax){
                res += lastMax - height[last];
            }else{
                lastMax = height[last];
            }
            last--;
        }
    }
    return res;
} 

// @lc code=end
