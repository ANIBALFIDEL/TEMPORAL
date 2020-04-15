/*
 ============================================================================
 Name        : Clase4_Ej-1.c
 Author      : Anibal
 Description : El programa es un juego en el cual el usuario debe adivinar un
 numero elegido aleatoriamente por el sistema
 ============================================================================
 */
/**
 * @brief
 * @return
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#define maxArray 10

int printArrayInt(int *pArray, int limite);
int ordenarArrayInt(int *pArray, int limite);
int getNumeroFlotante(float *pResultado,char *mensaje,char *mensajeError, int reintentos);
int getFloat(float *pResultado);
int esFlotante(char *cadena);

int main(void) {
	setbuf(stdout, NULL);
	/*Pedir al usuario que ingrese 10 numeros
	 * calcular min max y prom
	 * ingresar num e informar si se encuentra en el array
	 * Imprimir arraya de mayor a menor
	 * ;
	}======================================================================================*/
	int retorno;
	float resultadoFloat;
	retorno = getNumeroFlotante(&resultadoFloat,"\nIngrese numero flotante","ERROR.",3);
	if(retorno == 0)
	{
		printf("\nEl numero es flotante");
	}
	else
	{
		printf("\nEl numero NO es flotante");
	}
	return 0;
}

int printArrayInt(int *pArray, int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite >= 0)
	{
		retorno = 0;
		for(i = 0; i < limite; i++)
		{
			printf("\n[DEBUG] Indice %d - Valor guardado: %d",i,pArray[i]);
		}
	}
	return retorno;
}


int ordenarArrayInt(int *pArray, int limite)
{
	int flagSwap;
	int buffer;
	int i;
	int contador = 0;
	int retorno = 0;

	if(pArray != NULL && limite >= 0)
	{
		//printf("\nEntre AL IF");
		do
		{
			flagSwap = 0;
			for (i = 0; i < limite-1; i++)
			{
				if(pArray[i] < pArray [i+1])
				{
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
				}
			}
			contador++;
			//limite--;
		}while(flagSwap);
		retorno = contador;
	}
	return retorno;
}

int getNumeroFlotante(float *pResultado,char *mensaje,char *mensajeError, int reintentos)
{
	int retorno = -1;
	float aux;
	while(reintentos > 0)
	{
		printf("%s",mensaje);
		if(getFloat(&aux)==1)
		{
		   //if(aux>=minimo && aux<=maximo)
			//{
			   break;
			//}

		}
	   reintentos--;
	   printf("%s. Le quedan %d intentos",mensajeError,reintentos);
	}
	if(reintentos==0)
	{
		retorno=-1;
	}
	else
	{
		retorno=0;
		*pResultado = aux;
	}
	return retorno;
}
//debe retornar 1 si es flotante
int getFloat(float *pResultado)
{
	int retorno = -1;
	char buffer[64];
	fflush(stdin);
	fgets(buffer,sizeof(buffer),stdin);
	buffer[strlen(buffer)-1] = '\0';
	if(esFlotante(buffer) == 1)
	{
		*pResultado = atof(buffer);
		retorno = 1;
	}



	return retorno;
}

//retorna 1 si es flotante
int esFlotante(char *cadena)
{
	int retorno = 0;
	int i = 0;
	//int flagSigno = 0;
	int flagPunto = 0;


	if((cadena[0] >= '0' && cadena[0] <= '9') || cadena[0] == '-')
	{
		if((cadena[1] >= '0' && cadena[1] <= '9') || cadena[1] == '.')
		{
			//for(i=2; cadena[i] != '\0' && flagPunto < 2; i++)
			//i = 0;
			while (cadena[i] != '\0' && flagPunto < 2)
			{
				if (cadena[i] >= '0' && cadena[i] <= '9')
				{
					i++;
				}
				else if (cadena[i] == '.')
				{
					flagPunto++;
					i++;
				}
				else
				{
					break;
				}
			}
			if (cadena[i] == '\0' && flagPunto < 2)
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}




