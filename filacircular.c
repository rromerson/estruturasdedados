#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 10 //total de eventos

void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

char p[MAX];
int spos = 0;
int rpos = 0;

char qretrieve(void);
void enter(void);
void qstore(char q);
void review(void);
void delete(void);

int main(){
	char choice; //escolha do usuario
	int t;

	setlocale(LC_ALL, "Portuguese");

	for (t = 0; t < MAX; t++) p[t] = '\0'; //inicializa a matriz com nulos

	for (;;) {
		clear();
    printf("\n>> AGENDA");
		printf("\nI. Inserir evento\nL. Listar evento\nR. Remover evento\nS. Sair \n");
		printf("\nOpção:");
		scanf(" %c",&choice);

		switch (choice) {//escolha do usuario
			case 'I':
				enter();
				break;
			case 'L':
				review();
				break;
			case 'R':
				delete();
				break;
			case 'S':
				exit(0);
			default:
				printf("\nOpção Inválida:");
				getchar();
				printf("\nPresione ENTER para voltar\n");
				getchar();
		}

	}
	//===========================================================================
	printf("\nPresione ENTER para sair\n");
  getchar();
	return 0;
}

//===========================================================================
//insere um evento na fila
void enter(void){
	char event;

	do {
      printf("Insira o evento [%d]: ",spos+1);
      scanf(" %c",&event);
      if (event == '0') {
        return;
      } else {
        qstore(event);
      }

	}while(event != '0');
}

//===========================================================================
//vê o que há na fila
void review(void){
	int t;
	char temp;

  printf("\nspos: %p",spos);
  printf("\nrpos: %p\n",rpos);

  if (spos > rpos) { //normal.. ir da prox leitura ate a prox escrita
    for(t = rpos; t < spos; t++) {
      printf("\n[%d]: %c", t+1, p[t]);
    }
  } else if (spos == rpos) { // vazia
    printf("\nSem eventos para exibir.\n");
  } else { // rpos > spos - ultprapassou o zero
    for(t = rpos; t < MAX; t++) {
      printf("\n[%d]: %c", t+1, p[t]);
    }
    for(t = 0; t <= spos-1; t++) {
      printf("\n[%d]: %c", t+1, p[t]);
    }
  }

  scanf("%c",&temp);
	printf("\nPresione ENTER para voltar..\n");
  getchar();
}

//===========================================================================
//apaga um evento na fila
void delete(void){
	char event;
	char temp;

	event = qretrieve();
	if (!event) return;
	printf("%c\n",event);

	scanf("%c",&temp);
	printf("\nPresione ENTER para voltar..\n");
  getchar();
}

//===========================================================================
//armazena um evento
void qstore(char q){

  //Fila cheia quanto:
  // indice de recuperacao no inicio e de armazenamento no fim
  // ou se spos (armazenamento) tem um a menos que rpos (recuperação)
	if (spos+1 == rpos || (spos+1 == MAX && !rpos)) {
    printf("Lista cheia.\n");
    return;
	}
  p[spos] = q;
  spos++;
  if(spos == MAX) spos = 0;
}

//===========================================================================
//recupera um evento
char qretrieve(void) {

  if (rpos == MAX) rpos = 0; // leitura ja ta no fim? volta pro inicio
  if (rpos == spos) {
		printf("Sem eventos para remover.\n");
	  getchar();
		printf("\nPressione ENTER para voltar..\n");
	  getchar();
		return '\0';
	}
	rpos++;
	return p[rpos-1];
}
