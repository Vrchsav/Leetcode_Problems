/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    void linklist_to_array(ListNode* list1,vector<int>&arr){
        while(list1){
            arr.push_back(list1->val);
            list1=list1->next;
        }
    }

     void merge(vector<int>&nums,int low,int high,int mid){
        vector<int>ans;
        int i=low;
        int j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]>nums[j]){
                ans.push_back(nums[j]);
                j++;
            }
            else{
                ans.push_back(nums[i]);
                i++;
            }
        }
        while(i<=mid ){
            ans.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            ans.push_back(nums[j]);
            j++;
        }
        for (int k = 0; k < ans.size(); k++) {
            nums[low + k] = ans[k];
        }
    
        return;
    }

    void merge_sort(vector<int>&arr,int low,int high){
        if(high<=low){
            return;
        }
        int mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);

    }
    ListNode* solve(vector<int>arr){
        
        ListNode* dummy =new ListNode();
        ListNode*x=dummy;
        for(int i=0;i<arr.size();i++){
            ListNode* temp =new ListNode(arr[i]);
            x->next=temp;
            x=temp;
        }
        return dummy->next;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>arr;
        linklist_to_array(list1,arr);
        linklist_to_array(list2,arr);
        int n=arr.size()-1;
        merge_sort(arr,0,n);
        ListNode* ans=solve(arr);
        return ans;

    }
};