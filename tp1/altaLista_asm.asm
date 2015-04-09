
; ESTUDIANTE
	global estudianteCrear
	global estudianteBorrar
	global menorEstudiante
	global estudianteConFormato
	global estudianteImprimir
	
; ALTALISTA y NODO
	global nodoCrear
	global nodoBorrar
	global altaListaCrear
	global altaListaBorrar
	global altaListaImprimir

; AVANZADAS
	global edadMedia
	global insertarOrdenado
	global filtrarAltaLista
	global string_copiar
	global string_longitud
	global string_menor

; YA IMPLEMENTADAS EN C
	extern string_iguales
	extern insertarAtras
	extern malloc;<--- YO MANDE ESTO, ME GUSTAN lAS GALLETAS
	extern free;<--- Y ESTO, ME GUSTAN lAS GALLETAS	
	extern fprintf

; /** DEFINES **/    >> SE RECOMIENDA COMPLETAR LOS DEFINES CON LOS VALORES CORRECTOS
	%define NULL 	qword 0
	%define TRUE 	qword 1
	%define FALSE 	qword 0

	%define ALTALISTA_SIZE     		 16 
	%define OFFSET_PRIMERO 			 0
	%define OFFSET_ULTIMO  			 8

	%define NODO_SIZE     			 24
	%define OFFSET_SIGUIENTE   		 0
	%define OFFSET_ANTERIOR   		 8
	%define OFFSET_DATO 			 16

	%define ESTUDIANTE_SIZE  		 20
	%define OFFSET_NOMBRE 			 0
	%define OFFSET_GRUPO  			 8
	%define OFFSET_EDAD 			 16

	;puntero: 8 Bytes
	;unsigned integer: 4 Bytes

section .rodata


section .data
	;formatName: DB '%s',10, 9, '%s', 10, 9, '%u', 10, 0
	formatName: DB '%s', 10, 0
	formatGrp: DB   9, '%s', 10, 0
	formatAge: DB 9, '%u', 10, 0
section .text

;/** FUNCIONES OBLIGATORIAS DE ESTUDIANTE */    >> PUEDEN CREAR LAS FUNCIONES AUXILIARES QUE CREAN CONVENIENTES
;---------------------------------------------------------------------------------------------------------------

	; estudiante *estudianteCrear( char *nombre, char *grupo, unsigned int edad );
	estudianteCrear:

		; rdi es nombre, es un puntero
		; rsi es grupo, es un puntero
		; rdx es edad, es un unsig int

		;pusheos por convencion

		push rbp        ;A
		mov rbp, rsp
		push r12        ;A
		push r13        ;D		
		push r14        ;A
		push r15        ;D


STDNT_MEMOALOCATION:
		mov r12, rdi ;guardo puntero a nombre
		mov r13, rsi ;guardo puntero a grupo
		mov r14d, edx ; guardo edad la edad. Uso R14D y EDX por el tamano del unsing int (4 bytes)
		mov rdi, ESTUDIANTE_SIZE; guardo el tamano de la struct en el rdi
		call malloc; llamo a malloc y guardad memo, escupe la dire a la strut a RAX
		mov r15, rax; guardo la dire a struc en r15 
STDNT_NME_ALOCATION:
		mov rdi, r12; paso el puntero a nombre al RDI
		call string_copiar; llamo a string_copiar
		mov [r15+OFFSET_NOMBRE], rax; muevo al espacio reservado para el puntero al nombre el puntero al nuevo string

STDNT_GRP_ALOCATION:
		mov rdi, r13; ;muevo el puntero a grupo a rdi
		call string_copiar; llamo a string_copiar
		mov [r15+OFFSET_GRUPO], rax;  muevo al espacio reservado para el puntero al grupo el puntero al nuevo string

