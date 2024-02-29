#include <stdio.h>
#include <stdlib.h>

struct employee
{
    char ssn[20];
    char name[20];
    char dept[20];
    char designation[20];
    int salary;
    long int phno;
    struct employee *llink, *rlink;
};

typedef struct employee *EMPLOYEE;
EMPLOYEE start = NULL;

EMPLOYEE create()
{
    EMPLOYEE getnode;
    getnode = (EMPLOYEE)malloc(sizeof(struct employee));
    if (getnode == NULL)
    {
        printf("\nMemory couldn't be allocated!!!");
        // return;
    }
    printf("\nEnter the details of Employee");
    printf("\nEnter the ssn: ");
    scanf("%s", getnode->ssn);
    printf("\nEnter the name: ");
    scanf("%s", getnode->name);
    printf("\nEnter the department: ");
    scanf("%s", getnode->dept);
    printf("\nEnter the designation: ");
    scanf("%s", getnode->designation);
    printf("\nEnter the salary: ");
    scanf("%d", &getnode->salary);
    printf("\nEnter the phno: ");
    scanf("%ld", &getnode->phno);
    getnode->llink = NULL;
    getnode->rlink = NULL;
    return (getnode);
}

void insert_end()
{
    EMPLOYEE node, temp;
    node = create();
    if (start == NULL)
    {
        start = node;
    }
    else
    {
        temp = start;
        while (temp->rlink != NULL)
        {
            temp = temp->rlink;
        }
        temp->rlink = node;
        node->llink = temp;
    }
}

void delete_end()
{
    EMPLOYEE temp, prev;
    temp = start;
    if (temp == NULL)
    {
        printf("\nList is Empty");
    }
    else if (temp->rlink == NULL)
    {
        printf("\nThe deleted employee ssn is %s", temp->ssn);
        free(temp);
        start = NULL;
    }
    else
    {
        while (temp->rlink != NULL)
        {
            prev = temp;
            temp = temp->rlink;
        }
        prev->rlink = NULL;
        printf("\nThe deleted employee ssn is %s", temp->ssn);
        free(temp);
    }
}

void create_list()
{
    int n, i;
    printf("\nEnter the number of employees: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        insert_end();
    }
}

void status()
{
    EMPLOYEE temp;
    int count = 0;
    if (start == NULL)
    {
        printf("\nList is Empty");
        return;
    }
    temp = start;
    printf("\nThe Employee details are: ");
    while (temp != NULL)
    {
        printf("\n%s\n%s\n%s\n%s\n%d\n%ld\n", temp->ssn, temp->name, temp->dept,
               temp->designation, temp->salary, temp->phno);
        temp = temp->rlink;
        count++;
    }
    printf("\nThe number of nodes are: %d", count);
}

void insert_front()
{
    EMPLOYEE node;
    node = create();
    if (start == NULL)
    {
        start = node;
    }
    else
    {
        node->rlink = start;
        start->llink = node;
        start = node;
    }
}

void delete_front()
{
    EMPLOYEE temp;
    temp = start;
    if (temp == NULL)
    {
        printf("\nList is Empty");
    }
    else if (temp->rlink == NULL)
    {
        printf("\nThe deleted employee ssn is %s", temp->ssn);
        free(temp);
        start = NULL;
    }
    else
    {
        start = temp->rlink;
        start->llink = NULL;
        printf("\nThe deleted employee ssn is %s", temp->ssn);
        free(temp);
    }
}

void double_ended_queue()
{
    int ch;

    for (;;)
    {
        printf("\n---------------------------------------------");
        printf("\nDOUBLE ENDED QUEUE OPERATIONS");
        printf("\n1: Insert Rear \n2: Delete Rear \n3: Insert Front \n4: Delete Front \n5: Display \n6: Exit");
        printf("\n---------------------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_end();
            break;
        case 2:
            delete_end();
            break;
        case 3:
            insert_front();
            break;
        case 4:
            delete_front();
            break;
        case 5:
            status();
            break;
        case 6:
            return;
        default:
            printf("\nInvalid Choice!!!");
        }
    }
}

int main()
{
    int ch;

    for (;;)
    {
        printf("\n---------------------------------------------");
        printf("\nDOUBLY LINKED LIST OPERATIONS");
        printf("\n1: Create List \n2: Status of List \n3: Insert End \n4: Delete End \n5: Insert Front \n6: Delete Front \n7: Double Ended Queue Demo \n8: Exit");
        printf("\n---------------------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create_list();
            break;
        case 2:
            status();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            delete_end();
            break;
        case 5:
            insert_front();
            break;
        case 6:
            delete_front();
            break;
        case 7:
            double_ended_queue();
            break;
        case 8:
            return (0);
        default:
            printf("\nInvalid Choice!!!");
        }
    }
    return (0);
}
