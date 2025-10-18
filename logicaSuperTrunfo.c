#include <stdio.h>
#include <string.h>

// Definição da estrutura da carta
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

// Cálculo de dados derivados
void calcularDados(Carta *c) {
    c->densidadeDemografica = (c->area > 0) ? c->populacao / c->area : 0;
    c->pibPerCapita = (c->populacao > 0) ? (c->pib * 1e9) / c->populacao : 0;
}

// Imprime as informações da carta
void imprimirCarta(Carta c) {
    printf("Estado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Cidade: %s\n", c.cidade);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", c.densidadeDemografica);
    printf("PIB per capita: R$ %.2f\n", c.pibPerCapita);
    printf("-----------------------------\n");
}

// Função que retorna o valor do atributo escolhido
float obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        default: return 0;
    }
}

// Nome do atributo para exibição
const char* nomeDoAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Comparação de dois atributos e decisão final
void compararCartas(Carta c1, Carta c2, int atr1, int atr2) {
    float valor1_c1 = obterValorAtributo(c1, atr1);
    float valor1_c2 = obterValorAtributo(c2, atr1);
    float valor2_c1 = obterValorAtributo(c1, atr2);
    float valor2_c2 = obterValorAtributo(c2, atr2);

    float soma1 = 0, soma2 = 0;

    // Comparação para primeiro atributo
    printf("\nComparação pelo atributo 1: %s\n", nomeDoAtributo(atr1));
    printf("%s: %.2f | %s: %.2f\n", c1.cidade, valor1_c1, c2.cidade, valor1_c2);
    if (atr1 == 5) { // Densidade: menor vence
        soma1 += (valor1_c1 < valor1_c2) ? 1 : 0;
        soma2 += (valor1_c2 < valor1_c1) ? 1 : 0;
    } else {
        soma1 += (valor1_c1 > valor1_c2) ? 1 : 0;
        soma2 += (valor1_c2 > valor1_c1) ? 1 : 0;
    }

    // Comparação para segundo atributo
    printf("Comparação pelo atributo 2: %s\n", nomeDoAtributo(atr2));
    printf("%s: %.2f | %s: %.2f\n", c1.cidade, valor2_c1, c2.cidade, valor2_c2);
    if (atr2 == 5) {
        soma1 += (valor2_c1 < valor2_c2) ? 1 : 0;
        soma2 += (valor2_c2 < valor2_c1) ? 1 : 0;
    } else {
        soma1 += (valor2_c1 > valor2_c2) ? 1 : 0;
        soma2 += (valor2_c2 > valor2_c1) ? 1 : 0;
    }

    // Resultado final
    printf("\nResultado Final:\n");
    printf("%s: %d pontos\n", c1.cidade, (int)soma1);
    printf("%s: %d pontos\n", c2.cidade, (int)soma2);

    int vencedor = (soma1 > soma2) ? 1 : (soma2 > soma1) ? 2 : 0;

    if (vencedor == 1)
        printf("Vencedora: %s!\n", c1.cidade);
    else if (vencedor == 2)
        printf("Vencedora: %s!\n", c2.cidade);
    else
        printf("Empate!\n");
}

// Menu de seleção de atributo
int selecionarAtributo(int usado) {
    int escolha;
    printf("\nEscolha um atributo para comparar:\n");
    for (int i = 1; i <= 5; i++) {
        if (i != usado) {
            printf("%d - %s\n", i, nomeDoAtributo(i));
        }
    }
    printf("Digite sua opção: ");
    scanf("%d", &escolha);
    if (escolha < 1 || escolha > 5 || escolha == usado) {
        printf("Opção inválida. Tente novamente.\n");
        return selecionarAtributo(usado);
    }
    return escolha;
}

int main() {
    Carta carta1, carta2;
    int atributo1, atributo2;

    // Entrada de dados da carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Estado: "); fgets(carta1.estado, 50, stdin); strtok(carta1.estado, "\n");
    printf("Código: "); fgets(carta1.codigo, 10, stdin); strtok(carta1.codigo, "\n");
    printf("Cidade: "); fgets(carta1.cidade, 50, stdin); strtok(carta1.cidade, "\n");
    printf("População: "); scanf("%d", &carta1.populacao);
    printf("Área (km²): "); scanf("%f", &carta1.area);
    printf("PIB (em bilhões): "); scanf("%f", &carta1.pib);
    printf("Pontos Turísticos: "); scanf("%d", &carta1.pontosTuristicos);
    getchar(); // limpa buffer

    // Entrada de dados da carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: "); fgets(carta2.estado, 50, stdin); strtok(carta2.estado, "\n");
    printf("Código: "); fgets(carta2.codigo, 10, stdin); strtok(carta2.codigo, "\n");
    printf("Cidade: "); fgets(carta2.cidade, 50, stdin); strtok(carta2.cidade, "\n");
    printf("População: "); scanf("%d", &carta2.populacao);
    printf("Área (km²): "); scanf("%f", &carta2.area);
    printf("PIB (em bilhões): "); scanf("%f", &carta2.pib);
    printf("Pontos Turísticos: "); scanf("%d", &carta2.pontosTuristicos);

    
    calcularDados(&carta1);
    calcularDados(&carta2);

    
    printf("\n--- CARTA 1 ---\n"); imprimirCarta(carta1);
    printf("--- CARTA 2 ---\n"); imprimirCarta(carta2);

    
    atributo1 = selecionarAtributo(0);
    atributo2 = selecionarAtributo(atributo1);

    
    compararCartas(carta1, carta2, atributo1, atributo2);

    return 0;
}
