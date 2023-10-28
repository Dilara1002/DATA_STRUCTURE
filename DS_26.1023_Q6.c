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

// Listede en uzun ismin olduðu kaydý bulup yazdýran fonksiyon
void findLongestName(Student* head) {
    Student* current = head;
    char* longestName = "";
    int maxLength = 0;

    while (current != NULL) {
        int currentLength = strlen(current->name);
        if (currentLength > maxLength) {
            maxLength = currentLength;
            longestName = current->name;
        }
        current = current->next;
    }

    if (maxLength > 0) {
        printf("The Longest Name Int The List: %s\nUzunluk: %d\n", longestName, maxLength);
    } else {
        printf("The name could not found in the list.\n");
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
    head = addStudent(head, 209, "Abdurrahmangazi", 25);

    printf("Student List:\n");
    printStudents(head);

    // En uzun ismi bulup yazdýrma
    findLongestName(head);

    // Belleði temizle
    while (head != NULL) {
        Student* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}


