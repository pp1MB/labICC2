all: atividade2.o operacoes.o
	gcc atividade2.o operacoes.o -o karatsuba

atividade.o:
	gcc -c atividade2.c

operacoes.o:
	gcc -c operacoes.c

run:
	./karatsuba

clean:
	rm *.o karatsuba
