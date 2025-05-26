#include <stdio.h>
#include <string.h>

// variaveis da carta
typedef struct {
    char nome[30];
    int populacao;     // em milhões
    int area;          // em mil km²
    int pib;           // em bilhões de USD
    int densidade;     // hab/km²
} Carta;

// Função para exibir o menu 
void mostrarMenu(int ignorar) {
    printf("\nEscolha um atributo:\n");
    if (ignorar != 1) printf("1 - População\n");
    if (ignorar != 2) printf("2 - Área\n");
    if (ignorar != 3) printf("3 - PIB\n");
    if (ignorar != 4) printf("4 - Densidade Demográfica\n");
}

// Função para obter o valor de um atributo com base na opção escolhida
int obterValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidade;
        default: return -1;
    }
}

// Função para comparar dois valores com base no tipo de atributo
int comparar(int val1, int val2, int atributo) {
    return (atributo == 4) ? (val1 < val2 ? 1 : (val1 > val2 ? 2 : 0))
                           : (val1 > val2 ? 1 : (val1 < val2 ? 2 : 0));
}

// Função para obter o nome do atributo
const char* nomeAtributo(int opcao) {
    switch(opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 213, 8516, 2200, 25};
    Carta carta2 = {"Japão", 125, 378, 5000, 347};

    int escolha1, escolha2;

    // Menu de seleção do primeiro atributo
    do {
        mostrarMenu(0);
        printf("Escolha o primeiro atributo: ");
        scanf("%d", &escolha1);
        if (escolha1 < 1 || escolha1 > 4) {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha1 < 1 || escolha1 > 4);

    // Menu de seleção do segundo atributo (excluindo o primeiro)
    do {
        mostrarMenu(escolha1);
        printf("Escolha o segundo atributo: ");
        scanf("%d", &escolha2);
        if (escolha2 < 1 || escolha2 > 4 || escolha2 == escolha1) {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha2 < 1 || escolha2 > 4 || escolha2 == escolha1);

    // Obter valores de cada atributo
    int valor1_attr1 = obterValor(carta1, escolha1);
    int valor2_attr1 = obterValor(carta2, escolha1);

    int valor1_attr2 = obterValor(carta1, escolha2);
    int valor2_attr2 = obterValor(carta2, escolha2);

    // Comparações individuais
    int vencedor_attr1 = comparar(valor1_attr1, valor2_attr1, escolha1);
    int vencedor_attr2 = comparar(valor1_attr2, valor2_attr2, escolha2);

    // Soma dos atributos
    int soma1 = valor1_attr1 + valor1_attr2;
    int soma2 = valor2_attr1 + valor2_attr2;

    // Resultado final
    int vencedor_geral = (soma1 > soma2) ? 1 : (soma1 < soma2 ? 2 : 0);

    // Exibição clara do resultado
    printf("\n--- Resultado da Comparação ---\n");
    printf("País 1: %s\n", carta1.nome);
    printf("País 2: %s\n", carta2.nome);
    printf("\nAtributos Comparados:\n");
    printf("%s -> %s: %d | %s: %d\n", nomeAtributo(escolha1),
           carta1.nome, valor1_attr1, carta2.nome, valor2_attr1);
    printf("%s -> %s: %d | %s: %d\n", nomeAtributo(escolha2),
           carta1.nome, valor1_attr2, carta2.nome, valor2_attr2);

    printf("\nSoma dos Atributos:\n");
    printf("%s: %d\n", carta1.nome, soma1);
    printf("%s: %d\n", carta2.nome, soma2);

    // Resultado Final
    if (vencedor_geral == 0) {
        printf("\nResultado Final: Empate!\n");
    } else {
        printf("\nResultado Final: Vencedor - %s\n", vencedor_geral == 1 ? carta1.nome : carta2.nome);
    }

    return 0;
}
