// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>

// Node struct for Linked List Nodes
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Creating a Linked List from an Array
void create(int arr[], int n, Node** head) {
    if (n <= 0) {
        *head = NULL;
        return;
    }

    Node* last = NULL;
    *head = (Node*)malloc(sizeof(Node));
    (*head)->data = arr[0];
    (*head)->next = NULL;
    last = *head;

    for (int i = 1; i < n; i++){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        last->next = newNode;
        last = newNode;
    }
}

// Counting Nodes
int countNodes(Node* head) {
    int count = 0;
    while (head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

// Sum of Elements
int addNodeVals(Node* head) {
    int sum = 0;
    while (head != NULL){
        sum += head->data;
        head = head->next;
    }
    return sum;
}

// Max in Linked list
int maxValFinder(Node* head) {
    if (head == NULL){
        return -1;
    }

    int max = head->data;
    head = head->next;
    while (head != NULL){
        if (max < head->data){
            max = head->data;
        }
        head = head->next;
    }
    return max;
}

// Displaying Linked List items
void printList(Node* head) {
    if (head == NULL) {
        return;
    }

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Free the memory of linked list
void freeLinkedList(Node* head) {
    Node* temp = NULL;
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main Function
int main(void) {
    int arr_size = 0;

    printf("Enter the size of Array: ");
    scanf("%d", &arr_size);
    int* arr = malloc(sizeof(int)*arr_size);
    printf("Enter the Array Elements: ");
    for (int i = 0; i < arr_size; i++){
        scanf("%d", &arr[i]);
    }

    Node* head = NULL;

    // create() test code
    create(arr, arr_size, &head);

    // printList() test code
    printList(head);

    // countNodes() test code
    printf("The number of Nodes: %d\n", countNodes(head));

    // addNodeVals() test code
    printf("The sum of Node values: %d\n", addNodeVals(head));
 
    // maxValFinder() test code
    printf("The maximum value: %d\n", maxValFinder(head));

    // Free the memory
    free(arr);
    freeLinkedList(head);

    return 0;
}