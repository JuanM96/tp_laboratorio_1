#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

void initMovies(EMovie* lista, int largo)
{
    int i;
    for(i=0; i<largo; i++)
    {
        lista[i].isEmpty=1;
    }
}


void hardcodePeliculas(EMovie* lista,int largo)
{
    int i;
    char nombresHD[2][100]= {"The Lord of the Rings: The Fellowship of the Ring","The Lord of the Rings: The Two Towers"};
    char generoHD[2][50]= {"Fantasy","Fantasy"};
    int duracionHD[2]= {178,179};
    char descripcionHD[2][500]= {"Set in Middle-earth, the story tells of the Dark Lord Sauron (Sala Baker), who is seeking the One Ring. The Ring has found its way to the young hobbit Frodo Baggins (Elijah Wood). The fate of Middle-earth hangs in the balance as Frodo and eight companions who form the Fellowship of the Ring begin their journey to Mount Doom in the land of Mordor, the only place where the Ring can be destroyed.","Continuing the plot of The Fellowship of the Ring, the film intercuts three storylines. Frodo and Sam continue their journey towards Mordor to destroy the One Ring, meeting and joined by Gollum, the ring's former owner. Aragorn, Legolas, and Gimli come to the war-torn nation of Rohan and are reunited with the resurrected Gandalf, before fighting at the Battle of Helm's Deep. Merry and Pippin escape capture, meet Treebeard the Ent, and help to plan an attack on Isengard."};
    int puntajeHD[2]= {88,90};
    char linkImagenHD[2][200]= {"https://upload.wikimedia.org/wikipedia/en/0/0c/The_Fellowship_Of_The_Ring.jpg","https://upload.wikimedia.org/wikipedia/en/thumb/a/ad/Lord_of_the_Rings_-_The_Two_Towers.jpg/220px-Lord_of_the_Rings_-_The_Two_Towers.jpg"};
    for(i=0; i<2; i++)
    {
        strcpy(lista[i].titulo,nombresHD[i]);
        strcpy(lista[i].genero,generoHD[i]);
        strcpy(lista[i].descripcion,descripcionHD[i]);
        strcpy(lista[i].linkImagen,linkImagenHD[i]);
        lista[i].duracion=duracionHD[i];
        lista[i].puntaje=puntajeHD[i];
        lista[i].isEmpty=0;
    }
}

int obtenerEspacioLibre(EMovie* lista, int largo)
{
    int i;
    int auxReturn=-1;
    for(i=0; i<largo; i++)
    {
        if(lista[i].isEmpty==1)
        {
            auxReturn=i;
            break;
        }
    }
    return auxReturn;
}


int alta(EMovie* lista, int largo)
{
    int auxReturn;
    if(lista!=NULL&&largo>0)
    {
        int aux;
        aux=obtenerEspacioLibre(lista,largo);
        if(aux==-1)
        {
            auxReturn=-1;
        }
        else
        {
            showMessage("Ingrese Titulo");
            fflush(stdin);
            gets(lista[aux].titulo);
            showMessage("Ingrese Genero");
            fflush(stdin);
            gets(lista[aux].genero);
            showMessage("Ingrese Duracion");
            fflush(stdin);
            scanf("%d",&lista[aux].duracion);
            showMessage("Ingrese Descripcion");
            fflush(stdin);
            gets(lista[aux].descripcion);
            showMessage("Ingrese Puntaje");
            fflush(stdin);
            scanf("%d",&lista[aux].puntaje);
            showMessage("Ingrese Link de la Imagen");
            fflush(stdin);
            gets(lista[aux].linkImagen);
            lista[aux].isEmpty=0;
            auxReturn=0;
        }
    }
    else
    {
        auxReturn=-1;
    }

    return auxReturn;
}


