#include<iostream>
#define inf 10000
using namespace std;

void print(int *a, int n )
{
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%d ", *((a+i*n) + j));
        cout<<"\n";
    }
}
int main()
{
    cout<<"Enter the number of matrix : ";
    int n;
    cin>>n;
    int N = n+1;
    int p[N];
    cout<<"Enter the array of MCM : ";
    for(int i=0; i<N; i++)
    cin>>p[i];

    cout<<"Matrices different sizes  are \n ";
    for(int i=0; i<n; i++)
    cout<<p[i]<<"x"<<p[i+1]<<"  ";

    int m[N][N], s[N][N];
    for(int i=0; i<N; i++)
    {    
        for(int j=0; j<N; j++)
        {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }

    int j, q;
    q=0;
    for(int l = 2; l<N; l++)
    {
        for(int i=1; i<N-l+1; i++)
        {
            j = i+l-1;
            m[i][j] = inf;
            for (int k=1; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);

                if(q<m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout<<"Cost matrix : \n";
    print((int*)m, N);
    cout<<"Split matrix : \n";
    print((int*)s, N);
    

    return 0;
}
