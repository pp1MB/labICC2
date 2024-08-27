all: atividade.o operacoes.o
	gcc atividade.o operacoes.o -o karatsuba

atividade.o:
	gcc -c atividade.c

operacoes.o:
	gcc -c operacoes.c

run:
	./karatsuba

clean:
	rm *.o karatsuba
