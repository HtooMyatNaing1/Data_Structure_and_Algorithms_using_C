#include <stdio.h>
#include <stdlib.h>

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

// Linear Searching in Linked List
Node* LSearch(Node *head, int key) {
    while (head != NULL) {
        if (head->data == key) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Insert a node in Linked List
void insertNewNode(Node** head, int index, int value) {
    if (index < 0) return;

    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) return;

    newNode->data = value;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* iter_node = *head;
    int i = 0;

    while (i < index - 1 && iter_node->next != NULL) {
        iter_node = iter_node->next;
        i++;
    }

    newNode->next = iter_node->next;
    iter_node->next = newNode;
}

// Inserting a New Node at the end of the Linked List
void insertEnd(Node** head, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* iter_node = *head;
    while(iter_node->next != NULL) {
        iter_node = iter_node->next;
    }

    iter_node->next = newNode;
}

// Inserting a New Node in a Sorted Linked List
void insertSorted(Node** head, int value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) return;

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || value < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* iter_node = *head;

    while (iter_node->next != NULL &&
           iter_node->next->data < value) {
        iter_node = iter_node->next;
    }

    newNode->next = iter_node->next;
    iter_node->next = newNode;
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

    // LSearch() test code
    int value_to_find;
    printf("Enter the value you want to find: ");
    scanf("%d", &value_to_find);
    Node* result = LSearch(head, value_to_find);

    if (result != NULL) {
        printf("Found node with value: %d\n", result->data);
    } else {
        printf("Value not found in the list\n");
    }

    // insertNewNode() test code
    insertNewNode(&head, 2, 1000);
    printList(head);
    insertNewNode(&head, 0, 251);
    printList(head);

    // insertEnd() test code
    insertEnd(&head, 555);
    printList(head);

    // insertSorted() test code
    // The linked list should be sorted before using this function, 
    // otherwise the function will
    // result in unexpected behaviours
    insertSorted(&head, 500);
    printList(head);

    // Free the memory
    free(arr);
    freeLinkedList(head);

    return 0;
}