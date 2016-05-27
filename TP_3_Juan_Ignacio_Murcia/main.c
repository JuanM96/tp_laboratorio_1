#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
#define CANT 10



int main()
{
    char seguir='s';
    int opcion=0;
    int moviesFlag=0;
    int auxAlta;
    int auxBaja;
    int auxMod;
    char save;
    EMovie movies[CANT];
    initMovies(movies,CANT);
	if(cargarDesdeArchivo(movies,CANT))
	{
		printf("No se pudo abrir el fichero");
        system("pause");
		system("cls");
	}
	else
	{
		printf("Se cargaron las estructuras con exito\n");
		system("pause");
		system("cls");
	}
	//hardcodePeliculas(movies,CANT);
    while(seguir=='s')
    {
        showMessage("1- Agregar pelicula");
        showMessage("2- Borrar pelicula");
        showMessage("3- Modificar");
        showMessage("4- Generar pagina web");
        showMessage("5- Salir");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                auxAlta=alta(movies,CANT);
                if(auxAlta==-1)
                {
                    showMessage("ERROR,ALTA INCORRECTA O NO HAY ESPACIOS DISPONIBLES");
                }
                else
                {
                    moviesFlag=1;
                }
                break;
            case 2:
                if(moviesFlag==1)
                {
                    auxBaja=baja(movies,CANT);
                    if(auxBaja==-1)
                    {
                        showMessage("ERROR, BAJA INCORRECTA");
                    }
                }
                else
                {
                    showMessage("ERROR, INGRESE UNA PELICULA PRIMERO");
                }
                break;
            case 3:
                if(moviesFlag==1)
                {
                    auxMod=modificar(movies,CANT);
                    if(auxMod==-1)
                    {
                        showMessage("ERROR EN LA MODIFICACION");
                    }
                }
                else
                {
                    showMessage("ERROR, INGRESE UNA PELICULA PRIMERO");
                }
               break;
            case 4:
                generarPagina(movies,"Listado Peliculas.html",CANT);
                break;
            case 5:
                showMessage("Guardar cambios S/N ?");
                fflush(stdin);
				scanf("%c",&save);
				save=tolower(save);
				if(save == 's')
				{
					if(guardarEnArchivo(movies,CANT))
					{
						showMessage("No se pudo abrir el fichero");
						system("pause");
                        system("cls");
					}
					else
					{
						showMessage("Se guardo la informacion con exito");
						system("pause");
                        system("cls");
					}
				}
                seguir = 'n';
                break;
        }
    }

    return 0;
}
