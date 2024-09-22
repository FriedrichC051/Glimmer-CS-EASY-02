#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *next;
};
node *head=nullptr;
node *tail=nullptr;
int sum=0;
void ins_head(int x)
{
    node *nd=new node;
    nd->val=x;
    nd->next=head;
    head=nd;
    if(tail==nullptr){tail=nd;}
}
void ins_tail(int x)
{
    node *nd=new node;
    nd->val=x;
    nd->next=nullptr;
    if(tail==nullptr){head=tail=nd;}
    else
    {
        tail->next=nd;
        tail=nd;
    }
}
bool del(int i)
{
    if(head==nullptr)return 0;
    node *temp=head;
    if(i==1)
    {
        head=head->next;
        if(head==nullptr)tail=nullptr;
        delete temp;
        return 1;
    }
    for(int cnt=1;temp!=nullptr&&cnt<i-1;++cnt)
    {
        temp=temp->next;//当cnt=i-2时，temp已经指向i-1
        //cout<<temp->val<<'\n';
    }
    if(temp==nullptr||temp->next==nullptr)return 0;//如果删除的元素并不存在
    node *t=temp->next;
    temp->next=t->next;
    if(t->next==nullptr)tail=temp;
    delete t;
    return 1;
}
void print()
{
    int cnt=1;
    node *temp=head;
    while(temp!=nullptr&&cnt<=sum)
    {
        cout<<"rk"<<cnt<<": "<<temp->val<<'\n';
        temp=temp->next;
        cnt++;
    }
}
void cir()
{
    //if(head==nullptr)return;
    tail->next=head;
}
int main()
{
    int n=16;
    char op;
    int a,b,c,loc;
    ins_head(1);
    sum++;
    while(n--)
    {
        cin>>op;
        if(op=='H')
        {
            cin>>a>>b>>c;
            ins_head(c);
            ins_head(b);
            ins_head(a);
            sum+=3;
        }
        else if(op=='T')
        {
            cin>>a>>b>>c;
            ins_tail(a);
            ins_tail(b);
            ins_tail(c);
            sum+=3;
        }
        else if(op=='D')
        {
            cin>>loc;
            if(del(loc))sum--;
        }
        else cir();
        print();cout<<'\n';
    }
    return 0;
}

