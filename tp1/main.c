#include "altaLista.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void capitalize(char*);

void testStringLongitud () {
	//Strings
	printf("\nProbando string_longitud...\n");

	printf("\tInicializando strings para las pruebas...\n");
	char* s1 = "Gianfranco";
	char* s2 = "Pepe";
	char* s3 = "";
	
	//Prueba string_longitud
	printf("\tCalculando longitudes...\n");
	assert(string_longitud(s1) == 10);			/// s1 == "Gianfranco"
	assert(string_longitud(s2) == 4);			/// s2 == "Pepe"
	assert(string_longitud(s3) == 0);			/// s3 == ""
	printf("\tLas longitudes se calcularon correctamente\n");

}

void testsStringCopiar(){

	printf("\nProbando string_copiar...\n");

	printf("\tInicializando strings para las pruebas...\n");
	char* s1 = "Gianfranco";
	char* s2 = "Pepe";
	char* s3 = "";
	
		
	//Prueba string_copiar
	printf("\tCopiando strings...\n");
	char* s1copia = string_copiar(s1);
	char* s2copia = string_copiar(s2);
	char* s3copia = string_copiar(s3);

	assert(string_iguales(s1,s1copia));			/// s1 == "Gianfranco"
	assert(string_iguales(s2,s2copia));			/// s2 == "Pepe"
	assert(string_iguales(s3,s3copia));			/// s3 == ""
	printf("\tLos string se copiaron correctamente\n");

	//Liberamos las copias
	printf("\tBorrando string copiados...\n");
	free(s1copia);
	free(s2copia);
	free(s3copia);
	printf("\tLos strings fueron borrados\n");

}

void testCompararStrings() {

	printf("\nProbando string_menor...\n");

	printf("\tInicializando strings para las pruebas......\n");
	char* s1 = "Gianfranco";
	char* s2 = "Pepe";
	char* s3 = "Gianfranco";
	char* s4 = "Gian";
	char* s5 = "";

	printf("\tComparando strings...");
	assert(string_menor(s1,s2) == true);			/// s1 == "Gianfranco", s2 == "Pepe"
	assert(string_menor(s2,s1) == false);			/// s3 == "Gianfranco",  s4 == "Gian"
	assert(string_menor(s1,s3) == false);			/// s5 == ""
	assert(string_menor(s1,s4) == false);
	assert(string_menor(s4,s1) == true);
	assert(string_menor(s5,s1) == true);
	assert(string_menor(s1,s5) == false);
	printf("\tTodas las comparaciones de string se realizaron correctamente\n");	
}

void testCrearYBorrarEstudiante() {
	//Pruebas estudianteCrear
	printf("\nProbando estudianteCrear y estudianteBorrar...\n");

	printf("\tCreando estudiantes...\n");
	estudiante* e1 = estudianteCrear("Gianfranco","Lechuga",12);
	estudiante* e2 = estudianteCrear("","",5);

	assert(string_iguales("Gianfranco", e1->nombre));
	assert(string_iguales("Lechuga", e1->grupo));
	assert(e1->edad == 12);
	assert(string_iguales("", e2->nombre));
	assert(string_iguales("", e2->grupo));
	assert(e2->edad == 5);
	printf("\tLos estudiantes fueron creados correctamente\n");

	//Borrar estudiante
	printf("\tBorrando los estudiantes...\n");
	estudianteBorrar(e1);
	estudianteBorrar(e2);
	printf("\t\tLos estudiantes fueron borrados (Controlar con valgrind que no halla perdida de memoria\n");
}

