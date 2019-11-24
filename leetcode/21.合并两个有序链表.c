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
    //感谢题解,再研究研究
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    struct ListNode *p = l1;
    struct ListNode *q;
    while (p->next != NULL)
        p = p->next;

    p->next = l2;
    //冒泡排序排列val值(看的题解)
    int temp;
    for (p = l1; p; p = p->next)
    {
        struct ListNode *ptr;
        for (q = p->next; q; q = q->next)
        {
            ptr = p;
            if (ptr->val > q->val)
            {
                temp = q->val;
                q->val = p->val;
                p->val = temp;
            }
            else
            {
                ptr = q;
            }
        }
    }
    return l1;
}

// @lc code=end
