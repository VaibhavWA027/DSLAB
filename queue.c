#include <stdio.h>
#define MAX 5
int queue[MAX];

void insert(int *front, int *rear, int ele) {
    if (*rear == MAX - 1) {  
        printf("\nOverflow");
    } 
    else if (*front == -1 && *rear == -1) {
        *front = 0;
        *rear = 0;
        queue[*rear] = ele;  
    } 
    else {
        (*rear)++;  
        queue[*rear] = ele;  
    }
}

int delete(int *front, int *rear,int *queue) {
    if (*front == -1) {
        printf("\nUnderflow");
        return -1; 
    } 
    else {
        int val = queue[*front];
        if (*front == *rear) {  
            *front = -1;
            *rear = -1;
        } 
        else {
            (*front)++;  
        }
        return val;  
    }
}

void display(int *front, int *rear, int *queue) {
    if (*front == -1) {
        printf("\nQueue is empty");
    }   
    for (int i = *front; i <= *rear; i++) {
        printf("%d\t", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, front = -1, rear = -1, ele;
    do {
        printf("\n MAIN MENU");
        printf("\n 1)Insert");
        printf("\n2)Delete");
        printf("\n3)Display");
        printf("\n4)Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be added : ");
                scanf("%d", &ele);
                insert(&front, &rear, ele);
                printf("\nInsertion successful");
                break;
            case 2: {
                int deletedValue = delete(&front, &rear,queue);
                if (deletedValue != -1) {
                    printf("\nDeleted element: %d", deletedValue);
                }
                break;
            }
            case 3:
                display(&front, &rear,queue);
                break;
            case 4:
                printf("Thank you");
            default:
                printf("\nEnter valid choice ");
                break;
        }
    } while (choice != 4);
    return 0;
}
