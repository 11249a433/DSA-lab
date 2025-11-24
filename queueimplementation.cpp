#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int val) {
    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = val;
    printf("Enqueued %d\n", val);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1;
    }
    int val = queue[front++];
    if (front > rear)
        front = rear = -1;
    return val;
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("Dequeued : %d\n", dequeue());

    display();

    enqueue(40);
    enqueue(50);
    enqueue(60); // overflow

    display();

    return 0;
}