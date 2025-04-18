#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* concat(char* string1, char* string2) {
   if (string1 == NULL || string2 == NULL) {
      printf("At least one String is NULL!\n");
      return NULL;
   }
   if (strlen(string1) == 0) return string2;
   if (strlen(string2) == 0) return string1;

   char* concatStr = malloc((strlen(string1) + strlen(string2) + 1) * sizeof(char));
   if (concatStr == NULL) {
      printf("Trying to reserve memory failed!\n");
      return NULL;
   }
   for (size_t i = 0; i < strlen(string1); i++) concatStr[i] = string1[i];
   for (size_t j = 0; j < strlen(string2); j++) concatStr[strlen(string1) + j] = string2[j];
   concatStr[strlen(string1) + strlen(string2)] = '\0';
   return concatStr;
}

int main() {
   char* string1 = "Hello ";
   char* string2 = "World!";
   char* concatStr = concat(string1, string2);
   printf("%s\n", concatStr);
   free(concatStr);
   return EXIT_SUCCESS;
}