#include<iostream>
#include<vector>

struct ListNode {
   int val;
    ListNode *next;
   ListNode() : val(0), next(nullptr) {}    
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//merging two sorted list
//TC : O(N + M) {N -> length of list1 , M -> length of list2}
//SC : O(N + M) 

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* newList = new ListNode(-1);
        ListNode* temp = newList;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val <= temp2->val){
                ListNode* newNode = new ListNode(temp1->val);
                temp->next = newNode;
                temp=newNode;

                temp1=temp1->next;
            }
            else{
                ListNode* newNode = new ListNode(temp2->val);
                temp->next = newNode;
                temp=newNode;

                temp2=temp2->next;
            }
        }

        while(temp1 != NULL){
            ListNode* newNode = new ListNode(temp1->val);
            temp->next = newNode;
            temp=newNode;

            temp1=temp1->next;
        }

        while(temp2 != NULL){
            ListNode* newNode = new ListNode(temp2->val);
            temp->next = newNode;
            temp=newNode;

            temp2=temp2->next;
        }

        return newList->next;
    }