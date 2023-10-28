#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int number;
    char name[50];
    int age;
    struct Student* next;
} Student;

// Yeni ��renci d���m� eklemek i�in kullan�lan yard�mc� fonksiyon
Student* addStudent(Student* head, int number, const char* name, int age) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->number = number;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->next = head;
    return newStudent;
}

// Listede ��renci ad�na g�re arama ve bir sonraki d���m� silme fonksiyonu
void deleteNextStudentByName(Student* head, const char* name) {
    Student* current = head;

    while (current != NULL && current->next != NULL) {
        if (strcmp(current->name, name) == 0) {
            Student* nextStudent = current->next;
            current->next = nextStudent->next;
            free(nextStudent); // Bir sonraki ��renciyi sil
            return;
        }
        current = current->next;
    }
}

// ��renci listesini ekrana yazd�rmak i�in kullan�lan fonksiyon
void printStudents(Student* head) {
    Student* current = head;
    while (current != NULL) {
        printf("%d - %s %d\n", current->number, current->name, current->age);
        current = current->next;
    }
}

int main() {
    Student* head = NULL;

    // ��renci bilgilerini ekleyin
    head = addStudent(head, 201, "Saliha", 27);
    head = addStudent(head, 203, "Ece", 19);
    head = addStudent(head, 205, "Ali", 22);
    head = addStudent(head, 207, "Aysel", 20);

    printf("Student List:\n");
    printStudents(head);

    char searchName[50];
    printf("Enter the name of student who you want to delete from the student list: ");
    scanf("%s", searchName);

    // �simle ��renci arama ve bir sonraki ��renciyi silme
    deleteNextStudentByName(head, searchName);

    printf("Student List(Student is deleted who has been later):\n");
    printStudents(head);

    // Belle�i temizle
    while (head != NULL) {
        Student* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

