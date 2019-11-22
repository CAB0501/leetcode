/*
 * @lc app=leetcode.cn id=1 lang=csharp
 *
 * [1] 两数之和
 */

// @lc code=start
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var dic = new Dictionary<int,int>();
        for(int i = 0; i < nums.Length; i++){
            int temp = target - nums[i];
            if(dic.ContainsKey(temp)){
                return new int[] {i,dic[temp]};
            }
            dic[nums[i]] = i;
        }
        return new int[]{};
    }
}
// @lc code=end