STDNT_AGE_PALOCATION:
		mov [r15+OFFSET_EDAD], r14d; Muevo la edad a la a donde corresponde en la struct
		mov rax, r15; muevo a RAX la dire de la struc


		pop r15        ;A
		pop r14        ;D		
		pop r13        ;A
		pop r12        ;D
		pop rbp	
		ret


	; void estudianteBorrar( estudiante *e );
	estudianteBorrar:
		;EN RDI TENGO EL PUNTERO AL ESTUDIANTE
		;[RDI] == punteor al nombre
		push rbp
		mov rbp, rsp
		push r12; PUSH X CONV

		mov r12, rdi 		;moevo puntero a srtuc a r12 
		mov rdi, [rdi+OFFSET_NOMBRE];muevo a RDI el puntero a el  nombre del estudiante
		call free				;Libero la meno del nombre
		mov rdi, [r12+OFFSET_GRUPO]	;muevo a RDI el puntero a el  nombre del grupo
		call free ;Libero la meno del grupo
		mov rdi, r12; muevo a RDI el puntero a Struc
		call free ;libero memo, liberando el campo EDAD en el proseso
		pop r12 ;pops x convenxion
		pop rbp	
		ret

	; bool menorEstudiante( estudiante *e1, estudiante *e2 ){
	menorEstudiante:
		;rdi, al primer estudiante
		;rsi al segundo 

		push rbp 
		mov rbp, rsp
		push r13
		push r12 ;pusheos x convencion

		mov r12, rdi; guardo en R12 el puntero al 1er Estu
		mov r13, rsi; guardo en R13 el puntero al 2do Estu

		mov rdi, [r12+OFFSET_NOMBRE]; paso a rdi el puntero al nomber del 1er Estu
		mov rsi, [r13+OFFSET_NOMBRE]; paso a rsi el puntero al nomber del 1do estu
		call string_iguales; call string_iguales, en RAX escupe 1(TRUE) o 0(FALSE) acorde al input
		cmp rax, 1; comparo RAX con 1(TRUE)
		jz THEN_NOMBREQ; En caso afirmativo salta a THE_NOMBREQ (THEN NOMBRE IGUAL)
					   ; En caso contrario sigue de largo, podemos asumir que los nombre no son iguales 
		mov rdi, [r12+OFFSET_NOMBRE]; paso a rdi el puntero al nomber del 1er Estu
		mov rsi, [r13+OFFSET_NOMBRE]; paso a rsi el puntero al nomber del 1do estu.  
		call string_menor; call string_menor, en RAX escupe 1(TRUE) o 0(FALSE) acorde al input
		jmp FIN_Loco; Salta al fin de la funcion

		THEN_NOMBREQ:
		mov edi, [r12+OFFSET_EDAD]
		mov esi, [r13+OFFSET_EDAD]
		cmp edi, esi
		jl dio_menor
		mov rax, 0
		dio_menor:
		mov rax, 1


		FIN_Loco:
		pop r12
		pop r13
		pop rbp
		ret

	; void estudianteConFormato( estudiante *e, tipoFuncionModificarString f )
	estudianteConFormato:
		; COMPLETAR AQUI EL CODIGO
		;rdi, puntero estudiante
		;rsi, puntero tipoFuncionModificarString tipo void, y toma como parametro char

		push rbp
		mov rbp, rsp
		push r12
		push r13

		mov r12, rdi
		mov r13, rsi

		mov rdi, [r12]
		call r13
		mov rdi, [r12+OFFSET_GRUPO]
		call r13


		pop r13
		pop r12
		pop rbp
		ret
	; void estudianteImprimir( estudiante *e, FILE *file )
	estudianteImprimir:
		;en RDI, puntero a estudiante
		;en RSI, puntero Filer

		push rbp
		mov rbp, rsp
		push r12  
		push r13
		
		mov r12, rdi
		mov r13, rsi

		mov rdi, r13
		mov rdx, [r12]
		mov rsi, formatName
		call fprintf

		mov rdi, r13
		mov rdx, [r12+OFFSET_GRUPO]
		mov rsi, formatGrp
		call fprintf

		mov rdi, r13
		mov edx, dword [r12+OFFSET_EDAD]
		mov rsi, formatAge
		call fprintf




		pop r12
		pop r13
		pop rbp
		ret


;/** FUNCIONES DE ALTALISTA Y NODO **/    >> PUEDEN CREAR LAS FUNCIONES AUXILIARES QUE CREAN CONVENIENTES
;--------------------------------------------------------------------------------------------------------

	; nodo *nodoCrear( void *dato )
	nodoCrear:
		; rdi es siguiente, es un puntero a siguiente
		; rsi es anterior, es un puntero al anterior
		; rdx es data, es un puntero a estudiante(el dato)


	; NODO_SIZE     			24
	; OFFSET_SIGUIENTE   		0
	; OFFSET_ANTERIOR   		8
	; OFFSET_DATO 		 	 	16	

		push rbp        ;A
		mov rbp, rsp
		push r12        ;putero Data
		mov r12, rdi

NODE_MEMOALOCATION:
		mov rdi, NODO_SIZE
		call malloc

NODE_DAT_ALOCATION:
		mov [rax+OFFSET_DATO], r12

NODE_NXT_ALOCATION:
 		mov qword [rax+OFFSET_SIGUIENTE], 0

NODE_BFR_ALOCATION:
 		mov qword [rax+OFFSET_ANTERIOR], 0
		pop r12        
		pop rbp		
		ret

; 	; void nodoBorrar( nodo *n, tipoFuncionBorrarDato f )
 	nodoBorrar:
; 		; COMPLETAR AQUI EL CODIGO
		;EN RDI TENGO EL PUNTERO AL NODO
		;EN RSI PUNTO A FUNCION tipoFuncionBorrarDato
		push rbp
		mov rbp, rsp
		push r12
		push r13

		mov r12, rdi; nodo
		mov r13, rsi; funcio

		mov rdi, [r12+OFFSET_DATO];elimino dato
		call r13

		mov rdi, r12
		call free

		pop r12
		pop r13
		pop rbp	
		ret



	; altaLista *altaListaCrear( void )
	altaListaCrear:
				; rdi es siguiente, es un puntero a siguiente
		; rsi es anterior, es un puntero al anterior
		; rdx es data, es un puntero a estudiante(el dato)


	;ALTALISTA_SIZE     		16 
	;OFFSET_PRIMERO 			0
	;OFFSET_ULTIMO  			8

		push rbp        ;A
		mov rbp, rsp
		;push r12        ;putero Data
		
		mov rdi, ALTALISTA_SIZE
		call malloc
		;mov r12, rax

		mov qword [rax+OFFSET_PRIMERO], 0
		mov qword [rax+OFFSET_ULTIMO], 0

		;pop r12        
		pop rbp	
		ret

	; void altaListaBorrar( altaLista *l, tipoFuncionBorrarDato f )
	altaListaBorrar:
		
		;COMPLETAR AQUI EL CODIGO
		;EN RDI TENGO EL PUNTERO A LISTA
		;EN RSI PUNTO A FUNCION tipoFuncionBorrarDato
		push rbp
		mov rbp, rsp
		push rbx
		push r12
		push r13
		push r14
		push r15


		mov r12, rdi; guardo puntero a Lista
		mov r13, rsi; guardo puntero a tipoFuncionBorrarDato


RecorrerYDestruir:
;Nos fijamos que la lista esta vacia
		cmp qword [r12+OFFSET_PRIMERO], 0;colamparo con 0 para ver si hay siguiente
		jz llegamosAlFinal; si ese el caso salto a borrar la estruc

		

;Si no esta vacia, 
		mov r14, [r12+OFFSET_PRIMERO]; le paso a R14 la dire del primer nodo
		mov rbx, [r14+OFFSET_SIGUIENTE]; le paso a RBX la dire del siguiente Nodo
		mov [r12+OFFSET_PRIMERO], rbx; sobre escribo el puntero del primero con la dire del

		mov r15, [r12+OFFSET_PRIMERO]; seteo el puntero a anterior del nuevo primer como NULL
		mov qword [r15+OFFSET_ANTERIOR], 0;pero en realidad no hace falta XD, me gustan las chicas

		mov rdi, r14; le paso la dire del nodo a destruir a RDI
		call r13; llamamos a destruir nodo
		jmp RecorrerYDestruir




		llegamosAlFinal:
		mov rdi, r12
		call free

		pop r15
		pop r14
		pop r13
		pop r12
		pop rbx
		pop rbp	
		ret





	; void altaListaImprimir( altaLista *l, char *archivo, tipoFuncionImprimirDato f )
	altaListaImprimir:
		; COMPLETAR AQUI EL CODIGO

		


;/** FUNCIONES AVANZADAS **/    >> PUEDEN CREAR LAS FUNCIONES AUXILIARES QUE CREAN CONVENIENTES
;----------------------------------------------------------------------------------------------

	; float edadMedia( altaLista *l )
	edadMedia:
		; COMPLETAR AQUI EL CODIGO

	; void insertarOrdenado( altaLista *l, void *dato, tipoFuncionCompararDato f )
	insertarOrdenado:
		; COMPLETAR AQUI EL CODIGO

	; void filtrarAltaLista( altaLista *l, tipoFuncionCompararDato f, void *datoCmp )
	filtrarAltaLista:
		; COMPLETAR AQUI EL CODIGO

;/** FUNCIONES OPCIONALES **/    >> PUEDEN CREAR LAS FUNCIONES AUXILIARES QUE CREAN CONVENIENTES
;-

	string_copiar:

		;en RDI tengo el puntero 
		push rbp        ;A
		mov rbp, rsp
		push rbx
		push r12
		mov r12, rdi
		call string_longitud ;rax la longitud del elem
		inc rax	
		mov rdi, rax
		mov rbx, rdi 
		call malloc
		mov byte[rax+rbx-1], 0
		dec rbx
		cmp rbx, 0
		jz casoVacio
		mov rcx, rbx
		CopiandoConRCX:
		mov bl, [r12+rcx-1]
		mov [rax+rcx-1], bl
		loop CopiandoConRCX
		casoVacio:
		pop r12
		pop rbx
		pop rbp
		ret


	string_longitud:

		;rdi, puntero inical
		mov rax, rdi
		inicioSLL:
		cmp [rax], byte 0
		jz finstring
		inc rax
		jmp inicioSLL
		finstring:
		sub rax, rdi	
		ret	


	string_menor:

		  push rbp        
		  mov rbp, rsp
		  push r12      
loopMenor:mov r12b, [rsi]
		  inc rsi
		  cmp byte [rdi], r12b
		  jl esMenor
		  jg nesMenor
		  cmp byte [rdi], 0
		  jz nesMenor
		  inc rdi
		  jmp loopMenor
		  ;xor rax, rax
esMenor:  mov rax, TRUE
		  jmp FINmenor
nesMenor: mov rax, FALSE
FINmenor: pop r12
		  pop rbp
		  ret








