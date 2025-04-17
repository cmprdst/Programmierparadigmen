#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int is_prime(int num) {
    if (num < 2) { printf("Eine Zahl < 2 kann keine Primzahl sein!\n"); return 0; }

    int idxAddPrime = 0; // wo die nächste Primzahl im Array hingehört
    int length = 10;
    int *primes = malloc(length * sizeof(int)); // dynamisches Array → manuell Speicher allozieren für var. Größe
    if (primes == NULL) { printf("Speicherzuweisung fehlgeschlagen!\n"); return 0; }
    for (int i = 0; i < length; i++) primes[i] = 0;

    for (int i = 2; i <= sqrt(num); i++) { // max. (sqrt(num))² = num
        for (int j = 0; j <= idxAddPrime; j++) {
            if (primes[j] == 0) { // durch keine bisherige Primzahl teilbar → Primzahl
                primes[idxAddPrime++] = i;

                if (idxAddPrime == length) { // Array voll
                    length += 10;
                    int *temp = realloc(primes, sizeof(int) * length);
                    if (temp == NULL) {
                        printf("Speichervergrößerung fehlgeschlagen!\n");
                        free(primes);
                        return 0;
                    }
                    primes = temp;
                    for (int k = idxAddPrime; k < length; k++) primes[k] = 0;
                }
                break;
            }
            if (i % primes[j] == 0) break; // durch Primzahl teilbar → keine Primzahl
        }
    }
    for (int i = 0; i <= idxAddPrime; i++) { // Teilbarkeit von num durch alle Primzahlen prüfen
        if (primes[i] == 0) break;
        if (num % primes[i] == 0) {
            printf("%i ist keine Primzahl.\n", num);
            free(primes);
            return 0;
        }
    }
    printf("%i ist eine Primzahl.\n", num);
    free(primes);
    return 1;
}


int calculate_nth_prime_number(int n) {
    if (n < 1) { printf("Eine Zahl < 1 ergibt keinen Sinn!\n"); return 0; }

    int idxAddPrime = 0;
    int primes[n];
    for (int i = 0; i < n; i++) primes[i] = 0;

    for (int i = 2; idxAddPrime < n; i++) {
        for (int j = 0; j <= idxAddPrime; j++) {
            if (primes[j] == 0) { primes[idxAddPrime++] = i; break; }
            if (i % primes[j] == 0) break;
        }
    }
    printf("Die n-te Primzahl ist %i.\n", primes[n - 1]);
    return primes[n - 1];
}

int main() {
    is_prime(1); // 0
    is_prime(2); // 1
    is_prime(3); // 1

    calculate_nth_prime_number(5); // 11
}