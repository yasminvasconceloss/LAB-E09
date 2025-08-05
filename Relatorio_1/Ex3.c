/* Faça um código que recebe um valor n, referente a quantidade de
testes que serão feitos. Logo em seguida, monte uma função que recebe 5 valores
inteiros e mostra quantos valores digitados foram pares, quantos valores
digitados foram ímpares, quantos valores digitados foram positivos e quantos
valores digitados foram negativos e mostre na tela.
*/

#include <stdio.h>

// Função para analisar os 5 números
void analisar_numeros(int a, int b, int c, int d, int e) {
    int pares = 0, impares = 0;
    int positivos = 0, negativos = 0;
    int numeros[5] = {a, b, c, d, e};

    for (int i = 0; i < 5; i++) {
        int num = numeros[i];

        if (num % 2 == 0) {
            pares++;
        } else {
            impares++;
        }

        if (num > 0) {
            positivos++;
        } else if (num < 0) {
            negativos++;
        }
    }

    printf("Quantidade de numeros pares: %d\n", pares);
    printf("Quantidade de numeros impares: %d\n", impares);
    printf("Quantidade de numeros positivos: %d\n", positivos);
    printf("Quantidade de numeros negativos: %d\n", negativos);
}

int main() {
    int n;
    scanf("%d", &n); // Lê quantos testes serão feitos

    for (int i = 0; i < n; i++) {
        int a, b, c, d, e;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e); // Lê os 5 números
        analisar_numeros(a, b, c, d, e); // Chama a função para analisar
    }

    return 0;
}