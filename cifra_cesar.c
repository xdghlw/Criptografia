#include <stdio.h>
#include <stdlib.h>

char* criptografar(char* texto_simples) {

    // Descobrir tamanho do vetor.
    int contador = 0;
    while (texto_simples[contador] != '\0') {
        contador++;
    }

    // Alocar um vetor de chars com o mesmo tamanho do texto simples.
    char *texto_criptografado = (char*) malloc(contador * sizeof(char));

    //Criptografar.
    for (int i = 0; i < contador; i++) {
        texto_criptografado[i] = texto_simples[i] + 9;
    }

    return texto_criptografado;
}

int main() {
    char texto_simples[] = "Gustavo Henrique";
    char* texto_criptografado = criptografar(texto_simples);
    printf("%s", texto_criptografado);
}
