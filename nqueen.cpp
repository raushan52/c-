#include<iostream>
using namespace std;
int count=0;
bool issafe(int board[][100],int i,int j,int n)
{
    ///col
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1)
            return false;
    }
    ///left diagonal
    int x=i;
    int y=j;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;

        }
        x--;
        y--;
    }
    ///right diagonal
    x=i;
    y=j;
    while(x>=0 && y<n)
    {
        if(board[x][y]==1)
            return false;
        x--;
        y++;
    }
    return true;
}
bool nqueen(int board[][100],int i,int n)
{
    ///base case
    if(i==n)
    {
       for(int row=0;row<n;row++)
       {
           for(int col=0;col<n;col++)
           {
               if(board[row][col]==1)
               {
                   cout<<"Q ";
               }
               else
               {
                   cout<<"- ";
               }
           }
           cout<<endl;
       }
       count++;
       cout<<"**************************************"<<endl;
       return false;
    }
    ///rec case
    for(int col=0;col<n;col++)
    {
        if(issafe(board,i,col,n))
        {
            board[i][col]=1;
            bool nextQueenRakhPaRaheHai=nqueen(board,i+1,n);
            if(nextQueenRakhPaRaheHai)
            {
                return true;
            }
            board[i][col]=0;
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    int board[100][100]={0};
    nqueen(board,0,n);
    cout<<"count = "<<count;
}
