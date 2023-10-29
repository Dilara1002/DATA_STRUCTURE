#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Öðrenci yapýsý
typedef struct Student {
    int number;
    char name[50];
    int age;
    struct Student* next;
} Student;

// Yardýmcý fonksiyonlar
Student* addStudent(Student* head, int number, const char* name, int age) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->number = number;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->next = head;
    return newStudent;
}

void printStudents(Student* head) {
    Student* current = head;
    int count = 1;
    while (current != NULL) {
        printf("%d - %s %d %d\n", count, current->name, current->age, current->number);
        current = current->next;
        count++;
    }
}

Student* findStudentByName(Student* head, const char* name) {
    Student* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deleteNextStudentByName(Student* head, const char* name) {
    Student* current = head;
    while (current != NULL && current->next != NULL) {
        if (strcmp(current->name, name) == 0) {
            Student* nextStudent = current->next;
            current->next = nextStudent->next;
            free(nextStudent);
            return;
        }
        current = current->next;
    }
}

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
        printf("Listedeki en uzun isim: %s\nUzunluk: %d\n", longestName, maxLength);
    } else {
        printf("Listede isim bulunamadý.\n");
    }
}

int main() {
    Student* head = NULL;
    int studentCount = 0;

    while (1) {
        int choice;
        printf("\nMENU\n");
        printf("1. Ogrenci Ekle\n");
        printf("2. Ogrenci Bilgilerini Goster\n");
        printf("3. Ogrenci Adina Gore Kayit Ara\n");
        printf("4. Ogrenci Adina Gore Kaydi Sil\n");
        printf("5. En Uzun Isimli Ogrenciyi Bul\n");
        printf("6. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int number, age;
                char name[50];
                printf("Ogrenci numarasini girin: ");
                scanf("%d", &number);
                printf("Ogrenci adini girin: ");
                scanf("%s", name);
                printf("Ogrenci yaþini girin: ");
                scanf("%d", &age);
                head = addStudent(head, number, name, age);
                studentCount++;
                break;
            }
            case 2: {
                if (studentCount > 0) {
                    printf("Ogrenci Bilgileri:\n");
                    printStudents(head);
                } else {
                    printf("Henüz Ogrenci eklenmedi.\n");
                }
                break;
            }
            case 3: {
                if (studentCount > 0) {
                    char searchName[50];
                    printf("Aranacak Ogrenci adýný girin: ");
                    scanf("%s", searchName);
                    Student* foundStudent = findStudentByName(head, searchName);
                    if (foundStudent != NULL) {
                        printf("Ogrenci bulundu: %d - %s %d %d\n", foundStudent->number, foundStudent->name, foundStudent->age, foundStudent->number);
                    } else {
                        printf("Ogrenci bulunamadý.\n");
                    }
                } else {
                    printf("Henüz Ogrenci eklenmedi.\n");
                }
                break;
            }
            case 4: {
                if (studentCount > 0) {
                    char searchName[50];
                    printf("Silmek istediðiniz öðrenci adýný girin: ");
                    scanf("%s", searchName);
                    deleteNextStudentByName(head, searchName);
                    printf("Ogrenci silindi.\n");
                } else {
                    printf("Henüz Ogrenci eklenmedi.\n");
                }
                break;
            }
            case 5: {
                if (studentCount > 0) {
                    findLongestName(head);
                } else {
                    printf("Henüz Ogrenci eklenmedi.\n");
                }
                break;
            }
            case 6:
                // Çýkýþ iþlemi
                while (head != NULL) {
                    Student* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Geçersiz seçenek, lütfen tekrar deneyin.\n");
        }
    }

    return 0;
}

