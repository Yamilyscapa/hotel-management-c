#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define RESERVE_COST 50
#define CONTINENTAL_COST 25
#define RESERVES_SIZE 100

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
void cancel_reserve(struct reserve*, int*);
int search_reserve(struct reserve*);
void edit_reserve(struct reserve*);
void set_reserve_price(struct reserve*);
void clearsc();

int main() {
  struct reserve reserves[RESERVES_SIZE];
  int response = 0;
  bool exit = false;
  int arr_lenght = 0;
  
  do {
    clearsc();
    printf("1. Registrar nueva reserva\n");
    printf("2. Modificar reserva\n");
    printf("3. Cancelar reserva\n");
    printf("4. Buscar reserva\n");
    printf("5. Mostrar todas las reservas\n");
    printf("6. Salir\n");

    scanf("%d", &response);

    if (response == 1) make_reserve(reserves, &arr_lenght);
    if (response == 2) edit_reserve(reserves);
    if (response == 3) cancel_reserve(reserves, &arr_lenght);
    if (response == 4) search_reserve(reserves);
    if (response == 5) show_reserves(reserves, arr_lenght);
    if (response == 6) exit = true;

  } while(!exit);

  return 0;
}

void assign_reserve_date(struct date *reserve_date, bool in_or_out) {
  clearsc();
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
  clearsc();
  struct reserve new_reserve;
  struct date in_date;
  struct date out_date;
  int is_continental;
  int id = *lenght+1;
  bool exit = false;
  int exit_temp = 0;

  printf("Nombre del cliente:\n");
  scanf("%s", new_reserve.name);
  do{
    printf("Numero de habitacion (0-100):\n");
    scanf("%d", &new_reserve.room_number);
  } while (new_reserve.room_number > 100 || new_reserve.room_number < 0);
  printf("Incluye desayuno (0/1):\n");
  scanf("%d", &is_continental);
  new_reserve.id = id;

  // Assign boolean value to continental in struct
  if (is_continental == true) {
    new_reserve.continental = 1;
  } else {
    new_reserve.continental = 0;
  }

  assign_reserve_date(&in_date, true);
  assign_reserve_date(&out_date, false);

  if (in_date.month > out_date.month || in_date.year > out_date.year) {
    printf("La fecha de llegada no puede ser despues de la de salida\n");
    while(!exit) {
      printf("Continuar (1):");
      scanf("%d", &exit_temp);
      exit = exit_temp;
    }

    assign_reserve_date(&in_date, true);
    assign_reserve_date(&out_date, false);
  } else if (in_date.day == out_date.day && in_date.day == out_date.day && in_date.year == out_date.year) {
    printf("La fecha de salida y de entrada no pueden ser las mismas\n");
    while(!exit) {
      printf("Continuar (1):");
      scanf("%d", &exit_temp);
      exit = exit_temp;
    } 

    assign_reserve_date(&in_date, true);
    assign_reserve_date(&out_date, false);
  }

  new_reserve.date_in = in_date;
  new_reserve.date_out = out_date;

  set_reserve_price(&new_reserve);

  reserves[*lenght] = new_reserve;
  *lenght += 1;


  printf("Reserva generada con exito! su id es: %d\n", new_reserve.id);
  while(!exit) {
    printf("Continuar (1):");
    scanf("%d", &exit_temp);
    exit = exit_temp;
  }
}

void clearsc() {
  printf("\033[H\033[J");
}

void show_reserves(struct reserve *reserves, int lenght) {
  clearsc();
  bool exit = false;
  int exit_temp = 0;
  int size = (lenght == 0 ? 0 : lenght - 1);

  for (int i = 0; i <= size; i++) {
    if (reserves[i].id == 0) continue;
    printf("[%d] ", i+1);
    print_reserve(reserves[i]);
  }

  while(!exit) {
    printf("Continuar (1):");
    scanf("%d", &exit_temp);
    exit = exit_temp;
  }
}

