/*
En una librer�a se venden 4 modelos diferentes de cuadernos, con los siguientes precios:

	- Modelo#1 � Q10.00
	- Modelo#2 � Q15.00
	- Modelo#3 � Q18.50
	- Modelo#4 � Q25.00

Por otra parte, se tiene informaci�n sobre las ventas realizadas durante los �ltimos 30 d�as, estos
movimientos se deben de guardar en un archivo de la siguiente forma:

DIA1,MOD,CANT
DIA2,MOD,CANT
.
.
.
DIA30,MODELO,CANTIDAD

DIAi = Variable que representa el d�a que se efectu� la venta i (1 - 30)
MOD= Variable que representa c�digo de Modelo que se vendi�. (1 � 4)
CANT= Variable que representa la cantidad de unidades vendidas.

El programa debe ser capaz de:
	- Modificar el n�mero de unidades vendidas, solicitando al usuario el d�a y c�digo de articulo
	(modificaci�n del archivo)
	- Eliminaci�n de un d�a especifico de venta (modificaci�n del archivo)
	- Calcular el total recaudado por modelo en los 30 d�as.
 	- Calcular cu�l fue el modelo que se vendi� mas en los 30 d�as
*/

// Importaci�n de Librer�as
#include <fstream> //Para el manejo de archivos
#include <iostream> //Para operaciones de entrada o salida
#include <string> //Para el manejo de car�cteres
#include <vector> // Para el manejo de vectores

/*
Espacio de nombre el cual se asocia a "n" funciones, en este caso 
nos sirve para evitar los encapsulamientos std::cout o std::in
*/

using namespace std;

//Creaci�n de estructura de tipo cuadernos
struct cuadernos{
	int DIAi;
	int MOD;
	int CANT;
	float precioTotal;
};
//Funci�n para lectura del archivo
void leerArchivo(){
	ifstream lecarchivo;
	
	//Variables para guardar datos
	int dia, modelo, cantidad;
	float total;
	
	lecarchivo.open("HT6_EJERCICIO_01.txt", ios::in);
	
	cout << "**************** LISTADO DE VENTAS *****************" << endl;
	cout << "D�a" << "\t" << "Modelo" << "\t" << "Cantidad" << "\t" << "Precio Total" << endl;
	
	while(lecarchivo >> dia >> modelo >> cantidad >> total){
		cout << dia << "\t" << modelo << "\t" << cantidad << "\t" << "\t" << total << endl;
	}
	lecarchivo.close ();
}

//Funci�n encargada de gestionar la compra de cuadernos
void compra_cuadernos(){
	int modelo_cuaderno;
	
	//Declaraci�n de variable de tipo estructura
	cuadernos strCuadernos;
	
	cout << "----------MODELOS DE CUADERNOS-----------" << endl;
	cout << "Seleccione cualquiera de las opciones: " <<endl;
	cout << "\nModelo No. " << "\t" << "Precio" << endl;
	cout << "1." << "\t" << "\t" << "Q. 10.00" << endl;
	cout << "2." << "\t" << "\t" << "Q. 15.00" << endl;
	cout << "3." << "\t" << "\t" << "Q. 18.50" << endl;
	cout << "4." << "\t" << "\t" << "Q. 25.00" << endl;
	cin >> modelo_cuaderno; 
	
	//Ingresar cla cantidad de cuadernos
	cout <<"Ingresar la cantidad de cuadernos que desea comprar:" << endl;
	cin >> strCuadernos.CANT;
	
	//Ingresar el d�a en que se realiza la compra	
	cout <<"Ingresar el d�a de la compra (1-30):" << endl;
	cin >> strCuadernos.DIAi;
	
	switch(modelo_cuaderno){
		case 1:
			strCuadernos.MOD= 1;
			strCuadernos.precioTotal = strCuadernos.CANT * 10;
			break;
		case 2:
			strCuadernos.MOD= 2;
			strCuadernos.precioTotal = strCuadernos.CANT * 15;
			break;
		case 3:
			strCuadernos.MOD= 3;
			strCuadernos.precioTotal = strCuadernos.CANT * 18.50;
			break;
		case 4:
			strCuadernos.MOD= 4;
			strCuadernos.precioTotal = strCuadernos.CANT * 25;
			break;
		default:
			cout << "-Elecci�n Invalida-" << endl;
			break;
	}
	//Crear archivo std::ios_base::app
	ofstream archivoCompra("HT6_EJERCICIO_01.txt",std::ios_base::app);
	
	//Grabar datos en archivo
	archivoCompra << strCuadernos.DIAi << "\t" << strCuadernos.MOD << "\t" <<  strCuadernos.CANT << "\t" << strCuadernos.precioTotal << endl;
	
	//Cerramos archivo
	archivoCompra.close();
	
	cout << "-Venta guardada exitosamente-" << endl;
}

