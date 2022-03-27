#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Retorna true si ambos strings son iguales */
bool string_equals(char *string1, char *string2)
{
  return !strcmp(string1, string2);
}

/* Revisa que los parametros del programa sean válidos */
bool check_arguments(int argc, char **argv)
{
  if (argc != 3)
  {
    printf("Modo de uso: %s INPUT OUTPUT\n", argv[0]);
    printf("Donde:\n");
    printf("\tINPUT es la ruta del archivo de input\n");
    printf("\tOUTPUT es la ruta del archivo de output\n");
    return false;
  }

  return true;
}

int main(int argc, char **argv)
{
  /* Si los parámetros del programa son inválidos */
  if (!check_arguments(argc, argv))
  {
    /* Salimos del programa indicando que no terminó correctamente */
    return 1;
  }

  /* Abrimos el archivo de input */
  FILE *input_file = fopen(argv[1], "r");

  /* Abrimos el archivo de output */
  FILE *output_file = fopen(argv[2], "w");


  char command[32];


  /* Leemos la cantidad de restaurantes y de mesas en cada uno*/
  int N_LOCATIONS;
  fscanf(input_file, "%d", &N_LOCATIONS);

  int N_TABLES;
  for (int s = 0; s < N_LOCATIONS; s++)
  {
    fscanf(input_file, "%d", &N_TABLES);
    /*  [Por terminar] crear el restaurante con su numero correspondiente de mesas */
  }

  int TOTAL_TABLES;
  fscanf(input_file, "%d", &TOTAL_TABLES);


  /*EVENTO OPEN TABLE*/

  int location_id, table_id, capacity;
  for (int s = 0; s < TOTAL_TABLES; s++)
  {
      fscanf(input_file, "%s %d %d %d", command, &location_id, &table_id, &capacity);
      /* Evento de apertura de mesa en un restaurant con su respectiva capacidad */
  }



  /* EVENTO MENU-ITEM*/
  int N_ITEMS;
  fscanf(input_file, "%d", &N_ITEMS);
  /*  [Por terminar] crear los items del menu correspondientes */


  int item_id, price;
  for (int s = 0; s < N_ITEMS; s++)
  {
      fscanf(input_file, "%s %d %d", command, &item_id, &price);
      /* Evento de creacion de un plato (Todos los restaurantes comparten el mismo menu) */
  }


  /* String para guardar la instrucción actual*/

  /* Leemos la primera instrucción */
  fscanf(input_file, "%s", command);

  /* Mientras la instrucción sea distinta a END */
  while(!string_equals(command, "END"))
  {
    /* [Por terminar] implementar cada evento abajito */
   if (string_equals(command, "CUSTOMER")) {
      int location_id, table_id, customer_id;
      fscanf(input_file, "%d %d %d", &location_id, &table_id, &customer_id);

      /* Evento de llegada de un cliente a una mesa abierta en algun restaurante especifico */
    }
    else if (string_equals(command, "TABLE-STATUS"))
    {
      int location_id, table_id;
      fscanf(input_file, "%d %d", &location_id, &table_id);


    }
    else if (string_equals(command, "ORDER-CREATE"))
    {
      int location_id, table_id, customer_id, item_id;
      fscanf(input_file, "%d %d %d %d", &location_id, &table_id, &customer_id, &item_id);

    }
    else if (string_equals(command, "ORDER-CANCEL"))
    {
      int location_id, table_id, customer_id;
      fscanf(input_file, "%d %d %d", &location_id, &table_id, &customer_id);

    }
    else if (string_equals(command, "BILL-CREATE"))
    {
      int location_id, table_id;
      fscanf(input_file, "%d %d", &location_id, &table_id);


    }
    else if (string_equals(command, "CHANGE-SEATS"))
    {
      int location_id, first_table_id, first_customer_id, last_table_id, last_customer_id;
      fscanf(input_file, "%d %d %d %d %d", &location_id, &first_table_id, &first_customer_id, &last_table_id, &last_customer_id);
    }

    else if (string_equals(command, "PERROU-MUERTO"))
    {
      int location_id, table_id, customer_id;
      fscanf(input_file, "%d %d %d", &location_id, &table_id, &customer_id);
    }

    /* Leemos la siguiente instrucción */
    fscanf(input_file, "%s", command);
  }
  /*  [Por terminar] Generar el estado de todas las mesas en todos los restaurantes */


  /*  [Por terminar] Liberar estructuras */
  fclose(input_file);
  fclose(output_file);

  return 0;
}