void cancel_reserve(struct reserve *reserves, int *lenght) {
  clearsc();
  int id = 0;
  char name[20];
  bool founded = false;
  bool confirmation = false;
  int confirmation_temp;

  printf("Ingrese el numero de la reserva a cancelar:\n");
  scanf("%d", &id);
  printf("Ingrese el nombre de la reserva a cancelar:\n");
  scanf("%s", name);
  
  int j = 50;

  for (int i = 0; i < 50; i++) {
    if (reserves[i].id == id && strcmp(reserves[i].name ,name) == 0) {
      print_reserve(reserves[i]);
      founded = 1;

      if (founded == true) {
      printf("Seguro de cancelar la reserva? (0/1):\n");
      scanf("%d", &confirmation_temp);
      confirmation = confirmation_temp;

      if (confirmation == true) {
        reserves[i] = reserves[j];
        reserves[i].id = 0;
        lenght--;
        printf("Reserva cancelada con exito\n");
      } else {
        printf("Operacion cancelada\n");
      }
    }
  }
  j--;
}

}

int search_reserve(struct reserve *reserves) {
  clearsc();
  int id = 0;
  char name[20];
  int exit_temp = 0;
  bool exit = false;

  printf("Ingrese el id de la reserva:\n");
  scanf("%d", &id);
  printf("Ingrese el nombre del cliente:\n");
  scanf("%s", name);
  
  for (int i = 0; i < RESERVES_SIZE; i++) {
    if (reserves[i].id == id && strcmp(reserves[i].name ,name) == 0) {
      print_reserve(reserves[i]);
    } else if (i == RESERVES_SIZE && id == 0) {
        printf("Reserva no encontrada\n");
      return 0;
    }
  }

   while(!exit) {
    printf("Continuar (1):");
    scanf("%d", &exit_temp);
    exit = exit_temp;
  }

  return id-1;
}

void set_reserve_price(struct reserve *reserve) {
  float cost = 0.0;
  int diff_d = (reserve->date_out.day - reserve->date_in.day);
  int diff_m = (reserve->date_out.month - reserve->date_in.month) * 30.4;
  int diff_y = (reserve->date_out.year - reserve->date_in.year) / 365;

  cost = (diff_d + diff_m + diff_y) * RESERVE_COST;

  if (reserve->continental == true) { 
    cost += CONTINENTAL_COST;
  }

  reserve->cost = cost;
}

void edit_reserve(struct reserve *reserves) {
  clearsc();
  int id = search_reserve(reserves);
  int response = 0;
  int continental_temp;
  
  printf("Que dato desea modificar?\n- fecha de llegada: 1\n- fecha de salida: 2\n- desayuno: 3\n");
  scanf("%d", &response);

  switch (response) {
    case 1:
      assign_reserve_date(&reserves[id].date_in, true);
      printf("Reserva modificada con exito!\n");
    break;

    case 2:
      assign_reserve_date(&reserves[id].date_in, false);
      printf("Reserva modificada con exito!\n");
    break;

    case 3:
      printf("Desea incluir desayuno? (0/1):\n");
      scanf("%d", &continental_temp);
      reserves[id].continental = (continental_temp == 0 ? false : true);
      printf("Reserva modificada con exito!\n");
    break;

    default:
      printf("Opcion no valida\n");
    break;
  }  
}

void print_reserve(struct reserve reserve) {
  clearsc();
  printf("Nombre cliente: %s, Numero de reserva: %d, Fecha de llegada: %d/%d/%d, Fecha de salida: %d/%d/%d, Numero de cuarto: %d, Desayuno: %d, Costo: %2.f\n", reserve.name, reserve.id, reserve.date_in.day, reserve.date_in.month, reserve.date_in.year, reserve.date_out.day, reserve.date_out.month, reserve.date_out.year, reserve.room_number, reserve.continental, reserve.cost);
}