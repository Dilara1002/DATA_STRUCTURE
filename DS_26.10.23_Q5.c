#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int number;
    char name[50];
    int age;
    struct Student* next;
} Student;

// Yeni öðrenci düðümü eklemek için kullanýlan yardýmcý fonksiyon
Student* addStudent(Student* head, int number, const char* name, int age) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->number = number;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->next = head;
    return newStudent;
}

// Listede öðrenci adýna göre arama ve bir sonraki düðümü silme fonksiyonu
void deleteNextStudentByName(Student* head, const char* name) {
    Student* current = head;

    while (current != NULL && current->next != NULL) {
        if (strcmp(current->name, name) == 0) {
            Student* nextStudent = current->next;
            current->next = nextStudent->next;
            free(nextStudent); // Bir sonraki öðrenciyi sil
            return;
        }
        current = current->next;
    }
}

// Öðrenci listesini ekrana yazdýrmak için kullanýlan fonksiyon
void printStudents(Student* head) {
    Student* current = head;
    while (current != NULL) {
        printf("%d - %s %d\n", current->number, current->name, current->age);
        current = current->next;
    }
}

int main() {
    Student* head = NULL;

    // Öðrenci bilgilerini ekleyin
    head = addStudent(head, 201, "Saliha", 27);
    head = addStudent(head, 203, "Ece", 19);
    head = addStudent(head, 205, "Ali", 22);
    head = addStudent(head, 207, "Aysel", 20);

    printf("Student List:\n");
    printStudents(head);

    char searchName[50];
    printf("Enter the name of student who you want to delete from the student list: ");
    scanf("%s", searchName);

    // Ýsimle öðrenci arama ve bir sonraki öðrenciyi silme
    deleteNextStudentByName(head, searchName);

    printf("Student List(Student is deleted who has been later):\n");
    printStudents(head);

    // Belleði temizle
    while (head != NULL) {
        Student* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

