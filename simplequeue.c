#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int queue[MAX];
int front = -1, rear = -1;

int is_full() 
{
    return rear == MAX - 1;
}

int is_empty() 
{
    return front == -1 || front > rear;
}

void insert() 
{
    if (is_full()) 
	{
        printf("Queue overflow.....\n");
        return;
    }
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);
    if (is_empty()) 
	{
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Inserted %d into queue.\n", value);
}

void delete() 
{
    if (is_empty()) 
	{
        printf("Queue underflow.....\n");
        return;
    }
    int removed = queue[front];
    front++;
    if (front > rear) 
	{ // reset if queue becomes empty
        front = rear = -1;
    }
    printf("Deleted %d from queue.\n", removed);
}

void modify() 
{
    if (is_empty()) 
	{
        printf("Queue is empty. Nothing to modify.\n");
        return;
    }
    int pos, new_value;
    printf("Enter position to modify (1 is front): ");
    scanf("%d", &pos);
    int idx = front + pos - 1;
    if (pos <= 0 || idx > rear) 
	{
        printf("Invalid position.\n");
        return;
    }
    printf("Current value at position %d is %d.\n", pos, queue[idx]);
    printf("Enter new value: ");
    scanf("%d", &new_value);
    queue[idx] = new_value;
    printf("Modified position %d to %d.\n", pos, new_value);
}

void display() 
{
	int i;
    if (is_empty()) 
	{
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents (front to rear): ");
    for (i = front; i <= rear; i++) 
	{
        printf("%d", queue[i]);
        if (i < rear) printf(" -> ");
    }
    printf("\n");
}

void menu() 
{
    int choice;
    do {
        printf("\nSimple Queue chioce any opration...\n");
        printf("1) Insert\n");
        printf("2) Delete\n");
        printf("3) Modify\n");
        printf("4) Display\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) 
		{
            // clear invalid input
            while (getchar() != '\n');
            printf("Invalid input. Try again.\n");
            continue;
        }
        switch (choice) 
		{
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: modify(); break;
            case 4: display(); break;
            case 5: printf("Exiting.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
}

int main() 
{
    menu();
    return 0;
}


