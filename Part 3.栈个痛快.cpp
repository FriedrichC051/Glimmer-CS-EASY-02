#include<bits/stdc++.h>
using namespace std;
char st[1000],s[1000];
int top=0,pos=0;
int main()
{
    freopen("part3.in","r",stdin);
    freopen("part3.out","w",stdout);
    cin>>s;
    int op;
    for(int i=1;i<=34;++i)
    {
        cin>>op;
        if(i&1)
            while(op--)
            {
                st[++top]=s[pos];
                pos++;

            }
        else
            while(op--)
            {
                cout<<st[top];
                top--;
            }
        /*for(int i=top;i>=1;i--)
            cout<<st[i];
        cout<<'\n';*/
    }
    return 0;
}
