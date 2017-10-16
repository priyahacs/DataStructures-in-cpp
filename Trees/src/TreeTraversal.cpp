
#include <iostream>
#include <stack>
#include <queue>
using namespace std;


struct BinaryTreeNode{
    
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    
public:
    BinaryTreeNode(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
    
};




class TreePractice{


public:
    
    /***********************INORDER***************
     **********************************************/
    
    
    void PrintInorder(BinaryTreeNode *head)
    {
        
        
        if(head != NULL)
        {
            PrintInorder(head->left);
            cout<<head->data<<" ";
            PrintInorder(head->right);
        }
        
        return;
        
        
    }
    
    
    /***********************PREORDER***************
     **********************************************/
    
    void PrintPreorder(BinaryTreeNode *head)
    {
        
        if(head != NULL)
        {
            cout<<head->data<<" ";
            PrintPreorder(head->left);
            PrintPreorder(head->right);
        }
        
        return;
        
    }
    
    /***********************POSTORDER***************
     **********************************************/
    
    void PrintPostorder(BinaryTreeNode *head)
    {
        
        if(head != NULL)
        {
            PrintPostorder(head->left);
            PrintPostorder(head->right);
            cout<<head->data<<" ";
        }
        
        return;
        
    }
    
    /***********************Breadth First Search***************
     *********************************************************/
    

    
    int BFS(BinaryTreeNode *head, int value)
    {
        queue<BinaryTreeNode *> q1;
        
        if(head == NULL)
        {
            return 1;
        }
        
        q1.push(head);
        
        while(!q1.empty())
        {
            BinaryTreeNode *samp = q1.front();
            
            //cout<<"Element popped is"<<samp->data<<endl;
            
            q1.pop();
            
            if(samp->data == value)
            {
                return 0;
            }
            
            if(samp->left != NULL)
            {
                q1.push(samp->left);
            }
            
            if(samp->right != NULL)
            {
                q1.push(samp->right);
            }
        }
        
        
        return 1;
    }
    
    /***********************Depth First Search***************
     *********************************************************/
    
    int DFS(BinaryTreeNode *head, int value)
    {
        
        stack <BinaryTreeNode *> s1;
        
        if(head == NULL)
        {
            return 1;
        }
        s1.push(head);
        
        while(!s1.empty())
        {
            BinaryTreeNode *samp = s1.top();
            
            //cout<<"Element popped is"<<samp->data<<endl;
            
            s1.pop();
            
            if(samp->data == value)
            {
                return 0;
            }
            
            if(samp->right != NULL)
            {
                s1.push(samp->right);
            }
            
            if(samp->left != NULL)
            {
                s1.push(samp->left);
            }
            
        }
        
         return 1;
        
    }
    
    
    /***********************Height of the tree***************
     *********************************************************/

    
    int findHeight(BinaryTreeNode * head)
    {
        if(head != NULL )
        {
            return (max(findHeight(head->left),findHeight(head->right)))+ 1;
        }
        else
        {
            return -1;
        }
    }


};


/*
 
 Creating the folowing tree:

            10
           /  \
        11     12
       /  \    /  \
      13  14   15  16
 
 */



int main()
{
    BinaryTreeNode *head = new BinaryTreeNode(10);
    TreePractice tp;
    
    BinaryTreeNode *node1 = new BinaryTreeNode(11);
    BinaryTreeNode *node2 = new BinaryTreeNode(12);
    BinaryTreeNode *node3 = new BinaryTreeNode(13);
    BinaryTreeNode *node4 = new BinaryTreeNode(14);
    BinaryTreeNode *node5 = new BinaryTreeNode(15);
    BinaryTreeNode *node6 = new BinaryTreeNode(16);
    
    
    head->left = node1;
    head->right = node2;
    
    node1->left = node3;
    node1->right = node4;
    
    node2->left = node5;
    node2->right = node6;
    
    
    /*PreOrderTraversal*/
    
    cout<<"PreOrder Traversal:"<<endl;
    tp.PrintPreorder(head);
    
    cout<<endl;
    
    /*InOrderTraversal*/
    
    cout<<"InOrder Traversal:"<<endl;
    tp.PrintInorder(head);
    cout<<endl;
    
    /*PostOrderTraversal*/
    
    cout<<"PostOrder Traversal:"<<endl;
    tp.PrintPostorder(head);
    
    cout<<endl;
    
    
    
    /*Height of the Binary tree*/
    
    int height = tp.findHeight(head);
    cout<<"Height of the tree is"<<height<<endl;
    
    /*   BFS */
    
    int element = 25;
    int ans = tp.BFS(head, element);
    
    if( ans == 0)
    {
        cout<<"The element is found using BFS";
    }
    else
    {
        cout<<"The element is not found using BFS";
    }
    
    cout<<endl;
    
    /* DFS  */
    
    int ans_dfs = tp.DFS(head, element);
    
    if( ans_dfs == 0)
    {
        cout<<"The element is found using DFS";
    }
    else
    {
        cout<<"The element is not found using DFS";
    }
    
    cout<<endl;
    
    
    
    
    
    return 0;
    
    
    
}