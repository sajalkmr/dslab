#include<stdio.h>
#define MAX 5

/*Global Declaration.*/
int f = -1, r = -1;

/* Function definition for inserting an element into circular queue. */
void insert(char cq[MAX]) {
    char elem;
    printf("\nEnter the element to insert into the queue: ");
    scanf("\n%c", &elem); /* Use \n in scanf() to remove \n from the buffer. */
    if ((f == 0 && r == MAX - 1) || (f == r + 1)) {
        printf("\nQueue Overflow!!!");
        return;
    }
    if (f == -1) /* Circular queue is empty. */
        f = 0;
    r = (r + 1) % MAX; /* Points to the index of rear where element is to be inserted. */
    cq[r] = elem; /* Insert element at rear end. */
}

/* Function definition for deleting an element from circular queue. */
void delete (char cq[MAX]) {
    if (f == -1) {
        printf("\nQueue Underflow!!!");
        return ;
    }
    printf("\nThe deleted element is: %c", cq[f]);
    if (f == r) /* Circular queue has one element. */
    {
        f = -1;
        r = -1;
    } else
        f = (f + 1) % MAX; /* Points to the index of front after the element is deleted from front. */
}

/* Function definition for displaying elements in a circular queue. */
void display(char cq[MAX]) {
    int i;
    if (f == -1) {
        printf("\nQueue Underflow!!!");
    } else {
        printf("\nThe elements of queue are: ");
        for (i = f; i != r; i = ((i + 1) % MAX))
            printf("\t%c", cq[i]);
        printf("\t%c", cq[i]);
    }
}

int main() {
    int ch;
    char cq[MAX];
    /* Infinite loop. */
    for (;;) {
        printf("\n---------------------------------------------");
        printf("\nCIRCULAR QUEUE OPERATIONS");
        printf("\n1: Insert \n2: Delete \n3: Display \n4: Exit");
        printf("\n---------------------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert(cq);
                break;
            case 2:
                delete(cq);
                break;
            case 3:
                display(cq);
                break;
            case 4:
                return (0);
            default:
                printf("\nInvalid Choice!!!\n");
        }
    }
    return (0);
}