//Funci�n encarcada de modificar cantidad comprada de cuadernos
void modificarCantidad(){
	
	cout << "********** MODIFICACI�N DE CANTIDAD VENDIDA **********" << endl;
	leerArchivo();
	
	//Declaraci�n de variables
	int dia, modelo, cantidadNueva, diaAnterior, modeloAnterior, cantidadAnterior;
	float preciototalAnterior;
	char respuesta;
	bool bandera = false;
	bool bandera2 = false;
	
	//Creaci�n de archivos
	ifstream archivoAnterior;
	ofstream archivoActual;
	
	//Remover archivos si en caso existe
	remove("Temporal.txt");
	
	archivoAnterior.open("HT6_EJERCICIO_01.txt",ios::in);
	archivoActual.open("Temporal.txt",ios::app); 
	
	cout << "Ingresar el d�a en que fue realizada la venta (1-30):" << endl;
	cin >> dia;
	
	cout << "Ingresar el modelo que desea modificar la cantidad (1-40):" << endl;
	cin >> modelo;
	
	do{
		cout << "Ingresar la nueva cantidad:" << endl;
		cin >> cantidadNueva;
		cout << "�Seguro que se desea modificar el registro? S/N" << endl;
		cin >> respuesta;
		// Convertir respuesta a may�scula con: toupper
		respuesta = toupper (respuesta);
	}while (respuesta != 'S');
	
	//Leer datos del archivo anterior para modificarlos
	while(archivoAnterior >> diaAnterior >> modeloAnterior >> cantidadAnterior >> preciototalAnterior){
		if (dia == diaAnterior and modelo == modeloAnterior){
				//Calcular el nuevo total
			switch (modelo){
				case 1:
					preciototalAnterior = cantidadNueva * 10;
					break;
				case 2:
					preciototalAnterior = cantidadNueva * 15;
					break;
				case 3:
					preciototalAnterior = cantidadNueva * 18.50;
					break;
				case 4:
					preciototalAnterior = cantidadNueva * 25;
					break;
				default:
					cout << "-Modelo no existe-" << endl;
					break;
			}
			archivoActual << diaAnterior << "\t" << modeloAnterior << "\t" << cantidadNueva << "\t" << preciototalAnterior << endl;
			bandera = true;
			
			
		}
		else if (dia != diaAnterior and modelo != modeloAnterior){
			archivoActual << diaAnterior << "\t" << modeloAnterior << "\t" << cantidadAnterior << "\t" << preciototalAnterior << endl;
			bandera2 = true;
		}
		
	}
	if (bandera == false and bandera2 == true){
		cout << "-NO SE HA ENCONTRADO LA VENTA-" << endl;
	}
	//Cerramos archivo
	archivoAnterior.close();
	archivoActual.close ();
	
	if (bandera){
		cout << "-Registro guardado correctamente-" << endl;
		remove("HT6_EJERCICIO_01.txt");
		rename("Temporal.txt","HT6_EJERCICIO_01.txt");
		
	}
	
	
}

//Funci�n encargada de eliminar d�a de venta
void eliminarDiaVenta(){
	
	cout << "********** ELIMINACI�N DE D�A DE VENTA **********" << endl;
	leerArchivo();
	//Declaraci�n de variables
	int dia, diaAnterior, modeloAnterior, cantidadAnterior;
	float totalAnterior;
	bool bandera = false;
	
	//Creaci�n de archivos
	ifstream archivoAnterior;
	ofstream archivoNuevo;
	
	//Remover archivo si en caso existe
	remove("Temporal.txt");
	
	//Abrir archivos
	archivoAnterior.open("HT6_EJERCICIO_01.txt", ios::in);
	archivoNuevo.open("Temporal.txt", ios::app);
	
	//Obtenci�n del d�a a eliminar
	cout << "Por favor ingrese el d�a que desea eliminar del reporte:" << endl;
	cin >> dia;
	
	
	while(archivoAnterior >> diaAnterior >> modeloAnterior >> cantidadAnterior >> totalAnterior){
			if (dia == diaAnterior){
				
				bandera = true;
			}
			else if (dia != diaAnterior){
				archivoNuevo << diaAnterior << "\t" << modeloAnterior << "\t" << cantidadAnterior << "\t" << totalAnterior << endl;
			}
	}
	
	if (bandera == false){
		cout << "Registro eliminado correctamente..." << endl;
		cout << "D�a no encontrado en el registro de ventas" << endl;
		remove("Temporal.txt");
	}
	
	//Cerramos archivo
	archivoAnterior.close();
	archivoNuevo.close();
	
	if(bandera){
		//Eliminamos el archivo anterior
		remove("HT6_EJERCICIO_01.txt");
		//Renombramos el archivo nuevo
		rename("Temporal.txt", "HT6_EJERCICIO_01.txt");
	}
	
}

