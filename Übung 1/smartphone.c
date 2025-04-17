#include <stdio.h>

typedef struct {
  char* brand;
  char* model;
  char* color;
  int memory;
} smartphone_t;

void print_smartphone_configuration(smartphone_t phone) {
  printf("Your configuration:\nBrand: %s\nModel: %s\nColor: %s\nTotal Memory: %iGB\n",
    phone.brand, phone.model, phone.color, phone.memory);
}

void add_additional_sd_card(smartphone_t* phone) { phone -> memory += 128; }

int main() {
  smartphone_t phone = {"Sumsang", "Milkyway S3", "black", 16};
  print_smartphone_configuration(phone);

  add_additional_sd_card(&phone);
  print_smartphone_configuration(phone);
}
