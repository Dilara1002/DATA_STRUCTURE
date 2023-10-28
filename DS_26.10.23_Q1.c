#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* addNode(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void rearrangeList(Node** head) {
    Node* current = *head;
    Node* oddHead = NULL;
    Node* evenHead = NULL;
    Node* oddTail = NULL;
    Node* evenTail = NULL;

    while (current != NULL) {
        if (current->data % 2 == 0) {
            if (evenHead == NULL) {
                evenHead = evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }
        } else {
            if (oddHead == NULL) {
                oddHead = oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = current;
            }
        }
        current = current->next;
    }

    if (oddTail != NULL) {
        oddTail->next = evenHead;
        *head = oddHead;
    } else {
        *head = evenHead;
    }

    if (evenTail != NULL) {
        evenTail->next = NULL;
    }
}

int main() {
    Node* head = NULL;
    int value;

    printf("Enter numbers (type -1 to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        head = addNode(head, value);
    }

    rearrangeList(&head);

    printf("Rearranged List: ");
    printList(head);
    


    return 0;
}

