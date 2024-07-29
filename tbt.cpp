#include<iostream>
using namespace std;
class node
{
	int data;
	node* left;
	node* right;
	int lbit;
	int rbit;
	friend class bst;
};
class bst
{
	public:
	node* head;
	
	node* root;	
	

void create()
{
	head = new node();
	root = new node();
	head->left = root;
	head->lbit = 1;
	head->rbit = 1;
	head->right = head;
	cout<<"Enter root data."<<endl;
	cin>>root->data;
	root->left = head;
	root->right = head;
	root->lbit = 0;
	root->rbit = 0;
	while(1)
	{
	int flag = 0;
	node* curr;
	node* temp = root;
	char ch, c;
	int n;
	cout<<"Should we add more data?(Y/N)"<<endl;
	cin>>c;
	if(c=='N')
	{
		break;
	}
	curr = new node();
	cout<<"Enter data"<<endl;
	cin>>curr->data;
	n = curr->data;
	while(flag == 0)
	{
		
		if(n>temp->data)
		{
			if(temp->rbit == 0)
			{
				curr->left = temp;
	            curr->right = temp->right;
				temp->right = curr;	
				temp->rbit = 1;							
				flag = 1;
				break;
			}
			temp = temp->right;	
			flag = 0;		
			
		}
		else
		{
			if(temp->lbit == 0)
			{
				curr->left = temp->left;
	            curr->right = temp;
				temp->left = curr;
				temp->lbit = 1;
				flag = 1;
				break;
			}
			temp = temp->left;
			flag = 0;
		}
	}
    }
}
node* inordersuc(node* temp)
{
	node* x = temp->right;
	if(temp->rbit == 1)
	{
		while(x->lbit==1)
		{
			x = x->left;
		}
	}
	return x;
}
void inorder()
{
   node* temp = head;
   while(1)
   {
   	  temp = inordersuc(temp);
   	  if (temp == head)
   	     break;
   	  else
   	  cout << temp->data <<",";
   }
}
};

int main()
{
	bst b;
	b.create();
	cout<<"Inorder is :";
	b.inorder();
}
