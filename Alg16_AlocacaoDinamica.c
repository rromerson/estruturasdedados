//Alocacao Dinamica:
//MALLOC (), CALLOC(), REALLOC(), FREE()
//void free(void *ptr)

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void put_caracter(char *p);
void get_caracter(char *p);

int main() {

	char *p;

	setlocale(LC_ALL, "Portuguese");

	if (!(p=malloc(100))) {
		printf("Sem memória disponível\n");
		exit(1); // programa terminou de maneira excepcional
	} else {
		printf("\nMemória Alocada a partir de 0x%p\n",p);
	}

	put_caracter(p);
	get_caracter(p);

	free(p); //nunca use free com argumento inva'lido
  printf("\n\nMemória liberada a partir de 0x%p\n",p);

	//===========================================================================
  printf("\nPresione ENTER para sair\n");
  getchar();
  return 0;

}

//==============================================================================
// FUNCOES
void put_caracter(char *p){
	for (int i = 0; i < 100; i++) {
		*p=i;
		p++;
	}
	printf("\n100 caracteres escritos.\n");
}

void get_caracter(char *p){
	for (int i = 0; i < 100; i++) {
		printf("\nCaractere %d (%p)): %c",i, p,*p);
		p++;
	}
}
