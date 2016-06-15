#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"

void hardcodeDirec(eDirector* listaDirec,int largo)
{
    int i;
    char nombres[2][50]= {"Juan Perez","Alvaro Lopes"};
    char nacimientos[2][50]= {"10/05/78","02/12/84"};
    char paises[2][50]= {"Argentina","Brasil"};
    int codigoDirectores[2]= {0,1};
    for(i=0; i<2; i++)
    {
        /*printf("nombre\n");
        fflush(stdin);
        gets(listaDirec[i].nombre);
        printf("nacimiento\n");
        fflush(stdin);
        gets(listaDirec[i].nacimiento);
        printf("pais\n");
        fflush(stdin);
        gets(listaDirec[i].pais);
        printf("codigo\n");
        fflush(stdin);
        scanf("%d",&listaDirec[i].codDirec);*/
        strcpy(listaDirec[i].nombre,nombres[i]);
        strcpy(listaDirec[i].nacimiento,nacimientos[i]);
        strcpy(listaDirec[i].pais,paises[i]);
        listaDirec[i].codDirec=codigoDirectores[i];
    }
}


int validarDirector(ArrayList* listaDirec,int cod)
{
    int i;
    int auxReturn=-1;
    eDirector* pAux;
    for(i=0; i<listaDirec->size; i++)
    {
        pAux=al_get(listaDirec,i);
        printf("pAux= %d\nCod= %d",pAux->codDirec,cod);
        system("pause");
        if(pAux->codDirec==cod)
        {
            auxReturn=1;
            break;
        }
    }
    return auxReturn;
}

void alta(ArrayList* lista,ArrayList* listaDirec)
{
    int auxDirec;
    ePelicula* auxPeli=malloc(sizeof(ePelicula));
    showMessage("Ingrese titulo");
    fflush(stdin);
    gets(auxPeli->titulo);
    showMessage("Ingrese nacionalidad");
    fflush(stdin);
    gets(auxPeli->nacionalidad);
    showMessage("Ingrese anio de la pelicula");
    fflush(stdin);
    scanf("%d",&auxPeli->anioPelicula);
    showMessage("Ingrese Puntaje de la pelicula xx/100");
    fflush(stdin);
    scanf("%d",&auxPeli->puntaje);
    showMessage("Ingrese Codigo de director");
    fflush(stdin);
    scanf("%d",&auxPeli->director);
    auxDirec=validarDirector(listaDirec,auxPeli->director);
    while(auxDirec!=1)
    {
        showMessage("ERROR,DIRECTOR INEXISTENTE REINGRESE");
        fflush(stdin);
        scanf("%d",&auxPeli->director);
        printf("%d",auxPeli->director);
        system("pause");
        auxDirec=validarDirector(listaDirec,auxPeli->director);
    }
    auxPeli->identificador=lista->size;
    al_add(lista,auxPeli);
    system("cls");
    showMessage("Pelicula Agregada");
    system("pause");
    system("cls");
}
void modificar(ArrayList* lista,ArrayList* listaDirec)
{
    char opcion;
    int i;
    int auxIden;
    int auxDirec;
    int auxFlag=-1;
    ePelicula* auxPeli;
    showMessage("Ingrese identificador de la pelicula");
    fflush(stdin);
    scanf("%d",&auxIden);
    for(i=0; i<lista->size; i++)
    {
        auxPeli=al_get(lista,i);
        if(auxIden==auxPeli->identificador)
        {
            auxFlag=0;
            system("cls");
            showMessage("PELICULA ENCONTRADA");
            system("pause");
            printf("\nTitulo de la pelicula: %s\nAnio de la pelicula: %d\nNacionalidad de la pelicula: %s\nCodigo de Director de la pelicula: %d\n",auxPeli->titulo,auxPeli->anioPelicula,auxPeli->nacionalidad,auxPeli->director);
            showMessage("Desea modificarla? s/n");
            fflush(stdin);
            scanf("%c",&opcion);
            if(opcion=='s')
            {
                system("cls");
                showMessage("Ingrese titulo");
                fflush(stdin);
                gets(auxPeli->titulo);
                showMessage("Ingrese nacionalidad");
                fflush(stdin);
                gets(auxPeli->nacionalidad);
                showMessage("Ingrese anio de la pelicula");
                fflush(stdin);
                scanf("%d",&auxPeli->anioPelicula);
                showMessage("Ingrese Puntaje de la pelicula xx/100");
                fflush(stdin);
                scanf("%d",&auxPeli->puntaje);
                showMessage("Ingrese Codigo de director");
                fflush(stdin);
                scanf("%d",&auxPeli->director);
                auxDirec=validarDirector(listaDirec,auxPeli->director);
                while(auxDirec<0)
                {
                    showMessage("ERROR,DIRECTOR INEXISTENTE REINGRESE");
                    fflush(stdin);
                    scanf("%d",&auxPeli->director);
                    auxDirec=validarDirector(listaDirec,auxPeli->director);
                }
                al_set(lista,i,auxPeli);
                system("cls");
                showMessage("PELICULA MODIFICADA CON EXITO");
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                showMessage("PELICULA NO MODIFICADA");
                system("pause");
                system("cls");
            }
        }

    }
    if(auxFlag==-1)
    {
        system("cls");
        showMessage("PELICULA INEXISTENTE");
        system("pause");
        system("cls");
    }
}

