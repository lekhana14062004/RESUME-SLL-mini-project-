#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char name[100];
    char qualification[100];
    int workexp;
    long int phno;
    int age;
    struct node*link;
};
typedef struct node* NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("memory not available");
        return NULL;
    }
    return x;
}
NODE insertfront(NODE first)
{
    NODE temp;
    temp=getnode();
    printf("resume  details:name qualification workexperience phoneno age");
    scanf("%s %s %d %ld %d",(temp->name),(temp->qualification),&(temp->workexp),(&(temp->phno)),(&(temp->age)));
    temp->link=first;
    return temp;
}
NODE insertrear(NODE first)
{
    NODE temp,cur,prev;
    temp=getnode();
     printf("resume  details:name qualification workexperience phoneno age");
    scanf("%s %s %d %ld %d",(temp->name),(temp->qualification),&(temp->workexp),(&(temp->phno)),(&(temp->age)));
    temp->link=NULL;
    if(first==NULL)
    {
        return temp;
    }
    cur=first;
    prev=NULL;
    while(cur!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    prev->link=temp;
    return first;
}
void display(NODE first)
{
    NODE cur;
    cur=first;
    while(cur!=NULL)
    {
         printf("name:%s\nqualification:%s\nworkexp:%d\nphoneno:%ldage:%d\n",(cur->name),(cur->qualification),(cur->workexp),(cur->phno),(cur->age));
         cur=cur->link;
    }
     
}
void count(NODE first)
{
    int count=0;
    NODE cur;
    cur=first;
    while(cur!=NULL)
    {
            cur=cur->link;
            count++;
    }
     printf("the no of applicants are:%d",count);
}

void search(NODE first,char name[100])
{
    int index=0;
    NODE cur;
    cur=first;
    while(cur!=NULL)
    {
        index++;
        if(strcmp(cur->name,name)==0)
        {
           
           printf("the details of the applicant are:\nname:%s\nqualification:%s\nwork experience:%d\nphoneno:%ld\nage:%d",cur->name,cur->qualification,cur->workexp,cur->phno,cur->age);
            return;
        }
        cur=cur->link;
    }
    printf("the applicant not found");
        
}
int main()
{
    NODE first;
    first=NULL;
    int ch;
    char name[100];
    printf("1.for insert front\n2.for insert rear\n 3 for disaply");
    for(;;)
    {
        printf("enter choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:first=insertfront(first);
            break;
            case 2:first=insertrear(first);
            break;
            case 3:display(first);
            break;
            case 4:count(first);
            break;
            case 5:printf("enter the name of the applicant");
            scanf("%s",name);
            search(first,name);
            break;
            default:exit(0);
        }
    }
}
  

