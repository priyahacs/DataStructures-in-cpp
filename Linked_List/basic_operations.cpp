#include<iostream>
using namespace std;

struct ListNode{

    int val;
    ListNode *next;
    ListNode(int n)
    {
        val = n;
        next = NULL;
    }
};

class LinkedList{
    
private:
    ListNode *head;
    
public:
    
    LinkedList()
    {
        this->head = NULL;
    }
    
    
    ListNode* returnHead()
    {
        return this->head;
    }
    
    
    void InsertElementsEnd(int value)
    {
        ListNode * temp = head;
        if(head == NULL)
        {
            head = new ListNode(value);
            
            return;
        }
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = new ListNode(value);

        return;
        
    }
    void printElements()
    {
        ListNode * print = head;
        
        while(print != NULL)
        {
            cout<<print->val;
            print = print->next;
        }
        
    }
    
    int detectCycle()
    {
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != NULL && fast->next!= NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        
                if(slow == fast)
                {
                    break;
                }
        }
        
        
        if( fast== NULL || fast->next == NULL)
        {
            return 0;
        }
        
        slow = head;
        /*Node prev = null;
        while(slow != fast)
        {
            prev = fast;
            slow = slow.next;
            fast = fast.next;
        }
        prev.next = null*/
        
        while(fast->next != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
        
        return 1;
    
    }

    
    

};



ListNode * reverseLinkedList(ListNode * head)
{
    ListNode *prev = NULL;
    ListNode *cur = head;
    
    while(cur != NULL)
    {
        ListNode *curNext = cur->next;
        cur->next = prev;
        prev = cur;
        cur = cur->next;
    }
    
    head = prev;
    return head;
}

int main()
{
    
    LinkedList invoke;
    
    invoke.InsertElementsEnd(5);
    invoke.InsertElementsEnd(10);
    invoke.InsertElementsEnd(20);
    invoke.printElements();
    invoke.detectCycle();
    
    ListNode * head = invoke.returnHead();
    
    ListNode * ans = reverseLinkedList(head);
    
    return 0;
}
