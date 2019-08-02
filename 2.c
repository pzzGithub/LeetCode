//
// Created by 44811 on 2019/4/21.
//
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    int uper = 0;
    struct ListNode res, *tmp, *p = &res;
    while (1) {
        tmp = malloc(sizeof(struct ListNode));
        if (l1 == NULL && l2 == NULL) {
            if (uper == 1) {
                tmp->val = uper;
                uper = 0;
            } else
                break;
        } else {
            if (l1 == NULL) {
                if (l2->val + uper >= 10) {
                    tmp->val = l2->val + uper - 10;
                    uper = 1;
                } else {
                    tmp->val = l2->val + uper;
                    uper = 0;
                }
                l2 = l2->next;
            } else if (l2 == NULL) {
                if (l1->val + uper >= 10) {
                    tmp->val = l1->val + uper - 10;
                    uper = 1;
                } else {
                    tmp->val = l1->val + uper;
                    uper = 0;
                }
                l1 = l1->next;
            } else {
                if (l1->val + l2->val + uper >= 10) {
                    tmp->val = l1->val + l2->val + uper - 10;
                    uper = 1;
                } else {
                    tmp->val = l1->val + l2->val + uper;
                    uper = 0;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        tmp->next = NULL;
        p->next = tmp;
        p = p->next;
    }
    return res.next;
}

int main() {
    struct ListNode a1;
    struct ListNode a2;
    struct ListNode b1;
    a1.val = 9;
    a2.val = 8;
    a1.next = &a2;
    a2.next = NULL;
    b1.val = 1;
    b1.next = NULL;
    struct ListNode *res = addTwoNumbers(&a1, &b1);
    while (res) {
        printf("%d ", res->val);
        res = res->next;
    }
    return 0;
}