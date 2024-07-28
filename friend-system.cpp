#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    int uid;
    string name;
    node *next;
    friend class graph;
};

class graph
{
public:
    int n;
    node *head[200];
    int visited[200] = {0};
    void createlist();
    void displaylist();
    void DFT_rec(int start);
    void DFTrecursive(int start);
    void DFTnonrec(int start);
    void BFTnonrec(int start);
};
class stack
{
    int top=-1;
    int stk[200];
    friend class graph;
    public:
    void push(int n);
    int pop();
    bool isempty();
};

void stack :: push(int n)
{
   stk[++top] = n;
}

int stack :: pop()
{
   int k = stk[top--];
   return k;
}
bool stack :: isempty()
{
   if(top==-1)
   {
      return true;
   }
   return false;
}

class queue
{
    int f = -1;
    int r = -1;
    int qu[200];
    friend class graph;
    public:
    void push(int n);
    int pop();
    bool isempty();
}; 
void queue :: push(int n)
{
   qu[++r] = n;
}

int queue :: pop()
{
   int k = qu[++f];
   return k;
}
bool queue :: isempty()
{
   if(f==r)
   {
      return true;
   }
   return false;
}
void graph::createlist()
{

    cout << "Enter No. Of Users : " << endl;
    cin >> n;
    node *temp;
    node *curr;
    char c, ch;
    for (int i = 0; i < n; i++)
    {
        head[i] = new node();
        cout << "Enter UserName Of User ID : " << i << endl;
        cin >> head[i]->name;
        head[i]->uid = i;
        head[i]->next = NULL;
    }
    for (int i = 0; i < n; i++)
    {
       
        temp = head[i];
        do
        {
            cout << "Is there Any User who is Friends With User " << i << " (Y/N): " << endl;
            cin >> c;
            if (c == 'Y')
            {
                while(temp->next!=NULL)
                {
                   temp= temp->next;
                }
                curr = new node();
                cout << "Enter User ID Of the Friend : " << endl;
                cin >> curr->uid;
                curr->name = head[curr->uid]->name;
                curr->next = NULL;
                temp->next = curr;
                temp = temp->next;

                node *tempF = head[curr->uid];
                while (tempF->next != NULL)
                {
                    tempF = tempF->next;
                }
                tempF->next = new node();
                tempF->next->uid = i;
                tempF->next->name = head[i]->name;
                tempF->next->next = NULL;
            }
            cout << "Do You Want To Add More Friends? (Y/N)" << endl;
            cin >> ch;
        } while (ch == 'Y');
    }
}

void graph ::DFTrecursive(int start)
{
    visited[start] = 1;
    DFT_rec(start);
}

void graph::DFT_rec(int start)
{
    visited[start] = 1;
    cout << "->User ID : " << start << endl;
    cout << "->UserName :" << head[start]->name << endl;
    cout << "\n";
    node *temp = head[start]->next;
    while (temp != NULL)
    {
        if (visited[temp->uid] == 0)
        {
            DFT_rec(temp->uid);
        }
        temp = temp->next;
    }
}

void graph ::displaylist()
{
    node *temp;
    for (int i = 0; i < n; i++)
    {
        temp = head[i];
        cout << "********************************************" << endl;
        cout << "User ID : " << temp->uid << endl;
        cout << "UserName : " << temp->name << endl;
        cout << "Friends : " << endl;
        temp = temp->next;
        while (temp != NULL)
        {
            cout << "     -> User ID : " << temp->uid << endl;
            cout << "     -> UserName : " << temp->name << endl;
            cout << "\n";
            temp = temp->next;
        }
    }
}
void graph :: DFTnonrec(int start)
{
	node *temp;
	int i;
	for(i = 0;i<100;i++)
	{
		visited[i]=0;
	}
	stack s;
	int v = start;
	i = 1;
	visited[v]=1;
	s.push(v);
	while(i<=n)
	{
		while(!s.isempty())
     	{
	
		v = s.pop();
		temp = head[v];
		cout << "     -> User ID : " << temp->uid << endl;
              cout << "     -> UserName : " << temp->name << endl;
              cout << "\n";
	   }
		if(i==n)
		break;
	    while(temp!=NULL)
		{
			if(visited[temp->uid]==0)
			{
				s.push(temp->uid);
				visited[temp->uid]=1;
				i++;
			}
			temp=temp->next;
		}
		
	}
	
}

void graph :: BFTnonrec(int start)
{
	node *temp;
	int i;
	for(i = 0;i<100;i++)
	{
		visited[i]=0;
	}
	stack s;
	int v = start;
	i = 1;
	visited[v]=1;
	s.push(v);
	while(i<=n)
	{
		while(!s.isempty())
     	{
	
		v = s.pop();
		temp = head[v];
		cout << "     -> User ID : " << temp->uid << endl;
              cout << "     -> UserName : " << temp->name << endl;
              cout << "\n";
	   }
		if(i==n)
		break;
	    while(temp!=NULL)
		{
			if(visited[temp->uid]==0)
			{
				s.push(temp->uid);
				visited[temp->uid]=1;
				i++;
			}
			temp=temp->next;
		}
		
	}
	
}

int main()
{
    int choice;

    graph g;
    int id;
    while (1)
    {
        cout << "Enter Choice.\n1 = Create. \n2 = Display All Friends. \n3 = DFT Recursive. \n4 = DFT Non-Recursive.\n5 = BFT Non-Recursive.\n" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            g.createlist();
            break;
        case 2:
            cout << "\nAll The Users Are : " << endl;
            g.displaylist();
            break;
        case 3:
            cout << "Enter ID To Start DFT : " << endl;
            cin >> id;
            cout << "DFT is : " << endl;
            g.DFTrecursive(id);
            break;
        case 4:
            cout << "Enter ID To Start DFT : " << endl;
            cin >> id;
            cout << "DFT is : " << endl;
            g.DFTnonrec(id);
            break;
        case 5:
            cout << "Enter ID To Start BFT : " << endl;
            cin >> id;
            cout << "BFT is : " << endl;
            g.BFTnonrec(id);
            break;
        default:
            cout << "Invalid choice! Please choose again." << endl;
            break;
        }
    }
    return 0;
}
