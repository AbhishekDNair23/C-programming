#include<stdio.h>

int rear = -1, front = -1;
int queue[10];

void enqueue(int n)
{
    if (rear == 10 - 1)
    {
        printf("Queue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = n;
    }
    else
    {
        rear++;
        queue[rear] = n;
    }
}

int dequeue()
{
    int n;
    if (front == -1 || front > rear)
        return -1;

    n = queue[front];
    front++;

    if (front > rear)
        front = rear = -1;

    return n;
}

int main()
{
    int n, A[10][10];
    int visited[10] = {0};
    int start, v, i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while ((v = dequeue()) != -1)
    {
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (A[v][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}
