#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayList.h"

int main()
{
    char seguir='s';
    char save;
    int opcion;
    int flagPelicula=0;
    int flagDirector=0;
    int aux,aux2,aux3;
    int auxIsEmptyD,auxIsEmptyP;
    ArrayList* peliculas=al_newArrayList();
    ArrayList* directores=al_newArrayList();
    aux=cargarDesdeArchivoDirectores(directores);
    if(aux==0)
    {
        showMessage("LOS DIRECTORES SE CARGARON CON EXITO");
        system("pause");
        system("cls");
        auxIsEmptyD=al_isEmpty(directores);
        if(auxIsEmptyD==0)
        {
            flagDirector=1;
        }
    }
    aux2=cargarDesdeArchivoPeliculas(peliculas);
    if(aux2==0)
    {
        showMessage("LAS PELICULAS SE CARGARON CON EXITO");
        system("pause");
        system("cls");
        auxIsEmptyP=al_isEmpty(peliculas);
        if(auxIsEmptyP==0)
        {
            flagPelicula=1;
        }

    }
    printf("D=%d\nP=%d\n%d\n%d\n",flagDirector,flagPelicula,peliculas->size,directores->size);
    system("pause");
    system("cls");
    while(seguir=='s')
    {
        showMessage("1- ALTAS PELICULAS");
        showMessage("2- MODIFICAR DATOS DE UNA PELICULA");
        showMessage("3- BAJA DE PELICULA");
        showMessage("4- NUEVO DIRECTOR");
        showMessage("5- ELIMINAR DIRECTOR");
        showMessage("6- INFORMAR");
        showMessage("7- LISTAR");
        showMessage("8- BORRAR TODO");
        showMessage("9- SALIR");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                if(flagDirector==0)
                {
                    showMessage("PRIMERO INGRESE UN DIRECTOR");
                    system("pause");
                    system("cls");
                }
                else
                {
                    system("cls");
                    alta(peliculas,directores);
                    flagPelicula=1;
                }

                break;
            case 2:
                system("cls");
                if (flagPelicula==1)
                {
                    modificar(peliculas,directores);
                }
                else
                {
                    showMessage("ERROR, NO HAY PELICULAS REGISTRADAS");
                    system("pause");
                }
                break;
            case 3:
                system("cls");
                if (flagPelicula==1)
                {
                    baja(peliculas);
                }
                else
                {
                    showMessage("ERROR, NO HAY PELICULAS REGISTRADAS");
                    system("pause");
                    system("cls");
                }
                break;
            case 4:
                system("cls");
                nuevoDirector(directores);
                flagDirector=1;
                system("cls");
                break;
            case 5:
                system("cls");
                if (flagDirector==1)
                {
                    eliminarDirector(directores);
                }
                else
                {
                    showMessage("ERROR,NO HAY DIRECTORES REGISTRADOS");
                    system("pause");
                    system("cls");
                }
                break;
            case 6:
                system("cls");
                if (flagPelicula==1&&flagDirector==1)
                {
                    informar(peliculas,directores);
                    system("pause");
                    system("cls");
                }
                else
                {
                    showMessage("ERROR, NO HAY PELICULAS REGISTRADAS O NO HAY DIRECTORES REGISTRADOS");
                    system("pause");
                    system("cls");
                }
                break;
            case 7:
                system("cls");
                if (flagPelicula==1&&flagDirector==1)
                {
                    listar(peliculas,directores);
                    system("pause");
                    system("cls");
                }
                else
                {
                    showMessage("ERROR, NO HAY PELICULAS REGISTRADAS O NO HAY DIRECTORES REGISTRADOS");
                    system("pause");
                    system("cls");
                }
                break;
            case 8:
                system("cls");
                if (flagPelicula==1&&flagDirector==1)
                {
                    borrarTodo(peliculas,directores);
                }
                else
                {
                    showMessage("ERROR, NO HAY PELICULAS REGISTRADAS O NO HAY DIRECTORES REGISTRADOS");
                    system("pause");
                    system("cls");
                }
                break;
            case 9:
                showMessage("Guardar cambios S/N ?");
                fflush(stdin);
				scanf("%c",&save);
				save=tolower(save);
				if(save == 's')
				{
				    aux3=guardarEnArchivo(peliculas,directores);
					if(aux3==-1)
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
                al_deleteArrayList(peliculas);
                al_deleteArrayList(directores);
                seguir = 'n';
                break;
        }
    }

    return 0;
}
