#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[100];
    char genero[20];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[200];
    int isEmpty;
}EMovie;

/** \brief Hardcodea 2 peliculas
 *
 * \param lista es un puntero a la estructura EMovie
 * \param largo es la cantidad de elementos que tiene el array
 * \return nada
 *
 */

void hardcodePeliculas(EMovie* lista,int largo);
/** \brief inicializa los isEmpty en 1
 *
 * \param lista es un puntero a la estructura EMovie
 * \param largo es la cantidad de elementos que tiene el array
 * \return nada
 *
 */
void initMovies(EMovie* lista, int largo);

/** \brief busca el primer espacio libre
 *
 * \param lista es un puntero a la estructura EMovie
 * \param largo es la cantidad de elementos que tiene el array
 * \return retorna 1 si encontro espacio o -1 si no lo encontro
 *
 */
int obtenerEspacioLibre(EMovie* lista, int largo);

/** \brief busca el titulo
 *
 * \param lista es un puntero a la estructura EMovie
 * \param largo es la cantidad de elementos que tiene el array
 * \param titulo es el nombre a ser buscado
 * \return retorna la posicion del titulo sino devuelve -1
 *
 */
int buscarPorTitulo(EMovie* lista,char* titulo,int largo);

/**
 *  @brief Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int alta(EMovie* lista, int largo);

/**
 *  @brief Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int baja(EMovie* lista, int largo);

/** \brief modifica una pelicula buscando por su titulo
 *
 * \param lista es un puntero a la estructura EMovie
 * \param largo es la cantidad de elementos que tiene el array
 * \return retorna 1 si se modifico con exito y -1 si hubo un error
 *
 */
int modificar(EMovie* lista,int largo);

/** \brief guarda la estructura en el archivo binario
 *
 * \param lista es un puntero a la estructura EMovie
 * \param largo es la cantidad de elementos que tiene el array
 * \return  retorna 1 si se guardo con exito y -1 si hubo un error
 *
 */
int guardarEnArchivo(EMovie * lista,int largo);

/** \brief carga la estructura en el archivo binario
 *
 * \param lista es un puntero a la estructura EMovie
 * \param largo es la cantidad de elementos que tiene el array
 * \return retorna 1 si se cargo con exito y -1 si hubo un error
 *
 */
int cargarDesdeArchivo(EMovie * lista,int largo);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[],int largo);

/**
* @brief Solicita una cadena de caracteres al usuario y la muestra en un cuadro
* @param message Es el mensaje a ser mostrado
* @return nothing
*/

void showMessage(char* );

#endif // FUNCIONES_H_INCLUDED
