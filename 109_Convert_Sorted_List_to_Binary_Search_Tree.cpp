#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        
        
        ListNode* mid = findMid(head);
        
        TreeNode* root;
        root->val = mid->val;
        
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
    
    ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast = head;
        //slow=head;
        //fast=head;
        ListNode* pre = slow;
        
        /*
            1,2,  3   ,4,5 ,(null)
            s
            f
            
              s
                  f
                  
                  s
                         f
        */
        
        while(fast && fast->next!=NULL){ //小心fast ==NULL也要考慮進去
            fast=fast->next->next;
            pre=slow;
            slow=slow->next;
        }
        pre->next=NULL;
        return slow;
        
    }
    
    
};


int main(){
    
    ListNode* t;
    t->val=1;
    for(int i=2;i<10;i++){
        ListNode* tt;
        tt->val=i;
        tt->next=t;
        t=tt;
    }
    
    Solution ans;
    TreeNode* aa = ans.sortedListToBST(t);
    
    
    
    return 0;
}
