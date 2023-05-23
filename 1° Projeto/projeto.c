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
void updateUser();
void deleteUser();
void getUser();

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
    printf("2 - Atualizar dados de um usuário\n");
    printf("3 - Deletar um usuário\n");
    printf("4 - Buscar um usuário\n");
    printf("Informe sua ação : ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        createUser();
        break;
    case 2:
        updateUser();
        break;
    case 3:
        deleteUser();
        break;
    case 4:
        getUser();
        break;
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
        printf("O usuário é vacinado? (1) Sim, (0) Não: ");
        scanf("%d", &vacines[numberOfUsers]);

        if (vacines[numberOfUsers] == 1 || vacines[numberOfUsers] == 0)
        {
            break;
        }

        printf("Opção inválida. Por favor, informe 1 para 'Sim' ou 0 para 'Não'.\n");
    }

    printf("Usuário adicionado com sucesso!\n\n");
    printf("O ID do usuário criado foi : %d", ids[numberOfUsers]);

    numberOfUsers++;

    printf("\n\nRetornando para o menu...\n\n");
    sleep(5);
    menu();
}

void updateUser()
{
    if (numberOfUsers == 0)
    {
        printf("\nNão há usuários para atualizar.\n");
        printf("Retornando para o menu...\n\n");
        sleep(5);
        menu();
    }

    printf("---------------------------\n");
    printf("    ATUALIZAÇÃO DE USUÁRIO  \n");
    printf("---------------------------\n\n");

    int id;
    bool found = false;
    int index;

    printf("Informe o ID do usuário que deseja atualizar: ");
    scanf("%d", &id);

    for (int i = 0; i < numberOfUsers; i++)
    {
        if (ids[i] == id)
        {
            found = true;
            index = i;
            break;
        }
    }

    if (!found)
    {
        printf("Usuário com ID %d não encontrado.\n", id);
        printf("Retornando para o menu...\n\n");
        sleep(5);
        menu();
    }

    int option;

    printf("\nEscolha o campo que deseja atualizar:\n\n");
    printf("1 - Nome\n");
    printf("Nome atual : %s\n", names[index]);
    printf("2 - Email\n");
    printf("Email atual : %s\n", emails[index]);
    printf("3 - Sexo\n");
    printf("Sexo atual : %s\n", gender[index]);
    printf("4 - Altura\n");
    printf("Altura atual : %.2lf\n", heigth[index]);
    printf("5 - Vacinado\n");
    printf("Vacinado atual : %d\n", vacines[index]);
    printf("Informe sua escolha: ");
    scanf("%d", &option);

    getchar();

    switch (option)
    {
    case 1:
    {
        printf("Informe o novo nome do usuário: ");
        fgets(names[index], NAME_LENGTH, stdin);
        break;
    }
    case 2:
    {
        while (true)
        {
            printf("Informe o novo email do usuário: ");
            fgets(emails[index], EMAIL_LENGTH, stdin);

            emails[index][strcspn(emails[index], "\n")] = '\0';

            if (strchr(emails[index], '@') != NULL)
            {
                break;
            }

            printf("Email inválido. O email informado não contém o caractere '@'.\n");
        }
        break;
    }
    case 3:
    {
        while (true)
        {
            printf("Informe o novo sexo do usuário (Feminino, Masculino, Indiferente): ");
            fgets(gender[index], GENDER_LENGTH, stdin);

            gender[index][strcspn(gender[index], "\n")] = '\0';

            if (strcmp(gender[index], "Feminino") == 0 || strcmp(gender[index], "Masculino") == 0 || strcmp(gender[index], "Indiferente") == 0)
            {
                break;
            }

            printf("Sexo inválido. Por favor, informe 'Feminino', 'Masculino' ou 'Indiferente'.\n");
        }
        break;
    }
    case 4:
    {
        while (true)
        {
            printf("Informe a nova altura do usuário (entre 1 e 2 metros): ");
            scanf("%lf", &heigth[index]);

            if (heigth[index] >= 1.0 && heigth[index] <= 2.0)
            {
                break;
            }

            printf("Altura inválida. Por favor, informe um valor entre 1 e 2 metros.\n");
        }
        break;
    }
    case 5:
    {
        while (true)
        {
            printf("Informe se o usuário foi vacinado (1) Sim, (0) Não: ");
            scanf("%d", &vacines[index]);

            if (vacines[index] == 1 || vacines[index] == 0)
            {
                break;
            }

            printf("Opção inválida. Por favor, informe 1 para 'Sim' ou 0 para 'Não'.\n");
        }
        break;
    }
    default:
        printf("Opção inválida. Retornando para o menu...\n\n");
        sleep(5);
        menu();
        break;
    }

    printf("Usuário atualizado com sucesso!\n");
    printf("Retornando para o menu...\n\n");
    sleep(5);
    menu();
}

void deleteUser()
{
    if (numberOfUsers == 0)
    {
        printf("\nNão há usuários para deletar.\n");
        printf("Retornando para o menu...\n\n");
        sleep(5);
        menu();
    }

    printf("---------------------------\n");
    printf("      DELETAR USUÁRIO       \n");
    printf("---------------------------\n\n");

    int id;
    bool found = false;
    int index;

    printf("Informe o ID do usuário que deseja deletar: ");
    scanf("%d", &id);

    for (int i = 0; i < numberOfUsers; i++)
    {
        if (ids[i] == id)
        {
            found = true;
            index = i;
            break;
        }
    }

    if (!found)
    {
        printf("Usuário com ID %d não encontrado.\n", id);
        printf("Retornando para o menu...\n\n");
        sleep(5);
        menu();
    }

    for (int i = index; i < numberOfUsers - 1; i++)
    {
        ids[i] = ids[i + 1];
        strcpy(names[i], names[i + 1]);
        strcpy(emails[i], emails[i + 1]);
        strcpy(gender[i], gender[i + 1]);
        strcpy(andress[i], andress[i + 1]);
        heigth[i] = heigth[i + 1];
        vacines[i] = vacines[i + 1];
    }

    numberOfUsers--;

    printf("Usuário deletado com sucesso!\n");
    printf("Retornando para o menu...\n\n");
    sleep(5);
    menu();
}

void getUser()
{
    if (numberOfUsers == 0)
    {
        printf("\nNão há usuários cadastrados.\n");
        printf("Retornando para o menu...\n\n");
        sleep(5);
        menu();
    }

    printf("---------------------------\n");
    printf("     BUSCAR USUÁRIO POR EMAIL    \n");
    printf("---------------------------\n\n");

    char searchEmail[EMAIL_LENGTH];
    bool found = false;
    int index;

    printf("Informe o email do usuário que deseja buscar: ");
    getchar();
    fgets(searchEmail, EMAIL_LENGTH, stdin);
    searchEmail[strcspn(searchEmail, "\n")] = '\0';

    for (int i = 0; i < numberOfUsers; i++)
    {
        if (strcmp(emails[i], searchEmail) == 0)
        {
            found = true;
            index = i;
            break;
        }
    }

    if (!found)
    {
        printf("Usuário com o email '%s' não encontrado.\n", searchEmail);
    }
    else
    {
        printf("\nUsuário encontrado:\n");
        printf("ID: %d\n", ids[index]);
        printf("Nome: %s\n", names[index]);
        printf("Email: %s\n", emails[index]);
        printf("Sexo: %s\n", gender[index]);
        printf("Altura: %.2lf\n", heigth[index]);
        printf("Vacinado: %s\n", vacines[index] ? "Sim" : "Não");
    }

    printf("\nRetornando para o menu...\n\n");
    sleep(5);
    menu();
}

