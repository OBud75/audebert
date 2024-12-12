#include <stdio.h>
#include <string.h>

// Définition des structures
typedef struct Person {
    int age;
} Person;

typedef struct Book {
    int pages;
} Book;

// Fonction de comparaison pour deux `Person`
int are_persons_equals(Person *p1, Person *p2) {
    return p1->age == p2->age;
}

// Fonction de comparaison pour deux `Book`
int are_books_equals(Book *b1, Book *b2) {
    return b1->pages == b2->pages;
}

// Fonction générique pour comparer deux objets
int are_equals(void *obj1, void *obj2, int (*compare_fnc)(void *, void *)) {
    return compare_fnc(obj1, obj2);
}

// Fonction pour chercher un objet dans un tableau
int is_in_array(void *obj_to_find, void *array, int nb_of_elems_in_array, size_t elem_size, int (*compare_fnc)(void *, void *)) {
    char *p = (char *)array; // Pointeur vers le début du tableau
    for (int i = 0; i < nb_of_elems_in_array; i++) {
        if (compare_fnc(obj_to_find, p)) {
            return 1; // Trouvé
        }
        p += elem_size; // Avancer au prochain élément
    }
    return 0; // Pas trouvé
}

int main() {
    // Exemple avec des personnes
    Person person1 = {50};
    Person person2 = {50};

    int same_age = are_equals(&person1, &person2, (int (*)(void *, void *)) are_persons_equals);

    if (same_age) {
        printf("Same age.\n");
    } else {
        printf("Different age.\n");
    }

    // Tableau de personnes
    Person people[] = {{20}, {50}};
    int found = is_in_array(&person1, people, sizeof(people) / sizeof(Person), sizeof(Person), (int (*)(void *, void *)) are_persons_equals);

    if (found) {
        printf("Person 1 is in the people array.\n");
    } else {
        printf("Person 1 is not in the people array.\n");
    }

    // Exemple avec des livres
    Book book1 = {100};
    Book book2 = {200};
    Book book_array[] = {{150}, {200}};

    int same_pages = are_equals(&book1, &book2, (int (*)(void *, void *)) are_books_equals);

    if (same_pages) {
        printf("Same number of pages.\n");
    } else {
        printf("Different number of pages.\n");
    }

    int book_found = is_in_array(&book2, book_array, sizeof(book_array) / sizeof(Book), sizeof(Book), (int (*)(void *, void *)) are_books_equals);

    if (book_found) {
        printf("Book 2 is in the book array.\n");
    } else {
        printf("Book 2 is not in the book array.\n");
    }

    return 0;
}
