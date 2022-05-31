#include <stdio.h>
#include <locale.h>

int soma(int a, int b);

int main() {

  setlocale(LC_ALL, "Portuguese"); //habilita a acentua��o para o portugu�s
  //setlocale(LC_ALL,"C");

  int Sel, Num1, Num2;
  int Result;

    printf("\n>>>>>>> CALCULADORA <<<<<<<\n ");
    printf("Menu de Opera��es:\n");
    printf(" 1 - SOMA\n 2 - SUBTRA��O\n 3 - MULTIPLICA��O\n 4 - DIVIS�O\n 5 - SAIR\n");
    printf("\nDigite dois n�meros inteiros para serem os operandos:\n");
    scanf("%d%*c",&Num1);
    scanf("%d%*c",&Num2);
    printf("\nSelecione a opera��o pelo n�mero correspondente no menu:\n");
    scanf("%d%*c",&Sel);

    switch (Sel) {
      case 1:
        Result = soma(Num1, Num2);
        printf("O resultado da SOMA �: %d\n",Result);
        break;
      case 2:
        Result = Num1 - Num2;
        printf("O resultado da SUBTRA��O �: %d\n",Result);
        break;
      case 3:
        Result = Num1 * Num2;
        printf("O resultado da MULTIPLICA��O �: %d\n",Result);
        break;
      case 4:
        Result = Num1 / Num2;
        printf("O resultado da DIVIS�O �: %d\n",Result);
        break;
      case 5:
        Result = 0;
        printf("A calculadora ser� encerrada.\n");
        break;
      default: // no default nao se usa break
        Result = 0;
        printf("Nenhuma opera��o foi realizada e o resultado � %d\n",Result);
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
