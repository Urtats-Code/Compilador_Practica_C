#ifndef CODIGO_HPP_
#define CODIGO_HPP_
#include <iostream>
#include <sstream>
#include <fstream>
#include <set>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Estructura de datos para el código generado. El código, en vez de escribirlo directamente,
 * se guarda en esta estructura y, al final, se escribirán en un fichero.
 */
class Codigo {

private:

    /**************************/
    /* REPRESENTACION INTERNA */
    /**************************/

    /* Instrucciones que forman el código. */
    std::vector<std::string> instrucciones;

    /* Clave para generar identificaciones nuevos. Cada vez que se crea un id se incrementa. */
    int siguienteId;

    
public:

    /************************************/
    /* METODOS PARA GESTIONAR EL CODIGO */
    /************************************/

    /* Constructora */
    Codigo();

    /* Crea un nuevo identificador del tipo "%t1, %t2, ...", siempre diferente. */
    std::string nuevoId() ;

    /* Añade una nueva instrucción a la estructura. */
    void anadirInstruccion(const std::string &instruccion);

    /* Dada una lista de variables y su tipo, crea y añade las instrucciones de declaración */
    void anadirDeclaraciones(const std::vector<std::string> &idNombres, const std::string &tipoNombre);

    /* Dada una lista de parámetros y su tipo, crea y añade las instrucciones de declaración */
    void anadirParametros(const std::vector<std::string> &idNombres, const std::string &pClase, const std::string &pTipo);

   
    /* Añade a las instrucciones que se especifican la referencia que les falta.
     * Por ejemplo: "goto" => "goto 20" */
    void completarInstrucciones(std::vector<int> &numerosInstrucciones, const int referencia);

    /* Escribe las instrucciones acumuladas en la estructura en el fichero de salida, con su punto y coma al final. */
    void escribir() const;

    /* Devuelve el número de la siguiente instrucción. */
    int obtenRef() const;

    /////////////////////////////////////////////
    /* NUEVAS FUNCIONES AÑADIDAS */
    /////////////////////////////////////////////

    /* Devuelve el string atado a un TID*/
    std::string dollar_to_string( std::string* s );

    /* Por cada variable a la lista de entrada, empezando por el primero y hasta el último añade una instrucción teniendo en cuenta el par_class y el type.*/
    void anadir_argumentos(std::vector<std::string> &listaArgumentos, std::string &pClase, std::string &pTipo );

    /* Junta en una sola lista de integers las dos listas de integers que se le han pasado */
    std::vector<int> unirInt(const std::vector<int> &lista1, const std::vector<int> &lista2);

};

#endif /* CODIGO_HPP_ */
