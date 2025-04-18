#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char *array;
    int numElems;
    int size;
} Dyn_array_t;

void initArray(Dyn_array_t *array, int desSize) {
    if (array == NULL) {
        printf("The dynamic array is NULL!\n");
        return;
    }
    if (desSize <= 0) {
        printf("The requested size is less than or equal to zero!\n");
        return;
    }
    array->array = calloc(desSize + 1, sizeof(char));
    if (array->array == NULL) {
        printf("The allocation of memory failed!\n");
        return;
    }
    array->numElems = 0;
    array->size = desSize;
    array->array[0] = '\0';
}

void destroyArray(Dyn_array_t *array) {
    if (array == NULL) {
        printf("The dynamic array is NULL!\n");
        return;
    }
    if (array->array == NULL) {
        printf("The internal static array is NULL!\n");
        array->numElems = 0;
        array->size = 0;
        return;
    }
    // Compaction vom Array vor dem Löschen → Reduktion des reservierten Speicherplatzes auf maximal benötigten
    char* temp = realloc(array->array, (array->numElems + 1) * sizeof(char));
    if (temp == NULL) {
        printf("The reallocation of memory failed!\n");
        return;
    }
    array->array = temp;
    array->size = array->numElems;
    // printf("%lu, %llu\n", strlen(array->array), array->size * sizeof(char));
    // Ende der Compaction
    free(array->array);
    array->array = NULL;
    array->numElems = 0;
    array->size = 0;
}

void insert(Dyn_array_t *array, char elem) {
    if (array == NULL) {
        printf("The dynamic array is NULL!\n");
        return;
    }
    if (array->array == NULL) {
        printf("The internal static array is NULL!\n");
        return;
    }
    if (array->numElems == array->size) {
        char* temp = realloc(array->array, (2 * array->size + 1) * sizeof(char));
        if (temp == NULL) {
            printf("The reallocation of memory failed!\n");
            return;
        }
        array->array = temp;
        array->size *= 2;
    }
    array->array[array->numElems++] = elem;
    array->array[array->numElems] = '\0';
    // printf("%llu, %llu\n", strlen(array->array), array->size * sizeof(char));
}

int main() {
    Dyn_array_t example;
    initArray(&example, 2);
    insert(&example, 'a');
    insert(&example, 'b');
    insert(&example, 'c');
    insert(&example, 'd');
    insert(&example, 'e');
    destroyArray(&example);
    return EXIT_SUCCESS;
}