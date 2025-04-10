#include <stdio.h>

void print_tree_char(int height, char symbol) {
    if (height < 0) printf("Höhe kann nicht kleiner als 0 sein");
    else {
        int spaces = height - 1;
        int symbols = 1;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < spaces; j++) printf(" ");
            spaces--;
            for (int k = 0; k < symbols; k++) printf("%c", symbol);
            symbols += 2;
            printf("\n");
        }
        for (int l = 1; l < height; l++) printf(" ");
        printf("*\n");
    }
}

void print_tree(int height) { print_tree_char(height, '*'); }

int main() {
    print_tree(0);
    print_tree_char(5, 'o');
}