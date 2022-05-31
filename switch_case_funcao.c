#include <stdio.h>
#include <locale.h>

int soma(int a, int b);

int main() {

  setlocale(LC_ALL, "Portuguese"); //habilita a acentuação para o português
  //setlocale(LC_ALL,"C");

  int Sel, Num1, Num2;
  int Result;

    printf("\n>>>>>>> CALCULADORA <<<<<<<\n ");
    printf("Menu de Operações:\n");
    printf(" 1 - SOMA\n 2 - SUBTRAÇÃO\n 3 - MULTIPLICAÇÃO\n 4 - DIVISÃO\n 5 - SAIR\n");
    printf("\nDigite dois números inteiros para serem os operandos:\n");
    scanf("%d%*c",&Num1);
    scanf("%d%*c",&Num2);
    printf("\nSelecione a operação pelo número correspondente no menu:\n");
    scanf("%d%*c",&Sel);

    switch (Sel) {
      case 1:
        Result = soma(Num1, Num2);
        printf("O resultado da SOMA é: %d\n",Result);
        break;
      case 2:
        Result = Num1 - Num2;
        printf("O resultado da SUBTRAÇÃO é: %d\n",Result);
        break;
      case 3:
        Result = Num1 * Num2;
        printf("O resultado da MULTIPLICAÇÃO é: %d\n",Result);
        break;
      case 4:
        Result = Num1 / Num2;
        printf("O resultado da DIVISÃO é: %d\n",Result);
        break;
      case 5:
        Result = 0;
        printf("A calculadora será encerrada.\n");
        break;
      default: // no default nao se usa break
        Result = 0;
        printf("Nenhuma operação foi realizada e o resultado é %d\n",Result);
    }

  printf("\nPressione ENTER para continuar..\n");
  getchar(); // parada


  return 0;
}

//-----------------------------------------------------------------------------
// funfao para somar dois numeros
int soma(int a, int b){
  int res;
  res = a + b;

  return res;
}
//-----------------------------------------------------------------------------
