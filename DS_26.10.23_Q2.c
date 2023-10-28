#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ��renci yap�s�
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Yeni d���m eklemek i�in kullan�lan yard�mc� fonksiyon
Node* addNode(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Ba�l� listeyi b�y�kten k����e s�ralamak i�in kullan�lan fonksiyon
Node* sortList(Node* head) {
    Node* sortedList = NULL;
    Node* current = head;
    Node* temp;

    while (current != NULL) {
        Node* next = current->next;

        if (sortedList == NULL || current->data >= sortedList->data) {
            current->next = sortedList;
            sortedList = current;
        } else {
            temp = sortedList;
            while (temp->next != NULL && temp->next->data > current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    return sortedList;
}

// Ba�l� listeyi ekrana yazd�rmak i�in kullan�lan fonksiyon
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf("->");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    srand(time(NULL));
	int i;
    // Rastgele 100 say� ekleyin
    for (i = 0; i < 100; i++) {
        int randomNumber = rand() % 100;  // 0 ile 99 aras�nda rastgele say� �ret
        head = addNode(head, randomNumber);
    }

    printf("Random Numbers: ");
    printList(head);

    // Ba�l� listeyi b�y�kten k����e s�ralay�n
    head = sortList(head);

    printf("Ranked Numbers: ");
    printList(head);

    // Belle�i temizle
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}


