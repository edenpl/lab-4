#include<iostream>
#include<sstream>
#include<string.h>
using namespace std;



class Curso{
	private: 
		int nroAlumnos;
		string nombre;
		string codigo;
		
	public:
		Curso();
		Curso(string , string , int);
		
		string getCodigo();
		string getNombre();
		int getNroAlumnos();
		
		void setNombre(string);
		void setCodigo(string );
		void setNroAlumnos(int);
		string toString();
};
Curso::Curso(){
	nombre = "o";
	codigo = "o";
	nroAlumnos = 0;
}
Curso::Curso(string _nombre , string _codigo ,int _nroalumnos){
	nombre = _nombre;
	codigo = _codigo;
	nroAlumnos = _nroalumnos;
	
}
void Curso::setCodigo(string _codigo){
	codigo = _codigo;
}
void Curso::setNombre(string _nombre){
	nombre = _nombre;
}
void Curso::setNroAlumnos(int _nroAlumnos){
	nroAlumnos = _nroAlumnos;
}
string Curso::getNombre(){
	return nombre;
}
string Curso::getCodigo(){
	return codigo;
}
int Curso::getNroAlumnos(){
	return nroAlumnos;
}
string Curso::toString(){
	stringstream s;
	s<<"nombre : "<<nombre<<endl;
	s<<"codigo : "<<codigo<<endl;
	s<<"nroalumnos : "<<nroAlumnos<<endl;
	return s.str();
}



class ArregloDeCursos{
	Curso *cursos = NULL;
	int tam;
	public:
		int cantidad ;
		ArregloDeCursos();
		ArregloDeCursos(Curso *,int);
		~ArregloDeCursos();
		ArregloDeCursos(const ArregloDeCursos &c); 
		void redimensionar(int n);
		void push_back(Curso &);
		void insert(int ,Curso &);
		void remove(int pos);
		int getSize();
		void clear();
		string mostrar();
};
// un constructor simple
ArregloDeCursos::ArregloDeCursos(){
	cantidad = 0;
}
// constructor con parametros 
ArregloDeCursos::ArregloDeCursos(Curso *cursitos , int tama){
	tam = tama;
	cursitos = new Curso[tam];
	cursos  = cursitos;
}
//  constructor copia
ArregloDeCursos::ArregloDeCursos(const ArregloDeCursos &C){
	tam = C.tam;
	cursos = C.cursos;
	cursos = new Curso[tam];
}
// DESTRUCTOR
ArregloDeCursos::~ArregloDeCursos(){
}

// metodo pushback - > PARA EL INGRESO DE ELEMENTOS 
void ArregloDeCursos::push_back(Curso &p){

	if(cantidad < tam){
		cursos[cantidad++] = p;
	}
	
}
// metodos para mostrar el contenido del arreglo 
string ArregloDeCursos::mostrar(){
	stringstream s;
	for(int i = 0 ; i < cantidad; i ++){
		s<<cursos[i].toString()<<endl;
	}
	return s.str();
}
// metodo para redimimensionar el arreglo
void ArregloDeCursos::redimensionar(int num ){
	Curso *aux = new Curso[num];
	for(int i = 0 ; i < num ; i++){
		aux[i] = cursos[i];
	}
	delete[] cursos;
	cursos = aux;
}
// metodo para eliminar los elementos del arreglo 
void ArregloDeCursos::clear(){
	
	delete [] cursos;
	cout<<"\n\nSe eliminaron los elementos del arreglo\n";
}
// obtener el tamaño del arreglo
int ArregloDeCursos::getSize(){

	return  cantidad;

}

int main(){
	Curso *punt;
	ArregloDeCursos a1(punt,6);
	Curso a("hola1","4542",3);
	Curso b("hola1","4585",4);
	Curso c("hola3","15616",5);
	
	a1.push_back(a);  
	a1.push_back(a);  
	a1.push_back(b);   
	a1.push_back(c);   
	a1.push_back(b);  

	cout<<a1.mostrar()<<endl;
	
	cout<<a1.getSize()<<endl<<endl;
	
	a1.push_back(a);
	
	cout<<a1.getSize();
	a1.push_back(a);
	
	a1.clear();
	a1.mostrar();
	
	return 0;
}
