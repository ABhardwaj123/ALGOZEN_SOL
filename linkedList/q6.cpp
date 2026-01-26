#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;

        while(temp != NULL){
            length++;
            temp = temp->next;
        }

        int posi = length - n;
        if(posi == 0){
            if(length == 0){
                return NULL;
            }else{
                return head->next;
            }
        }

        temp = head;

        while(posi - 1 != 0){
            posi--;
            temp=temp->next;
        }

        if(temp->next->next == NULL){
            temp->next = NULL;
        }else{
            temp->next = temp->next->next;
        }

        return head;
    }