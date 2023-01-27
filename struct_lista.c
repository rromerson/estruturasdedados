#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 5

int menu_select();
void enter();
void list();
void delete();
int find_free();
void init_list();
void clear();

struct address {
	char nome[30];
	char rua[40];
	char cidade[20];
	char estado[3];
	unsigned long int cep;
} addr_info[MAX];

int main() {
	int choice;

	setlocale(LC_ALL, "Portuguese.Brazil");

	init_list();
	while (1) {
		choice = menu_select();
		switch (choice) {
			case  1:
				enter();
				break;
			case  2:
				delete();
				break;
			case  3:
				list();
				break;
			case  4:
				exit(1);
				break;
			default:
				exit(1);
		}
	}

	printf("\nPresione ENTER para sair\n");
  getchar();
	return 0;
}

//=============================================================================
//INICIALIZACAO DA LISTA
void init_list(){
		int i;
		for (i = 0; i < MAX; i++) {
			addr_info[i].nome[0] = '\0';
		}
}
//=============================================================================
//EXIBIR O MENU DE SELECAO E RECEBER OPCAO DO USUARIO
int menu_select(){
	int t;

	clear();
	printf("\n>>>>>>> MENU <<<<<<<\n");
	printf(" 1 - Inserir um nome\n");
	printf(" 2 - Excluir um nome\n");
	printf(" 3 - Listar o arquivo\n");
	printf(" 4 - Sair\n");

	do {
		printf("\nDigite sua escolha: ");
		scanf("%d%*c",&t);
	} while(t<1 || t>4);

	return t;
}
//=============================================================================
//CADASTRAR UM USUARIO
void enter(){
	int slot;

	slot = find_free();
	if (slot == -1) {
		printf("\nLista cheia");
		return;
	}

	printf("\nCADASTRO ");
	printf("\nDigite o nome: ");
	fgets(addr_info[slot].nome,30,stdin);
	addr_info[slot].nome[strcspn(addr_info[slot].nome, "\n")] = '\0';
	printf("Digite a rua: ");
	fgets(addr_info[slot].rua,40,stdin);
	addr_info[slot].rua[strcspn(addr_info[slot].rua, "\n")] = '\0';
	printf("Digite o cidade: ");
	fgets(addr_info[slot].cidade,20,stdin);
	addr_info[slot].cidade[strcspn(addr_info[slot].cidade, "\n")] = '\0';
	printf("Digite a sigla do estado: ");
	fgets(addr_info[slot].estado,3,stdin);
	addr_info[slot].estado[strcspn(addr_info[slot].estado, "\n")] = '\0';
	printf("Digite o CEP: ");
	scanf("%lu",&addr_info[slot].cep);
}
//=============================================================================
//ENCONTRAR UMA POSICAO LIVRE
int find_free(){
	int i;
	for (i = 0; (addr_info[i].nome[0] && i<MAX) ; i++);
	if (i == MAX) return -1;
	return i;
}
//=============================================================================
//EXCLUIR UM USUARIO
void delete(){
	int slot;

	printf("\nDigite o número do registro a ser excluído: ");
	scanf("%d%*c",&slot);
	if (slot >= 0 && slot < MAX) {
		addr_info[slot].nome[0] = '\0';
	}

}
//=============================================================================
//LISTAR OS CADASTROS EXISTENTES
void list(){
	for (int i = 0; i < MAX; i++) {
		printf("\nREGISTRO [%d]",i);
		printf("\nNome: %s",addr_info[i].nome);
		printf("\nRua: %s",addr_info[i].rua);
		printf("\nCidade: %s",addr_info[i].cidade);
		printf("\nEstado: %s",addr_info[i].estado);
		printf("\nCEP: %lu\n",addr_info[i].cep);
	}
	printf("\nPressione ENTER para voltar\n");
  getchar();
}
//=============================================================================
//LISTAR OS CADASTROS EXISTENTES
void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
