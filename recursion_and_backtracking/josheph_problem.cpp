class Node {
public:
    Node* next;
    int val;

    Node(int val) : val(val), next(NULL) {}
};


class Solution {
  public:
  
    int findIndex(int n , int k){
        if(n==1) return 0;
        
        int ind = findIndex(n-1 , k);
        ind = (ind+k)%n;
        return ind;
    }
    int josephus(int n, int k) {
        // code here
    //  Node *temp = new Node(1);
    // Node *head = temp;
    // for(int i = 2; i <= n; i++) {
    //     Node* newTemp = new Node(i);
    //     temp->next = newTemp;
    //     temp = temp->next;
    // }
    // temp->next = head;


    // while(temp != temp->next) {
    //     int p = k - 1;
    //     while(p--) {
    //         temp = temp->next;
    //     }
    //     Node* curr = temp->next;
    //     temp->next = curr->next;
    //     delete curr;
    // }
    // int ans = temp->val;
    // delete temp;
    // return ans;
    
    
    
    int result = findIndex(n , k);
    return result+1;
    }
};