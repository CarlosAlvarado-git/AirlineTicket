#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define colum 6
#define fil 32
char vuelo[5] = "";
int asientos[32][6];
char nuevoasig[3] = "";
int contador = 0;
void clearscreen()
{
    system("@cls||clear");
}
void Convertir( int f, int c)// esta funo
{
    char numeros[2];
    sprintf(numeros, "%d", f);
    char letra[2];
    if( c == 0)
    {
        letra[0] = 'A';
    }
    if( c == 1)
    {
       letra[0] = 'B';
    }
    if( c == 2)
    {
        letra[0] = 'C';
    }
    if( c == 3)
    {
        letra[0] = 'D';
    }
    if( c == 4)
    {
        letra[0] = 'E';
    }
    if( c == 5)
    {
        letra[0] = 'F';
    }
    strcat(nuevoasig, letra);
    strcat(nuevoasig, numeros);

}
int Verificar(char asiento[3]) // 1: es vacío y correcto| 2: es lleno y correcto| 3: incorrecto ==== char string2 = {(char)M}; 70
{
    int devuelvo = 0; 
    int M = 65;
    int bal = 0;
    int columna;
    int fila;
    for(int i = 0; M <= 70; M++, i++)
    {   
        char letra = {(char)(M)};
        if(asiento[0] == letra)
        {
            bal = 1; 
            columna = i;
        }
    } 
    char numeros[2] = { asiento[1], asiento[2]};
    int numero = atoi(numeros);
    if(numero > 0 && numero <= 32 && bal == 1)
    {
        bal = 1;
        fila = numero-1;
    }
    else 
    {
        bal = 0;
    }
    if( bal == 1)
    {
         if(asientos[fila][columna] == 0)
         {
             devuelvo = 1;
             asientos[fila][columna] = 1;
             contador++;
         }
         else 
         {
             devuelvo = 2;
         }
    }
    else 
    {
        devuelvo = 3;
    }
    
    return devuelvo;

}
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
            //clearscreen();
            while(1)
            {
                char asig[3] = "";
                printf("Ingrese el asiento que desee: \n");
                scanf("%s", asig);
                int r = Verificar(asig);
                if(r == 1)
                {
                    printf("Asiento %s reservado.\n", asig);
                    break;
                }
                else if (r == 2)
                {
                    printf("Asiento %s ya ha sido reservado.\n", asig);
                    int ban = 0;
                    int filaS;
                    int columS;
                    for(int i = 0; i < 32; i++)
                    {
                        for(int x = 0; x < 6; x++)
                        {
                            if(asientos[i][x] == 0)
                            {
                                ban = 1;
                                filaS = i +1 ;
                                columS = x;
                                break;
                            }
                        }
                        if(ban == 1)
                        {
                            break;
                        }
                    }
                    Convertir(filaS, columS);
                    printf("El asiento %s está disponible.\n", nuevoasig);

                }
                else 
                {
                    printf("Asiento %s no existe. \n", asig);
                }
            }
            
        }
        else if (respuesta == 2)
        {
            //clearscreen();
            int le = 65;
            printf("|  |");
            int ban = 1;
            for(int i = -1; i < 32; i++)
            {
                for(int x = 0; x < 6; x++)
                {
                    if(i == -1)
                    {
                      
                        char let = {(char)le};
                        printf("|%c|", let);
                        le++;
                    }
                    else
                    {
                        if(asientos[i][x] == 0)
                        printf("|%d|", asientos[i][x]);
                        else
                        {
                          printf("|x|");
                        }
                    }
                    
                }                
                if(i >= 0 && i < 8)
                {
                  printf("\n");
                  printf("|%d |", (i+2));
                }
                else if( i != -1 && i < 31)
                {
                  printf("\n");
                  printf("|%d|", (i+2));
                }
                else if(ban == 1) 
                {
                    printf("\n");
                    printf("|%d |", (i+2));
                    ban = 0;
                }   
                else
                {

                }             
            } 
            printf("\n"); 
        }
        else if (respuesta == 3)
        {
            int todos = 192;
            float promlibre = ((todos-contador)*100.00)/todos;
            float promocup = ((contador)*100)/todos;
            printf("#RESUMEN: \n");
            printf("Asientos ocupados: %d de 192, [%f]\n", contador, promocup);
            printf("Asientos disponibles: %d de 192, [%f]\n", (todos-contador), promlibre);
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