void baja(ArrayList* lista)
{
    char opcion;
    int i;
    int auxIden;
    int flag=0;
    int auxContains;
    ePelicula* auxPeli;
    showMessage("Ingrese identificador de la pelicula");
    fflush(stdin);
    scanf("%d",&auxIden);
    for(i=0; i<lista->size; i++)
    {
        auxPeli=al_get(lista,i);
        auxContains=al_contains(lista,auxPeli);
        if(auxIden==auxPeli->identificador&&auxContains==1)
        {
            flag=1;
            system("cls");
            showMessage("PELICULA ENCONTRADA");
            system("pause");
            printf("\nTitulo de la pelicula: %s\nAnio de la pelicula: %d\nNacionalidad de la pelicula: %s\nCodigo de Director de la pelicula: %d\n",auxPeli->titulo,auxPeli->anioPelicula,auxPeli->nacionalidad,auxPeli->director);
            showMessage("Desea eliminarla? s/n");
            fflush(stdin);
            scanf("%c",&opcion);
            if(opcion=='s')
            {
                system("cls");
                al_remove(lista,i);
                showMessage("PELICULA BORRADA");
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                showMessage("PELICULA NO BORRADA");
                system("pause");
                system("cls");
            }
            break;
        }

    }
    if(flag==0)
    {
        system("cls");
        showMessage("PELICULA INEXISTENTE");
        system("pause");
        system("cls");
    }
}

void nuevoDirector(ArrayList* listaDirec)
{
    eDirector* director=malloc(sizeof(eDirector));
    showMessage("ingrese nombre del director");
    fflush(stdin);
    gets(director->nombre);
    showMessage("ingrese Fecha de nacimiento del director (xx/xx/xxxx)");
    fflush(stdin);
    gets(director->nacimiento);
    showMessage("ingrese pais del director");
    fflush(stdin);
    gets(director->pais);
    director->codDirec=listaDirec->size;
    al_add(listaDirec,director);
    system("cls");
    showMessage("DIRECTOR INGRESADO CON EXITO");
    system("pause");
    system("cls");
}
void eliminarDirector(ArrayList* listaDirec)
{
    char opcion;
    int i;
    int auxCod,flag=0;
    eDirector* pAux;
    eDirector* borrado;
    showMessage("Codigo del director");
    fflush(stdin);
    scanf("%d",&auxCod);
    for(i=0; i<listaDirec->size; i++)
    {
        pAux=al_get(listaDirec,i);
        if(pAux->codDirec==auxCod)
        {
            showMessage("DIRECTOR ENCONTRADO");
            flag=1;
            printf("\nNombre: %s\nFecha de nacimiento: %s\nPais: %s\n",pAux->nombre,pAux->nacimiento,pAux->pais);
            showMessage("Desea Eliminarlo? s/n");
            fflush(stdin);
            scanf("%c",&opcion);
            if(opcion=='s')
            {
                borrado=al_pop(listaDirec,i);
                system("cls");
                printf("Nombre= %s\nNacimiento= %s\nPais= %s\nFUE ELIMINADO CON EXITO",borrado->nombre,borrado->nacimiento,borrado->pais);
                system("pause");
            }
            else
            {
                system("cls");
                showMessage("DIRECTOR NO ELIMINADO");
                system("pause");
            }
        }

    }
    if(flag==0)
    {
        system("cls");
        showMessage("DIRECTOR INEXISTENTE");
        system("pause");
    }
}

