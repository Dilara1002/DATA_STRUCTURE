#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int number;
    char name[50];
    int age;
    struct Student* next;
} Student;

void printStudents(Student* head) {
    Student* current = head;
    int count = 1;
    while (current != NULL) {
        printf("%d - %s %d %d\n", count, current->name, current->age, current->number);
        current = current->next;
        count++;
    }
}



int main() {
    Student* head = NULL;
    int studentCount = 0;

    // Öðrenci bilgilerini ekleme iþlemi
    head = (Student*)malloc(sizeof(Student));
    head->number = 201;
    strcpy(head->name, "Saliha");
    head->age = 27;
    head->next = (Student*)malloc(sizeof(Student));
    head->next->number =203 ;
    strcpy(head->next->name, "Ece");
    head->next->age = 19;
    head->next->next = NULL;

    studentCount = 2; // Toplam öðrenci sayýsý

    printf("Student Information:\n");
    printStudents(head);

    return 0;
}