void testCompararEstudiantes() {
	//Pruebas menorEstudiante
	printf("\nProbando menorEstudiante...\n");

	printf("\tCreando estudiantes...\n");
	estudiante* e1 = estudianteCrear("Gianfranco","Lechuga",12);
	estudiante* e2 = estudianteCrear("Pepe", "Zapallo", 21);
	estudiante* e3 = estudianteCrear("Gianfranco","Zanahoria", 21);
	estudiante* e4 = estudianteCrear("Gian", "Berenjena", 15);
	estudiante* e5 = estudianteCrear("","",5);

	printf("\tComparando estudiantes...\n");
	assert(menorEstudiante(e1,e2) == true);			/// e1->nombre == "Gianfranco", e2->"Pepe"
	assert(menorEstudiante(e2,e1) == false);
	assert(menorEstudiante(e1,e3) == true);			/// e3->nombre == "Gianfranco", e1->edad == 12, e2->edad == 21
	assert(menorEstudiante(e3,e1) == false);
	assert(menorEstudiante(e1,e4) == false);		/// e4->nombre == "Gian"
	assert(menorEstudiante(e4,e1) == true);
	assert(menorEstudiante(e5,e1) == true);			/// e5->nombre == ""
	assert(menorEstudiante(e1,e5) == false);
	printf("\tLas comparaciones se hicieron correctamente\n");

	printf("\tBorrando estudiantes...\n");
	estudianteBorrar(e1);
	estudianteBorrar(e2);
	estudianteBorrar(e3);
	estudianteBorrar(e4);
	estudianteBorrar(e5);
	printf("\tLos estudiantes fueron borrados\n");
}

void testEstudianteConFormato() {
	printf("\nProbando estudianteConFormato...\n");

	printf("\tCreando estudiante...\n");
	estudiante* e1 = estudianteCrear("Gianfranco","Lechuga",12);

	printf("\tAplicando formato (capitalize)...\n");
	estudianteConFormato(e1, (tipoFuncionModificarString) capitalize);
	assert(string_iguales(e1->nombre, "GIANFRANCO"));		/// e1->nombre == "Gianfranco" (antes de aplicar la funcion)
	assert(string_iguales(e1->grupo, "LECHUGA"));			/// e1->grupo == "Lechuga" (antes de aplicar la funcionn)
	printf("\tEl formateo se hizo adecaduamante\n");
	
	printf("\tBorrando estudiante...\n");
	estudianteBorrar(e1);
	printf("\tEl estudiante fue borrado\n");
}

void testEstudianteImprimir() {
	printf("\nProbando estudianteImprimir...\n");

	printf("\tCreando estudiantes...\n");
	estudiante* e1 = estudianteCrear("Gianfranco","Lechuga",12);
	estudiante* e2 = estudianteCrear("","",5);

	//Seto estos string para despues poder los asserts
	//char* nombre = NULL;
	//char* grupo = NULL;
	//unsigned int* edad = NULL;
	
	FILE* gianfranco = fopen("gianfranco.txt", "a+");
	FILE* sinNombre = fopen("sinNombre.txt", "a+");
	estudianteImprimir(e1, gianfranco);					/// e1->nombre == "GIANFRANCO", e1->Grupo == "Lechuga", e1->edad == 12
	estudianteImprimir(e2, sinNombre);					/// e1->nombre == "", e1->Grupo == "", e1->edad == 5
	fclose(gianfranco);
	fclose(sinNombre);
	printf("\tLos estudiantes fueron guardados\n");

	// printf("\tComprobando que los archivos se hayan generado correctamente...\n");
	//gianfranco = fopen("gianfranco.txt", "r");
	//fscanf(gianfranco, "%s\n\t%s\n\t%u\n", nombre,grupo,edad);
	//assert(string_iguales(e1->nombre, nombre));
	//assert(string_iguales(e1->grupo, grupo));
	//assert(e1->edad == *edad);	
	//fclose(gianfranco);

	// sinNombre = fopen("sinNombre.txt", "r");
	// fscanf(sinNombre, "%s\n\t%s\n\t%u\n", nombre,grupo,edad);
	// assert(string_iguales("", nombre));
	// assert(string_iguales("", grupo));
	// assert(e2->edad == *edad);
	// fclose(sinNombre);
	// printf("\t\tLos estudiante se imprimieron correctamente\n");

	printf("\tBorrando los estudiantes...\n");
	//remove("sinNombre.txt");
	//remove("gianfranco.txt");
	estudianteBorrar(e1);
	estudianteBorrar(e2);
	printf("\t\tLos estudiantes fueron borrados (Controlar con valgrind que no halla perdida de memoria)\n");
}

