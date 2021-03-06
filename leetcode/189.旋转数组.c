/*
 * @lc app=leetcode.cn id=189 lang=c
 *
 * [189] 旋转数组
 *
 * https://leetcode-cn.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (39.34%)
 * Likes:    417
 * Dislikes: 0
 * Total Accepted:    79.7K
 * Total Submissions: 202.3K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,4,5,6,7] 和 k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右旋转 1 步: [7,1,2,3,4,5,6]
 * 向右旋转 2 步: [6,7,1,2,3,4,5]
 * 向右旋转 3 步: [5,6,7,1,2,3,4]
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-1,-100,3,99] 和 k = 2
 * 输出: [3,99,-1,-100]
 * 解释: 
 * 向右旋转 1 步: [99,-1,-100,3]
 * 向右旋转 2 步: [3,99,-1,-100]
 * 
 * 说明:
 * 
 * 
 * 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
 * 要求使用空间复杂度为 O(1) 的 原地 算法。
 * 
 * 
 */

// @lc code=start


void rotate(int* nums, int numsSize, int k){

    int a[numsSize];
    for (int i = 0; i < numsSize; i++)
    {
        /* code */
        a[(k+i)%numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; i++)
    {
        /* code */
        nums[i] = a[i];
    } 
}

void rotate(int* nums, int numsSize, int k){

    for (int i = 0; i < k; i++)
    {
        int lastNum = nums[numsSize-1];
        for (int j = 0; j < numsSize; j++)
        {
            int firstNum = nums[j];
            nums[j] = lastNum;
            lastNum = firstNum;
        }
        
    }
}

void rotate(int* nums, int numsSize, int k){
    k %= numsSize;
    Reversal(nums,0,numsSize-1);
    Reversal(nums,0,k-1);
    Reversal(nums,k,numsSize-1);
} 

void Reversal(int* nums,int StatrIndx,int EndIndex){

    while(StatrIndx < EndIndex){ 
		int startNum = nums[StatrIndx];
		nums[StatrIndx] = nums[EndIndex];
		nums[EndIndex] = startNum;
		StatrIndx++;
		EndIndex--;
	}
}
// @lc code=end

