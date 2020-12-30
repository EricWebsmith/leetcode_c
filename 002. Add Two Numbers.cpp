#include <iostream>



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode l3_head;
        ListNode* l3 = &l3_head;
        int carry=0;
        while(l1 || l2){
            int v1 = 0;
            if (l1){
                v1 = l1->val;
                l1 = l1->next;
            }
            int v2 = 0;
            if(l2){
                v2 = l2->val;
                l2 = l2->next;
            }

            int v3=v1+v2+carry;
            if (v3 > 10){
                carry = 1;
                v3 = v3/10;
            }
            else{
                carry=0;
            }
            l3->val = v3;
        }

        if(carry){
            l3->next = new ListNode(carry);
        }

        return &l3_head;
    }

    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        ListNode l3_head;
        ListNode* l3 = &l3_head;
        int carry=0;
        while(l1 || l2){
            int v1 = 0;
            if (l1){
                v1 = l1->val;
                l1 = l1->next;
            }
            int v2 = 0;
            if(l2){
                v2 = l2->val;
                l2 = l2->next;
            }

            int v3=v1+v2+carry;
            if (v3 >= 10){
                carry = 1;
                v3 = v3 % 10;
            }
            else{
                carry=0;
            }
            l3->next = new ListNode(v3);
            l3 = l3->next;
        }

        if(carry){
            l3->next = new ListNode(carry);
        }

        return l3_head.next;
    }

    int main(){

        ListNode l1_head;
        ListNode l2_head;
        ListNode* l1 = &l1_head;
        ListNode* l2 = &l2_head;
        l1->val = 1;
        l1->next = new ListNode();
        l1 = l1->next;
        l1->val = 2;

        l2->val = 1;
        l2->next = new ListNode();
        l2 = l2->next;
        l2->val = 2;

        ListNode * l3 = addTwoNumbers(&l1_head, &l2_head);

    }    