void testCrearYBorrarNodo() {
	printf("\nProbando nodoCrear y nodoBorrar...\n");
	
	printf("\tCreando estudiantes...\n");
	estudiante* e1 = estudianteCrear("Gianfranco","Lechuga",12);
	estudiante* e2 = estudianteCrear("","",5);
	printf("\tCreando nodos con los estudiantes...\n");
	nodo* n1 = nodoCrear(e1);
	nodo* n2 = nodoCrear(e2);
	assert(n1->siguiente == 0);
	assert(n1->anterior == 0);
	assert(n1->dato == e1);
	assert(n2->siguiente == 0);
	assert(n2->anterior == 0);
	assert(n2->dato == e2);
	printf("\tLos nodos fueron creados correctamente\n");

	printf("\tProbando nodoBorrar...\n");
	nodoBorrar(n1, (tipoFuncionBorrarDato) estudianteBorrar);
	nodoBorrar(n2, (tipoFuncionBorrarDato) estudianteBorrar);
	printf("\tLos nodos fueron borrados (Checkear con valgrind que no se pierda memoria)\n");

}

void testAltaListaCrearYAltaListaBorrar (void){

	printf("\nProbando altaListaCrear y altaListaBorrar...\n");
	
	printf("\tCreando lista vacia...\n");
	altaLista* listaVacia = altaListaCrear();
	assert(listaVacia->primero == NULL);
	assert(listaVacia->ultimo == NULL);
	printf("\tLista creada correctamente\n");
	
	printf("\tBorrando lista vacia...\n");
	altaListaBorrar(listaVacia, (tipoFuncionBorrarDato) estudianteBorrar);
	printf("\tLa lista fue borrada (Checkear con valgrind que no se pierda memoria)\n");

	printf("\n\tCreando lista con estudiantes...\n");
	
	printf("\t\tCreando estudiantes para lista...\n");
	estudiante* e1 = estudianteCrear("Gianfranco","Lechuga",12);
	estudiante* e2 = estudianteCrear("Pepe", "Zapallo", 21);
	estudiante* e3 = estudianteCrear("Gianfranco","Zanahoria", 21);

	printf("\t\tCreando lista...\n");
	altaLista* todosLosEstudiantes = altaListaCrear();
	
	printf("\t\tAgregando estudiantes a la lista\n");
	insertarAtras(todosLosEstudiantes, e1);
	insertarAtras(todosLosEstudiantes, e2);
	insertarAtras(todosLosEstudiantes,e3);

	nodo* d1 = todosLosEstudiantes->primero; //Primero
	nodo* d2 = d1->siguiente;
	nodo* d3 = d2->siguiente;
	assert(d1->siguiente == d2);
	assert(d1->anterior == NULL);
	assert(d1->dato = e1);
	assert(d2->siguiente == d3);
	assert(d2->anterior == d1);
	assert(d2->dato == e2);	//Tercero y ultimo
	assert(d3->siguiente == NULL);
	assert(d3->anterior == d2);
	assert(d3->dato == e3);
	printf("\t\tLa lista fue creada correctamente\n");
	
	printf("\t\tBorrando lista...\n");
	altaListaBorrar(todosLosEstudiantes, (tipoFuncionBorrarDato) estudianteBorrar);
	printf("\t\tLa lista fue borrada correctamente 	(Checkear con valgrind que no se pierda memoria)\n");
}

