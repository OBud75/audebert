#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition des structures
typedef struct Person {
    int age;
} Person;

typedef struct Book {
    int pages;
} Book;

// Fonction de comparaison pour deux `Person`
int are_persons_equals(void *p1, void *p2) {
    Person *person1 = (Person *)p1;
    Person *person2 = (Person *)p2;
    return person1->age == person2->age;
}

// Fonction de comparaison pour deux `Book`
int are_books_equals(void *b1, void *b2) {
    Book *book1 = (Book *)b1;
    Book *book2 = (Book *)b2;
    return book1->pages == book2->pages;
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

    // On peu itérer directement sur les pointeurs:
    // for (char *p = (char *)array; p < (char *)array + nb_of_elems_in_array * elem_size; p += elem_size) {
    //     if (compare_fnc(obj_to_find, (void *)p)) {
    //         return 1;
    //     }
    // }
    return 0; // Pas trouvé
}

// Comme fonction de comparaison on peut penser à retourner -1 si obj1 < obj2, 0 si égal et 1 si obj1 > obj2

int main() {
    // Allouer dynamiquement deux personnes
    Person *person1 = (Person *)malloc(sizeof(Person));
    Person *person2 = (Person *)malloc(sizeof(Person));
    if (!person1 || !person2) {
        fprintf(stderr, "Erreur : échec de l'allocation mémoire pour Person.\n");
        free(person1);
        free(person2);
        return 1;
    }

    person1->age = 50;
    person2->age = 50;

    // Comparer deux personnes
    int same_age = are_equals(person1, person2, are_persons_equals);

    if (same_age) {
        printf("Same age.\n");
    } else {
        printf("Different age.\n");
    }

    // Allouer dynamiquement un tableau de personnes
    int num_people = 2;
    Person *people = (Person *)malloc(num_people * sizeof(Person));
    if (!people) {
        fprintf(stderr, "Erreur : échec de l'allocation mémoire pour le tableau de personnes.\n");
        free(person1);
        free(person2);
        return 1;
    }

    people[0].age = 20;
    people[1].age = 50;

    // Vérifier si person1 est dans le tableau
    int found = is_in_array(person1, people, num_people, sizeof(Person), are_persons_equals);

    if (found) {
        printf("Person 1 is in the people array.\n");
    } else {
        printf("Person 1 is not in the people array.\n");
    }

    // Allouer dynamiquement deux livres
    Book *book1 = (Book *)malloc(sizeof(Book));
    Book *book2 = (Book *)malloc(sizeof(Book));
    if (!book1 || !book2) {
        fprintf(stderr, "Erreur : échec de l'allocation mémoire pour Book.\n");
        free(person1);
        free(person2);
        free(people);
        free(book1);
        free(book2);
        return 1;
    }

    book1->pages = 100;
    book2->pages = 200;

    // Allouer dynamiquement un tableau de livres
    int num_books = 2;
    Book *book_array = (Book *)malloc(num_books * sizeof(Book));
    if (!book_array) {
        fprintf(stderr, "Erreur : échec de l'allocation mémoire pour le tableau de livres.\n");
        free(person1);
        free(person2);
        free(people);
        free(book1);
        free(book2);
        return 1;
    }

    book_array[0].pages = 150;
    book_array[1].pages = 200;

    // Comparer deux livres
    int same_pages = are_equals(book1, book2, are_books_equals);

    if (same_pages) {
        printf("Same number of pages.\n");
    } else {
        printf("Different number of pages.\n");
    }

    // Vérifier si book2 est dans le tableau de livres
    int book_found = is_in_array(book2, book_array, num_books, sizeof(Book), are_books_equals);

    if (book_found) {
        printf("Book 2 is in the book array.\n");
    } else {
        printf("Book 2 is not in the book array.\n");
    }

    // Libérer toute la mémoire allouée dynamiquement
    free(person1);
    free(person2);
    free(people);
    free(book1);
    free(book2);
    free(book_array);
    // En sortant du programme, toute la mémoire allouée est de toute façon libérée

    return 0;
}