int compareFilms(void* pFilm1,void* pFilm2)
{

    if(((ePelicula*)pFilm1)->puntaje > ((ePelicula*)pFilm2)->puntaje)
    {
        return 1;
    }
    if(((ePelicula*)pFilm1)->puntaje < ((ePelicula*)pFilm2)->puntaje)
    {
        return -1;
    }
    return 0;


}

void listar(ArrayList* lista,ArrayList* listaDirec)
{
    int i,j;
    ArrayList* listaOrdenada;
    listaOrdenada=al_clone(lista);
    al_sort(listaOrdenada,compareFilms,0);
    ePelicula* pAuxP;
    eDirector* pAuxD;
    for(i=0; i<lista->size; i++)
    {
        pAuxP=al_get(listaOrdenada,i);
        for(j=0; j<listaDirec->size; j++)
        {
            pAuxD=al_get(listaDirec,j);
            if(pAuxP->director==pAuxD->codDirec)
            {
                break;
            }
        }
        printf("\nTitulo de la pelicula: %s\nDirector de la pelicula: %s\nNacionalidad de la pelicula: %s\nPuntaje: %d/100\n",pAuxP->titulo,pAuxD->nombre,pAuxP->nacionalidad,pAuxP->puntaje);
    }
    al_deleteArrayList(listaOrdenada);
}

void informar(ArrayList* lista,ArrayList* listaDirec)
{
    int opcion;
    printf("1-Top 3 Mejores Peliculas\n");
    printf("2-Top 5 Peores Peliculas\n");
    scanf("%d",&opcion);
    switch(opcion)
    {
        case 1:
            if(lista->size>3)
            {
                int i,j;
                int largo;
                ArrayList* listaOrdenada;
                ArrayList* top3;
                listaOrdenada=al_clone(lista);
                al_sort(listaOrdenada,compareFilms,0);
                ePelicula* pAuxP;
                eDirector* pAuxD;
                top3=al_subList(listaOrdenada,0,2);
                largo=al_len(top3);
                for(i=0; i<largo; i++)
                {
                    pAuxP=al_get(top3,i);
                    for(j=0; j<listaDirec->size; j++)
                    {
                        pAuxD=al_get(listaDirec,j);
                        if(pAuxP->director==pAuxD->codDirec)
                        {
                            break;
                        }
                    }
                    printf("----------[%d]----------",(i+1));
                    printf("\nTitulo de la pelicula: %s\nDirector de la pelicula: %s\nNacionalidad de la pelicula: %s\nPuntaje: %d/100\n",pAuxP->titulo,pAuxD->nombre,pAuxP->nacionalidad,pAuxP->puntaje);
                }
                al_deleteArrayList(listaOrdenada);
                al_deleteArrayList(top3);
            }
            else
            {
                showMessage("IMPOSIBLE REALIZAR TOP SIN LA CANTIDAD CORRECTA DE PELICULAS");
            }
            break;
        case 2:
            if(lista->size>5)
            {
                int i,j;
                int largo;
                ArrayList* listaOrdenada;
                ArrayList* top5;
                listaOrdenada=al_clone(lista);
                al_sort(listaOrdenada,compareFilms,1);
                ePelicula* pAuxP;
                eDirector* pAuxD;
                top5=al_subList(listaOrdenada,0,4);
                largo=al_len(top5);
                for(i=0;i<largo;i++)
                {
                    pAuxP=al_get(top5,i);
                    for(j=0;j<listaDirec->size;j++)
                    {
                        pAuxD=al_get(listaDirec,j);
                        if(pAuxP->director==pAuxD->codDirec)
                        {
                            break;
                        }
                    }
                    printf("----------[%d]----------",(i+1));
                    printf("\nTitulo de la pelicula: %s\nDirector de la pelicula: %s\nNacionalidad de la pelicula: %s\nPuntaje: %d/100\n",pAuxP->titulo,pAuxD->nombre,pAuxP->nacionalidad,pAuxP->puntaje);
                }
                al_deleteArrayList(listaOrdenada);
                al_deleteArrayList(top5);
            }
            else
            {
                showMessage("IMPOSIBLE REALIZAR TOP SIN LA CANTIDAD CORRECTA DE PELICULAS");
            }
            break;
    }


}

