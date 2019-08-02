//
// Created by 44811 on 2019/4/14.
//
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode res, *p = &res;
    res.next = NULL;

    while (l1 != NULL || l2 != NULL) {
        struct ListNode *node = malloc(sizeof(*node));
        node->next = NULL;
        p->next = node;
        p = node;
        if (l1 != NULL) {
            if (l2 != NULL) {
                if (l1->val < l2->val) {
                    node->val = l1->val;
                    l1 = l1->next;
                } else {
                    node->val = l2->val;
                    l2 = l2->next;
                }
            } else {
                node->val = l1->val;
                l1 = l1->next;
            }
        } else {
            node->val = l2->val;
            l2 = l2->next;
        }
    }

    return res.next;
}


int main() {
    struct ListNode a1;
    struct ListNode a2;
    struct ListNode a3;
    struct ListNode b1;
    struct ListNode b2;
    struct ListNode b3;
    a1.val = 1;
    a2.val = 2;
    a3.val = 3;
    a1.next = &a2;
    a2.next = &a3;
    a3.next = NULL;
    b1.val = 1;
    b2.val = 3;
    b3.val = 4;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = NULL;
    struct ListNode *l = mergeTwoLists(&a1, &a2);
    while (l) {
        printf("%d ", l->val);
        l = l->next;
    }
    return 0;
}