#include<iostream>

using namespace std;

class ListNode {
  public:
  int val;
  ListNode * next;

  ListNode() {
    val = 0;
    next = NULL;
  }
  ListNode(int d) {  
    val = d;
  }
};

class SinglyLinkedList {
  public:
    ListNode * head;

  SinglyLinkedList() {
    head = NULL;
  }
  SinglyLinkedList(ListNode * n) {
    head = n;
  }

  // 2. Append a ListNode to the list
  void appendListNode(ListNode * n) {
  
      if (head == NULL) {
        head = n;
        cout << "ListNode Appended" << endl;
      } else {
        ListNode * ptr = head;
        while (ptr -> next != NULL) {
          ptr = ptr -> next;
        }
        ptr -> next = n;
        cout << "ListNode Appended" << endl;
      }   

  }
  
  void printList() {
    if (head == NULL) {
      cout << "No ListNodes in Singly Linked List";
    } else {
      cout << endl << "Singly Linked List Values : ";
      ListNode * temp = head;

      while (temp != NULL) {
        cout << "("<< temp -> val << ")--> ";
        temp = temp -> next;
      }
    }
  }

    ListNode *detectCycle() {
        if(head == NULL || head->next == NULL) return NULL;
        
        
        ListNode *ptr2 = head;
        ListNode *ptr = head->next;
        ListNode *temp = head->next->next;
        if(temp == NULL) return NULL;
        if(ptr->next->next == ptr) return ptr->next;

        
        while(temp->next!= NULL){
           
            ListNode *extra;
            ptr->next=ptr2;
            extra=ptr;
            ptr2=ptr;

            ptr=temp;
            if(temp == NULL) return NULL;
           
            

            while(extra!=head){
                extra=extra->next;
                if(extra==temp || extra == ptr) return extra;
                
            }
             temp= temp->next;
                        
        }
        
        return NULL;

    }

    void loop(int d){
        ListNode* ptr = head;
        while(ptr->val!=d){
            ptr=ptr->next;
        }
       ListNode* ptr2 = ptr;
       while(ptr2->next!=NULL){
            ptr2=ptr2->next;
        }
        ptr2->next=ptr;

       cout<<"looped \n";

    }

};

int main() {

  SinglyLinkedList s;

  int d;
  
  cout<<" enter the number of ListNode: \n";
  int m; cin>>m;

  for(int i =0 ; i<m;++i){
       ListNode * n = new ListNode();
       cin>>d;
       n->val= d;
       s.appendListNode(n);
  }
  cout<<endl;
  int ld;
  cin>>ld; 
  s.loop(ld);

  ListNode* nm = s.detectCycle();
  cout<<endl;
  cout<<nm->val;


     //  s.printList();
   //   system("cls");

  return 0;
}


 


// //#include<bits/stdc++.h>
// #include<iostream>
// #include<vector>

// using namespace std;

// class ListNode {
//   public:
//   int val;
//   ListNode * next;

//   ListNode() {
//     val = 0;
//     next = NULL;
//   }
//   ListNode(int d) {  
//     val = d;
//   }
// };

// class SinglyLinkedList {
//   public:
//     ListNode * head;

//   SinglyLinkedList() {
//     head = NULL;
//   }
//   SinglyLinkedList(ListNode * n) {
//     head = n;
//   }

//   // 2. Append a ListNode to the list
//   void appendListNode(ListNode * n) {
  
//       if (head == NULL) {
//         head = n;
//         cout << "ListNode Appended" << endl;
//       } 
//       else {
//         ListNode * ptr = head;
//         while (ptr -> next != NULL) {
//           ptr = ptr -> next;
//         }
//         ptr -> next = n;
//         cout << "ListNode Appended" << endl;
//       }
//   }  

//      void deleteNode(ListNode* node){
//         ListNode *slow,*fast;
//         slow =node;
//         if(slow->next==NULL)return ;
//         fast=slow->next;
//         slow->val=fast->val;
//         slow->next=fast->next;
//     }   

 
  
//   void printList() {
//     if (head == NULL) {
//       cout << "No ListNodes in Singly Linked List";
//     } else {
//       cout << endl << "Singly Linked List Values : ";
//       ListNode * temp = head;

//       while (temp != NULL) {
//         cout << "("<< temp -> val << ")--> ";
//         temp = temp -> next;
//       }
//     }
//   }


//    void takeinput(vector<int>&v){
//     int m = v.size();
//      for(int i =0 ; i<m;++i){
//        ListNode * n = new ListNode();
//        n->val= v[i];
//        appendListNode(n);
//       }
//      cout<<endl;
//    }


//   ListNode * findd(int v){
//     if(head==NULL)return head;
//     ListNode * nd = head;

//     while(nd->next!=NULL){
//       if(nd->val==v){
//         return nd;
//       }
//       nd=nd->next;
//     }

//     return NULL;
//   }
// };

// int main() {

//   SinglyLinkedList s;

//   int d;
  
//   cout<<" enter the number of Node: \n";
//   int m; cin>>m;
  
//   vector<int>vec;
//   cout<<"enter ll elements \n";
//   for(int i =0 ; i<m; ++i){
//     int x; cin>>x;
//     vec.push_back(x);
//   }
//   cout<<"\n";
  
//   s.takeinput(vec);
 


//  cout<<" enter node value to be deleted \n";
//  int dele; cin>>dele;

//  ListNode *pointer_to_dele_node = s.findd(dele);

//  s.deleteNode(pointer_to_dele_node);

//  s.printList();



//   return 0;
// }

