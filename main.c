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
  };


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
  } while(!exit);

  return 0;
}