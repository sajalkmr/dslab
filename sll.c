#include<stdio.h>
#include<stdlib.h>

struct student {
    char usn[20];
    char name[20];
    char program[20];
    int sem;
    long int phno;
    struct student *link;
};

typedef struct student* STUDENT;
STUDENT start = NULL; /* Initially start contains nothing. */

/* Function definition to allocate memory. */
STUDENT create() {
    STUDENT getnode;
    getnode = (STUDENT)malloc(sizeof(struct student));
    if (getnode == NULL) {
        printf("\nMemory could not be allocated!!!");
        return NULL;
    }
    printf("\nEnter the details of Student");
    printf("\nEnter the usn: ");
    scanf("%s", getnode->usn);
    printf("\nEnter the name: ");
    scanf("%s", getnode->name);
    printf("\nEnter the branch: ");
    scanf("%s", getnode->program);
    printf("\nEnter the sem: ");
    scanf("%d", &getnode->sem);
    printf("\nEnter the phno: ");
    scanf("%ld", &getnode->phno);
    getnode->link = NULL;
    return getnode;
}

/* Function definition to insert element at front of the list. */
void insert_front() {
    STUDENT node;
    node = create();
    if (start == NULL) { /* If the list is empty. */
        start = node;
    } else {
        node->link = start; /* The link of node is assigned the address of the next node which present in start. */
        start = node; /* Now start contains the address of created node. */
    }
}

/* Function definition to delete element at front of the list. */
void delete_front() {
    STUDENT temp;
    if (start == NULL) {
        printf("\nList is Empty");
    } else {
        temp = start;
        start = temp->link; /* Now start will contain the address of the next node. */
        printf("\nThe deleted student usn is %s", temp->usn);
        free(temp);
    }
}

/* Function definition to create a list using front insertion. */
void create_list() {
    int n, i;
    printf("\nEnter the number of students: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        insert_front(); /* Call the insert front function. */
    }
}

/* Function definition to display the status of the list. */
void status() {
    STUDENT temp;
    int count = 0;
    if (start == NULL) {
        printf("\nList is Empty");
        return;
    }
    temp = start;
    printf("\nThe Student details are: ");
    while (temp != NULL) {
        printf("\n%s\n%s\n%s\n%d\n%ld\n", temp->usn, temp->name, temp->program, temp->sem, temp->phno);
        temp = temp->link;
        count++;
    }
    printf("\nThe number of nodes are: %d", count);
}

/* Function definition for inserting a node at end of the list. */
void insert_end() {
    STUDENT node, temp;
    node = create();
    if (start == NULL) { /* If the list is empty. */
        start = node;
    } else {
        temp = start;
        while (temp->link != NULL) /* Traverse till the end of the list. */
            temp = temp->link;
        temp->link = node; /* Insert the node at the end. */
    }
}

/* Function definition to delete element at end of the list. */
void delete_end() {
    STUDENT temp, prev;
    temp = start;
    if (temp == NULL) {
        printf("\nList is Empty");
    } else if (temp->link == NULL) { /* One node in the list. */
        printf("\nThe deleted student usn is %s", temp->usn);
        free(temp);
        start = NULL;
    } else {
        while (temp->link != NULL) {
            prev = temp;
            temp = temp->link;
        }
        printf("\nThe deleted student usn is %s", temp->usn);
        free(temp);
        prev->link = NULL;
    }
}

/* Function to demonstrate stack operations. */
void stack_demo() {
    int ch;
    for (;;) {
        printf("\n---------------------------------------------");
        printf("\nSTACK OPERATIONS");
        printf("\n1: Insert End \n2: Delete End \n3: Status of Stack \n4: Exit");
        printf("\n---------------------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert_end();
                break;
            case 2:
                delete_end();
                break;
            case 3:
                status();
                break;
            case 4:
                return;
            default:
                printf("\nInvalid Choice!!!");
        }
    }
}

int main() {
    int ch;
    /* Infinite loop. */
    for (;;) {
        printf("\n---------------------------------------------");
        printf("\nSINGLY LINKED LIST OPERATIONS");
        printf("\n1: Create List \n2: Status of List \n3: Insert End \n4: Delete End \n5: Insert Front \n6: Delete Front \n7: Stack Demo \n8: Exit");
        printf("\n---------------------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
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
                stack_demo();
                break;
            case 8:
                return 0;
            default:
                printf("\nInvalid Choice!!!");
        }
    }
    return 0;
}
