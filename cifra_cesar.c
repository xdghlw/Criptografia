#include <stdio.h>

void criptografar(char* texto_simples) {

    int contador = 0;

    // Descobrir tamanho do vetor;
    while (texto_simples[contador] != '\0') {
        contador++;
    }

    // Declarar um vetor de chars com o mesmo tamanho do texto simples.
    char texto_criptografado[contador];

    //
    for (int i = 0; i < contador; i++) {
        texto_criptografado[i] = texto_simples[i] + 3;
        printf("%c", texto_simples[i]);
    }
    printf("%s", "\n");
    for (int i = 0; i < contador; i++) {
        printf("%c", texto_criptografado[i]);
    }
}

int main() {
    criptografar("gustavo");
}
