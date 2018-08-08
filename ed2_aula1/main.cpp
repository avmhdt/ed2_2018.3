#include <stdio.h>

int main()
{
    FILE *arquivo;

    arquivo = fopen("meuArquivo.txt", "r");

    if(arquivo) {
        char texto[30] = "Estruturas de Dados II";
        //fputs(texto, arquivo);
        char lerTexto[10];
        fgets(lerTexto, 10, arquivo);
        printf(lerTexto);
        fclose(arquivo);
    }
}