int buscarPorTitulo(EMovie* lista,char* titulo,int largo)
{
    int i;
    int auxReturn=-1;
    for(i=0; i<largo; i++)
    {
        if(strcmp(lista[i].titulo,titulo)==0&&lista[i].isEmpty==0)
        {
            auxReturn=i;
            break;
        }
    }
    return auxReturn;
}


int baja(EMovie* lista, int largo)
{
    int auxReturn;
    if(lista!=NULL&&largo>0)
    {
        int aux;
        char auxTitulo[20];
        char opcion;
        showMessage("Ingrese Titulo de la Pelicula");
        fflush(stdin);
        gets(auxTitulo);
        while (strlen(auxTitulo)>20)
        {
            showMessage("ERROR, TITULO INVALIDO REINGRESE");
            fflush(stdin);
            gets(auxTitulo);
        }
        aux=buscarPorTitulo(lista,auxTitulo,largo);
        if(aux>=0)
        {
            auxReturn=0;
            showMessage("TITULO ENCONTRADO");
            printf("Titulo\tGenero\tDuracion\t\n");
            printf("%s\t%s\t%d\n",lista[aux].titulo,lista[aux].genero,lista[aux].duracion);
            showMessage("Desea Eliminarlo? s/n");
            fflush(stdin);
            scanf("%c",&opcion);
            opcion=tolower(opcion);
            while(opcion!='s'&&opcion!='n')
            {
                showMessage("ERROR, REINGRESE");
                showMessage("Desea Eliminarlo? s/n");
                fflush(stdin);
                scanf("%c",&opcion);
                opcion=tolower(opcion);
            }
            if (opcion=='s')
            {
                showMessage("Pelicula Eliminada");
                lista[aux].isEmpty=1;
            }
            else
            {
                showMessage("Pelicula No Eliminada");
            }
        }
        else
        {
            showMessage("PELICULA NO EXISTENTE");
            system("pause");
            system("cls");
            auxReturn=0;
        }
    }
    else
    {
        auxReturn=-1;
    }
    return auxReturn;
}


int modificar(EMovie* lista,int largo)
{
    char opcion;
    int i;
    char auxTitulo[20];
    int auxReturn=-1;
    int flag=0;
    if(lista!=NULL&&largo>0)
    {
        showMessage("Ingrese Titulo de la Pelicula");
        fflush(stdin);
        gets(auxTitulo);
        for(i=0; i<largo; i++)
        {
            if(strcmp(lista[i].titulo,auxTitulo)==0&&lista[i].isEmpty==0)
            {
                flag=1;
                system("cls");
                showMessage("PELICULA ENCONTRADA");
                system("pause");
                printf("\nTitulo: %s\nGenero: %s\nDuracion: %d\nPuntaje: %d\nLink de la imagen: %s\nDescripcion: %s\n",lista[i].titulo,lista[i].genero,lista[i].duracion,lista[i].puntaje,lista[i].linkImagen,lista[i].descripcion);
                system("pause");
                showMessage("Desea Modificarla? s/n");
                fflush(stdin);
                scanf("%c",&opcion);
                opcion=tolower(opcion);
                while(opcion!='s'&&opcion!='n')
                {
                    showMessage("ERROR, REINGRESE");
                    showMessage("Desea Modificarla? s/n");
                    fflush(stdin);
                    scanf("%c",&opcion);
                    opcion=tolower(opcion);
                }
                if(opcion=='s')
                {
                    system("cls");
                    showMessage("Ingrese Titulo");
                    fflush(stdin);
                    gets(lista[i].titulo);
                    showMessage("Ingrese Genero");
                    fflush(stdin);
                    gets(lista[i].genero);
                    showMessage("Ingrese Duracion");
                    fflush(stdin);
                    scanf("%d",&lista[i].duracion);
                    showMessage("Ingrese Descripcion");
                    fflush(stdin);
                    gets(lista[i].descripcion);
                    showMessage("Ingrese Puntaje");
                    fflush(stdin);
                    scanf("%d",&lista[i].puntaje);
                    showMessage("Ingrese Link de la Imagen");
                    fflush(stdin);
                    gets(lista[i].linkImagen);
                    auxReturn=0;
                    showMessage("PELICULA MODIFICADA CON EXITO");
                    system("pause");
                    break;
                }
                else
                {
                    system("cls");
                    showMessage("PELICULA NO MODIFICADA");
                    system("pause");
                    break;
                }
            }

        }
        if(flag==0)
        {
            system("cls");
            showMessage("PELICULA INEXISTENTE");
            system("pause");
        }
    }
    return auxReturn;

}

