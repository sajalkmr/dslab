#include<stdio.h>
#include<stdlib.h>

struct node
{
    char ssn[25], name[25], dept[25], desgn[25];
    int sal;
    long int phone;
    struct node* llink;
    struct node* rlink;
};

typedef struct node* NODE;
NODE start = NULL;
int count = 0;

NODE create()
{
    NODE snode;
    snode = (NODE)malloc(sizeof(struct node));
    if(snode == NULL)
    {
        printf("\nMemory is not available");
        exit(1);
    }
    printf("\nEnter the ssn, Name, dept, designation, sal, PhoneNo of the employee:");
    scanf("%s %s %s %s %d %ld", snode->ssn, snode->name, snode->dept, snode->desgn,
        &snode->sal, &snode->phone);
    snode->llink = NULL;
    snode->rlink = NULL;
    count++;
    return snode;
}

NODE insertfront()
{
    NODE temp;
    temp = create();
    if(start == NULL)
    {
        return temp;
    }
    temp->rlink = start;
    start->llink = temp;
    return temp;
}

NODE deletefront()
{
    NODE temp;
    if(start == NULL)
    {
        printf("\nLinked list is empty");
        return NULL;
    }
    if(start->rlink == NULL) // only start node is present in the DLL
    {
        printf("\nThe Employee node with ssn:%s is deleted ", start->ssn);
        count--;
        free(start); // free is memory de-allocation function
        return NULL;
    }
    temp = start;
    start = start->rlink; // start->link is made as next 'start'
    temp->rlink = NULL;
    start->llink = NULL;
    printf("\nThe Employee node with ssn:%s is deleted", temp->ssn);
    count--;
    free(temp);
    return start;
}

NODE insertend()
{
    NODE cur, temp;
    temp = create();
    if(start == NULL) // empty DLL
    {
        return temp;
    }
    cur = start;
    while(cur->rlink != NULL) // Till last node
    {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
    return start;
}

NODE deleteend()
{
    NODE cur, prev;
    if(start == NULL)
    {
        printf("\nLinked List is empty");
        return NULL;
    }
    if(start->rlink == NULL) // single node
    {
        printf("\nThe Employee node with the ssn:%s is deleted", start->ssn);
        free(start);
        count--;
        return NULL;
    }
    prev = NULL;
    cur = start;
    while(cur->rlink != NULL) // Till last node
    {
        prev = cur;
        cur = cur->rlink;
    }
    printf("\nThe employee node with the ssn:%s is deleted", cur->ssn);
    prev->rlink = NULL; // last but one node will not be connected to anything
    cur->llink = NULL;
    free(cur);
    count--;
    return start;
}

void display()
{
    NODE cur;
    int num = 1;
    if(start == NULL)
    {
        printf("\nNo Contents to display in DLL \n");
        return;
    }
    printf("\nThe contents of DLL: \n");
    cur = start;
    while(cur != NULL)
    {
        printf("\n||%d|| SSN:%s| Name:%s| Dept:%s| Desgn:%s| Sal:%d| Ph No:%ld|", num, cur->ssn, cur->name, cur->dept, cur->desgn, cur->sal, cur->phone);
        cur = cur->rlink;
        num++;
    }
    printf("\n No of Employee nodes is %d \n", count); // count is global variable
}

void dequeuedemo() // choice 7 of main function
{
    int ch;
    while(1)
    {
        printf("\n~~~DE-Queue Demo using DLL~~~\n");
        printf("\n1:Enqueue front \n2: Dequeue front \n3: Enqueue end \n4: Dequeue end\n5: Display \n");
        printf("\nEnter your choice for DE-queue demo");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: start = insertfront();
                    break;
            case 2: start = deletefront();
                    break;
            case 3: start= insertend();
                    break;
            case 4: start = deleteend();
                    break;
            case 5: display();
                    break;
            default: return;
        }
    }
    return;
}

int main()
{
    int ch, i, n;
    while(1)
    {
        printf("\n~~~Menu~~~");
        printf("\nEnter your choice for DLL operation \n");
        printf("\n1:Create DLL of Employee Nodes");
        printf("\n2:Display Status");
        printf("\n3:Insert At End");
        printf("\n4:Delete At End");
        printf("\n5:Insert At front");
        printf("\n6:Delete At Front");
        printf("\n7:DE-Queue Demo using DLL(Insertion and Deletion at Both Ends)");
        printf("\n8:Exit \n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the no of Employees:");
                scanf("%d", &n);
                for(i = 1; i <= n; i++)
                    start = insertfront();
                break;
            case 2:
                display();
                break;
            case 3:
                start = insertend();
                break;
            case 4:
                start = deleteend();
                break;
            case 5:
                start= insertfront();
                break;
            case 6:
                start= deletefront();
                break;
            case 7:
                dequeuedemo();
                break;
            case 8:
                exit(0);
            default:
                printf("\n Please enter the valid choice");
        }
    }
}
