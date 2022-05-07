/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL, *output = NULL;
    int ten_num = 0, l1_num = 0, l2_num = 0;
    bool l1_zero_bit = false, l2_zero_bit = false;

    head = output = malloc(sizeof(struct ListNode));

    do {
        if (l1_zero_bit)
            l1_num = 0;
        else
            l1_num = l1->val;
        if (l2_zero_bit)
            l2_num = 0;
        else
            l2_num = l2->val;
        output->val = l1_num + l2_num + ten_num;

        ten_num = output->val / 10;
        output->val = output->val % 10;

        // check l1 whether it's end or not
        if (l1->next == NULL) {
            l1_zero_bit = true;
        } else {
            l1 = l1->next;
        }

        // check l2 whether it's end or not
        if (l2->next == NULL) {
            l2_zero_bit = true;
        } else {
            l2 = l2->next;
        }

        // check function whether it's end or not
        if ((l1->next == NULL) && (l2->next == NULL) && !ten_num) {
            output->next = NULL;
            break;
        } 

        // go to next node
        output->next = malloc(sizeof(struct ListNode));
        output = output->next;
    } while (1);
    
    return head;
}
