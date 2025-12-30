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

//detection of a cycle in a linked list
//time complexity : O(N)
//space complexity : O(1)

bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }

        return false;
    }