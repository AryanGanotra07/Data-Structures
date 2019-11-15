#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void printA(int A[], int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void heapify(int A[], int n)
{
    int i = n, temp;
    temp = A[i];
    while (i > 1 && A[i / 2] < temp)
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

int sort(int A[], int n)
{
    int val, last, i, j, temp;
    val = A[1];
    last = A[n];
    A[1] = last;
    i = 1;
    j = 2 * i;

    while (j <= n - 1)
    {

        if (A[j + 1] > A[j])
        {
            j = j + 1;
        }

        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * i;
        }
        else
        {
            break;
        }
    }
    A[n] = val;
    return val;
}

int search(int A[], int n, int elem)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (A[i] == elem)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int A[] = {0, 10, 2, 3, 1, 7, 9, 4, 8, 5, 6}, i, elem, c;
    for (i = 2; i <= 10; i++)
    {
        heapify(A, i);
    }
    printf("Heapify result:\n");
    printA(A, 10);
    printf("\nEnter element to increase priority:");
    scanf("%d", &elem);
    printf("\nEnter number to increase priority by:");
    scanf("%d", &c);
    i = search(A, 10, elem);
    A[i] = elem + c;
    heapify(A, i);
    

    printf("Heapify result after decreasing priority:\n");
    printA(A, 10);

    for (i = 10; i > 1; i--)
    {
        printf("\nDeleted:%d\n", sort(A, i));
        printA(A, 10);
    }

    printf("\nHeap sort result:\n");
    printA(A, 10);
    return 0;
}