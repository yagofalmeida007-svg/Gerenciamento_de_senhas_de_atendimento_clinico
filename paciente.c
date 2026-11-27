
#include <stdio.h>
#include "paciente.h"

int classificarPaciente(Paciente p) {
    if (p.idade > 80) {
        return URGENTE;
    }

    if (p.gestante == 1 ||
        p.lactante == 1 ||
        p.necessidadeEspecial == 1 ||
        p.obeso == 1) {
        return PREFERENCIAL;
    }

    if (p.genero == 'F' && p.idade >= 60) {
        return PREFERENCIAL;
    }

    if (p.genero == 'M' && p.idade >= 65) {
        return PREFERENCIAL;
    }

    return NORMAL;
}

int lerSimNao(char pergunta[]) {
    int resposta;

    do {
        printf("%s (1-Sim / 0-Nao): ", pergunta);
        scanf("%d", &resposta);

        if (resposta != 0 && resposta != 1) {
            printf("Resposta invalida! Digite 1 ou 0.\n");
        }

    } while (resposta != 0 && resposta != 1);

    return resposta;
}

Paciente cadastrarPaciente() {
    Paciente p;

    printf("\n===== CADASTRO DE PACIENTE =====\n");

    do {
        printf("Genero (M/F/O): ");
        scanf(" %c", &p.genero);

        if (p.genero >= 'a' && p.genero <= 'z') {
            p.genero -= 32;
        }

        if (p.genero != 'M' &&
            p.genero != 'F' &&
            p.genero != 'O') {
            printf("Genero invalido! Tente novamente.\n");
        }

    } while (p.genero != 'M' &&
             p.genero != 'F' &&
             p.genero != 'O');

    do {
        printf("Idade: ");
        scanf("%d", &p.idade);

        if (p.idade <= 0) {
            printf("Idade invalida! Digite uma idade positiva.\n");
        }

    } while (p.idade <= 0);

    p.gestante = 0;
    p.lactante = 0;

    if (p.genero == 'F') {
        p.gestante = lerSimNao("Esta gestante?");
        p.lactante = lerSimNao("E lactante?");
    }

    p.necessidadeEspecial =
        lerSimNao("Possui necessidade especial?");

    p.obeso =
        lerSimNao("Possui condicao de obesidade?");

    p.categoria = classificarPaciente(p);

    return p;
}
