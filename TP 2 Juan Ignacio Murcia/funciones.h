#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estadoLibre;
    int dni;

}ePersona;

/** \brief inicializa estadoLibre en 1.
 *
 * \param lista el array se pasa como parametro.
 * \param largo el tamaño del array.
 * \return nada, por ser funcion void.
 *
 */


void initPersonas(ePersona* lista, int largo);


/**
 * \brief Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param largo el tamaño del array.
 * @return el primer indice disponible.
 */
int obtenerEspacioLibre(ePersona* lista, int largo);

/** \brief Agrega 1 persona y pregunta al usuario si quiere ingresar otra.
 *
 * \param lista el array se pasa como parametro.
 * \param largo el tamaño del array.
 * \return nada, por ser funcion void.
 *
 */


void addPersona(ePersona* lista, int largo);

/**
 * @brief Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param largo el tamaño del array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni.
 */

int buscarPorDni(ePersona* lista, int dni,int largo);

/** \brief invoca la funcion buscarPorDni y usa esa posicion para cambiar el valor estadoLibre a 0.
 *
 * \param lista el array se pasa como parametro.
 * \param largo el tamaño del array.
 * \return nada, por ser funcion void.
 *
 */

void erasePersona(ePersona* lista, int largo);



/** \brief Ordena las personas de la estrucura por nombre y las muestra ordenadas.
 *
 * \param lista el array se pasa como parametro.
 * \param largo el tamaño del array
 * \return nada, por ser funcion void.
 *
 */

void ordenarPersona(ePersona* lista,int largo);

/** \brief Grafica la cantidad de personas por edad.
 *
 * \param lista el array se pasa como parametro.
 * \param largo el tamaño del array
 * \return nada, por ser funcion void.
 *
 */

void graficarPersona(ePersona* lista,int largo);

/**
* @brief Solicita una cadena de caracteres al usuario y la muestra en un cuadro
* @param message Es el mensaje a ser mostrado
* @return nada, por ser funcion void.
*/


void showMessage(char* );

#endif // FUNCIONES_H_INCLUDED
