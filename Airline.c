#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define colum 6
#define fil 32
char vuelo[5] = "";
int asientos[32][6];
int main(void)
{
  while(1)
  {
      printf("Ingrese su vuelo: ");
      scanf("%s", vuelo);
      int leg = strlen(vuelo);
      if(leg != 5)
      {
        printf("Por favor ingrese un vuelo de 5 caracteres\n");
      }
      else
      {
        break;
      }
  }
    
    printf("Bienvenido a Charl´s Arline             vuelo: %s\n", vuelo);
    for(int i = 0; i < 32; i++)
    {
        for(int x = 0; x < 6; x++)
        {
            asientos[i][x] = 0;
        }
    }
    
    while(1)
    {
        int respuesta;
        printf("1. Reservar asiento. \n2. Ver disponibilidad de asientos. \n3. Ver Resumen \n4. Salir\n :> ");
        scanf("%d", &respuesta);
        if(respuesta == 1)
        {

        }
        else if (respuesta == 2)
        {

        }
        else if (respuesta == 3)
        {
            /* code */
        }
        else if (respuesta == 4)
        {
            break;
        }
        else
        {
            printf("Por favor sólo ingrese los números que aparecen en el menú");
        }
        
        
        
    }
    return 0;
}