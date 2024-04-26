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


/************/
/* añadir_argumentos */
/************/


void Codigo::anadir_argumentos(  const vector<string> &listaArgumentos,  const string &pClase,  const string &pTipo )  {
   
  vector<string>::const_iterator string_iter;

  string EMPTY_STRING = " ";  
  string LOW_BAR = "_";

  for (string_iter=listaArgumentos.begin(); string_iter!=listaArgumentos.end(); string_iter++) {

    string name = pClase + LOW_BAR +  pTipo; 
    string cadena =  name + EMPTY_STRING +  *string_iter; 
    anadirInstruccion( *string_iter );
    
  }

}

std::vector<string> inilista() { 

  std::vector<string>  v = {};
  return v;

}

std::vector< int > inilistaNum() { 

  std::vector< int > v = {};
  return v;

}

std::vector<string> anadir( std::vector<string> &lista, string &nombre ) {  
    lista.push_back( nombre ); 
    return lista; 
}