#include<iostream>
#include<stdlib.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//reversing a linked list
//time complexity : O(N)
//space complexity : O(1)


ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;

        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* front = NULL;

        while(temp != NULL){
            front = temp->next;
            temp->next = prev;

            prev = temp;
            temp=front;
        }

        return prev;
    }