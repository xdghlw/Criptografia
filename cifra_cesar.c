#include <stdio.h>
#include <stdlib.h>

// Definindo o tamanho do intervalo imprimível (32 a 127)
#define MIN_ASCII 32
#define MAX_ASCII 127
#define TAM_INTERVALO (MAX_ASCII - MIN_ASCII + 1) // 96

//Criptografar.
void criptografar(char texto_simples[], int chave) {
    int contador = 0;
    while (texto_simples[contador] != '\0') {
        contador++;
    }
    // Garante que a chave fique dentro do intervalo de 0 a 95
    // Isso evita problemas se a chave for muito grande ou negativa
    chave = (chave % TAM_INTERVALO + TAM_INTERVALO) % TAM_INTERVALO;

    for (int i = 0; i < contador; i++) {
        // 1. Transforma o caractere atual para uma base 0 (subtraindo 32)
        int caractere_base0 = texto_simples[i] - MIN_ASCII;

        // 2. Aplica a chave e rotaciona usando o módulo do tamanho do intervalo (96)
        int novo_caractere = (caractere_base0 + chave) % TAM_INTERVALO;

        // 3. Volta o caractere para o intervalo ASCII correto (somando 32)
        texto_simples[i] = novo_caractere + MIN_ASCII;

//        printf("%c", texto_simples[i], texto_simples[i]);
    }
}

void descriptografar(char* texto_criptografado) {
    int contador = 0;

    // Descobre o tamanho da string
    while (texto_criptografado[contador] != '\0') {
        contador++;
    }

    int chave;

    //Aplicar todas as chaves possíveis de acordo com o intervalo.
    for (chave = 1; chave <= TAM_INTERVALO; chave++) {
        printf("%d: ", chave);
        for (int j = 0; j < contador; j++) {
        int c = ((texto_criptografado[j] - MIN_ASCII + chave) % TAM_INTERVALO) + MIN_ASCII;
        printf("%c", c);
        }
    printf("\n");
    }
}

int main() {
    char texto_simples[] = "Gustavo Henrique Loreto Weirich";
    criptografar(texto_simples, 17);
    descriptografar(texto_simples);
}
