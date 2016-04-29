#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void initPersonas(ePersona* lista, int largo)
{
    int i;
    for(i=0; i<largo; i++)
    {
        lista[i].estadoLibre=1;
    }
}

int obtenerEspacioLibre(ePersona* lista, int largo)
{
    int i;
    int auxReturn=-1;
    for(i=0; i<largo; i++)
    {
        if(lista[i].estadoLibre==1)
        {
            auxReturn=i;
            break;
        }
    }
    return auxReturn;
}

void addPersona(ePersona* lista, int largo)
{
    int aux;
    int auxLen;
    int opcion='s';
    while(opcion=='s')
    {
        aux=obtenerEspacioLibre(lista,largo);
        if(aux>=0)
        {
            showMessage("Ingrese nombre");
            fflush(stdin);
            scanf("%s",&lista[aux].nombre);
            auxLen=strlen(lista[aux].nombre);
            while(auxLen<0 || auxLen>20)
            {
                showMessage("ERROR, Reingrese nombre menor a 20 caracteres");
                scanf("%s",&lista[aux].nombre);
                auxLen=strlen(lista[aux].nombre);
            }
            showMessage("Ingrese edad");
            fflush(stdin);
            scanf("%d",&lista[aux].edad);
            while (lista[aux].edad<1 || lista[aux].edad>100)
            {
                showMessage("ERROR, EDAD INVALIDA REINGRESE");
                fflush(stdin);
                scanf("%d",&lista[aux].edad);
            }
            showMessage("Ingrese DNI");
            fflush(stdin);
            scanf("%d",&lista[aux].dni);
            while (lista[aux].dni<10000000 || lista[aux].dni>99999999)
            {
                showMessage("ERROR, DNI INVALIDO REINGRESE");
                fflush(stdin);
                scanf("%d",&lista[aux].dni);
            }
            lista[aux].estadoLibre=0;
            system("cls");
            showMessage("Persona Agregada");
            showMessage("Quiere Ingresar Otra Persona? s/n");
            fflush(stdin);
            scanf("%c",&opcion);
            while(opcion!='s'&&opcion!='n')
            {
                showMessage("ERROR, REINGRESE(s/n): ");
                fflush(stdin);
                scanf("%c",&opcion);
            }
            system("cls");

        }
        else
        {
            opcion='n';
        }
    }
}

int buscarPorDni(ePersona* lista,int dni,int largo)
{
    int i;
    int auxReturn=-1;
    for(i=0; i<largo; i++)
    {
        if(lista[i].dni==dni)
        {
            auxReturn=i;
            break;
        }
    }
    return auxReturn;
}

void erasePersona(ePersona* lista, int largo)
{
    int aux;
    int auxDni;
    char opcion;
    showMessage("Ingrese Dni");
    fflush(stdin);
    scanf("%d",&auxDni);
    while (auxDni<10000000 || auxDni>99999999)
    {
        showMessage("ERROR, DNI INVALIDO REINGRESE");
        fflush(stdin);
        scanf("%d",&auxDni);
    }
    aux=buscarPorDni(lista,auxDni,largo);
    if(aux>=0)
    {
        showMessage("DNI ENCONTRADO");
        printf("NOMBRE\tEDAD\tDNI\n");
        printf("%s\t%d\t%d\n",lista[aux].nombre,lista[aux].edad,lista[aux].dni);
        showMessage("Desea Eliminarlo? s/n");
        fflush(stdin);
        scanf("%c",&opcion);
        opcion=tolower(opcion);
        if (opcion=='s')
        {
            showMessage("Persona Eliminada");
            lista[aux].estadoLibre=1;
        }
        else
        {
            showMessage("Persona No Eliminada");
        }
    }
    else
    {
        showMessage("El DNI especificado no esta registrado");
    }

}

void ordenarPersona(ePersona* lista,int largo)
{
    ePersona backupLista;
    int i,j;
    for(i=0; i<largo-1; i++)
    {
        for(j=i+1; j<largo; j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                backupLista=lista[i];
                lista[i]=lista[j];
                lista[j]=backupLista;
            }
        }
    }
    showMessage("LISTA ORDENADA POR NOMBRE");
    printf("NOMBRE              \tEDAD\tDNI     \n");
    for(i=0; i<largo; i++)
    {
        printf("%-20s\t%-3d \t%-8d\n",lista[i].nombre,lista[i].edad,lista[i].dni);
    }
}
void graficarPersona(ePersona* lista,int largo)
{
    int i;
    int max=0;
    int menor18=0;
    int entre19y35=0;
    int mayor35=0;
    for(i=0; i<largo; i++)
    {
        if(lista[i].edad<=18)
        {
            menor18++;
        }
        else if(lista[i].edad>=19 && lista[i].edad<=35)
        {
            entre19y35++;
        }
        else
        {
            mayor35++;
        }
    }
    if(menor18>entre19y35&&menor18>mayor35)
    {
        max=menor18;
    }
    else if (entre19y35>menor18&&entre19y35>mayor35)
    {
        max=entre19y35;
    }
    else
    {
        max=mayor35;
    }
    showMessage("GRAFICO DE EDADES");
    printf("\n");
    for(i=0;i<max;i++)
    {
        //printf("\t");
        if((max-i-1)<menor18)
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }

        printf("\t");
        if((max-i-1)<entre19y35)
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }
        printf("\t");
        if((max-i-1)<mayor35)
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }
        printf("\n");
    }
    printf("<18\t19-35\t>35\n");
}


void showMessage(char* message)
{
    int auxLen;
    int i;
    auxLen=strlen(message);
    printf("%c",201);
    for(i=0; i<auxLen+4; i++)
    {
        printf("%c",205);
    }
    printf("%c",187);
    printf("\n%c",186);
    for(i=0; i<auxLen+4; i++)
    {
        printf(" ");
    }
    printf("%c",186);
    printf("\n%c  %s  %c\n",186,message,186);
    printf("%c",186);
    for(i=0; i<auxLen+4; i++)
    {
        printf(" ");
    }
    printf("%c\n",186);
    printf("%c",200);
    for(i=0; i<auxLen+4; i++)
    {
        printf("%c",205);
    }
    printf("%c\n",188);

}
