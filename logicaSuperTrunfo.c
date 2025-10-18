#include <stdio.h>
#include <string.h>

// Definição da estrutura de uma carta
typedef struct {
    char estado[50];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
    float pibPerCapita;
} Carta;

// Função para calcular densidade demográfica e PIB per capita
void calcularDados(Carta *carta) {
    if (carta->area > 0) {
        carta->densidadeDemografica = (float)carta->populacao / carta->area;
    } else {
        carta->densidadeDemografica = 0;
    }

    if (carta->populacao > 0) {
        carta->pibPerCapita = (carta->pib * 1e9) / carta->populacao; // PIB em reais
    } else {
        carta->pibPerCapita = 0;
    }
}

// Função para imprimir informações de uma carta
void imprimirCarta(Carta carta) {
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", carta.densidadeDemografica);
    printf("PIB per capita: R$ %.2f\n", carta.pibPerCapita);
    printf("-----------------------------\n");
}

// Função de comparação entre duas cartas
void compararCartas(Carta c1, Carta c2, int opcao) {
    printf("\nComparando cartas (Atributo: ");
    
    switch (opcao) {
        case 1:
            printf("População):\n");
            printf("%s: %d habitantes\n", c1.cidade, c1.populacao);
            printf("%s: %d habitantes\n", c2.cidade, c2.populacao);
            if (c1.populacao > c2.populacao)
                printf("Resultado: %s venceu!\n", c1.cidade);
            else if (c2.populacao > c1.populacao)
                printf("Resultado: %s venceu!\n", c2.cidade);
            else
                printf("Empate!\n");
            break;

        case 2:
            printf("Área):\n");
            printf("%s: %.2f km²\n", c1.cidade, c1.area);
            printf("%s: %.2f km²\n", c2.cidade, c2.area);
            if (c1.area > c2.area)
                printf("Resultado: %s venceu!\n", c1.cidade);
            else if (c2.area > c1.area)
                printf("Resultado: %s venceu!\n", c2.cidade);
            else
                printf("Empate!\n");
            break;

        case 3:
            printf("PIB):\n");
            printf("%s: R$ %.2f bilhões\n", c1.cidade, c1.pib);
            printf("%s: R$ %.2f bilhões\n", c2.cidade, c2.pib);
            if (c1.pib > c2.pib)
                printf("Resultado: %s venceu!\n", c1.cidade);
            else if (c2.pib > c1.pib)
                printf("Resultado: %s venceu!\n", c2.cidade);
            else
                printf("Empate!\n");
            break;

        case 4:
            printf("Pontos Turísticos):\n");
            printf("%s: %d pontos\n", c1.cidade, c1.pontosTuristicos);
            printf("%s: %d pontos\n", c2.cidade, c2.pontosTuristicos);
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Resultado: %s venceu!\n", c1.cidade);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("Resultado: %s venceu!\n", c2.cidade);
            else
                printf("Empate!\n");
            break;

        case 5:
            printf("Densidade Demográfica):\n");
            printf("%s: %.2f hab/km²\n", c1.cidade, c1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n", c2.cidade, c2.densidadeDemografica);
            if (c1.densidadeDemografica < c2.densidadeDemografica)
                printf("Resultado: %s venceu!\n", c1.cidade);
            else if (c2.densidadeDemografica < c1.densidadeDemografica)
                printf("Resultado: %s venceu!\n", c2.cidade);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida!\n");
    }
}

int main() {
    Carta carta1, carta2;
    int opcao;

    // Entrada dos dados da primeira carta
    printf("Digite os dados da Carta 1:\n");
    printf("Estado: ");
    fgets(carta1.estado, sizeof(carta1.estado), stdin);
    strtok(carta1.estado, "\n");

    printf("Código: ");
    fgets(carta1.codigo, sizeof(carta1.codigo), stdin);
    strtok(carta1.codigo, "\n");

    printf("Cidade: ");
    fgets(carta1.cidade, sizeof(carta1.cidade), stdin);
    strtok(carta1.cidade, "\n");

    printf("População: ");
    scanf("%d", &carta1.populacao);

    printf("Área (km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    getchar(); // limpar buffer do Enter

    // Entrada dos dados da segunda carta
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: ");
    fgets(carta2.estado, sizeof(carta2.estado), stdin);
    strtok(carta2.estado, "\n");

    printf("Código: ");
    fgets(carta2.codigo, sizeof(carta2.codigo), stdin);
    strtok(carta2.codigo, "\n");

    printf("Cidade: ");
    fgets(carta2.cidade, sizeof(carta2.cidade), stdin);
    strtok(carta2.cidade, "\n");

    printf("População: ");
    scanf("%d", &carta2.populacao);

    printf("Área (km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    
    calcularDados(&carta1);
    calcularDados(&carta2);

    
    printf("\n--- CARTA 1 ---\n");
    imprimirCarta(carta1);
    printf("--- CARTA 2 ---\n");
    imprimirCarta(carta2);

    // Menu interativo
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    
    compararCartas(carta1, carta2, opcao);

    return 0;
}
