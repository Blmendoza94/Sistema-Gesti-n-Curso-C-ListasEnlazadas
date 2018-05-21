#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
using namespace std;
//Autor: Boris Mendoza Leyton Version: 1.6 Fecha: 18-05-2018.
//Programa que gestiona el control de notas por curso y alumno.

//Declaracion de clase alumno, esta tiene como fin realizar la función de nodo dentro de la lista enlazada de nombre Curso.
class Alumno{
	
	public:
		
	string rut;
	string nombre;
	float n1,n2,n3,n4,prom;
	
	public: Alumno *siguiente;
	
	public:
		//declaración de constructores.
		Alumno(){
			
		}
		Alumno(string rut,string nombre){
			this->rut = rut;
			this->nombre = nombre;
			n1 = 1.0;
			n2 = 1.0;
			n3 = 1.0;
			n4 = 1.0;
			prom = 1.0;	
		}
		//Método que muestra los datos del alumno ingresado.
		void mostrarDatos(){
			cout<<"\n Rut : "<<rut;
			cout<<"\n Nombre : "<<nombre;
		}
		//Método que muestra atributos como notas, promedio y condicion de aprobacion del curso por un alumno. 
		void mostrarAlumno(){
			
			prom = (n1+n2+n3+n4)/4;
			cout<<"\n Rut : "<<rut;
			cout<<"\n Nombre : "<<nombre<<" .... "<<"["<<setprecision(2)<<n1<<"]"<<" ["<<setprecision(2)<<n2<<"]"<<" ["<<setprecision(2)<<n3<<"]"<<" ["<<setprecision(2)<<n4<<"]";
			cout<<"\n Promedio: "<<" .... "<<" ["<<setprecision(2)<<prom<<"] "<<endl;
			
			if(prom>= 1.0 && prom < 4.0 ){
			   cout<<"\n Promedio: "<<" .... "<<" [ REPROBADO ] "<<endl;
			}else if(prom>= 4.0 && prom < 6.0){
				cout<<"\n Promedio: "<<" .... "<<" [ RINDE EXAMEN ] "<<endl;
			}else if ( prom>= 6.0){
				cout<<"\n Promedio: "<<" .... "<<" [ APROBADO ] "<<endl;
			}
		}
};
//Declaracion de la clase Curso que cumple la funcion de lista Enlazada.
class Curso{
	//Declaración de atributos.
	public:
    string profesor;
    string asignatura;
	Alumno *primero;
    
    public:
    //Declaración de constructores.	
    Curso(){
	}
	
    Curso(string profesor,string asignatura){
    	this->profesor = profesor;
    	this->asignatura = asignatura;
    	primero = NULL;
	}
    //Método que tiene como finalidad agregar los nodos alumno a la lista enlazada.
	void agregar(Alumno *alumn){
		
		Alumno *aux;
		aux = primero;
		alumn->siguiente = aux;
		primero = alumn;
	}
	// Función booleana que tiene como finalidad señalar la existencia de un curso en uso.
	bool existeCurso(){
	   return primero != NULL;
	}
	//Función booleana que tiene como finalidad señalar la existencia de campos de profesor y asignatura distintos de vacio. 
	bool existeProfesor(){
		return profesor != " " && asignatura != "";
	}
	// Función entera que tiene como finalidad retornar el total de alumnos en la lista, ademas de mostrar los datos de estos. 
	int mostrar(){
		Alumno *aux;
		int i = 0;
		aux = primero;
		//cout<<"\n Nombre docente: "<<this->profesor;
		//cout<<"\n Asignatura: "<<this->asignatura<<endl<<endl;
		while(aux != NULL){
			aux->mostrarAlumno();
			cout<<"\n";
			aux = aux->siguiente;
			i++;
		}
		return i;
	}
	//Método que realiza la busqueda del rut en donde se quieren agregar notas, además realiza el agregado de las mismas. 
    void buscarAgregar(Curso *list, string r){
	Alumno *aux = list->primero;
	float n_1 = 0.0 ,n_2 = 0.0 ,n_3 = 0.0 ,n_4 = 0.0;
	bool existe = false;
	while(aux != NULL){
		
		if(aux->rut == r){
		
			system("cls");
			
			cout<<"\n\n\t - FORMULARIO DE INGRESO DE NOTAS -\n\n ";
			cout<<" -> Importante: Las notas deben ingresarse en un rango de 1 a 7.\n";
			aux->mostrarDatos();
			//Cada while valida que las notas se encuentre en rangos de 1 a 7, de lo contrario la vuelve a solicitar.
			while(n_1 < 1.0 || n_1 > 7.0){
			cout<<"\n\n Ingrese nota 1 : ";
			cin>>n_1;
			aux->n1 = n_1;
		    }
			while(n_2 < 1.0 || n_2 > 7.0){
			cout<<"\n Ingrese nota 2 : ";
			cin>>n_2;
			aux->n2 = n_2;
		   }
		   while(n_3 < 1.0 || n_3 > 7.0){
	        cout<<"\n Ingrese nota 3 : ";
			cin>>n_3;
			aux->n3 = n_3;
			}
		   while(n_4 < 1.0 || n_4 > 7.0){
			cout<<"\n Ingrese nota 4 : ";
			cin>>n_4;
			aux->n4 = n_4;
		   }
		   cin.ignore();
			cout<<"\n\t - > NOTAS AGREGADAS CON EXITO < -\n\n ";
			existe = true;
		}
		aux = aux->siguiente;
	}
	if(existe == false){
		cout<<"\n\t - > EL RUT DE ALUMNO NO EXISTE < -\n\n ";
	}
}
//Método que realiza la impresión por pantalla de las estadísticas.
void estadisticas(Curso *list_2){
	system("cls");
	float promedioCurso = 0;
	Alumno *aux = list_2->primero;
	float totalAlumnos = 0;
	cout<<"\n\t        **** ESTADISTICAS **** \n";
	cout<<"\n Profesor: "<<list_2->profesor<<endl;
	cout<<" Asignatura: "<<list_2->asignatura<<endl;
	cout<<"\n Lista del Curso: \n\n";
	totalAlumnos = list_2->mostrar();
	cout<<"\n Total Alumnos del curso: "<<totalAlumnos;
	while(aux != NULL){
		promedioCurso += aux->prom;
		aux = aux->siguiente;
	}
    cout<<"\n Promedio Curso: "<<setprecision(2)<<promedioCurso/totalAlumnos;
	
}
	

};

