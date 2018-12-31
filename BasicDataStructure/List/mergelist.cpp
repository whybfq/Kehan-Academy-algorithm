#include<iostream>
#include<string>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;

void CreateList_R(LinkList &L)
{
	int n;
	LinkList s, r;
	L=new LNode;
	L->next=NULL; 
	r=L;
	cout <<"ÇëÊäÈëÔªËØ¸öÊýn£º" <<endl;
	cin>>n;
	cout <<"ÇëÒÀ´ÎÊäÈën¸öÕûÐÍÊý(·ÇµÝ¼õ)£º" <<endl;
	cout <<"Î²²å·¨´´½¨µ¥Á´±í..." <<endl;
	while(n--)
    {
		s=new LNode;
		cin>>s->data;
		s->next=NULL;
		r->next=s;
		r=s;
	}
}

void mergelinklist(LinkList La, LinkList Lb, LinkList &Lc)
{
    LinkList p,q,r;
    p=La->next;
    q=Lb->next;
    Lc=La;     
    r=Lc;     
    while(p&&q)
    {
        if(p->data<=q->data)        {
            r->next=p;
            r=p;
            p=p->nex;
        }
        else             
        {
            r->next=q;
            r=q;
            q=q->next;
        }
    }
    r->next=p?p:q;

}
void Listprint_L(LinkList L)
{
    LinkList p;
    p=L->next;
    while (p)
    {
        cout<<p->data<<"\t";
		p=p->next;
    }
    cout<<endl;
}

int main()
{
	LinkList La,Lb,Lc;
	cout << "´´½¨ÓÐÐò£¨·ÇµÝ¼õ£©µ¥Á´±íLa:"<<endl;
	CreateList_R(La);
	cout << "´´½¨ÓÐÐò£¨·ÇµÝ¼õ£©µ¥Á´±íLb:"<<endl;
	CreateList_R(Lb);
	cout << "½«Á½¸öÓÐÐò£¨·ÇµÝ¼õ£©µ¥Á´±íLaºÍLbºÏ²¢ÎªLc£º"<<endl;
	mergelinklist(La,Lb,Lc);
	cout << "ºÏ²¢ºóµÄ½á¹ûLc£º"<<endl;
	Listprint_L(Lc);
	return 0;
}