void testAltaListaImprimir() {
	printf("\nProbando altaListaImprimir...\n");

	printf("\tCreando lista vacia...\n");
	altaLista* listaVacia = altaListaCrear();

	printf("\t\tImprimiendo la lista...\n");
	altaListaImprimir(listaVacia, "vacia.txt", (tipoFuncionImprimirDato) estudianteImprimir);
	printf("\t\tLa lista fue guardada\n");
	// printf("\tComprobando que el archivo se halla generado correctamente\n");
	// FILE* archivoLista = fopen("vacia.txt", "r");
	// char* contenidoArchivo = NULL;

	// fscanf (archivoLista, "%s\n", contenidoArchivo);
	// assert(string_iguales(contenidoArchivo, "vacia"));
	// printf("\tLa lista se imprimió correctamente\n");
	// fclose(archivoLista);
	printf("\tBorrando lista vacia...\n");
	altaListaBorrar(listaVacia, (tipoFuncionBorrarDato) estudianteBorrar);
	printf("\tLa lista fue borrada\n");

	printf("\n\tCreando lista con estudiantes...\n");
	printf("\t\tCreando estudiantes para lista...\n");
	estudiante* e1 = estudianteCrear("Gianfranco","Lechuga",12);
	estudiante* e2 = estudianteCrear("Pepe", "Zapallo", 21);
	estudiante* e3 = estudianteCrear("Gianfranco","Zanahoria", 21);

	printf("\t\tCreando lista...\n");
	altaLista* todosLosEstudiantes = altaListaCrear();
	printf("\t\tAgregando estudiantes a la lista\n");
	insertarAtras(todosLosEstudiantes, e1);
	insertarAtras(todosLosEstudiantes, e2);
	insertarAtras(todosLosEstudiantes,e3);
	
	printf("\tImprimiendo la lista...\n");
	altaListaImprimir(todosLosEstudiantes, "todosLosEstudiantes.txt", (tipoFuncionImprimirDato) estudianteImprimir);
	printf("\tLa lista fue guardada\n");

	// printf("\tComprobando que el archivo se halla generado correctamente\n");
	// archivoLista = fopen("todosLosEstudiantes.txt", "r");
	// char* nombre = NULL;
	// char* grupo = NULL;
	// unsigned int* edad = NULL;
	// fscanf (archivoLista, "%s\n\t%s\n\t%u\n", nombre, grupo, edad);
	// assert(string_iguales(nombre, e1->nombre));
	// assert(string_iguales(grupo, e1->grupo));
	// assert(*edad == e1->edad);
	// fscanf (archivoLista, "%s\n\t%s\n\t%u\n", nombre, grupo, edad);
	// assert(string_iguales(nombre, e2->nombre));
	// assert(string_iguales(grupo, e2->grupo));
	// assert(*edad == e2->edad);
	// fscanf (archivoLista, "%s\n\t%s\n\t%u\n", nombre, grupo, edad);
	// assert(string_iguales(nombre, e3->nombre));
	// assert(string_iguales(grupo, e3->grupo));
	// assert(*edad == e3->edad);
	// fclose(archivoLista);
	// printf("\tLa lista se imprimió correctamente\n");

	printf("\t\tBorrando lista...\n");
	altaListaBorrar(todosLosEstudiantes, (tipoFuncionBorrarDato) estudianteBorrar);
	printf("\t\tLa lista fue borrada correctamente\n");
}


void testEdadMedia() {

	printf("\nProbando altaListaImprimir...\n");

	printf("\tCreando lista vacia...\n");
	altaLista* listaVacia = altaListaCrear();

	printf("\t\tCalculando edad media...\n");
	float media = edadMedia(listaVacia);
	assert(media == 0.0);
	printf("\t\tEl calculo se realizo correctamente\n");

	printf("\tBorrando lista vacia...\n");
	altaListaBorrar(listaVacia, (tipoFuncionBorrarDato) estudianteBorrar);
	printf("\tLa lista fue borrada\n");

	printf("\n\tCreando lista con estudiantes...\n");
	printf("\t\tCreando estudiantes para lista...\n");
	estudiante* e1 = estudianteCrear("Gianfranco","Lechuga",21);
	estudiante* e2 = estudianteCrear("Pepe", "Zapallo", 21);
	estudiante* e3 = estudianteCrear("Gianfranco","Zanahoria", 21);

	printf("\t\tCreando lista...\n");
	altaLista* todosLosEstudiantes = altaListaCrear();
	printf("\t\tAgregando estudiantes a la lista\n");
	insertarAtras(todosLosEstudiantes, e1);
	insertarAtras(todosLosEstudiantes, e2);
	insertarAtras(todosLosEstudiantes,e3);
	
	printf("\tCalculando edad media...\n");
	media = edadMedia(todosLosEstudiantes);
	assert(media == 21.0);
	printf("\tEl calculo se realizo correctamente\n");

	printf("\t\tBorrando lista...\n");
	altaListaBorrar(todosLosEstudiantes, (tipoFuncionBorrarDato) estudianteBorrar);
	printf("\t\tLa lista fue borrada correctamente\n");
}

