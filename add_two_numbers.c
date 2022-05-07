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

    while (1) {
        l1_num = l1_zero_bit ? 0: l1->val;
        l2_num = l2_zero_bit ? 0: l2->val;
        output->val = l1_num + l2_num + ten_num;

        ten_num = output->val / 10;
        output->val = output->val % 10;

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;

        // go to next node
        if (!l1 && !l2 && !ten_num) {
            output->next = NULL;
            break;
        } else {
            output->next = malloc(sizeof(struct ListNode));
            output = output->next;
        }

        // check l1 whether it's end or not
        l1_zero_bit = l1? false: true;

        // check l2 whether it's end or not
        l2_zero_bit = l2? false: true;

    }
    
    return head;
}
