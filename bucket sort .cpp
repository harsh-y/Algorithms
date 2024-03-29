#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

#define NARRAY 7
#define NBUCKET 5
#define INTERVAL 20

struct Node
{
    int data;
    struct Node *next;
};

void BucketSort(int arr[]);
struct Node *InsertionSort(struct Node *list);
void print(int arr[]);
void printBuckets(struct Node *list);
int getBucketIndex(int value);

void BucketSort(int arr[])
{
    int i, j;
    struct Node **buckets;

    buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);

    for (i = 0; i < NBUCKET; ++i)
    {
        buckets[i] = NULL;
    }

    for (i = 0; i < NARRAY; ++i)
    {
        struct Node *current;
        int pos = getBucketIndex(arr[i]);
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = arr[i];
    current->next = buckets[pos];
    buckets[pos] = current;
    }

    for (i = 0; i < NBUCKET; i++)
    {
        cout << "Bucket[" << i << "] : ";
        printBuckets(buckets[i]);
        cout << endl;
    }

    for (i = 0; i < NBUCKET; ++i)
    {
        buckets[i] = InsertionSort(buckets[i]);
    }
    cout <<"\nBuckets after sorting\n" << endl;
    for (i = 0; i < NBUCKET; i++)
    {
        cout << "Bucket[" << i << "] : ";
        printBuckets(buckets[i]);
        cout << endl;
    }

    for (j = 0, i = 0; i < NBUCKET; ++i)
    {
        struct Node *node;
        node = buckets[i];
        while (node)
        {
            arr[j++] = node->data;
            node = node->next;
        }
    }

    for (i = 0; i < NBUCKET; ++i)
    {
        struct Node *node;
        node = buckets[i];
        while (node)
        {
            struct Node *tmp;
            tmp = node;
            node = node->next;
            free(tmp);
        }
    }
    free(buckets);
    return;
}

struct Node *InsertionSort(struct Node *list)
{
    struct Node *k, *nodeList;
    if (list == 0 || list->next == 0)
    {
        return list;
    }
    nodeList = list;
    k = list->next;
    nodeList->next = 0;
    while (k != 0)
    {
        struct Node *ptr;
        if (nodeList->data > k->data)
        {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = nodeList;
            nodeList = tmp;
            continue;
        }

        for (ptr = nodeList; ptr->next != 0; ptr = ptr->next)
        {
            if (ptr->next->data > k->data)
            break;
        }

        if (ptr->next != 0)
        {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
            continue;
        }
        else
        {
            ptr->next = k;
            k = k->next;
            ptr->next->next = 0;
            continue;
        }
    }
    return nodeList;
}

int getBucketIndex(int value)
{
    return value / INTERVAL;
}

void print(int ar[])
{
    int i;
    for (i = 0; i < NARRAY; ++i)
    {
        cout << setw(3) << ar[i];
    }
    cout << endl;
}

void printBuckets(struct Node *list)
{
    struct Node *cur = list;
    while (cur)
    {
        cout << setw(3) << cur->data;
        cur = cur->next;
    }
}


int main(void)
{
    int array[NARRAY];
    for(int i = 0; i<NARRAY; i++)
    {
        array[i]=rand() % 100;
    }
    cout << "\nArray :";
    print(array);

    BucketSort(array);
    cout << "\nSorted Array :";
    print(array);
}
