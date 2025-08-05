/*Questão 1) Em uma banca de frutas o preço das laranjas pode assumir 2 valores
distintos, R$0,80 cada se forem adquiridas menos de uma dúzia, e R$0,65 se forem
adquiridas pelo menos doze. Utilizando a estrutura de decisão if-else, elabore
um programa que leia o número de laranjas compradas e imprima o valor total da
compra. */

#include <stdio.h>

int main() {
    int quantidade;
    float preco;

    // Lê quantas laranjas foram compradas
    scanf("%d", &quantidade);


    if (quantidade >= 12) {
        preco = 0.65;
    } else { 
        preco = 0.80;
    }

    printf("Preco da unidade: R$%.2f\n", preco);

    printf("Preco total: R$%.2f\n", quantidade * preco);

    return 0;
}