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
    assert(string_longitud(s1) == 10);            /// s1 == "Gianfranco"
    assert(string_longitud(s2) == 4);            /// s2 == "Pepe"
    assert(string_longitud(s3) == 0);            /// s3 == ""
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

    assert(string_iguales(s1,s1copia));            /// s1 == "Gianfranco"
    assert(string_iguales(s2,s2copia));            /// s2 == "Pepe"
    assert(string_iguales(s3,s3copia));            /// s3 == ""
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
    assert(string_menor(s1,s2) == true);            /// s1 == "Gianfranco", s2 == "Pepe"
    assert(string_menor(s2,s1) == false);            /// s3 == "Gianfranco",  s4 == "Gian"
    assert(string_menor(s1,s3) == false);            /// s5 == ""
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
    assert(menorEstudiante(e1,e2) == true);            /// e1->nombre == "Gianfranco", e2->"Pepe"
    assert(menorEstudiante(e2,e1) == false);
    assert(menorEstudiante(e1,e3) == true);            /// e3->nombre == "Gianfranco", e1->edad == 12, e2->edad == 21
    assert(menorEstudiante(e3,e1) == false);
    assert(menorEstudiante(e1,e4) == false);        /// e4->nombre == "Gian"
    assert(menorEstudiante(e4,e1) == true);
    assert(menorEstudiante(e5,e1) == true);            /// e5->nombre == ""
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
    assert(string_iguales(e1->nombre, "GIANFRANCO"));        /// e1->nombre == "Gianfranco" (antes de aplicar la funcion)
    assert(string_iguales(e1->grupo, "LECHUGA"));            /// e1->grupo == "Lechuga" (antes de aplicar la funcionn)
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
   
    FILE* gianfranco = fopen("gianfranco.txt", "a+");
    FILE* sinNombre = fopen("sinNombre.txt", "a+");
    estudianteImprimir(e1, gianfranco);                    /// e1->nombre == "GIANFRANCO", e1->Grupo == "Lechuga", e1->edad == 12
    estudianteImprimir(e2, sinNombre);                    /// e1->nombre == "", e1->Grupo == "", e1->edad == 5
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
    assert(d2->dato == e2);    //Tercero y ultimo
    assert(d3->siguiente == NULL);
    assert(d3->anterior == d2);
    assert(d3->dato == e3);
    printf("\t\tLa lista fue creada correctamente\n");
   
    printf("\t\tBorrando lista...\n");
    altaListaBorrar(todosLosEstudiantes, (tipoFuncionBorrarDato) estudianteBorrar);
    printf("\t\tLa lista fue borrada correctamente     (Checkear con valgrind que no se pierda memoria)\n");
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

// void testInsertarAdelante() {

//     printf("\nProbando insertarAdelante...\n");
   
//     printf("\tCreando lista...\n");
//     altaLista* todosLosEstudiantes = altaListaCrear();
//     printf("\tLista creada correctamente\n");
   
//     printf("\tCreando estudiantes para lista...\n");
//     estudiante* e1 = estudianteCrear("Gianfranco","Lechuga",12);
//     estudiante* e2 = estudianteCrear("Pepe", "Zapallo", 21);
//     estudiante* e3 = estudianteCrear("Gianfranco","Zanahoria", 21);
//     printf("\tEstudiantes creados\n");
   
//     printf("\t\tAgregando estudiantes a la lista...\n");
//     insertarAdelante(todosLosEstudiantes, e1);
//     insertarAdelante(todosLosEstudiantes, e2);
//     insertarAdelante(todosLosEstudiantes, e3);

//     nodo* d3 = todosLosEstudiantes->primero; //Primero
//     nodo* d2 = d3->siguiente;
//     nodo* d1 = d2->siguiente;
//     assert(d1->siguiente == NULL);
//     assert(d1->anterior == d2);
//     assert(d1->dato = e1);
//     assert(d2->siguiente == d1);
//     assert(d2->anterior == d3);
//     assert(d2->dato == e2);    //Tercero y ultimo
//     assert(d3->siguiente == d2)    ;
//     assert(d3->anterior == NULL);
//     assert(d3->dato == e3);
//     printf("\t\tLa lista fue creada correctamente\n");
   
