		insertarOrdenado:

	; bool menorEstudiante( estudiante *e1 RDI , estudiante *e2 RSI){
	; menorEstudiante:

		push rbp        ;A
		mov rbp, rsp
		push rbx 		;D
		push r12        ;A
		push r13		;D
		push r14        ;A
		push r15 		;D
		sub rbp, 8 		;A

			mov qword rax, 0
			mov rbx, rdi; guardo puntero a Lista
			mov r12, rsi; guardar puntero a Dato
			mov r13, rdx; guardo puntero a Funcion


		VeoSiListaEsVacia:

			cmp qword [rdi+OFFSET_PRIMERO], 0; veo si la lista es vacia
			je AgregarVacio; si es el caso jmp a agrelgar e

		VeoSiDatoMayorAUltimo:
			mov r14 ,  [rbx+OFFSET_ULTIMO]
			; mov rdi, r12
			; mov rsi, [r14 +OFFSET_DATO]
			mov rsi, r12
			mov rdi, [r14 +OFFSET_DATO]
			call r13
			cmp rax, byte 1
			je DatoEsMayorAUltimo
			jne VeoSiDatoMenorAPrimer

			DatoEsMayorAUltimo:
			mov r14 ,  [rbx+OFFSET_ULTIMO]
			mov rdi, r12
			call nodoCrear
			mov [r14+OFFSET_SIGUIENTE], rax
			mov [rax+OFFSET_ANTERIOR], r14
			mov [rbx+OFFSET_ULTIMO], rax
			jmp SalgoDeInsertarOrdenado


		VeoSiDatoMenorAPrimer:

			mov r14, [rbx+OFFSET_PRIMERO]
			mov rdi, [r14+OFFSET_DATO]
			mov rsi, r12
			call r13
			cmp rax, byte 1
			jne DatoMenorAPrimer
			je BuscoPorListaNoVacia ;DATO ES MAYOR A PRIMERO

			DatoMenorAPrimer:
			mov r14, [rbx+OFFSET_PRIMERO]
			mov rdi, r12
			call nodoCrear
			mov [r14+OFFSET_ANTERIOR], rax
			mov [rax+OFFSET_SIGUIENTE], r14
			mov [rbx+OFFSET_PRIMERO], rax
			jmp SalgoDeInsertarOrdenado


			;caso contrario
		BuscoPorListaNoVacia:

			mov r14, [rbx+OFFSET_PRIMERO]
			jmp SaltoSigNodo

			comparoConSigNodo:
			mov r14, [r14+OFFSET_SIGUIENTE]
			SaltoSigNodo:
			; mov rsi, [r14+OFFSET_DATO]
			; mov rdi, r12
			mov rdi, [r14+OFFSET_DATO]
			mov rsi, r12
			call r13 
			cmp rax, byte 1
			je comparoConSigNodo
			; jz BuscoPorListaNoVacia
			jne insertoAntes

			insertoAntes:
			mov rdi, r12 
			call nodoCrear
			mov r15, [r14+OFFSET_ANTERIOR]
			mov [r15+OFFSET_SIGUIENTE], rax
			mov [r14+OFFSET_ANTERIOR], rax
			mov [rax+OFFSET_SIGUIENTE], r14
			mov [rax+OFFSET_ANTERIOR], r15
			jmp SalgoDeInsertarOrdenado

		AgregarVacio:

		mov rdi, r12
		call nodoCrear
		mov[rbx+OFFSET_PRIMERO], rax
		mov[rbx+OFFSET_ULTIMO], rax

		SalgoDeInsertarOrdenado:

		add rbp, 8
		pop r15
		pop r14	
		pop r13
		pop r12
		pop rbx
		pop rbp
		ret 