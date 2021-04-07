#ifndef Linkedlist_H_INCLUDED
#define Linkedlist_H_INCLUDED

struct Node
{
    int data;
    struct Node *next;
};
struct Node* create(int A[],int n)
{
    int i;
    struct Node *t=NULL,*last=NULL;
    struct Node *first=NULL;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    return first;
}
/*void create2(int A[],int n)
{
    int i;
    struct Node *t,*last;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}*/
void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}
void Rdisplay(struct Node *p)
{
    if(p!=NULL)
    {
        Rdisplay(p->next);
        printf("%d\t",p->data);
    }
}
int count(struct Node *p)
{
    int c=0;
    while(p!=NULL)
    {
        c+=1;
        p=p->next;
    }
    return c;
}
int Rcount(struct Node *p)
{
    if(p==NULL)
    {
        return 0;
    }
    return Rcount(p->next)+1;
}
int sum(struct Node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
int Rsum(struct Node *p)
{
    if(p==NULL)
        return 0;
    return Rsum(p->next)+p->data;
}
int Max(struct Node *p)
{
    int max=-32768;
    while(p!=NULL)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    return max;
}
int Min(struct Node *p)
{
    int min=32768;
    while(p!=NULL)
    {
        if(p->data<min)
            min=p->data;
        p=p->next;
    }
    return min;
}
struct Node* LSearch(struct Node *p,int key)
{
    struct Node *q=NULL;
    while(p!=NULL)
    {
        if(key==p->data)
        {
            /*q->next=p->next;
            p->next=first;
            first=p;*/
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
};
struct Node* Rsearch(struct Node *p,int key)
{
    if(p==NULL)
    {
        return NULL;
    }
    if(key==p->data)
        return p;
    return Rsearch(p->next,key);
};
void clear(struct Node *p)
{
    struct Node *q;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        free(q);
    }
}
struct Node* Insert(struct Node *p,int index,int x)
{
    struct Node *first = p;
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    if(index<0 || index>count(p))
        return first;
    t->data=x;
    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1 && p!=NULL;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
    return first;
}
/*void Insertlast(int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
        first=last1=t;
    last1->next=t;
    last1=t;
}*/
struct Node* SortedInsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;
    struct Node *first;
    first = p;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=t;
        return first;
    }
    if(x<first->data)
    {
        t->next=first;
        first=t;
        return first;
    }
    while(p!=NULL && x>p->data)
    {
        q=p;
        p=p->next;
    }
    t->next=q->next;
    q->next=t;
    return first;
}
struct Node* Delete(struct Node *p,int index)
{
    struct Node *first = p;
    struct Node *q=NULL;
    int x=-1;
    if(index<1 || index>count(p))
        return first;
    if(index==1)
    {
        x=first->data;
        first=first->next;
        free(p);
        return first;
    }
    else
    {
        for(int i=0;i<index-1 && p!=NULL;i++)
        {
            q=p;
            p=p->next;
        }
        x=p->data;
        q->next=p->next;
        free(p);
        return first;
    }
}
int Issorted(struct Node *p)
{
    int x=-65536;
    while(p!=NULL)
    {
        if(p->data<x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}
void RemoveDuplicates(struct Node *p) //for sorted linked list
{
    struct Node *q= p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}
void Remove_duplicates(struct Node*p) //for unsorted linked list
{
    struct Node *q=NULL;
    int m=Max(p);
    int *A=(int *)malloc(m*sizeof(int));
    for(int i=0;i<m;i++)
        A[i]=0;
    while(p!=NULL)
    {
        if(A[p->data]==0)
        {
            q=p;
            A[p->data]=1;
            p=p->next;
        }
        else
        {
            q->next=p->next;
            free(p);
            p=q->next;
        }
    }
}
struct Node* Reverse_list(struct Node *p)
{
    struct Node *first=p;
    struct Node *r=NULL,*q=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
    return first;
}
/*void Rev_list(struct Node *q,struct Node *p)
{
    if(p!=NULL)
    {
        Rev_list(p,p->next);
        p->next=q;
    }
    else
    {
        first=q;
    }
}*/
struct Node* Concat(struct Node *p,struct Node *q)
{
    struct Node *third = p;
    while(p->next!=NULL)
        p=p->next;
    p->next=q;
    return third;
}
struct Node* Mergelists(struct Node *p,struct Node*q)
{
    struct Node *third = NULL;
    struct Node *last=NULL;
    if(p->data<q->data)
    {
        third=last=p;
        p=p->next;
        last->next=NULL;
    }
    if(q->data<p->data)
    {
        third=last=q;
        q=q->next;
        last->next=NULL;
    }
    while(p!=NULL && q!=NULL)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p!=NULL)
        last->next=p;
    else
        last->next=q;

    return third;
}
int isLoop(struct Node *f)
{
    struct Node *p,*q;
    p=q=f;
    while(p!=NULL &&q!=NULL)
    {
        p=p->next;
        q=q->next;
        q=(q!=NULL)?q->next:NULL;
        if(p==q)
            return 1;
    }
    return 0;
}
int mid_element(struct Node *p)
{
    int mid=count(p)/2;
    for(int i=0;i<mid && p!=NULL;i++)
        p=p->next;
    return p->data;
}


#endif // Linkedlist_H_INCLUDED