void borrarTodo(ArrayList* lista, ArrayList* listaDirec)
{
    char opcion;
    int aux1,aux2;
    aux1=al_isEmpty(lista);
    aux2=al_isEmpty(listaDirec);
    if(aux1==0&&aux2==0)
    {
        showMessage("Este procedimiento borrar todos los datos ingresados");
        showMessage("desea continuar? s/n");
        fflush(stdin);
        scanf("%c",&opcion);
        opcion=tolower(opcion);
        if(opcion=='s')
        {
            al_clear(lista);
            al_clear(listaDirec);
            showMessage("TODOS LOS DATOS HAN SIDO BORRADOS");
            system("pause");
            system("cls");
        }
        else
        {
            showMessage("NINGUN DATO FUE BORRADO");
            system("pause");
            system("cls");
        }
    }
    else
    {
        showMessage("LAS LISTAS YA ESTAN VACIAS");
        system("pause");
        system("cls");
    }
}

int guardarEnArchivo(ArrayList* lista,ArrayList* listaDirec)
{
    int i;
    FILE *f;
    FILE *f2;
    ePelicula* pAux;
    eDirector* pAux2;
    f=fopen("peliculas.dat","wb");
    f2=fopen("directores.dat","wb");
    if(f == NULL)
    {
        return -1;
    }
    for(i=0;i<lista->size;i++)
    {
        pAux=al_get(lista,i);
        fwrite(pAux,sizeof(ePelicula),1,f);
    }
    for(i=0;i<listaDirec->size;i++)
    {
        pAux2=al_get(listaDirec,i);
        fwrite(pAux2,sizeof(eDirector),1,f2);
    }
    fclose(f);
    return 0;
}

int cargarDesdeArchivoPeliculas(ArrayList* lista)
{
    int flag = 0;
    int auxReturn=-1;
    int aux;
    ePelicula* auxPeli;
    FILE *f;
    f=fopen("peliculas.dat", "rb");
    if(f==NULL)
    {
        f= fopen("peliculas.dat", "wb");
        if(f==NULL)
        {
            return auxReturn;
        }
        flag=1;
    }
    if(flag ==0)
    {
        auxReturn=0;
        aux=feof(f);
        while(aux==0)
        {
            auxPeli=malloc(sizeof(ePelicula));
            fread(auxPeli,sizeof(ePelicula),1,f);
            al_add(lista,auxPeli);
            aux=feof(f);
        }
    }
    fclose(f);
    return auxReturn;
}

int cargarDesdeArchivoDirectores(ArrayList* listaDirec)
{
    int auxReturn;
    FILE* f;
    int flag=0;
    int aux;
    eDirector* auxDirec;
    f=fopen("directores.dat", "rb");
    if(f==NULL)
    {
        f= fopen("directores.dat", "wb");
        if(f==NULL)
        {
            return auxReturn;
        }
        flag=1;
    }
    if(flag ==0)
    {
        auxReturn=0;
        aux=feof(f);
        while(aux==0)
        {
            auxDirec=malloc(sizeof(eDirector));
            fread(auxDirec,sizeof(eDirector),1,f);
            al_add(listaDirec,auxDirec);
            aux=feof(f);
        }
    }
    return auxReturn;
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




