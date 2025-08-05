/* Desenvolva um código que leia um valor numérico entre 0 e 50,
inclusive, e imprima o resto da divisão desse número por todos os seus
antecessores maiores que 0.
*/

#include <stdio.h>

int main() {
    int numero;
    int i;

    // Lendo o numero (só aceita se for maior que 0)
    scanf("%d", &numero);

    if (numero <= 0) {
        printf("Numero invalido! Digite um valor maior que 0.\n");
        return 0;
    }

    // Mostrando o resto da divisão por todos os antecessores
    for (i = numero - 1; i >= 1; i--) {
        printf("Resto da divisao de %d por %d: %d\n", numero, i, numero % i);
    }

    return 0;
}