#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Öðrenci yapýsý
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Yeni düðüm eklemek için kullanýlan yardýmcý fonksiyon
Node* addNode(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Baðlý listeyi büyükten küçüðe sýralamak için kullanýlan fonksiyon
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

// Baðlý listeyi ekrana yazdýrmak için kullanýlan fonksiyon
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
    // Rastgele 100 sayý ekleyin
    for (i = 0; i < 100; i++) {
        int randomNumber = rand() % 100;  // 0 ile 99 arasýnda rastgele sayý üret
        head = addNode(head, randomNumber);
    }

    printf("Random Numbers: ");
    printList(head);

    // Baðlý listeyi büyükten küçüðe sýralayýn
    head = sortList(head);

    printf("Ranked Numbers: ");
    printList(head);

    // Belleði temizle
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}


