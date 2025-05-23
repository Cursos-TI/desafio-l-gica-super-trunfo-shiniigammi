#include <stdio.h>
#include <string.h>

/* Desafio Super Trunfo - Países
Tema 2 - Comparação das Cartas
Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
Siga os comentários para implementar cada parte do desafio.
*/

// Estrutura da carta
typedef struct {
    char estado[3];
    char codigo[4]; // Ex: A01, B02
    char nome[30];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
} Carta;

// Função para exibir os atributos de uma carta
void mostrarCarta(Carta c) {
    printf("\nCódigo: %s (%s)\n", c.codigo, c.estado);
    printf("Cidade: %s\n", c.nome);
    printf("População: %lu habitantes\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
}

// Função para exibir o menu de atributos
void exibirMenuAtributos() {
    printf("\n### Atributos Disponíveis ###\n");
    printf("1 - População (maior vence)\n");
    printf("2 - Área (maior vence)\n");
    printf("3 - PIB (maior vence)\n");
    printf("4 - Pontos Turísticos (maior vence)\n");
    printf("5 - Densidade Populacional (menor vence)\n");
}
    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }


// Função para comparar um único atributo
void compararUmAtributo(Carta c1, Carta c2, int atributo) {
    int resultado = 0;

    switch (atributo) {
        case 1: // População
            resultado = (c1.populacao > c2.populacao) ? 1 :
                        (c1.populacao < c2.populacao) ? 2 : 0;
            break;

        case 2: // Área
            resultado = (c1.area > c2.area) ? 1 :
                        (c1.area < c2.area) ? 2 : 0;
            break;

        case 3: // PIB
            resultado = (c1.pib > c2.pib) ? 1 :
                        (c1.pib < c2.pib) ? 2 : 0;
            break;

        case 4: // Pontos Turísticos
            resultado = (c1.pontosTuristicos > c2.pontosTuristicos) ? 1 :
                        (c1.pontosTuristicos < c2.pontosTuristicos) ? 2 : 0;
            break;

        case 5: // Densidade (menor vence)
            resultado = (c1.densidadePopulacional < c2.densidadePopulacional) ? 1 :
                        (c1.densidadePopulacional > c2.densidadePopulacional) ? 2 : 0;
            break;

        default:
            printf("Atributo inválido!\n");
            break;

            return;
    }

    printf("\n### Resultado da Comparação ###\n");
    if (resultado == 1)
        printf("A cidade vencedora é: %s\n", c1.nome);
    else if (resultado == 2)
        printf("A cidade vencedora é: %s\n", c2.nome);
    else
        printf("Empate!\n");
}


// Função para comparar dois atributos escolhidos
void compararDoisAtributos(Carta c1, Carta c2, int atributo1, int atributo2) {
    int resultado1 = 0, resultado2 = 0;

    // Função simulada para cada atributo
    for (int i = 0; i < 2; i++) {
        int attr = (i == 0) ? atributo1 : atributo2;
        int r = 0;

        switch (attr) {
            case 1: // População
                r = (c1.populacao > c2.populacao) ? 1 :
                    (c1.populacao < c2.populacao) ? 2 : 0;
                break;

            case 2: // Área
                r = (c1.area > c2.area) ? 1 :
                    (c1.area < c2.area) ? 2 : 0;
                break;

            case 3: // PIB
                r = (c1.pib > c2.pib) ? 1 :
                    (c1.pib < c2.pib) ? 2 : 0;
                break;

            case 4: // Pontos Turísticos
                r = (c1.pontosTuristicos > c2.pontosTuristicos) ? 1 :
                    (c1.pontosTuristicos < c2.pontosTuristicos) ? 2 : 0;
                break;

            case 5: // Densidade (menor vence)
                r = (c1.densidadePopulacional < c2.densidadePopulacional) ? 1 :
                    (c1.densidadePopulacional > c2.densidadePopulacional) ? 2 : 0;
                break;

            default:
                printf("Atributo inválido!\n");
                return;
        }

        if (i == 0) resultado1 = r;
        else resultado2 = r;
    }
     // Exibição dos Resultados:
     // Após realizar as comparações, exiba os resultados para o usuário.
     // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.
    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    // Lógica de decisão
    printf("\n### Resultado ###\n");
    if (resultado1 == resultado2) {
        if (resultado1 == 1)
            printf("A cidade vencedora é: %s (venceu nos dois critérios)\n", c1.nome);
        else if (resultado1 == 2)
            printf("A cidade vencedora é: %s (venceu nos dois critérios)\n", c2.nome);
        else
            printf("Empate total!\n");
    } else {
        if (resultado1 == 0) // Atributo 1 empatado
            printf("Critério 1 empatado, critério 2 decidiu!\n");
        else if (resultado2 == 0) // Atributo 2 empatado
            printf("Critério 2 empatado, critério 1 decidiu!\n");

        int vencedor = (resultado1 != 0) ? resultado1 : resultado2;
        (vencedor == 1) ? printf("A cidade vencedora é: %s\n", c1.nome) :
        (vencedor == 2) ? printf("A cidade vencedora é: %s\n", c2.nome) :
        printf("Empate!\n");
    }
}

int main() {

    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    Carta carta1, carta2;

    printf("### Cadastro de Cartas Super Trunfo - Países ###\n");

    // Cadastro carta 1
    printf("\n### Carta 1 ###\n");
    printf("Estado (UF): ");
    scanf("%s", carta1.estado);
    printf("Código da carta (ex: A01): ");
    scanf("%s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nome);
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    carta1.densidadePopulacional = carta1.populacao / carta1.area;

    // Cadastro carta 2
    printf("\n### Carta 2 ###\n");
    printf("Estado (UF): ");
    scanf("%s", carta2.estado);
    printf("Código da carta (ex: B02): ");
    scanf("%s", carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nome);
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    carta2.densidadePopulacional = carta2.populacao / carta2.area;

    int opcao;
    do {
        printf("\n### Menu Principal ###\n");
        printf("1 - Exibir Cartas\n");
        printf("2 - Comparar por 1 Atributo\n");
        printf("3 - Comparar por 2 Atributos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                printf("\n--- Carta 1 ---");
                mostrarCarta(carta1);
                printf("\n--- Carta 2 ---");
                mostrarCarta(carta2);
                break;
            
            case 2: {
                int atributo;
                exibirMenuAtributos();
                printf("Escolha o atributo para comparar: ");
                scanf("%d", &atributo);
                compararUmAtributo(carta1, carta2, atributo);
                break;
            }
            case 3: {
                int atributo1, atributo2;
                exibirMenuAtributos();
                printf("Escolha o primeiro atributo: ");
                scanf("%d", &atributo1);
                exibirMenuAtributos();
                printf("Escolha o segundo atributo: ");
                scanf("%d", &atributo2);
                compararDoisAtributos(carta1, carta2, atributo1, atributo2);
                break;
            }

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
