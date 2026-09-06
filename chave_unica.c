#include <stdio.h>
#include <string.h>

void obterOcteto(char *texto) {

    while (*texto != '\0') {
        unsigned char ascii = (unsigned char) *texto;
        for (int i = 7; i >= 0; i--) {
            printf("%d", (ascii >> i) & 1);
        }
        printf(" ");
        printf("(%c)", ascii);
        texto++;
        printf(" \n");
    }
}


void xorMensagem(const unsigned char *texto,
                 const unsigned char *chave,
                 unsigned char *resultado,
                 int tamanho) {
    for (int i = 0; i < tamanho; i++) {

        resultado[i] = texto[i] ^ chave[i];
//        printf("%d", texto[i] ^ chave[i]);
    }
}

int chave_unica() {
    // Mensagem original
    char mensagem1[] = "I love you";

//    Imprime octetos correspondente ao código ASCII.
    obterOcteto(&mensagem1);

    // Chave única (exemplo)
    unsigned char chave1[] = {
        0x15, 0x3A, 0x71, 0x02, 0x6C,
        0x1F, 0x55, 0x0A, 0x31, 0x7E
    };

    int tamanho = strlen(mensagem1);

    unsigned char textoCifrado[20];

    // Cifra = Mensagem XOR Chave
    xorMensagem((unsigned char *)mensagem1,
                chave1,
                textoCifrado,
                tamanho);

    printf("Texto cifrado (hex):\n");
    for (int i = 0; i < tamanho; i++)
        printf("%02X ", textoCifrado[i]);

    printf("\n\n");

    // Suponha que um atacante queira que o texto cifrado
    // represente outra mensagem.

    char mensagem2[] = "Elvis lives";

    unsigned char chave2[20];

    // Calcula a chave necessária
    xorMensagem(textoCifrado,
                (unsigned char *)mensagem2,
                chave2,
                tamanho);

    printf("Chave 2 (hex):\n");
    for (int i = 0; i < tamanho; i++)
        printf("%02X ", chave2[i]);

    printf("\n\n");

    // Verificação
    unsigned char recuperada[20];

    xorMensagem(textoCifrado,
                chave2,
                recuperada,
                tamanho);

    recuperada[tamanho] = '\0';

    printf("Mensagem obtida usando a chave 2:\n");
    printf("%s\n", recuperada);

    return 0;
}

