#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 20

int main()
{
    char seguir='s'; //termina el programa o sigue iterando.
    int opcion=0; //Opcion para el switch.
    int auxError; //Indica si hay posiciones disponibles para ingresar.
    int addFlag=0; // flag para saber si se ingreso una persona.
    ePersona personas[CANT];
    initPersonas(personas,CANT);
    while(seguir=='s')
    {
        showMessage("1- Agregar persona");
        showMessage("2- Borrar persona");
        showMessage("3- Imprimir lista ordenada por  nombre");
        showMessage("4- Imprimir grafico de edades");
        showMessage("5- Salir");
        fflush(stdin);
        scanf("%d",&opcion);


        switch(opcion)
        {
            case 1: // Agregar persona
                system("cls");
                auxError=obtenerEspacioLibre(personas,CANT);
                if (auxError>=0)
                {
                    addPersona(personas,CANT);
                    addFlag=1;
                }
                else
                {
                    showMessage("No hay espacios disponibles");
                    system("pause");
                }
                system("cls");
                break;
            case 2://Borrar persona
                if(addFlag==1)
                {
                    system("cls");
                    erasePersona(personas,CANT);
                    system("pause");
                    system("cls");
                }
                else
                {
                    showMessage("Imposible Operar...");
                    system("pause");
                    system("cls");
                }
                break;
            case 3://Imprimir lista ordenada por  nombre
                if(addFlag==1)
                {
                        system("cls");
                        ordenarPersona(personas,CANT);
                        system("pause");
                        system("cls");
                }
                else
                {
                    showMessage("Imposible Operar...");
                    system("pause");
                    system("cls");
                }
                break;
            case 4://Imprimir grafico de edades
                if(addFlag==1)
                {
                    system("cls");
                    graficarPersona(personas,CANT);
                    system("pause");
                    system("cls");
                }
                else
                {
                    showMessage("Imposible Operar...");
                    system("pause");
                    system("cls");
                }
                break;
            case 5://salir
                seguir = 'n';
                break;
            default: // Valido que se ingrese solo los numeros del menu
                showMessage("ERROR, INGRESE UN NUMERO DEL 1 AL 5");
                system("pause");
                system("cls");
                break;
        }
    }

    return 0;
}
