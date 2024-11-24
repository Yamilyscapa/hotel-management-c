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

void print_reserve(struct reserve);
void make_reserve(struct reserve*, int*);
void assign_reserve_date(struct date*, bool);
void show_reserves(struct reserve*, int);
void cancel_reserve(struct reserve*);
void search_reserve(struct reserve*);
void set_reserve_price(struct reserve*);

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
    if (response == 4) search_reserve(reserves);
    if (response == 3) cancel_reserve(reserves);

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
    printf("[%d] ", i+1);
    print_reserve(reserves[i]);
  }
}

void cancel_reserve(struct reserve *reserves) {
  int id = 0;
  char name[20];
  bool founded = false;
  bool confirmation = false;
  int confirmation_temp;
  struct reserve blank_reserve;

  printf("Ingrese el numero de la reserva a cancelar:\n");
  scanf("%d", &id);
  printf("Ingrese el nombre de la reserva a cancelar:\n");
  scanf("%s", name);
  
  for (int i = 0; i < 50; i++) {
    if (reserves[i].id == id && strcmp(reserves[i].name ,name) == 0) {
      print_reserve(reserves[i]);
      founded = 1;

      if (founded == true) {
      printf("Seguro de cancelar la reserva? (0/1):\n");
      scanf("%d", &confirmation_temp);
      confirmation = confirmation_temp;

      if (confirmation == true) {
        reserves[i] = blank_reserve;
        printf("Reserva cancelada con exito\n");
      } else {
        printf("Operacion cancelada\n");
      }
    }
  }
}

  
}

void search_reserve(struct reserve *reserves) {
  int id = 0;
  char name[20];

  printf("Ingrese el numero de la reserva:\n");
  scanf("%d", &id);
  printf("Ingrese el nombre de la reserva:\n");
  scanf("%s", name);
  
  for (int i = 0; i < 50; i++) {
    if (reserves[i].id == id && strcmp(reserves[i].name ,name) == 0) {
      print_reserve(reserves[i]);
    }
  }
}

void set_reserve_price(struct reserve *reserve) {}

void print_reserve(struct reserve reserve) {
  printf("Nombre cliente: %s, Numero de reserva: %d, Fecha de llegada: %d/%d/%d, Fecha de salida: %d/%d/%d, Numero de cuarto: %d, Desayuno: %d, Costo: %2.f\n", reserve.name, reserve.id, reserve.date_in.day, reserve.date_in.month, reserve.date_in.year, reserve.date_out.day, reserve.date_out.month, reserve.date_out.year, reserve.room_number, reserve.continental, reserve.cost);
}