#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define COST int 50;

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

void make_reserve(struct reserve*, int*);
void assign_reserve_date(struct date*, bool);
void show_reserves(struct reserve*, int);


int main() {
  struct reserve reserves[50];
  int response = 0;
  bool exit = false;
  int arr_lenght = 0;
  
  do {
    printf("1. Registrar nueva reserva\n");
    printf("2. Modificar reserva\n");
    printf("3. Cancelar reserva\n");
    printf("4. Buscar reserva\n");
    printf("5. Mostrar todas las reservas\n");
    printf("6. Salir\n");

    scanf("%d", &response);

    if (response == 6) exit = true;
    if (response == 1) make_reserve(reserves, &arr_lenght);
    if (response == 5) show_reserves(reserves, arr_lenght);
  } while(!exit);

  return 0;
}

void assign_reserve_date(struct date *reserve_date, bool in_or_out) {
  char in_out[] = "llegada";

  if (in_or_out == false) {
    strcpy(in_out, "salida");
  }

  printf("Ingrese el dia de %s:\n", in_out);
  scanf("%d", &reserve_date->day);
  printf("Ingrese el mes de %s:\n", in_out);
  scanf("%d", &reserve_date->month);
  printf("Ingrese el año de %s:\n", in_out);
  scanf("%d", &reserve_date->year);
}

void make_reserve(struct reserve *reserves, int *lenght) {
  struct reserve new_reserve;
  struct date in_date;
  struct date out_date;
  int is_continental;

  printf("Nombre del cliente:\n");
  scanf("%s", new_reserve.name);
  printf("Numero de habitacion:\n");
  scanf("%d", &new_reserve.room_number);
  printf("Incluye desayuno (0/1):\n");
  scanf("%d", &is_continental);
  new_reserve.id = *lenght;

  // Assign boolean value to continental in struct
  if (is_continental == true) {
    new_reserve.continental = 1;
  } else {
    new_reserve.continental = 0;
  }

  assign_reserve_date(&in_date, true);
  assign_reserve_date(&out_date, false);

  new_reserve.date_in = in_date;
  new_reserve.date_out = out_date;

  reserves[*lenght] = new_reserve;
  *lenght += 1;
}

void show_reserves(struct reserve *reserves, int lenght) {
  int size = (lenght == 0 ? 0 : lenght - 1);

  for (int i = 0; i <= size; i++) {
    printf("[%d] Nombre cliente: %s, Numero de reserva: %d, Fecha de llegada: %d/%d/%d, Fecha de salida: %d/%d/%d, Numero de cuarto: %d, Desayuno: %d, Costo: %2.f\n",
    i+1, reserves[i].name, reserves[i].id, reserves[i].date_in.day, reserves[i].date_in.month, reserves[i].date_in.year, reserves[i].date_out.day, reserves[i].date_out.month, reserves[i].date_out.year, reserves[i].room_number, reserves[i].continental, reserves[i].cost);
  }
}