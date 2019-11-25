/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (58.33%)
 * Likes:    722
 * Dislikes: 0
 * Total Accepted:    142.7K
 * Total Submissions: 244.5K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if(l1 == NULL){
        return l2;
    }
    if (l2 == NULL){
        return l1;
    } 
    struct ListNode *pNode = l1;
    while (pNode->next != NULL)
    {
        pNode = pNode->next;
    }
    pNode->next = l2;
    struct ListNode *head = l1;
    struct ListNode *end = NULL;
    while (head != end)
    {
        while(head->next != end){
            if (head->next->val < head->val)
            {
                int data = head->next->val;
                head->next->val = head->val;
                head->val = data;
            }
            head = head->next;
        }
        end = head;
        head = l1;
    }
    return l1;
}

// @lc code=end
