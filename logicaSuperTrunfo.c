#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado[30];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para calcular dados derivados
void calcularDados(Carta *carta) {
    if (carta->area > 0) {
        carta->densidadePopulacional = carta->populacao / carta->area;
    } else {
        carta->densidadePopulacional = 0;
    }

    if (carta->populacao > 0) {
        carta->pibPerCapita = carta->pib / carta->populacao;
    } else {
        carta->pibPerCapita = 0;
    }
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta c) {
    printf("Cidade: %s (%s)\n", c.nomeCidade, c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: %.2f\n\n", c.pibPerCapita);
}

// Função para cadastrar os dados de uma carta
void cadastrarCarta(Carta *carta, int numero) {
    printf("\n--- Cadastro da Carta %d ---\n", numero);

    printf("Estado: ");
    scanf(" %[^\n]", carta->estado);

    printf("Código da carta: ");
    scanf(" %[^\n]", carta->codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Calcula dados derivados
    calcularDados(carta);
}

int main() {
    Carta carta1, carta2;

    // Cadastro das duas cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    // Exibição dos dados
    printf("\n=== Carta 1 ===\n");
    exibirCarta(carta1);

    printf("=== Carta 2 ===\n");
    exibirCarta(carta2);

    // Comparação com base na População
    printf("Comparação de cartas (Atributo: População):\n\n");
    printf("Carta 1 - %s (%s): %d habitantes\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d habitantes\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

    // Determinação do vencedor
    if (carta1.populacao > carta2.populacao) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
