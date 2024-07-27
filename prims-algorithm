#include<iostream>
using namespace std;

class graph 
{
    int n;
    int cost[20][20];
public:
    void create();
    void prims();
};

void graph::create() 
{
    int i, j, c;
    cout << "Enter No Of Vertices (Max 20): ";
    cin >> n;
    char ch;
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            cost[i][j] = 9999; //initialize cost matrix
        }
    }
    ch = 'Y';
    do 
    {
        cout << "Enter Source, Destination Vertex and Cost Between Them: ";
        cin >> i >> j >> c;
        cost[i][j] = c;
        cost[j][i] = c;
        cout << "Do you want to add more connections? (Y/N): ";
        cin >> ch;
    } while (ch == 'Y');
}

void graph::prims() 
{
    int min;
    cout << "Enter Starting Vertex: ";
    int s;
    cin >> s;
    int nearest[20];
    int i, k, j, m = 0;
    int mincost = 0;
    int r[25][3];

    for (i = 0; i < n; i++) 
	  {
        nearest[i] = -1; 
    }
    nearest[s] = s; 

    for (i = 0; i < n - 1; i++) 
    {
        min = 9999;
        for (k = 0; k < n; k++) 
        {
            if (nearest[k] != -1) 
            {
                for (j = 0; j < n; j++) 
                {
                    if (cost[k][j] < min && nearest[j] == -1) 
                    {
                        min = cost[k][j];
                        s = k;
                        m = j;
                    }
                }
            }
        }
        r[i][0] = s;
        r[i][1] = m;
        r[i][2] = min;
        mincost += min;
        nearest[m] = m;
    }
    cout << "SHORTEST PATH IS\n";
    for (i = 0; i < n - 1; i++) 
    {
        cout << r[i][0] << " " << r[i][1] << " " << r[i][2] << endl;
    }
    cout << "TOTAL COST IS : " << mincost << endl;
}

int main() 
{
    graph g;
    g.create();
    g.prims();
    return 0;
}
