#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ArrayList.h"
typedef struct{

    char nombre[50];
    char nacimiento[50];
    char pais[50];
    int contPeli;
    int codDirec;

}eDirector;
typedef struct{

    char titulo[50];
    int anioPelicula;
    char nacionalidad[50];
    int director;
    int puntaje;
    int identificador;
    int contDirec;

}ePelicula;

/** \brief Harcodea 2 directores de la estructura
 *
 * \param listaDirec es la estructura de eDirector
 * \param largo es el tamaño del array
 * \return nada por que es void
 *
 */

void hardcodeDirec(eDirector* listaDirec,int largo);

/** \brief inicializa todos los isEmptyPelicula y isEmptyDirec en 1
 * \param lista es la estructura de ePelicula
 * \param listaDirec es la estructura de eDirector
 * \param largo es el tamaño del array
 * \return no devuelve nada
 *
 */

void initStructPeli(ePelicula* lista);
void initStructDirec(eDirector* lista);
int compareFilms(void* pFilm1,void* pFilm2);
/** \brief Busca el primer espacio libre
 * \param lista es la estructura de ePelicula
 * \param listaDirec es la estructura de eDirector
 * \param largo es el tamaño del array
 * \param index si es 0 busca en peliculas y si es 1 busca en directores
 * \return la posicion del array donde esta libre
 *
 */

int buscarLibre(ePelicula* lista,eDirector* listaDirec,int largo,int index);


/** \brief Busca el primer espacio libre
 * \param listaDirec es la estructura de eDirector
 * \param largo es el tamaño del array
 * \param cod es el codigo de director
 * \return devuelve -1 si no encuentra al director y 1 si lo encuentra
 *
 */

int validarDirector(ArrayList* listaDirec,int cod);

/** \brief da de alta una pelicula y pregunta para agregar otra
 * \param lista es la estructura de ePelicula
 * \param listaDirec es la estructura de eDirector
 * \param largo es el tamaño del array
 * \return no devuelve nada
 *
 */

void alta(ArrayList* lista,ArrayList* listaDirec);

/** \brief Modifica los datos una pelicula
 * \param lista es la estructura de ePelicula
 * \param listaDirec es la estructura de eDirector
 * \param largo es el tamaño del array
 * \return no devuelve nada
 *
 */

void modificar(ArrayList* lista,ArrayList* listaDirec);

/** \brief da de baja una pelicula
 * \param lista es la estructura de ePelicula
 * \param listaDirec es la estructura de eDirector
 * \param largo es el tamaño del array
 * \return no devuelve nada
 *
 */

void baja(ArrayList* lista);

/** \brief da de alta un director y pregunta para agregar otro
 * \param listaDirec es la estructura de eDirector
 * \param largo es el tamaño del array
 * \return no devuelve nada
 *
 */

void nuevoDirector(ArrayList* listaDirec);

/** \brief da de baja un director
 * \param listaDirec es la estructura de eDirector
 * \param largo es el tamaño del array
 * \return no devuelve nada
 *
 */

void eliminarDirector(ArrayList* listaDirec);

/** \brief Ordena y muestra por los criterios solicitados (titulo [descendentemente] y Año [ascendentemente])
 * \param listaDirec es la estructura de eDirector
 * \param largo es el tamaño del array
 * \return no devuelve nada
 *
 */

void listar(ArrayList* lista,ArrayList* listaDirec);

void informar(ArrayList* lista,ArrayList* listaDirec);

int guardarEnArchivo(ArrayList* lista,ArrayList* listaDirec);

int cargarDesdeArchivoPeliculas(ArrayList* lista);

int cargarDesdeArchivoDirectores(ArrayList* listaDirec);

void borrar(ArrayList* lista, ArrayList* listaDirec);

/**
* \brief Solicita una cadena de caracteres al usuario y la muestra en un cuadro
* \param message Es el mensaje a ser mostrado
* \return nada, por ser funcion void.
*/

void showMessage(char* );

#endif // FUNCIONES_H_INCLUDED
