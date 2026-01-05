#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 //adding two numbers that are represented in linked list
 //time complexity : O(max(n , m)) {n -> length of first linked list , m -> length of second linked list}
 //space complexity : O(1) {excluding the space used to return answer}


 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* newList = new ListNode(-1);
        ListNode* temp = newList;

        int carry = 0;

        while(temp1 != NULL && temp2 != NULL){
            int sum = temp1->val + temp2->val + carry;

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            temp->next = newNode;
            temp = newNode;

            temp1 = temp1->next;
            temp2 = temp2->next;

        }

        while(temp1 != NULL){
            int sum = temp1->val + carry;

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            temp->next = newNode;
            temp = newNode;

            temp1 = temp1->next;
        }

        while(temp2 != NULL){
            int sum = temp2->val + carry;

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            temp->next = newNode;
            temp = newNode;

            temp2 = temp2->next;
        }

        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }

        return newList->next;
    }