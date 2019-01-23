#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode *resList = malloc(sizeof(struct ListNode));
    struct ListNode *currResNode = resList;
    currResNode->next = NULL;
    int carry = 0;
    while (l1 || l2) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
        }
        if (l2) {
            sum += l2->val;
        }
        currResNode->val = sum % 10;
        carry = sum / 10;
        if ((l1 && l1->next) || (l2 && l2->next) || carry) {
            struct ListNode *newNode = malloc(sizeof(struct ListNode));
            newNode->val = 0;
            newNode->next = NULL;
            currResNode->next = newNode;
        }
        currResNode = currResNode->next;
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    if (carry) {
        currResNode->val = carry;
    }
    return resList;
}

int main(void)
{
    int n1[] = {2, 4, 3};
    int n2[] = {5, 6, 4};
    struct ListNode *l1, *l2;
    struct ListNode *c;
    l1 = malloc(sizeof(struct ListNode));
    l2 = malloc(sizeof(struct ListNode));

    c = l1;
    for (int i = 0; i < 2; i++) {
        c->val = n1[i];
        c->next = malloc(sizeof(struct ListNode));
        c = c->next;
    }
    c->val = n1[2];
    c->next = NULL;

    c = l2;
    for (int i = 0; i < 2; i++) {
        c->val = n2[i];
        c->next = malloc(sizeof(struct ListNode));
        c = c->next;
    }
    c->val = n2[2];
    c->next = NULL;
    struct ListNode *resNode = addTwoNumbers(l1, l2);
    while (resNode) {
        printf("%d\n", resNode->val);
        resNode = resNode->next;
    }
    return 0;
}

