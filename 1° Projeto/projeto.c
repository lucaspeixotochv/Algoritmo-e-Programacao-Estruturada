#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>

#define MAX_USUARIOS 1000
#define NAME_LENGTH 70
#define EMAIL_LENGTH 80
#define GENDER_LENGTH 15
#define ADRESS_LENGTH 100

int ids[MAX_USUARIOS];
char names[MAX_USUARIOS][NAME_LENGTH];
char emails[MAX_USUARIOS][EMAIL_LENGTH];
char gender[MAX_USUARIOS][GENDER_LENGTH];
char andress[MAX_USUARIOS][ADRESS_LENGTH];
double heigth[MAX_USUARIOS];
int vacines[MAX_USUARIOS];
int numberOfUsers = 0;

void menu();
int generateId();
void createUser();

int main()
{
    setlocale(LC_ALL, "UTF-8");

    menu();

    return 0;
}

void menu()
{
    int option;

    printf("---------------------------\n");
    printf("            MENU           \n");
    printf("---------------------------\n\n");

    printf("1 - Criar usuário\n");
    printf("2 - Buscar um usuário\n");
    printf("3 - Deletar um usuário\n");
    printf("4 - Atualizar dados de um usuário\n");
    printf("Informe sua ação : ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        createUser();
        break;
    // case 2:
    //     updateUser();
    //     break;
    // case 3:
    //     deleteUser();
    //     break;
    // case 4:
    //     getUser();
    //     break;
    default:
        printf("---------------------------\n");
        printf("         AÇÃO INVÁLIDA     \n");
        printf("---------------------------\n\n");
        printf("Retornando para o menu...\n\n");
        sleep(5);
        menu();
        break;
    }
}

int generateId()
{
    srand(time(NULL));
    return rand();
}

void createUser()
{
    if (numberOfUsers >= MAX_USUARIOS)
    {
        printf("\nLimite de usuários alcançado.\n");
        printf("Retornando para o menu...\n\n");
        sleep(5);
        menu();
    }

    printf("---------------------------\n");
    printf("     CRIAÇÃO DE USUÁRIO    \n");
    printf("---------------------------\n\n");

    ids[numberOfUsers] = generateId();

    printf("Informe o nome do usuário: ");
    getchar();
    fgets(names[numberOfUsers], NAME_LENGTH, stdin);

    while (true)
    {
        printf("Informe o email do usuário: ");
        fgets(emails[numberOfUsers], EMAIL_LENGTH, stdin);

        emails[numberOfUsers][strcspn(emails[numberOfUsers], "\n")] = '\0';

        if (strchr(emails[numberOfUsers], '@') != NULL)
        {
            break;
        }

        printf("Email inválido. O email informado não contém o caractere '@'.\n");
    }

    while (true)
    {
        printf("Informe o sexo do usuário (Feminino, Masculino, Indiferente): ");
        fgets(gender[numberOfUsers], GENDER_LENGTH, stdin);

        gender[numberOfUsers][strcspn(gender[numberOfUsers], "\n")] = '\0';

        if (strcmp(gender[numberOfUsers], "Feminino") == 0 || strcmp(gender[numberOfUsers], "Masculino") == 0 || strcmp(gender[numberOfUsers], "Indiferente") == 0)
        {
            break;
        }

        printf("Sexo inválido. Por favor, informe 'Feminino', 'Masculino' ou 'Indiferente'.\n");
    }

    while (true)
    {
        printf("Informe a altura do usuário (entre 1 e 2 metros): ");
        scanf("%lf", &heigth[numberOfUsers]);

        if (heigth[numberOfUsers] >= 1.0 && heigth[numberOfUsers] <= 2.0)
        {
            break;
        }

        printf("Altura inválida. Por favor, informe um valor entre 1 e 2 metros.\n");
    }

    while (true)
    {
        printf("O usuário é vacinado? (1) Sim, (2) Não: ");
        scanf("%d", &vacines[numberOfUsers]);

        if (vacines[numberOfUsers] == 1 || vacines[numberOfUsers] == 0)
        {
            break;
        }

        printf("Opção inválida. Por favor, informe 1 para 'Sim' ou 0 para 'Não'.\n");
    }

    printf("Usuário adicionado com sucesso!\n");
    numberOfUsers++;

    printf("Retornando para o menu...\n\n");
    sleep(5);
    menu();
}