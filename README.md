# TP Orga II: Lista doblemente enlazada en Assembly
---------------------------------------------------
---------------------------------------------------

## UPDATE 12/04/2015
--------------------
	*Managed to delet almost all bugs and pached up all mem leaks
	*There is still a pseudo bug when the program tries to delet a student with an empty name (""). It doesnt break the program but makes valgrin go berserk.

### NOTES
---------
The status of each fuction is as follows:
	
	** estudianteCrear			(TESTED FULL)
	** estudianteBorrar			(TESTED FULL)
	** menorEstudiante			(TESTED FULL)
	** estudianteConFormato		(TESTED FULL)
	** estudianteImprimir		(TESTED FULL)
	** nodoCrear				(TESTED FULL)
	** nodoBorrar				(TESTED FULL)
	** altaListaCrear			(TESTED FULL)
	** altaListaBorrar			(TESTED FULL)
	** altalistaImprimir		(TESTED FULL)
	** edadMedia				(TESTED FULL)
	** insertarOrdenado			(TESTED FULL)
	** filtrarAltaLista			(TESTED FULL)
	** string_copiar			(TESTED FULL)
	** string_longitud			(TESTED FULL)
	** string_menor				(TESTED FULL)
	**listaEnPantalla			(WORKS - UNTESTED)

## UPDATE 11/04/2015
--------------------
	*Finnaly done with insertarOrdena (TESTED FULL)
	*filtrarLista still aint working
	*Its 3am on weekend night and Im stuck coding in fucking assembly
	*Testing a git commit aliasing thingy, have to push manually


### NOTES
---------
The status of each fuction is as follows:
	
	** estudianteCrear			(TESTED FULL)
	** estudianteBorrar			(TESTED FULL)
	** menorEstudiante			(TESTED FULL)
	** estudianteConFormato		(TESTED FULL)
	** estudianteImprimir		(TESTED FULL)
	** nodoCrear				(TESTED FULL)
	** nodoBorrar				(TESTED FULL)
	** altaListaCrear			(TESTED FULL)
	** altaListaBorrar			(TESTED FULL)
	** altalistaImprimir		(TESTED FULL)
	** edadMedia				(TESTED FULL)
	** insertarOrdenado			(TESTED FULL)
	** filtrarAltaLista			(WTF IS GOING ON!?)
	** string_copiar			(TESTED FULL)
	** string_longitud			(TESTED FULL)
	** string_menor				(TESTED FULL)
	**listaEnPantalla			(WORKS - UNTESTED)


## UPDATE 11/04/2015
--------------------
	*New implementation of filtrarLista. (UNFINISHED)
	*Final implementation of edadMedia. (TESTED)
	*Bug clean up on insertarOrdenado. (TESTED)
	*Asked Danni, she got the message about 1h late... so whatever, I guess

### NOTES
---------
 -Should look up operations concernig XMM and MM registres (movq, subss, cvtsi2ss, divss, movlhps.. and so on). Further reading: edadMedia and operation with floats in ASM.
 -I think I obsses over people.


## UPDATE 10/04/2015
--------------------
	*First implementation of filtrarLista (UNFINISHED).
	*First implementation of insertarOrdenado (NOT TESTED).
	*I feel lonley and sad all the time.
	*I live with a constant existential crisis.
	*All implemented functions work with allined stacks.
	*Am I really alive or is this just an illusion?.
	*I hope there is a god and he/she/it can hear me.
	*I don't want to exist forever, yet I do want to exist forever.
	*I desperatly want someone to connect with.
	*Death is an undivorceable part of life, that thought makes my unimaginably miserable   . 
	*Hate myself and I often think of myself as weak or unworthy of others affection.


### NOTES
---------


## UPDATE 10/04/2015
--------------------
	*borraLista works fine.
	*Fixed stack related bug in borrarNodo.
	*Realigned stack pointer in all functions.
	*First implementation of altalistaImprimir (TESTED).
	*Fixed wrong push sequence in imprimierEstudiante.
	*I hate my life

### NOTES
---------
 - Issues with borrarLista were actually caused by disorganized pushes and unaligned stacks pointer in several other functions. 
 - Also, recent indepth sould searching made me cuestion if I have bad luck with girls or if im just dumb as fuck. Some more souls searching later on revealed its usually the latter.... :(





## UPDATE 09/04/2015
--------------------
	* borrarLista still won't work properly, reason unknown.
	* Half-assed implementation of edadMedia, won't work either.
