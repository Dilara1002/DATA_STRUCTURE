#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int number;
    char name[50];
    int age;
    struct Student* next;
} Student;

// ��renci ad�na g�re kay�t arama fonksiyonu
Student* findStudentByName(Student* head, const char* name) {
    Student* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current; // �sim bulundu, ��renci bilgisini d�nd�r
        }
        current = current->next;
    }
    return NULL; // �sim bulunamazsa NULL d�nd�r
}
void freeList(Student* head) {
    while (head != NULL) {
        Student* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Student* head = NULL;
    int studentCount = 0;

    // ��renci bilgilerini ekleme i�lemi
    head = (Student*)malloc(sizeof(Student));
    head->number = 201;
    strcpy(head->name, "Dilara");
    head->age = 21;
    head->next = (Student*)malloc(sizeof(Student));
    head->next->number = 203;
    strcpy(head->next->name, "Efe");
    head->next->age = 25;
    head->next->next =(Student*)malloc(sizeof(Student));
    head->next->next->number=211;
    strcpy(head->next->next->name, "Necmettin");
    head->next->next->age= 23;
    head->next->next->next =NULL;

    studentCount = 3; // Toplam ��renci say�s�

    printf("Student Information:\n");
    // ��renci bilgilerini ekrana yazd�rma
    Student* current = head;
    while (current != NULL) {
        printf("%d - %s %d %d\n", current->number, current->name, current->age, current->number);
        current = current->next;
    }

    // �simle ��renci arama
    char searchName[50];
    printf("Enter the student name who will search: ");
    scanf("%s", searchName);

    Student* foundStudent = findStudentByName(head, searchName);

    if (foundStudent != NULL) {
        printf("Student is found: %d - %s %d %d\n", foundStudent->number, foundStudent->name, foundStudent->age, foundStudent->number);
    } else {
        printf("Student could not found.\n");
    }
	
	freeList(head);
    return 0;
}

