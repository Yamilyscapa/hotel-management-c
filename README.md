# Gestión de Reservas de Hotel

Este proyecto implementa un sistema básico de gestión de reservas para un hotel, utilizando el lenguaje de programación C. Permite registrar, editar, buscar, cancelar y visualizar reservas, además de calcular los costos asociados a las mismas.

---

## **Contenido**

1. [Características](#características)
2. [Requisitos del Sistema](#requisitos-del-sistema)
3. [Compilación y Ejecución](#compilación-y-ejecución)
4. [Uso](#uso)
5. [Estructuras y Funcionalidades](#estructuras-y-funcionalidades)

---

## **Características**

- Registro de nuevas reservas.
- Edición de detalles de reservas existentes.
- Búsqueda de reservas por ID y nombre del cliente.
- Cancelación de reservas.
- Visualización de todas las reservas.
- Cálculo automático de costos según la duración de la estadía y la inclusión de desayuno.

---

## **Requisitos del Sistema**

- **Compilador C:** GCC o cualquier compilador compatible con ANSI C.
- **Sistema Operativo:** Cualquier sistema que soporte C (Linux, Windows, macOS).
- **Bibliotecas estándar:** `stdio.h`, `stdbool.h`, `string.h`, `stdlib.h`, `ctype.h`.

---

## **Compilación y Ejecución**

1. **Compilación:**
   Ejecuta el siguiente comando en la terminal para compilar el programa:

   ```bash
   gcc -o hotel_reservations main.c
   ```

2. **Ejecución:**
   Una vez compilado, ejecuta el programa:
   ```bash
   ./hotel_reservations
   ```

---

## **Uso**

Al iniciar el programa, se muestra un menú interactivo con las siguientes opciones:

1. Registrar nueva reserva.
2. Modificar reserva existente.
3. Cancelar una reserva.
4. Buscar reserva por ID y nombre.
5. Mostrar todas las reservas.
6. Salir del programa.

Selecciona la opción deseada introduciendo el número correspondiente.

---

## **Estructuras y Funcionalidades**

### **Estructura Principal**

#### `struct reserve`

Almacena la información de una reserva, incluyendo:

- `name`: Nombre del cliente.
- `id`: Número único de reserva.
- `date_in` y `date_out`: Fechas de entrada y salida.
- `room_number`: Número de habitación.
- `continental`: Indica si incluye desayuno (0 = No, 1 = Sí).
- `cost`: Costo total de la reserva.

#### `struct date`

Representa una fecha con día, mes y año.

---

### **Funciones**

1. **`make_reserve`**  
   Registra una nueva reserva solicitando datos al usuario, asigna un ID único y calcula el costo.

2. **`assign_reserve_date`**  
   Permite ingresar las fechas de entrada y salida de la reserva.

3. **`show_reserves`**  
   Muestra todas las reservas registradas, excepto las que están canceladas.

4. **`cancel_reserve`**  
   Permite cancelar una reserva buscando por ID y nombre.

5. **`search_reserve`**  
   Busca una reserva específica y la imprime.

6. **`edit_reserve`**  
   Modifica datos como fecha de entrada, salida o si incluye desayuno.

7. **`set_reserve_price`**  
   Calcula el costo de la reserva basado en la duración y los servicios seleccionados.

8. **`print_reserve`**  
   Imprime los detalles de una reserva en formato legible.

---

## **Notas Adicionales**

- **Límites del sistema:**

  - Soporta hasta 100 reservas simultáneamente.
  - Los números de habitación deben estar entre 0 y 100.
  - Los datos se mantienen en memoria mientras se ejecuta el programa. No se guardan en archivos.

- **Errores comunes:**
  - Ingresar una fecha de salida anterior a la de entrada.
  - Usar IDs duplicados para búsquedas o cancelaciones.
