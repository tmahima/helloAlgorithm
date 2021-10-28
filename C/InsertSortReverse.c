#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *head)
{
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void insert(struct node **head,int d)
{
    struct node *current,*ptr;
        current=malloc(sizeof(struct node));
        current->next=NULL;
        current->data=d;
        if(*head==NULL)
        {
            *head=current;
        }
        else
        {
          ptr=*head;
          while(ptr->next!=NULL)
          {
              ptr=ptr->next;
          }
           ptr->next=current;
        }
}

// FUNCTION FOR SORT 

void sort(struct node **head)
{
    struct node *p1,*p2;
    for(p1=*head;p1!=NULL;p1=p1->next)
    {
        for(p2=p1->next;p2!=NULL;p2=p2->next)
        {
            if(p1->data > p2->data)
            {
                int temp=p1->data;
                p1->data=p2->data;
                p2->data=temp;
            } 
        }
    }
}
void insertE(struct node **head,int element)
{
    struct node *temp,*ptr,*prv;
    temp=malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=element;
    if(*head==NULL||(*head)->data > temp->data){
        temp->next=*head;
        *head=temp;
    }
    else
    {
        ptr=*head;
        while(ptr!=NULL&&ptr->data < temp->data)
        {
            prv=ptr;
            ptr=ptr->next;
        }
        temp->next=ptr;
        prv->next=temp;
    }
}
void reverse(struct node **head)
{
    struct node *ptr=*head,*ptr1;
    while(ptr->next!=NULL)
    {
       ptr1=ptr->next;
       ptr->next=ptr1->next;
       ptr1->next=*head;
       *head=ptr1;
    }
}

int main()
{
    struct node *head=NULL;
    int n,d;
    printf("Enter the size: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       scanf("%d",&d); 
      insert(&head,d);
    }
    printf("original linked list: ");
    display(head);
    printf("\n");

    sort(&head);
    printf("Sorted linked list: ");
    display(head);
    printf("\n");

    int e;
    printf("Enter the element to be inserted: ");
    scanf("%d",&e);
    insertE(&head,e);
    printf("After inserting in a sorted linked list: ");
    display(head);
    printf("\n");

    reverse(&head);
    printf("Reversed linked list: ");
    display(head);
    return 0;
}