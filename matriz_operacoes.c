#define Linhas 2
#define Colunas 2

#include <stdio.h>
#include <locale.h>

int main() {

  setlocale(LC_ALL, "Portuguese");

  // VARIAVEIS PARA OPERACOES
  int Matriz1[Linhas][Colunas];
  int Matriz2[Linhas][Colunas];
  int MatrizMult[Linhas][Colunas];
  int MatrizSoma[Linhas][Colunas];
  int MatrizSub[Linhas][Colunas];
  int MatrizTrans[Linhas][Colunas];
  // VARIAVEIS PARA A SELECAO E MENU
  int Sel;
  int VarLoop = 1;

  printf("\n\n>> MATRIZ DE INTEIROS: tamanho %d X %d\n",Linhas,Colunas);

  // PREENCHIMENTO DAS MATRIZES
  printf("\nPreenchendo a Matriz 1: \n");
  for (int i = 0; i < Linhas; i++) { // controle da linha
    for (int j = 0; j < Colunas; j++) { // controle da coluna
      printf(" Digite o número [%d,%d]: ",i+1,j+1);
      scanf("%d%*c",&Matriz1[i][j]);
    }
  }

  printf("\nPreenchendo a Matriz 2: \n");
  for (int i = 0; i < Linhas; i++) { // controle da linha
    for (int j = 0; j < Colunas; j++) { // controle da coluna
      printf(" Digite o número [%d,%d]: ",i+1,j+1);
      scanf("%d%*c",&Matriz2[i][j]);
    }
  }

  printf("\nA Matriz (1) é: \n");
  for (int i = 0; i < Linhas; i++) {
    printf("| ");
    for (int j = 0; j < Colunas; j++) {
      printf("%d | ",Matriz1[i][j]);
    }
    printf("\n");
  }

  printf("\nA Matriz (2) é: \n");
  for (int i = 0; i < Linhas; i++) {
    printf("| ");
    for (int j = 0; j < Colunas; j++) {
      printf("%d | ",Matriz2[i][j]);
    }
    printf("\n");
  }
  printf("\n\nPressione ENTER para continuar\n");
  getchar();
///////////////////////////////////////////////////////////////////////////////

while (VarLoop == 1) { // loop infinito

  int MatrizAux = 0; // AUXILIAR DA MULTIPLICACAO

  printf("\n>>>>>>> CALCULADORA <<<<<<<\n ");
  printf("Menu de Operações:\n");
  printf(" 1 - SOMA\n 2 - SUBTRAÇÃO\n 3 - MULTIPLICAÇÃO\n 4 - TRANSPOSTA\n 5 - SAIR\n");
  printf("\nSelecione a operação pelo número correspondente no menu: ");
  scanf("%d%*c",&Sel);

  switch (Sel) {
    case 1: // SOMA ///////////////////////////////////////////////////////////
      for (int i = 0; i < Linhas; i++) { // controle da linha
        for (int j = 0; j < Colunas; j++) { // controle da coluna
          MatrizSoma[i][j] = Matriz1[i][j] + Matriz2[i][j]; // operacao
        }
      }
      printf("\nA Matriz SOMA é: \n");
      for (int i = 0; i < Linhas; i++) {
        printf("| ");
        for (int j = 0; j < Colunas; j++) {
          printf("%d | ",MatrizSoma[i][j]);
        }
        printf("\n");
      }
      break;
    case 2: // SUBTRACAO //////////////////////////////////////////////////////
      for (int i = 0; i < Linhas; i++) { // controle da linha
        for (int j = 0; j < Colunas; j++) { // controle da coluna
          MatrizSub[i][j] = Matriz1[i][j] - Matriz2[i][j]; // operacao
        }
      }
      printf("\nA Matriz SUBTRAÇÃO é: \n");
      for (int i = 0; i < Linhas; i++) {
        printf("| ");
        for (int j = 0; j < Colunas; j++) {
          printf("%d | ",MatrizSub[i][j]);
        }
        printf("\n");
      }
      break;
    case 3: // MULTIPLICACAO //////////////////////////////////////////////////
      /* o terceiro for representa a composicao do termo que e'a soma das
         multiplicacoes de cada linha*coluna, o que depende dos numeros de
         colunas da Matriz1 e linhas da Matriz2 */
      for (int i = 0; i < Linhas; i++) { // controle da linha
        for (int j = 0; j < Colunas; j++) { // controle da coluna
          for (int k = 0; k < Colunas; k++) { // ver comentario antes dos 3 for
            MatrizAux = MatrizAux + (Matriz1[i][k] * Matriz2[k][j]); // operacao
          }
          MatrizMult[i][j] = MatrizAux;
          MatrizAux = 0;
        }
      }
      printf("\nA Matriz MULTIPLICAÇÃO é: \n");
      for (int i = 0; i < Linhas; i++) {
        printf("| ");
        for (int j = 0; j < Colunas; j++) {
          printf("%d | ",MatrizMult[i][j]);
        }
        printf("\n");
      }
      break;
    case 4: //TRANSPOSTA //////////////////////////////////////////////////////
      for (int i = 0; i < Linhas; i++) { // controle da linha
        for (int j = 0; j < Colunas; j++) { // controle da coluna
          MatrizTrans[i][j] = Matriz1[j][i]; // operacao
        }
      }
      printf("\nA Matriz (1) TRANSPOSTA é: \n");
      for (int i = 0; i < Linhas; i++) {
        printf("| ");
        for (int j = 0; j < Colunas; j++) {
          printf("%d | ",MatrizTrans[i][j]);
        }
        printf("\n");
      }
      break;
    case 5: //////////////////////////////////////////////////////////////////
      VarLoop = 0;
      printf("A calculadora será encerrada.\n");
      break;
    default: // no default nao se usa break
      printf("Nenhuma operação foi realizada.\n");
  }
  printf("\n\nPressione ENTER para continuar\n");
  getchar();

}

printf("\n\nPressione ENTER para sair\n");
getchar();

return 0;

}