// Declaración de la función principal.
int main(){
	
	bool reset = true;
	Curso *listaEnlazada = new Curso();
	int i = 0;
	while(reset == true){
		
	system("cls");
	
	int op = 0;
    //Menú del programa.
	cout<<"\n < Sistema registro de Notas >\n\n";
	cout<<" 1.- Registrar curso.\n";
	cout<<" 2.- Registrar alumnos.\n";
	cout<<" 3.- Ingresar nota a un alumno.\n";
	cout<<" 4.- Mostrar estadisticas.\n";
	cout<<" 5.- Salir del programa.\n";
    cout<<"\n - > Ingrese su seleccion: ";
    cin>>op;
    cin.ignore();
    //Ingreso de la variable op como uno de los case de la función switch
    switch(op){
    	// Case 1 realiza el registro del curso.
    	case 1:{
    		system("cls");
    		string profesor;
    		string asignatura;
    		
    		cout<<"\n\n\t       - FORMULARIO DE REGISTRO CURSO -\n\n";
    		cout<<" -> Importante: Debes ingresar un nombre de profesor y asignatura.\n\n";
    		while(profesor == "" || profesor == " "){
    		cout<<" -> Ingrese nombre profesor: ";
    		getline(cin,profesor,'\n');
    		listaEnlazada->profesor = profesor;
    		}
    	    while(asignatura == "" || asignatura == " "){
    		cout<<" -> Ingrese asignatura: ";
    		getline(cin,asignatura,'\n');
    		listaEnlazada->asignatura = asignatura;
    	    }
    	    
    	    if(i == 0){
			cout<<"\n\t < CURSO REGISTRADO > \n";
    	   }
    	    if(i>0){
			cout<<"\n\t             < CURSO REGISTRADO > \n";
    	    cout<<"\n\t [FUERON SOBRE ESCRITO PROFESOR Y ASIGNATURA]\n\n";
		  }
			i++;
    	    cin.get();
			break;
		}
		//Case 2 realiza el registro de un alumno en el curso.
		case 2:{
			if(listaEnlazada->existeProfesor()){
			system("cls");
			string rut;
			string nombre;
			bool p = false;
			Alumno *existe = new Alumno();
			existe = listaEnlazada->primero;
			cout<<"\n\n\t      - FORMULARIO DE REGISTRO ALUMNO -\n\n";
			do{
			
			cout<<" -> Ingrese rut: ";
			getline(cin,rut,'\n');// getline permite el ingreso de string con espacios.
			while(existe != NULL){
				if(rut == existe->rut){
					cout<<"\n\n\t ERROR -> HAZ INGRESADO UN RUT EXISTEN. \n\n";
					p = true;
					break;
				}else{
					p = false;
				}
				existe = existe->siguiente;
			}
		}while( p == true );
			cout<<" -> Ingrese nombre: ";
			getline(cin,nombre,'\n');
			
			Alumno *a = new Alumno(rut,nombre);
			listaEnlazada->agregar(a);
			cout<<"\n\t < ALUMNO AGREGADO > \n\n";
		    }else{
		    	cout<<"\n\n\t - NO EXISTE CURSO PARA REGISTRAR ALUMNOS -\n\n";
			}
	        cin.get();
			break;
		}
		//Case 3 permite ingresar las notas a un alumno según su rut. 
		case 3:{
			if(listaEnlazada->existeCurso()){
			system("cls");
			string rut;
			cout<<"\n\n\t       - FORMULARIO DE INGRESO DE NOTAS -\n\n ";
			cout<<" -> Ingrese rut alumno: ";
			getline(cin,rut,'\n');
			listaEnlazada->buscarAgregar(listaEnlazada,rut);
		    }else{
		    	cout<<"\n\n\t   - NO EXISTEN ALUMNOS PARA AGREGAR NOTAS -\n\n";
			}
			cin.get();
			break;
		}
		//Case 4 realiza el cálculo de la estadísticas del programa.
		case 4:{
			if(listaEnlazada->existeCurso()&&listaEnlazada->existeProfesor()){
			listaEnlazada->estadisticas(listaEnlazada);
		    }else{
		    	cout<<"\n\n\t   - NO EXISTE CURSO PARA CALCULAR ESTADISTICAS -\n\n";
			}
			cin.get();
			break;
		}
		case 5:{
			cout<<"\n\t - > [ FIN DEL PROGRAMA - HASTA LUEGO ] < - \n\n";
			reset = false;
			break;
		}
		// En caso de que op se distinto de alguna de la opciones, se muestra el mensaje de ingreso erróneo y se finaliza el programa. 
		default: {
			cout<<"\n\t - > [ INGRESO ERRONEO - FIN DEL PROGRAMA ] < - \n\n";
			reset = false;
			break;
		}
	}

}
	return 0;
}