//Funci�n calcular el total vendido para el cuaderno
void totalModelo(){
	//Creaci�n de variable tipo archivo
	ifstream archivo;
	//Variables que almacenar�n los datos del archivo
	int dia, modelo, cantidad;
	float total;
	//Contadores de totales por modelo de cuaderno
	float totalModelo1 = 0.00, totalModelo2 = 0.00, totalModelo3 = 0.00, totalModelo4 = 0.00;
	
	//Abrir archivo
	archivo.open("HT6_EJERCICIO_01.txt", ios::in);
	
	//Lectura del archivo
	while (archivo >> dia >> modelo >> cantidad >> total){
		if (modelo == 1){
			totalModelo1 = totalModelo1 + total;
		}else if (modelo == 2){
			totalModelo2 = totalModelo2 + total;
		}else if (modelo == 3){
			totalModelo3 = totalModelo3 + total;
		}else if (modelo == 4){
			totalModelo4 = totalModelo4 + total;
		}
	}
	
	archivo.close();
	
	cout <<"El total recaudado por modelo en 30 d�as es de: " << endl;
	cout <<"Modelo 1: Q. " << totalModelo1 << endl;
	cout <<"Modelo 2: Q. " << totalModelo2 << endl;
	cout <<"Modelo 3: Q. " << totalModelo3 << endl;
	cout <<"Modelo 4: Q. " << totalModelo4 << endl;
	
}

//Funi�n para calcular el modelo m�s vendido
void modelomasVen(){
	//creaci�n de variable tipo archivo
	ifstream archivo;
	//Declaraci�n de variables
	int dia, modelo, cantidad = 0;
	float total;
	//Contadores de cantidad vendidas por modelo
	int conModelo1 = 0, conModelo2 = 0, conModelo3 = 0, conModelo4 = 0;
	//Variable de control de qui�n es mayor
	int aux = 0, cont = 1;
	
	//Abrir archivo
	archivo.open("HT6_EJERCICIO_01.txt", ios::in);
	
	//lectura de archivo y validaci�n de cantidad vendida por el modelo de cuaderno
	while (archivo >> dia >> modelo >> cantidad >> total){
		if (modelo == 1){
			conModelo1 = conModelo1 + cantidad;
		}else if (modelo == 2){
			conModelo2 = conModelo2 + cantidad;
		}else if (modelo == 3){
			conModelo3 == conModelo3 + cantidad;
		}else if (modelo == 4){
			conModelo4 == conModelo4 + cantidad;
		}
	}
	
	//Arreglo para realizar iteraciones para saber qu�en es mayor
	int arregloContador[4] = {conModelo1, conModelo2, conModelo3, conModelo4};
	
	//Interaci�n de arreglo
	//Iteraci�n: ir a uno a uno seg�n los registros que se encuentren en un vector, arreglo, lista, etc.
	for (int i = 0; i <= 3; i++){
		if (arregloContador[i] > aux){
			aux = arregloContador[i];
			cont = cont + 1;
		}
	}
	
	switch(cont){
		case 1:
			cout << "EL MODELO M�S VENDIDO ES EL NO. 1 CON: " << conModelo1 << " CANTIDADES VENDIDAS." << endl;
			break;
		case 2:
			cout << "EL MODELO M�S VENDIDO ES EL NO. 2 CON: " << conModelo2 << " CANTIDADES VENDIDAS." << endl;
			break;
		case 3:
			cout << "EL MODELO M�S VENDIDO ES EL NO. 3 CON: " << conModelo3 << " CANTIDADES VENDIDAS." << endl;
			break;
		case 4:
			cout << "EL MODELO M�S VENDIDO ES EL NO. 4 CON: " << conModelo4 << " CANTIDADES VENDIDAS." << endl;
			break;
		default:
			cout << "-NO ES POSIBLE CALCULAR EL MODELO M�S VENDIDO-" << endl;
			break;
	}
	
}

//Funci�n principal del programa
int main(){
	
	//Declaraci�n de variables
	int eleccion; //int= va almacenar n�meros enteros
	bool finalizar = false; //bool= almacenar valores verdaderos o falsos
	
	//Ciclo
	do {
		//Menu principal
		//limpiar buffer
		fflush (stdin);
		cin.clear();
		
		//Salida de consola
		cout << "-------------------VENTA DE LIBROS---------------" << endl;
		cout << "Por favor elegir una opci�n" << endl;
		cout << "\n1. Compra de cuadernos." << endl;
		cout << "2. Modificar unidades vendidas." << endl;
		cout << "3. Eliminaci�n de d�a de venta." << endl;
		cout << "4. Total recaudado por modelo (30 d�as)." << endl;
		cout << "5. Modelo m�s vendido (30 d�as)." << endl;
		cout << "6. Salir." << endl;
		//obtener opci�n ingresada por el usuario
		cin >> eleccion;
		
		switch (eleccion){
			case 1: 
				//Invocaci�n de funci�n para compra de cuadernos
				compra_cuadernos();
				break;
			case 2:
				//Invocaci�n de funci�n para modificar
				modificarCantidad();
				break;
			case 3:
				eliminarDiaVenta();
				break;
			case 4:
				totalModelo();
				break;
			case 5:
				modelomasVen();
				break;
			case 6: 
				finalizar = true;
				break;
			default:
				cout << "-Elecci�n Invalida-" << endl;
				eleccion = 0;
				break;
		}
		
		
	}while (finalizar != true);
	
	
	
	return 0;
}
