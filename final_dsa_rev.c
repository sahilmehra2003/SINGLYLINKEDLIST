#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node*next;
}*head,*temp;
int n;
void create(){
    struct node*newnode;
    head=temp=NULL;
    for(int i=0;i<n;i++){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data of newnode\n",i+1);
    scanf("%d",&(newnode->data));
    newnode->next=NULL;
    if (head==NULL)
    {
        head=temp=newnode;
    }else
    {
        temp->next=newnode;
        temp=newnode;
    }
    
    
    }
}
void traverse(){
    if (head==NULL)
    {
        printf("\nlinked list is empty\n");
    }
    else{
    temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
}
}
void insertatbeg(){
    int x;
    printf("\nenter data for the node to be inserted\n");
    scanf("%d",&x);
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if (head==NULL)
    {
        head=newnode;
    }else
    {
        newnode->next=head;
        head=newnode;
    }
}
void insertionatend(){
     int x;
    printf("\nenter data for the node to be inserted\n");
    scanf("%d",&x);
    struct node*newnode;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if (head==NULL)
    {
        head=newnode;
    }else
    {
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        
    }
}
void insertatposition(){
    int x;
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    if (head==NULL)
    {
        newnode->data=x;
        printf("\nenter data for the node to be inserted\n");
        scanf("%d",&x);
        head=newnode;
    }else{
    int position;
    printf("\nenter the position\n");
    scanf("%d",&position);
    printf("\nposition where node is to be inserted is %d",position);
    temp=head;
    if (position==0)
    {
        insertatbeg();
    }else if (position==n)
    {
        insertionatend();
    }else if (position>0 && position<n)
    {
        printf("\nenter data for the node to be inserted\n");
        scanf("%d",&x);
        newnode->data=x;
        int i=0;
        while (i<position-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }else
    {
        printf("\nposition is greater than size\n");
    }
    
    
    }
    
}
void deleteatbeg(){
    if (head==NULL)
    {
        printf("\nlinked list is empty\n");
    }
    else{
    temp=head;
    head=head->next;
    free(temp);
}
}
void deleteatend(){
    if (head==NULL)
    {
        printf("\nlinked list is empty\n");
    }
    else{
        temp=head;
        struct node*p=temp->next;
        while (p->next!=NULL)
        {
            temp=temp->next;
            p=p->next;
        }
        temp->next=NULL;
        free(p);
        
    }
}
void deleteatposition(int length){
    int position;
    printf("\nenter the position\n");
    scanf("%d",&position);
    if (position==0)
    {
        printf("\nlinked list is empty\n");
    }
    else
    {
        temp=head;
        printf("\nposition where node is to be deleted is %d",position);
        if (position==1)
        {
            deleteatbeg();
        }else if (position==length)
        {
            deleteatend();
        }else if (position>1 && position<length)
        {
            struct node*p=temp->next;
            int i=1;           
            while (i<position-1)
            {
                p=p->next;
                temp=temp->next;
            }
            temp->next=p->next;
            free(p);
            
        }else
        {
            printf("\nposition greater than size\n");
        }
        
        
        
        
    }
    

}
int length(){
    int count=0;
    if (head==NULL)
    {
        return 0;
    }else
    {
        temp=head;
        while (temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        
    }
    return count;
    
    

}
int main(){
    printf("\nenter no. of nodes\n");
    scanf("%d",&n);
    create();
    traverse();
    insertatbeg();
    printf("\nlinked list after insertion at beginning\n");
    traverse();
    insertionatend();
    printf("\nlinked list after insertion at end\n");
    traverse();
    insertatposition();
    printf("\nlinked list after insertion at position\n");
    traverse();
    deleteatbeg();
    printf("\nlinked list after deletion at beginning\n");
    traverse();
    deleteatend();
    printf("\nlinked list after deletion at last\n");
    traverse();
    int l;
    l=length();
    deleteatposition(l);
    printf("\nlinked list after deletion at position\n");
    traverse();
}