int guardarEnArchivo(EMovie * lista,int largo)
{
    FILE *f;
    f=fopen("peliculas.dat","wb");
    if(f == NULL)
    {
        return 1;
    }
    fwrite(lista,sizeof(EMovie),largo,f);
    fclose(f);
    return 0;
}

int cargarDesdeArchivo(EMovie *lista,int largo)
{
    int flag = 0;
    FILE *f;
    f=fopen("peliculas.dat", "rb");
    if(f==NULL)
    {
        f= fopen("peliculas.dat", "wb");
        if(f==NULL)
        {
            return 1;
        }
        flag=1;
    }
    if(flag ==0)
    {
        fread(lista,sizeof(EMovie),largo,f);
    }
    fclose(f);
    return 0;
}

void generarPagina(EMovie lista[], char nombre[],int largo)
{
    if(lista!=NULL&&largo>0)
    {
        int flag=0;
        int i;
        if(guardarEnArchivo(lista,largo))
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

            if(cargarDesdeArchivo(lista,largo))
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
        }
        FILE *pHtml;
        pHtml=fopen(nombre,"w");
        if(pHtml==NULL)
        {
            pHtml= fopen("peliculas.dat", "wb");
            flag=1;
        }
        if(flag ==0)
        {
            fprintf(pHtml,"<!DOCTYPE html>\n<!-- Template by Quackit.com -->\n<html lang='en'>\n<head>\n    <meta charset='utf-8'>\n    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n    <meta name='viewport' content='width=device-width, initial-scale=1'>\n    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n    <title>Lista peliculas</title>\n    <!-- Bootstrap Core CSS -->\n    <link href='css/bootstrap.min.css' rel='stylesheet'>\n    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n    <link href='css/custom.css' rel='stylesheet'>\n    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n    <!--[if lt IE 9]>\n        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n    <![endif]-->\n</head>\n<body>\n    <div class='container'>\n        <div class='row'>");
            for(i=0;i<largo;i++)
            {
                if(lista[i].isEmpty==0)
                {
                    fprintf(pHtml,"\n            <article class='col-md-4 article-intro'>\n                <a href='#'>\n                    <img class='img-responsive img-rounded' src='%s' alt=''>\n                </a>\n                <h3>\n                    <a href='#'>%s</a>\n                </h3>\n				<ul>\n					<li>Genero:%s</li>\n					<li>Puntaje:%d</li>\n					<li>Duracion:%d</li>					\n				</ul>\n                <p>%s</p>\n            </article>\n",lista[i].linkImagen,lista[i].titulo,lista[i].genero,lista[i].puntaje,lista[i].duracion,lista[i].descripcion);
                }
            }
            fprintf(pHtml,"</div>\n        <!-- /.row -->\n    </div>\n    <!-- /.container -->\n    <!-- jQuery -->\n    <script src='js/jquery-1.11.3.min.js'></script>\n    <!-- Bootstrap Core JavaScript -->\n    <script src='js/bootstrap.min.js'></script>\n	<!-- IE10 viewport bug workaround -->\n	<script src='js/ie10-viewport-bug-workaround.js'></script>\n	<!-- Placeholder Images -->\n	<script src='js/holder.min.js'></script>\n</body>\n</html>");
        }
        fclose(pHtml);
    }
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
