#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct date {
  int day, month, year;
};

struct reserve {
  char name[20];
  int id;
  struct date date_in;
  struct date date_out;
  int room_number;
  bool continental;
  float cost;
};

int make_reserve(/* char[], int, char[], char[], int, bool */);

int main() {
  struct reserve reserves[25];
  int response = 0;
  bool exit = false;
  
  do {
    printf("1. Registrar nueva reserva\n");
    printf("2. Modificar reserva\n");
    printf("3. Cancelar reserva\n");
    printf("4. Buscar reserva\n");
    printf("5. Mostrar todas las reservas\n");
    printf("6. Salir\n");

    scanf("%d", &response);

    if (response == 6) exit = true;
    if (response == 1) make_reserve();
  } while(!exit);

  return 0;
}

int make_reserve() {
  struct reserve new_reserve;
  int continental_temp;

  printf("Nombre del cliente:\n");
  scanf("%s", new_reserve.name);
  printf("Codigo de reserva:\n");
  scanf("%d", &new_reserve.id);
  printf("Numero de habitacion:\n");
  scanf("%d", &new_reserve.room_number);
  printf("Incluye desayuno (y/n):\n");
  scanf("%d", &continental_temp);
  // Assign boolean value to continental in struct
  if (continental_temp == true) {
    new_reserve.continental = true;
  } else {
    new_reserve.continental = false;
  }

  printf("%d\n", new_reserve.continental);
  return 0;
}