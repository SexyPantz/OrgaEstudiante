#include "altaLista.h"
#include <stdio.h>

void guillotine(char* tete);

int main (void){
	
	  estudiante* manu0 = estudianteCrear("asdifu", "0A", 22);
	  estudiante* manu1 = estudianteCrear("Manuel", "1A", 23);
	  printf("Nombre:%s, \n Grupo:%s, \n Edad:%u, \n", manu0->nombre, manu0->grupo, manu0->edad);
	  // printf("Nombre:%s, \n Grupo:%s, \n Edad:%u, \n", manu1->nombre, manu1->grupo, manu1->edad);

	//  bool AmenorB = string_menor("0000000", "asdasdasd");
	// 	printf("0meoB:%u, \n", AmenorB);

	// FILE* megustanlaschicas = fopen("chicas.txt", "a+"); //w rescritura

	  altaLista* listaloca0 = altaListaCrear();
     insertarAtras(listaloca0, manu1);

	altaListaBorrar(listaloca0, (tipoFuncionBorrarDato) estudianteBorrar);

	

	// estudianteImprimir(manu0, megustanlaschicas);
	// estudianteImprimir(manu1, megustanlaschicas);
	//  estudianteImprimir(nodoloco0->dato, megustanlaschicas);

	// // fclose(megustanlaschicas);

	//   bool M0mM1 = menorEstudiante(manu1, manu0);

	// void (*cortar)(char*)= guillotine;

	// printf("Nombre:%s \n", manu0->nombre);
	// estudianteConFormato(manu0, cortar);
	// printf("Nombre:%s \n", manu0->nombre);

	// 	printf("M0mM1:%u, \n", M0mM1);

 	estudianteBorrar(manu0);
	// 	 //estudianteBorrar(manu0);

	// 	nodoBorrar(nodoloco0, (tipoFuncionBorrarDato)estudianteBorrar); 
		 
		return 0;
}


void guillotine(char* tete){
	
	tete[0] = '0';


}



