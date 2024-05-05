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
    for (auto iter = idNombres.rbegin(); iter != idNombres.rend(); ++iter) {
        string imprimir = tipoNombre + " " + *iter;
        anadirInstruccion(imprimir);
    }
}


/*********************/
/* anadirParametros  */
/*********************/

void Codigo::anadirParametros(const vector<string> &idNombres, const std::string &clase, const string &tipoNombre) {
    for (auto iter = idNombres.rbegin(); iter != idNombres.rend(); ++iter) {
        anadirInstruccion(clase + "_" + tipoNombre  + " " + *iter);
    }
}



/**************************/
/* completarInstrucciones */
/**************************/

void Codigo::completarInstrucciones(vector<int> &numInstrucciones, int valor) {
  
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


/////////////////////////////////////////////7
/* NUEVAS FUNCIONES AÑADIDAS */
/////////////////////////////////////////////7


/************/
/* dollar_to_string */
/************/
std::string Codigo::dollar_to_string(std::string* s) {
    if (s == nullptr) { 
        return ""; 
    }
    std::string result = *s; 
    return result;
}

/************/
/* anadir_argumentos */
/************/

void Codigo::anadir_argumentos(std::vector<std::string> &listaArgumentos, std::string &pClase, std::string &pTipo) {
    vector<string>::const_iterator string_iter;

    const string EMPTY_STRING = " ";
    const string LOW_BAR = "_";

    for (string_iter = listaArgumentos.begin(); string_iter != listaArgumentos.end(); ++string_iter) {
        string name = pClase + LOW_BAR + pTipo;
        string cadena = name + EMPTY_STRING + *string_iter;
        anadirInstruccion(cadena);
    }
}



/************/
/* unirInt*/
/************/
vector<int> Codigo::unirInt(const vector<int> &lista1, const vector<int> &lista2) {
    
    vector<int> resultado; 

    for( int num1 : lista1 ){
      resultado.push_back(num1);
    }

    for (int num : lista2) {
      resultado.push_back(num);
    }

    return resultado;
}