void testInsertarOrdenado() {

	printf("\n** TEST insertarOrdenado ** \n");
	
	printf("\t\n*CREANDO LISTA*\n");
	altaLista* todosLosEstudiantes = altaListaCrear();
	printf("\t\n*ECHO* \n");
	
	printf("\t\n*CREANDO ESTUDIANTE*\n");
	int a = 0;
	//estudiante* e0 = estudianteCrear("02A2", "1A", 0);
	estudiante* e1 = estudianteCrear("Diego", "78", 33);
	a++;
	estudiante* e2 = estudianteCrear("Diego", "1A", 50);
	a++;
	estudiante* e3 = estudianteCrear("Diego", "1A", 50);
	a++;
	estudiante* e4 = estudianteCrear("Batista", "78", 33);
	a++;
	estudiante* e5 = estudianteCrear("Batista", "78", 33);
	a++;
	estudiante* e6 = estudianteCrear("Zacundo", "789", 18);
	a++;
	estudiante* e7 = estudianteCrear("C3P0", "90", 90);
	a++;
	estudiante* e8 = estudianteCrear("5689", "89", 33);
	a++;
	estudiante* e9 = estudianteCrear("", "1213", 120);
	a++;
	estudiante* eA = estudianteCrear("F000", "13", 900);
	a++;

	printf("\t\n*%u ESTUDIANTE CREADOS*\n", a);
	
	printf("\t\n*GENERANDO LISTA*\n");
	insertarOrdenado(todosLosEstudiantes, e1, (tipoFuncionCompararDato) menorEstudiante);
	insertarOrdenado(todosLosEstudiantes, e2, (tipoFuncionCompararDato) menorEstudiante);
	insertarOrdenado(todosLosEstudiantes, e3, (tipoFuncionCompararDato) menorEstudiante);
	insertarOrdenado(todosLosEstudiantes, e4, (tipoFuncionCompararDato) menorEstudiante);
	insertarOrdenado(todosLosEstudiantes, e5, (tipoFuncionCompararDato) menorEstudiante);
	insertarOrdenado(todosLosEstudiantes, e6, (tipoFuncionCompararDato) menorEstudiante);
	insertarOrdenado(todosLosEstudiantes, e7, (tipoFuncionCompararDato) menorEstudiante);
	insertarOrdenado(todosLosEstudiantes, e8, (tipoFuncionCompararDato) menorEstudiante);
	insertarOrdenado(todosLosEstudiantes, e9, (tipoFuncionCompararDato) menorEstudiante);
	insertarOrdenado(todosLosEstudiantes, eA, (tipoFuncionCompararDato) menorEstudiante);

	printf("\t\n*IMPRIMIENDO LISTA*\n");

	listaEnPantalla(todosLosEstudiantes);


	// assert(todosLosEstudiantes->primero->dato == e1);
	// assert(todosLosEstudiantes->ultimo->dato == e1);
	// printf("\t\t\tPrimer estudiante agregado\n");
	// insertarOrdenado(todosLosEstudiantes, e2, (tipoFuncionCompararDato) menorEstudiante);
	
	// nodo *primero = todosLosEstudiantes->primero;
	// nodo *ultimo = todosLosEstudiantes->ultimo;

	// assert(primero->dato == e1);
	// assert(primero->anterior == NULL);
	// assert(primero->siguiente == ultimo);
	// assert(ultimo->dato == e2);
	// assert(ultimo->anterior == primero);
	// assert(ultimo->siguiente == NULL);
	// printf("\t\t\tSegundo estudiante agregado\n");
	
	// insertarOrdenado(todosLosEstudiantes, e3, (tipoFuncionCompararDato) menorEstudiante);

	// primero = todosLosEstudiantes->primero;
	// nodo *segundo = primero->siguiente;
	// ultimo = todosLosEstudiantes->ultimo;
	
	// assert(primero->dato == e1);
	// assert(primero->anterior == NULL);
	// assert(primero->siguiente == segundo);
	// assert(segundo->dato == e3);
	// assert(segundo->anterior == primero);
	// assert(segundo->siguiente == ultimo);
	// assert(ultimo->dato == e2);
	// assert(ultimo->anterior == segundo);
	// assert(ultimo->siguiente == NULL);
	// printf("\t\tLa lista fue creada correctamente\n");
	
	printf("\t\n*BORRANDO LISTA*\n");
	altaListaBorrar(todosLosEstudiantes, (tipoFuncionBorrarDato) estudianteBorrar);
	printf("\t\n*ECHO*\n");
}

