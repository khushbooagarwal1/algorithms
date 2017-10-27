/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
void print(deque< Node* > q){
    if(q.empty()){
        return;
    }
    Node* root = q.front();
    q.pop_front();
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    if(root->right != NULL){
        q.push_front(root->right);
    }
    if(root->left != NULL){
        q.push_back(root->left);
    }
    print(q);
}
void diagonalPrint(Node *root)
{
   // your code here
   deque< Node* > q;
   q.push_back(root);
  // while(!q.empty())
        print(q);
}
