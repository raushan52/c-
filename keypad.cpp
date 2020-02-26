#include<iostream>
using namespace std;
char keypad[][100] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void sequence(char* in ,char* out, int i,int j)
{
    //base case
    if(in[i]=='\0')
    {
        out[j]=in[i];
        cout<<out<<endl;
        return;
    }
    //rec case
    int digit=in[i]-'0';
    if(digit==1 || digit ==0)
    {
        sequence(in,out,i+1,j);
        //return;

    }
    for(int k =0;keypad[digit][k]!='\0';k++)
    {
        out[j]=keypad[digit][k];
        sequence(in,out,i+1,j+1);
    }
}
int main()
{
    char in[100];
    char out[100];
    cin>>in;
    sequence(in,out,0,0);


}
