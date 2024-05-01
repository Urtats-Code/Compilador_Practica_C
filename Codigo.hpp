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

    std::vector<std::string> anadirStr( std::vector<std::string> &lista, std::string &nombre ) ;

    std::string unirStrings1(const char* c, const std::string& s) ;
    std::string dollar_to_string( std::string* s );

    /////////////////////////////////////////////7
    /* NUEVAS FUNCIONES AÑADIDAS */
    /////////////////////////////////////////////7



    // /* Por cada variable a la lista de entrada, empezando por el primero y hasta el último añade una instrucción teniendo en cuenta el par_class y el type.*/
    // void anadir_argumentos(const std::vector<std::string> &listaArgumentos, const std::string &pClase, const std::string &pTipo);

    // /* Crea una lista vacía */
    // std::vector<std::string> inilista();

    // /* Crea una lista vacía cuyo primer y único elemento es “num”. */
    std::vector<int> inilistaNum(int num);

    // /* Añade el nombre al comienzo de la lista de strings de entrada y devuelve la nueva lista. */
    // std::vector<std::string> anadirStr(std::vector<std::string> &lista, std::string &nombre);

    // /* Añade el numero al comienzo de la lista de numeros de entrada y devuelve la nueva lista. */
    // std::vector<int> anadirInt(std::vector<int> &lista, int &num);

    // /* Junta en una sola lista de integers las dos listas de integers que se le han pasado */
    // std::vector<int> unirInt(const std::vector<int> &lista1, const std::vector<int> &lista2);

};

#endif /* CODIGO_HPP_ */
