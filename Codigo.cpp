#include "Codigo.hpp"

using namespace std;

/****************/
/* Constructora */
/****************/

Codigo::Codigo() {
  siguienteId = 1;
}

/***********/
/* nuevoId */
/***********/


string Codigo::nuevoId() {
  string nId("%t");
  nId += to_string(siguienteId++);
  return nId;
}

/*********************/
/* anadirInstruccion */
/*********************/

void Codigo::anadirInstruccion(const string &instruccion) {
  string cadena;
  cadena = to_string(obtenRef()) + ": " + instruccion;
  instrucciones.push_back(cadena);
}

/***********************/
/* anadirDeclaraciones */
/***********************/

void Codigo::anadirDeclaraciones(const vector<string> &idNombres, const string &tipoNombre) {
  vector<string>::const_iterator iter;
  for (iter=idNombres.begin(); iter!=idNombres.end(); iter++) {
    anadirInstruccion(tipoNombre + " " + *iter);
  }
}

/*********************/
/* anadirParametros  */
/*********************/

void Codigo::anadirParametros(const vector<string> &idNombres, const std::string &clase, const string &tipoNombre) {
  vector<string>::const_iterator iter;
  for (iter=idNombres.begin(); iter!=idNombres.end(); iter++) {
    	anadirInstruccion(clase + "_" + tipoNombre  + " " + *iter );
  }
}


/**************************/
/* completarInstrucciones */
/**************************/

void Codigo::completarInstrucciones(vector<int> &numInstrucciones, const int valor) {
  string referencia = " " + to_string(valor) ;
  vector<int>::iterator iter;
 
  for (iter = numInstrucciones.begin(); iter != numInstrucciones.end(); iter++) {
    instrucciones[*iter-1].append(referencia);
  }
}

/************/
/* escribir */
/************/

void Codigo::escribir() const {
  vector<string>::const_iterator iter;
  for (iter = instrucciones.begin(); iter != instrucciones.end(); iter++) {
    cout << *iter << endl;
  }
}


/************/
/* obtenRef */
/************/

int Codigo::obtenRef() const {
	return instrucciones.size() + 1;
}

std::string Codigo::unirStrings1(const char* c, const std::string& s) {
    string result;
    result.append(c);
    result.append(s);
    return result;
}

std::string Codigo::dollar_to_string(std::string* s) {
    if (s == nullptr) { 
        // Handle potential null pointer
        return ""; // Or throw an exception if appropriate
    }

    std::string result = *s; // Dereference the pointer to get the string
    
    // Perform your dollar-replacement logic on 'result'
    // ...

    return result;
}
/////////////////////////////////////////////7
/* NUEVAS FUNCIONES AÑADIDAS */
/////////////////////////////////////////////7

/*********************/
/* unirStrings1 */
/*********************/

// string Codigo::unirStrings1( char *c, string *s ){

//   int i; 
//   std::string result[ sizeof( c ) + sizeof( s ) ] = { "a" }; 

//   for( i = 0 ; i < sizeof( c ) ; i ++ )
//     result[ i ] = c[ i ];

//   for( i = 0 ; i < sizeof( s ) ; i ++ )
//     result[ i ] = s[ i ];

//   return &result;

// }

// /************/
// /* anadir_argumentos */
// /************/

// void Codigo::anadir_argumentos(const vector<string> &listaArgumentos, const string &pClase, const string &pTipo ) {

//   vector<string>::const_iterator string_iter;

//   string EMPTY_STRING = " ";
//   string LOW_BAR = "_";

//   for (string_iter=listaArgumentos.begin(); string_iter!=listaArgumentos.end(); string_iter++) {

//     string name = pClase + LOW_BAR +  pTipo;
//     string cadena =  name + EMPTY_STRING +  *string_iter;
//     anadirInstruccion( *string_iter );
//   }

// }

// /************/
// /* inilista*/
// /************/

// vector<string> Codigo::inilista() {

//   std::vector<string>  v = {};
//   return v;

// }

// /************/
// /* inilistaNum */
// /************/

// vector<int> Codigo::inilistaNum(int num) {

//   vector<int> v = {};
//   v.push_back( num );
//   return v;

// }

// /************/
// /* inilistaNumEmpty */
// /************/

// vector<int> Codigo::inilistaNumEmpty( ) {

//   vector<int> v = {};
//   return v;

// }

// /************/
// /* anadirStr*/
// /************/
// vector<string> Codigo::anadirStr( vector<string> &lista, string &nombre ) {
//     lista.push_back( nombre );
//     return lista;
// }

// /************/
// /* anadirInt*/
// /************/
// vector<int> Codigo::anadirInt( vector<int> &lista, int &num ) {
//     lista.push_back( num );
//     return lista;
// }


// /************/
// /* unirInt*/
// /************/
// vector<int> Codigo::unirInt(const vector<int> &lista1, const vector<int> &lista2) {
//     vector<int> resultado;

//     // Agregar elementos de la primera lista
//     for (int num : lista1) {
//         resultado.push_back(num);
//     }

//     // Agregar elementos de la segunda lista
//     for (int num : lista2) {
//         resultado.push_back(num);
//     }

//     return resultado;
// }
