#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_USUARIOS 1000
#define NAME_LENGTH 70
#define EMAIL_LENGTH 80
#define GENDER_LENGTH 15
#define ADRESS_LENGTH 100

typedef struct
{
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
    char gender[GENDER_LENGTH];
    char address[ADRESS_LENGTH];
    double height;
    int vaccines;
} User;

typedef struct
{
    User users[MAX_USUARIOS];
    int numberOfUsers;
} BackupData;

BackupData backupData;
User users[MAX_USUARIOS];

int numberOfUsers = 0;

void menu();
int generateId();
void createUser();
void updateUser();
void deleteUser();
void getUser();
// void getAllUsers();
// void backup();
// void restore();

int main()
{
    menu();
    return 0;
}

void menu()
{
    char option;

    printf("---------------------------\n");
    printf("            MENU           \n");
    printf("---------------------------\n\n");

    printf("(a) - Criar usuário\n");
    printf("(b) - Atualizar dados de um usuário\n");
    printf("(c) - Deletar um usuário\n");
    printf("(d) - Buscar um usuário\n");
    printf("(e) - Mostrar todos os usuários\n");
    printf("(f) - Fazer backup\n");
    printf("(g) - Fazer Restauração dos dados\n");
    printf("Informe sua ação : ");
    scanf(" %c", &option);

    option = tolower(option);

    switch (option)
    {
    case 'a':
        createUser();
        break;
    case 'b':
        updateUser();
        break;
    case 'c':
        deleteUser();
        break;
    case 'd':
        getUser();
        break;
    // case 'e':
    //     getAllUsers();
    //     break;
    // case 'f':
    //     backup();
    //     break;
    // case 'g':
    //     restore();
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

    users[numberOfUsers].id = generateId();

    printf("Informe o nome do usuário: ");
    getchar();
    fgets(users[numberOfUsers].name, NAME_LENGTH, stdin);

    while (true)
    {
        printf("Informe o email do usuário: ");
        fgets(users[numberOfUsers].email, EMAIL_LENGTH, stdin);

        users[numberOfUsers].email[strcspn(users[numberOfUsers].email, "\n")] = '\0';

        if (strchr(users[numberOfUsers].email, '@') != NULL)
        {
            break;
        }

        printf("Email inválido. O email informado não contém o caractere '@'.\n");
    }

    while (true)
    {
        printf("Informe o sexo do usuário (Feminino, Masculino, Indiferente): ");
        fgets(users[numberOfUsers].gender, GENDER_LENGTH, stdin);

        users[numberOfUsers].gender[strcspn(users[numberOfUsers].gender, "\n")] = '\0';

        if (strcmp(users[numberOfUsers].gender, "Feminino") == 0 || strcmp(users[numberOfUsers].gender, "Masculino") == 0 || strcmp(users[numberOfUsers].gender, "Indiferente") == 0)
        {
            break;
        }

        printf("Sexo inválido. Por favor, informe 'Feminino', 'Masculino' ou 'Indiferente'.\n");
    }

    while (true)
    {
        printf("Informe a altura do usuário (entre 1 e 2 metros): ");
        scanf("%lf", &users[numberOfUsers].height);

        if (users[numberOfUsers].height >= 1.0 && users[numberOfUsers].height <= 2.0)
        {
            break;
        }

        printf("Altura inválida. Por favor, informe um valor entre 1 e 2 metros.\n");
    }

    while (true)
    {
        printf("O usuário é vacinado? (1) Sim, (0) Não: ");
        scanf("%d", &users[numberOfUsers].vaccines);

        if (users[numberOfUsers].vaccines == 1 || users[numberOfUsers].vaccines == 0)
        {
            break;
        }

        printf("Opção inválida. Por favor, informe 1 para 'Sim' ou 0 para 'Não'.\n");
    }

    printf("Usuário adicionado com sucesso!\n\n");
    printf("O ID do usuário criado foi : %d", users[numberOfUsers].id);

    numberOfUsers++;

    printf("\n\nRetornando para o menu...\n\n");
    sleep(5);
    menu();
}

void updateUser()
{
    int userId;
    bool userFound = false;

    printf("---------------------------\n");
    printf("   ATUALIZAÇÃO DE USUÁRIO   \n");
    printf("---------------------------\n\n");

    printf("Informe o ID do usuário que deseja atualizar: ");
    scanf("%d", &userId);

    for (int i = 0; i < numberOfUsers; i++)
    {
        if (users[i].id == userId)
        {
            userFound = true;

            printf("\nUsuário encontrado!\n\n");
            printf("ID do usuário: %d\n", users[i].id);
            printf("Nome atual: %s\n", users[i].name);
            printf("Email atual: %s\n", users[i].email);
            printf("Sexo atual: %s\n", users[i].gender);
            printf("Altura atual: %.2lf\n", users[i].height);
            printf("Status de vacinação atual: %s\n", users[i].vaccines == 1 ? "Sim" : "Não");

            printf("\nAtualize os dados do usuário:\n");

            printf("Novo nome: ");
            getchar();
            fgets(users[i].name, NAME_LENGTH, stdin);

            while (true)
            {
                printf("Novo email: ");
                fgets(users[i].email, EMAIL_LENGTH, stdin);

                users[i].email[strcspn(users[i].email, "\n")] = '\0';

                if (strchr(users[i].email, '@') != NULL)
                {
                    break;
                }

                printf("Email inválido. O email informado não contém o caractere '@'.\n");
            }

            while (true)
            {
                printf("Novo sexo (Feminino, Masculino, Indiferente): ");
                fgets(users[i].gender, GENDER_LENGTH, stdin);

                users[i].gender[strcspn(users[i].gender, "\n")] = '\0';

                if (strcmp(users[i].gender, "Feminino") == 0 || strcmp(users[i].gender, "Masculino") == 0 || strcmp(users[i].gender, "Indiferente") == 0)
                {
                    break;
                }

                printf("Sexo inválido. Por favor, informe 'Feminino', 'Masculino' ou 'Indiferente'.\n");
            }

            while (true)
            {
                printf("Nova altura (entre 1 e 2 metros): ");
                scanf("%lf", &users[i].height);

                if (users[i].height >= 1.0 && users[i].height <= 2.0)
                {
                    break;
                }

                printf("Altura inválida. Por favor, informe um valor entre 1 e 2 metros.\n");
            }

            while (true)
            {
                printf("Novo status de vacinação (1) Sim, (0) Não: ");
                scanf("%d", &users[i].vaccines);

                if (users[i].vaccines == 1 || users[i].vaccines == 0)
                {
                    break;
                }

                printf("Opção inválida. Por favor, informe 1 para 'Sim' ou 0 para 'Não'.\n");
            }

            printf("\nDados do usuário atualizados com sucesso!\n");
            break;
        }
    }

    if (!userFound)
    {
        printf("Usuário com ID %d não encontrado.\n", userId);
    }

    printf("\nRetornando para o menu...\n\n");
    sleep(5);
    menu();
}

void deleteUser()
{
    int userId;
    bool userFound = false;

    printf("---------------------------\n");
    printf("      DELETAR USUÁRIO       \n");
    printf("---------------------------\n\n");

    printf("Informe o ID do usuário que deseja deletar: ");
    scanf("%d", &userId);

    for (int i = 0; i < numberOfUsers; i++)
    {
        if (users[i].id == userId)
        {
            userFound = true;

            printf("\nUsuário encontrado!\n\n");
            printf("ID do usuário: %d\n", users[i].id);
            printf("Nome: %s\n", users[i].name);
            printf("Email: %s\n", users[i].email);
            printf("Sexo: %s\n", users[i].gender);
            printf("Altura: %.2lf\n", users[i].height);
            printf("Status de vacinação: %s\n", users[i].vaccines == 1 ? "Sim" : "Não");

            printf("\nTem certeza de que deseja deletar esse usuário? (s/n): ");
            char confirmation;
            scanf(" %c", &confirmation);

            if (tolower(confirmation) == 's')
            {
                for (int j = i; j < numberOfUsers - 1; j++)
                {
                    users[j] = users[j + 1];
                }

                numberOfUsers--;
                printf("Usuário deletado com sucesso!\n");
            }
            else
            {
                printf("Ação de exclusão cancelada.\n");
            }

            break;
        }
    }

    if (!userFound)
    {
        printf("Usuário com ID %d não encontrado.\n", userId);
    }

    printf("\nRetornando para o menu...\n\n");
    sleep(5);
    menu();
}

void getUser()
{
    char userEmail[EMAIL_LENGTH];
    bool userFound = false;

    printf("---------------------------\n");
    printf("    BUSCAR USUÁRIO POR EMAIL \n");
    printf("---------------------------\n\n");

    printf("Informe o email do usuário que deseja buscar: ");
    getchar();
    fgets(userEmail, EMAIL_LENGTH, stdin);

    userEmail[strcspn(userEmail, "\n")] = '\0';

    for (int i = 0; i < numberOfUsers; i++)
    {
        if (strcmp(users[i].email, userEmail) == 0)
        {
            userFound = true;

            printf("\nUsuário encontrado!\n\n");
            printf("ID do usuário: %d\n", users[i].id);
            printf("Nome: %s\n", users[i].name);
            printf("Email: %s\n", users[i].email);
            printf("Sexo: %s\n", users[i].gender);
            printf("Altura: %.2lf\n", users[i].height);
            printf("Status de vacinação: %s\n", users[i].vaccines == 1 ? "Sim" : "Não");

            break;
        }
    }

    if (!userFound)
    {
        printf("Usuário com o email '%s' não encontrado.\n", userEmail);
    }

    printf("\nRetornando para o menu...\n\n");
    sleep(5);
    menu();
}