//     printf("\t\tBorrando lista...\n");
//     altaListaBorrar(todosLosEstudiantes, (tipoFuncionBorrarDato) estudianteBorrar);
//     printf("\t\tLa lista fue borrada correctamente     (Checkear con valgrind que no se pierda memoria)\n");
// }

int main (void){

    testStringLongitud();
    testsStringCopiar();
    testCompararStrings();
    testCrearYBorrarEstudiante();
    testCompararEstudiantes();
    testEstudianteConFormato();
    testEstudianteImprimir();
    testCrearYBorrarNodo();
    testAltaListaCrearYAltaListaBorrar();
    testAltaListaImprimir();
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
	





























// #include "altaLista.h"
// #include <stdio.h>
// #include <assert.h>
// void guillotine(char* tete);

// int main (void){
	
// 	 estudiante* manu0 = estudianteCrear("02A2", "1A", 0);
// 	 estudiante* manu1 = estudianteCrear("Diego", "1A", 23);
// 	 estudiante* manu2 = estudianteCrear("Facundo", "9A", 18);
// 	 estudiante* manu3 = estudianteCrear("Ale", "B9", 50);
// 	 estudiante* manu4 = estudianteCrear("Batista", "78", 33);
// 	 estudiante* manu5 = estudianteCrear("Batista", "789", 20);
// 	 estudiante* manu6 = estudianteCrear("Facundo", "789", 18);
// 	 estudiante* manu7 = estudianteCrear("C3P0", "90", 90);
// 	 estudiante* manu8 = estudianteCrear("5689", "89", 33);
// 	 estudiante* manu9 = estudianteCrear("Ruperta", "1213", 120);
// 	 estudiante* manuT = estudianteCrear("F000", "13", 900);

// 	 char* archivoPrint = "altListPrntASM.txt";

// 	altaLista* listaloca0 = altaListaCrear();

//  //    insertarOrdenado(listaloca0, manu1, (tipoFuncionCompararDato) menorEstudiante);
//  //    insertarOrdenado(listaloca0, manu2, (tipoFuncionCompararDato) menorEstudiante);
//  //    insertarOrdenado(listaloca0, manu3, (tipoFuncionCompararDato) menorEstudiante);
//  //    insertarOrdenado(listaloca0, manu0, (tipoFuncionCompararDato) menorEstudiante);
// 	// insertarOrdenado(listaloca0, manu5, (tipoFuncionCompararDato) menorEstudiante);
// 	// insertarOrdenado(listaloca0, manu6, (tipoFuncionCompararDato) menorEstudiante);
// 	// insertarOrdenado(listaloca0, manu7, (tipoFuncionCompararDato) menorEstudiante);
// 	// insertarOrdenado(listaloca0, manu8, (tipoFuncionCompararDato) menorEstudiante);
//  //    insertarOrdenado(listaloca0, manu9, (tipoFuncionCompararDato) menorEstudiante);
//  //    insertarOrdenado(listaloca0, manu4, (tipoFuncionCompararDato) menorEstudiante);
//  //    insertarOrdenado(listaloca0, manuT, (tipoFuncionCompararDato) menorEstudiante);

// 		// insertarAtras(listaloca0, manu0);
// 		// insertarAtras(listaloca0, manu2);
// 	 //    insertarAtras(listaloca0, manu3);
// 	 //    insertarAtras(listaloca0, manu4);
// 		// insertarAtras(listaloca0, manu5);
// 		// insertarAtras(listaloca0, manu6);
// 		// insertarAtras(listaloca0, manu7);
// 		// insertarAtras(listaloca0, manu1);
// 		// insertarAtras(listaloca0, manu8);
// 	 //    insertarAtras(listaloca0, manu9);
// 	 //    insertarAtras(listaloca0, manu4);
// 	 //    insertarAtras(listaloca0, manuT);

// 	//altaListaImprimir(listaloca0, archivoPrint, (tipoFuncionImprimirDato) estudianteImprimir);


// 	altaListaBorrar(listaloca0, (tipoFuncionBorrarDato) estudianteBorrar);
// //	altaListaBorrar(listalocaV, (tipoFuncionBorrarDato) estudianteBorrar);

		 
// 		return 0;
// }


// void guillotine(char* tete){
	
// 	tete[0] = '0';


// }



