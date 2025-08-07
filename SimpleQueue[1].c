#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int q[MAX], front = -1, rear = -1;

void insert(int n) {
    if (rear == MAX - 1) {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1) front = 0;
    q[++rear] = n;
    printf("Inserted: %d\n", n);
}

int delete() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return -1;
    }
    int val = q[front++];
    if (front > rear) front = rear = -1;
    return val;
}

void modify() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    int pos, val;
    printf("Enter position to modify (1 to %d): ", rear - front + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > rear - front + 1) {
        printf("Invalid position.\n");
        return;
    }
    printf("Enter new value: ");
    scanf("%d", &val);
    q[front + pos - 1] = val;
    printf("Modified successfully.\n");
}

void display() {
	int i;
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");
    for (i = front; i <= rear; i++)
        printf("[%d] = %d\n", i - front + 1, q[i]);
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1.Insert  2.Delete  3.Modify  4.Display  5.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                val = delete();
                if (val != -1) printf("Deleted: %d\n", val);
                break;
            case 3:
                modify();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
