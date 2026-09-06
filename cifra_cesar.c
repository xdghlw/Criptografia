#include <stdio.h>
#include <stdlib.h>

void criptografar(char* texto_simples) {

    // Descobrir tamanho do vetor.
    int contador = 0;
    while (texto_simples[contador] != '\0') {
        contador++;
    }

    // Alocar um vetor de chars com o mesmo tamanho do texto simples.
    char *texto_criptografado = (char*) malloc(contador * sizeof(char));

    //Criptografar.
    for (int i = 0; i < contador; i++) {
        texto_simples[i] = texto_simples[i] + 9;
    }
}

int main() {
    char texto_simples[] = "Gustavo Henrique";
    criptografar(texto_simples);
    printf("%s", texto_simples);
}
