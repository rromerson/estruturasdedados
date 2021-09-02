#include <stdio.h>
#include <locale.h>
#include <string.h>

#define MAX 10

void clean_stdin();

int main() {

  char nome1[MAX], nome2[MAX];
	int tam1 = 0, tam2 = 0;

	setlocale(LC_ALL, "Portuguese.Brazil");

  //RECEBER AS STRINGS DO TECLADO
  printf("\nDigite o nome 1: ");
  fgets(nome1, MAX, stdin);
  nome1[strcspn(nome1, "\n")] = '\0';
  clean_stdin();
	printf("O nome 1 é: %s", nome1);

  printf("\nDigite o nome 2: ");
  fgets(nome2, MAX, stdin);
  nome2[strcspn(nome2, "\n")] = '\0';
  clean_stdin();
	printf("O nome 2 é: %s", nome2);

  tam1 = strlen(nome1);
  tam2 = strlen(nome2);
	printf("\nTam1: %d\nTam2: %d\n",tam1,tam2);

  printf("\nPressione ENTER para sair\n");
  getchar();
  return 0;
}
// FUNCAO PRA LIMPAR O BUFFER DE ENTRADA STDIN
void clean_stdin() { // limpar o buffer de entrada
    char c;
    do {
        c = getchar();//recebe nenhum caracter do teclado ate chegar no EOF ou \n
    } while (c != '\n' && c != EOF);
}
