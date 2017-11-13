#include<stdio.h>
#include<conio.h>
#define make (nptr)malloc(sizeof(struct node))

//----------------------------------------------
/*
    MADE BY-> BISWAJIT BANERJEE
*/

//----------------------------------------------



struct node
{
    /* A structure containing the integer type data,
       a pointer of type node (which is a structure*/
    int data;
    struct node * r;
};

//---------------------------------------------

typedef struct node* nptr;

//----------------------------------------------
void display(nptr h);
void show(nptr h);
int findlen(int j);
nptr creat();
nptr addnode(nptr h);
nptr addh(nptr h,int data);
nptr addl(nptr h,int data);
nptr addm(nptr h,int data,int pos);


void display(nptr h)
{
    /* A function to display the Linked List.*/
    nptr t;
    printf("\n\t\t");
    for(t=h;t!=NULL;t=t->r)
        printf("%d\t",t->data);
    getch();
}

//----------------------------------------------
 void show(nptr h)
 {
    /* A function to display the Linked List
       as the way it is.*/
     nptr d;
     int i,j,l,n;
     printf("Here is your linked list--->\n\t");
     for(d=h;d->r!=NULL;d=d->r)
     {
         j=findlen(d->data);
         for(i=0;i<13+j;i++)
            printf("%c",254);
         printf("    ");
     }
     j=findlen(d->data);
     for(i=0;i<8+j;i++)
        printf("%c",254);
     printf("\n\t");
     for(d=h;d!=NULL;d=d->r)
     {
         printf("%c %d %c(%x)%c--->",221,d->data,221,d->r,222);
     }
     printf("NULL\n\t");
     for(d=h;d->r!=NULL;d=d->r)
     {
         j=findlen(d->data);
         for(i=0;i<13+j;i++)
            printf("%c",223);
        printf("    ");
     }
     j=findlen(d->data);
     for(i=0;i<8+j;i++)
        printf("%c",223);
     printf("\n\t");
     for(d=h,n=1;d!=NULL;d=d->r,n++)
     {
         j=findlen(d->data);
         l=j+7;
         printf("%d>%x",n,d);
         for(i=0;i<l+2;i++)
            printf(" ");
     }

 }

//---------------------------------------------

int findlen(int j)
 {
     /* A function to find length of the Linked List*/
     int i=0;
     do
     {
         j/=10;
         i++;
     }while(j);
     return i;
 }

//---------------------------------------------
nptr create()
{
    /*A function to create a single Linked List*/
    nptr h=NULL,n,t;
    int d;
    while(2)
    {
        printf("\nEnter the data[-999 to exit]::");
        scanf("%d",&d);
        if(d==-999)
            return h;
        if(h==NULL)
        {
            h=t=(nptr)malloc(sizeof(struct node));
            h->data=d;
            h->r=NULL;
        }
        else
        {
            n=make;
            n->data=d;
            n->r=NULL;
            t->r=n;
            t=n;
        }
    }
    return h;
}
//----------------------------------------------

nptr addnode(nptr h)
{
    /*A function to add data to the Linked List */
    int pos,data,len;
    nptr k;
    printf("\nPlease enter the data you want to add to the linked list::");
    scanf("%d",&data);
    for(k=h,len=1;k!=NULL;len++,k=k->r);

    again:
    {

        printf("Please enter the position");
        printf("(1st position is for the head and %d is for the last)::",len);
        scanf("%d",&pos);
        if(pos==1)
            h=addh(h,data);
        else if(pos==len)
            h=addl(h,data);
        else
        {
            if(pos<len)
                h=addm(h,data,pos);
            else
            {
                printf("Invalid position press 1 to re-enter ");
                if(getch()==1)
                    goto again;
            }

        }
    }

}
//---------------------------------------------
nptr addh(nptr h,int data)
{
    /*A function to add data at the beginning of the Linked List*/
    nptr d=make;
    d->data=data;
    d->r=h;
    h=d;
    return h;
}
//---------------------------------------------
nptr addl(nptr h,int data)
{
    /*A function to add data at the end of the Linked List*/
    nptr d=make,t;
    for(t=h;t->r!=NULL;t=t->r);
    d->data=data;
    d->r=NULL;
    t->r=d;
    return h;
}
//---------------------------------------------
nptr addm(nptr h,int data,int pos)
{
    /*A function to add data at any specified point in between the starting and end*/
    int i,j,len;
    nptr d,t;
    d=make;
    d->data=data;
    for(t=h,len=1;len+1!=pos;len++,t=t->r);
    d->r=t->r;
    t->r=d;
    return h;
}

//---------------------------------------------
