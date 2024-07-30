#include <stdio.h>
void insert(int a[], int i)
{
    int e = a[i];
    int n = i;
    while(i>1 && a[i]>=a[i/2])
    {
        a[i] = a[i/2];
        i = i/2;
        a[i] = e;
    }
}
void del(int a[], int n)
{
    int i = 1;
    while(2*i <=n)
    {
        int j = 2*i;
        if((j<n) && a[j]<a[j+1])
        j++;
        if(a[i]<=a[j])
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i = j;
        }
        else
        {
            break;
        }
    }
}
int main(void) {
	// your code goes here
	int n;
	scanf("%d",&n);
	n++;
	int n2 = n;
	int a[n];
     for(int i = 1; i<=n; i++)
     {
         scanf("%d",&a[i]);
         insert(a,i);
     }
     while(n2 > 1)
     {
         int t = a[1];
         a[1] = a[n2];
         a[n2] = t;
         n2--;
         del(a,n2);
     }
     for(int i = 2; i<=n; i++)
     {
         printf("%d ",a[i]);
     }
}
