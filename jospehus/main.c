#include <stdio.h>
#include <stdlib.h>
/*
struct node {
    int data; //value
    struct node *next; //links to the next node
};

typedef struct node NODE;
typedef NODE *NODEPTR;

void circle(NODEPTR *, int);
void display (NODEPTR *);
int survivorPosition(NODEPTR *, int);
*/

int main() {
    
    struct node {
        int data; //value
        struct node *next; //links to the next node
    } *current, *head, *tail, *temp, *previous;

    head = NULL;

    int i;
    int size = 0;
    int skip = 0;

    //get input
/*
    printf("Please enter the number of people: ");
    scanf("%d", &size);
    printf("Please enter the number of people to skip: ");
    scanf("%d", &skip);
*/
    size = 6;

    //create node
    for (i = 1; i <= size; i++) {
        current = (struct node *) malloc(sizeof(struct node));
        current->data = i;
        current->next = NULL;

        if (head == NULL) {
            head = current;
            previous = current;
        } else {
            previous->next = current;
            previous = current;
        }
    }
    current->next = head;
    tail = current;

    //display
    temp = head;
    while (temp->next != head){
        printf("(%p, %d, %p)\n", (void*) temp, temp->data, (void *) temp->next);
        temp = temp->next;
    }

    printf("(%p, %d, %p)\n", (void*) temp, temp->data, (void *) temp->next);

    printf("\n");


    //survivor
    skip = 2;
    int total = size;
    int k = 1;

    previous = tail;
    current = head;

    while (current->next != current){
        k = 0;
        while (k < skip){
            current = current->next;
            previous = previous->next;
            k++;
        }

        temp = current;
        printf("Pre switch Previous (%p, %d, %p)\n", (void*) previous, previous->data, (void *) previous->next);

        previous->next = current->next;
        printf("Killing (%p, %d, %p)\n", (void*) temp, temp->data, (void *) temp->next);

        current = current->next;

        free(temp);
        printf("Post switch Previous (%p, %d, %p)\n", (void*) previous, previous->data, (void *) previous->next);
        total--;
    }

    printf("(%p, %d, %p)\n", (void*) current, current->data, (void *) current->next);

    //circle(&head, size);
    //display(&head);
    //survivorPosition(&head, skip);

    return 0;
}
/*
// create the circle of people
void circle (NODEPTR *head, int size){ //head is a pointer that points to the head of the list
    NODEPTR new, tail; //all pointers

    int i;
    new = (NODEPTR *) malloc(sizeof(NODEPTR)); //pointer of new memory location

    for (i = 0; i < size; i++) {
        new->data = i;
        new->next = NULL;

        if (*head == NULL) {
            *head = new;
            tail = new;
        } else {
            tail->next = new;
            tail = new;
            tail->next = *head;
        }
    }
}

int survivorPosition (NODEPTR *head, int x){ //determine which spot to stand in to survive

    while (*head->next != *head){ //head -> next is not NULL
        //delete everything x element
        int count = 0;
        while (count < x){

        }

    }

}

void display (NODEPTR *head){
    NODEPTR temp;

    temp = head;
    while (temp->next != head){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
*/