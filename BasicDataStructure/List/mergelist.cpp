#include<iostream>
#include<string>
using namespace std;

typedef struct LNode {
	int data; //½áµãµÄÊý¾ÝÓò
	struct LNode *next; //½áµãµÄÖ¸ÕëÓò
}LNode, *LinkList; //LinkListÎªÖ¸Ïò½á¹¹ÌåLNodeµÄÖ¸ÕëÀàÐÍ

void CreateList_R(LinkList &L)//Î²²å·¨´´½¨µ¥Á´±í
{
	//ÊäÈën¸öÔªËØµÄÖµ£¬½¨Á¢´ø±íÍ·½áµãµÄµ¥Á´±íL
	int n;
	LinkList s, r;
	L=new LNode;
	L->next=NULL; //ÏÈ½¨Á¢Ò»¸ö´øÍ·½áµãµÄ¿ÕÁ´±í
	r=L; //Î²Ö¸ÕërÖ¸ÏòÍ·½áµã
	cout <<"ÇëÊäÈëÔªËØ¸öÊýn£º" <<endl;
	cin>>n;
	cout <<"ÇëÒÀ´ÎÊäÈën¸öÕûÐÍÊý(·ÇµÝ¼õ)£º" <<endl;
	cout <<"Î²²å·¨´´½¨µ¥Á´±í..." <<endl;
	while(n--)
    {
		s=new LNode;//Éú³ÉÐÂ½áµã
		cin>>s->data; //ÊäÈëÔªËØÖµ¸³¸øÐÂ½áµãµÄÊý¾ÝÓò
		s->next=NULL;
		r->next=s;//½«ÐÂ½áµãs²åÈëÎ²½áµãrÖ®ºó
		r=s;//rÖ¸ÏòÐÂµÄÎ²½áµãs
	}
}

void mergelinklist(LinkList La, LinkList Lb, LinkList &Lc)
{
    LinkList p,q,r;
    p=La->next; //pÖ¸ÏòLaµÄµÚÒ»¸öÔªËØ
    q=Lb->next; //qÖ¸ÏòLbµÄµÚÒ»¸öÔªËØ
    Lc=La;      //LcÖ¸ÏòLaµÄÍ·½áµã
    r=Lc;       //rÖ¸ÏòLcµÄÎ²²¿
    while(p&&q)
    {
        if(p->data<=q->data)//°ÑpÖ¸ÏòµÄ½áµã´®ÆðÀ´
        {
            r->next=p;
            r=p;
            p=p->next;//pºóÒÆÒ»¸ö½áµã 
        }
        else             //°ÑqÖ¸ÏòµÄ½áµã´®ÆðÀ´
        {
            r->next=q;
            r=q;
            q=q->next;
        }
    }
    r->next=p?p:q;//Ïàµ±ÓÚif(p) r->next=p; else r->next=q;
    delete Lb;
}
void Listprint_L(LinkList L) //µ¥Á´±íµÄÊä³ö
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
