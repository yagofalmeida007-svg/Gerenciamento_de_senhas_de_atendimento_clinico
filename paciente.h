
#ifndef PACIENTE_H
#define PACIENTE_H

// Categorias de atendimento
#define NORMAL 0
#define PREFERENCIAL 1
#define URGENTE 2

// Estrutura do paciente
typedef struct {
    char genero;
    int idade;
    int gestante;
    int lactante;
    int necessidadeEspecial;
    int obeso;
    char senha[10];
    int categoria;
} Paciente;

// Funcoes do modulo paciente
int classificarPaciente(Paciente p);
Paciente cadastrarPaciente();

#endif
