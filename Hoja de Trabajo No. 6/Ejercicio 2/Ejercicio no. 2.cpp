/*
Realice un programa que, dado el peso, la altura, la edad y el género (M/F) de un grupo de N personas
que pertenecen a un departamento de la república, obtenga un promedio de peso, altura y edad de esta
población. Los datos deben guardarse de forma ordenada por edad en un archivo de datos. Así mismo
el programa debe ser capaz leer los datos del archivo y generar un reporte con la media del peso, altura
y la edad. 
*/

//Importación de librerías
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Creación de estructura
struct personas{
	int edad;
	char genero;
	float altura;
	float peso;
};

void ordenar(){
	
	personas temporalPersonas;
	vector<personas> vectorRegistros;


	ifstream archivoLectura;
	archivoLectura.open("Registro de Personas.txt",ios::in);
	
	while(archivoLectura>>temporalPersonas.edad>>temporalPersonas.peso>>temporalPersonas.altura>>temporalPersonas.genero){
    	vectorRegistros.push_back(temporalPersonas);
	};
	
  
  archivoLectura.close();
  
  for(int i=0; i<vectorRegistros.size(); i++) {
   for(int j=i+1; j<vectorRegistros.size(); j++)
   {

      if(vectorRegistros[j].edad < vectorRegistros[i].edad) {
         temporalPersonas = vectorRegistros[i];
         vectorRegistros[i] = vectorRegistros[j];
         vectorRegistros[j] = temporalPersonas;
      }
   }
  } 

    ofstream archivoNuevo;
    archivoNuevo.open("Registro de Personas.txt",ios::out);
    
    for (int i=0; i<vectorRegistros.size(); i++){
      archivoNuevo << vectorRegistros[i].edad <<"\t"<< vectorRegistros[i].peso <<"\t"<< vectorRegistros[i].altura <<"\t"<< vectorRegistros[i].genero <<endl;
    }
    
    archivoNuevo.close();

}

void personasRegistro(){
	bool terminar = false;
	char continuar;
	personas strPersonas;
	
	cout << "************* Registro de Persona *************" << endl;
	
	
	do{
		cout << "Ingresar la edad de la persona" << endl;
		cin >> strPersonas.edad;
		
		cout << "Ingresar el peso de la persona" << endl;
		cin >> strPersonas.peso;
		
		cout << "Ingresar la altura de la persona" << endl;
		cin >> strPersonas.altura;
		
		cout << "Ingresar el genero de la persona (M/F)" << endl;
		cin >> strPersonas.genero;
		strPersonas.genero = toupper(strPersonas.genero);
		
		//Crear archivo
		ofstream archivoPersonas ("Registro de Personas.txt", std::ios_base::app);
		
		//Grabar datos
		archivoPersonas << strPersonas.edad << "\t" << strPersonas.peso << "\t" << strPersonas.altura << "\t" << strPersonas.genero << endl;
		
		//Cerramos archivo
		archivoPersonas.close();
		
		cout << "¿Desea registrar a otra persona? S/N" << endl;
		cin >> continuar;
		continuar = toupper(continuar);
		
		if (continuar == 'S'){
			//Variable terminar = falsa
			terminar = false;
		}else {
			terminar = true;
		}
		//sino entonces terminar = true; sino: else{}
		
		
			
	}while(terminar != true);
	
}

void promedio(){
	//Declaración de variables para promedio
	float promedioEdad = 0.00, promedioPeso = 0.00, promedioAltura = 0.00;
	//Contador del ciclo (variable global dentro de la función)
	int i = 0;
	
	// Declaración de variables tipo estructura de Persona
	personas temporalPersonas;
	// Declaración de vector de tipo estructura de Persona
	vector <personas> vectorRegistros;
	
	//Declaración de variable archivo
	ifstream archivoLectura;
	//Abrimos archivo
	archivoLectura.open("Registro de Personas.txt",ios::in);
	
	//Lectura 
	while(archivoLectura>>temporalPersonas.edad>>temporalPersonas.peso>>temporalPersonas.altura>>temporalPersonas.genero){
    	vectorRegistros.push_back(temporalPersonas);
	};
	
	//Cerramos archivo
	archivoLectura.close();
	
	//Iteración de vector para sarcar promedios
	for (i; i < vectorRegistros.size(); i++){
		//Suma de registors
		promedioEdad = vectorRegistros[i].edad + promedioEdad;
		promedioAltura = vectorRegistros[i].altura + promedioAltura;
		promedioPeso = vectorRegistros[i].peso + promedioPeso;
		
	}
	
	//Calcular promedios
	promedioEdad = promedioEdad/(i);
	promedioAltura = promedioAltura/(i);
	promedioPeso = promedioPeso/(i);
	
	//Salida
	cout << "************** PROMEDIOS ************" << endl;
	cout << "\nEdad" << "\t" << "Altura" << "\t" << "Peso" << endl;
	cout << promedioEdad << "\t" << promedioAltura << "\t" << promedioPeso << endl;
}

void reporte(){
	// Declaración de variables tipo estructura de Persona
	personas temporalPersonas;
	// Declaración de vector de tipo estructura de Persona
	//vector <personas> vectorRegistros;
	 
	 //Salida de pantalla
	 cout << "*************** REPORTE DE REGISTRO DE PERSONAS ***************" << endl;
	 cout <<  "\nEdad" << "\t" << "Peso" << "\t" << "Altura" << "\t" << "Genero" << endl;
	
	 
	 //Declaración de variable archivo
	ifstream archivoLectura;
	//Abrimos archivo
	archivoLectura.open("Registro de Personas.txt",ios::in);
	
	//Lectura 
	while(archivoLectura>>temporalPersonas.edad>>temporalPersonas.peso>>temporalPersonas.altura>>temporalPersonas.genero){
    	
    	cout << temporalPersonas.edad << "\t" << temporalPersonas.peso << "\t" << temporalPersonas.altura << "\t" << temporalPersonas.genero << endl;
	};
	
	//Cerramos archivo
	archivoLectura.close();
	
}

//Función principal
int main(){
	//Declaración de variables
	int opcion;
	bool finalizar = false;
	
	do {
		//Limpiar buffer
		fflush(stdin);
		cin.clear();
		
		cout << "*************** CONTROL DE PESO ***************" << endl;
		cout << "********** Departamento de Guatemala *********" << endl;
		cout << "\nSelecciona la opción deseada: " << endl;
		cout << "\n1. Registro de persona" << endl;
		cout << "2. Promedios de peso, altura y edad" << endl;
		cout << "3. Reporte" << endl;
		cout << "4. Salir" << endl;
		cin  >> opcion;
		
		switch(opcion){
			case 1:
				personasRegistro();
				ordenar();
				break;
			case 2:
				promedio();
				break;
			case 3:
				reporte();
				break;
			case 4:
				break;
			default:
				cout << "Por favor ingresar cualquiera de las opciones dadas" << endl;
				break;
		}
		
		
	}while (finalizar != true);
	
	
	
	return 0;
}