void testFiltrarAltaLista(){
	printf("\n**TEST filtrarAltaLista**\n");
	printf("\n**************************************\n");
	printf("\t\n*CREANDO LISTAS*\n");
	altaLista* listaRecortar = altaListaCrear();
	altaLista* listaSave = altaListaCrear();
	printf("\t\n*LISTAS ECHA*\n");
	printf("\n**************************************\n");
	printf("\t\n*GENERANDO ESTUDIANTE BARDERO*\n");
	estudiante* cmp = estudianteCrear("Gianfranco","Lechuga",12);
	printf("\t\n*ESTUDIANTE BARDERO ECHO*\n");

	//printf("\tFiltrando lista...\n");
	//filtrarAltaLista(lista, (tipoFuncionCompararDato) menorEstudiante, cmp);
	//assert(lista->primero == NULL);
	//assert(lista->ultimo == NULL);
	//printf("\tLista filtrada correctamente\n");
	printf("\n**************************************\n");

	printf("\t\n*GENERANDO NERDS*\n");
	estudiante* e0 = estudianteCrear("02A2", "1A", 0); 
	estudiante* e1 = estudianteCrear("Diego", "78", 33);
	estudiante* e2 = estudianteCrear("Luke", "1A", 50); //V
	estudiante* e3 = estudianteCrear("Headroom", "1A", 50);//V
	estudiante* e4 = estudianteCrear("Ruperrta", "78", 33);//V
	estudiante* e5 = estudianteCrear("Batista", "78", 33);
	estudiante* e6 = estudianteCrear("Mao", "789", 18);//V
	estudiante* e7 = estudianteCrear("C3P0", "90", 90);
	estudiante* e8 = estudianteCrear("Khan", "89", 33);//V
	estudiante* e9 = estudianteCrear("", "1213", 120);
	estudiante* eA = estudianteCrear("Zoe", "13", 900);//V
	printf("\t\n*NERDS CREADOS*\n");
	
	//printf("\tAgregando un estudiante a la lista...\n");
	//insertarAtras(lista, e1);
	//printf("\tFiltrando lista...\n");
	//filtrarAltaLista(lista, (tipoFuncionCompararDato) menorEstudiante, cmp);
	//assert(lista->primero == NULL);
	//assert(lista->ultimo == NULL);
	//printf("La lista se filrto correctamente\n");
	// printf("\n**************************************\n");
	// printf("\t\n*METIENDO NERDS EN ORDEN*\n");
	// insertarOrdenado(listaRecortar, e0, (tipoFuncionCompararDato) menorEstudiante);
	// insertarOrdenado(listaRecortar, e1, (tipoFuncionCompararDato) menorEstudiante);
	// insertarOrdenado(listaRecortar, e2, (tipoFuncionCompararDato) menorEstudiante);
	// insertarOrdenado(listaRecortar, e3, (tipoFuncionCompararDato) menorEstudiante);
	// insertarOrdenado(listaRecortar, e4, (tipoFuncionCompararDato) menorEstudiante);
	// insertarOrdenado(listaRecortar, e5, (tipoFuncionCompararDato) menorEstudiante);
	// insertarOrdenado(listaRecortar, e6, (tipoFuncionCompararDato) menorEstudiante);
	// insertarOrdenado(listaRecortar, e7, (tipoFuncionCompararDato) menorEstudiante);
	// insertarOrdenado(listaRecortar, e8, (tipoFuncionCompararDato) menorEstudiante);
	// insertarOrdenado(listaRecortar, e9, (tipoFuncionCompararDato) menorEstudiante);
	// insertarOrdenado(listaRecortar, eA, (tipoFuncionCompararDato) menorEstudiante);
	//printf("\t\n*NERDS EN SOTANO*\n");


	printf("\n**************************************\n");

	printf("\t\n*METIENDO NERDS EN FILA*\n");
	insertarAtras(listaRecortar, e0);

	insertarAtras(listaRecortar, e1);
	insertarAtras(listaRecortar, e2);
	insertarAtras(listaRecortar, e3);
	insertarAtras(listaRecortar, e4);
	insertarAtras(listaRecortar, e5);
	insertarAtras(listaRecortar, e6);
	insertarAtras(listaRecortar, e7);
	insertarAtras(listaRecortar, e8);
	insertarAtras(listaRecortar, e9);
	insertarAtras(listaRecortar, eA);

	//insertarAtras(listaSave, e0);
	//insertarAtras(listaSave, e1);
	//insertarAtras(listaSave, e5);
	//insertarAtras(listaSave, e6);
	//insertarAtras(listaSave, e7);
	insertarAtras(listaSave, e9);
	printf("\t\n*NERDS EN SOTANO*\n");
	printf("\n**************************************\n");


	printf("\t\n*VICTIMAS*\n");
	listaEnPantalla(listaRecortar);
	printf("\t\n*SALVO*\n");
	listaEnPantalla(listaSave);

	printf("\n**************************************\n");
	printf("\t\n*BULLYING*\n");
	filtrarAltaLista(listaRecortar, (tipoFuncionCompararDato) menorEstudiante, cmp);
	filtrarAltaLista(listaSave, (tipoFuncionCompararDato) menorEstudiante, cmp);
	printf("\t\n*BULLYING ECHO*\n");
	printf("\n**************************************\n");

	printf("\t\n*SOBREVIVEN*\n");
	listaEnPantalla(listaRecortar);

	printf("\n**************************************\n");

	printf("\t\n*ESPERADA*\n");
	listaEnPantalla(listaSave);
	//altaListaImprimir(lista, "listafiltrada.txt", (tipoFuncionImprimirDato) estudianteImprimir);
	//nodo* primero = lista->primero;
	//nodo* segundo = primero->siguiente;
	// nodo* tercero = segundo->siguiente;
	// assert(primero->dato == e2);
	// assert(segundo->dato == e4);
	// assert(tercero->dato == e5);
	// assert(tercero == lista->ultimo);

	printf("\n**************************************\n");

	printf("\t\n*BORRANDO BARDO*\n");
	estudianteBorrar(cmp);
	printf("\t\n*BARDO BORRADO*\n");

	printf("\t\n*BORRANDO NERDS*\n");
	altaListaBorrar(listaRecortar, (tipoFuncionBorrarDato) estudianteBorrar);
	altaListaBorrar(listaSave, (tipoFuncionBorrarDato) estudianteBorrar);
	printf("\t\n*LISTA BORRADA*\n");

}

int main (void){

	// testStringLongitud();
	// testsStringCopiar();
	// testCompararStrings();
	// testCrearYBorrarEstudiante();
	//testCompararEstudiantes();
	// testEstudianteConFormato();
	// testEstudianteImprimir();
	// testCrearYBorrarNodo();
	// testAltaListaCrearYAltaListaBorrar();
	// testAltaListaImprimir();
	// testEdadMedia();
	// testInsertarOrdenado();
	testFiltrarAltaLista();
	return 0;
}

void capitalize(char* s){
  int i= 0;
  while(s[i] != 0) {
  	if (s[i] >= 97 && s[i] <= 122)
    s[i] -= 32;
    i++;
  }
}


