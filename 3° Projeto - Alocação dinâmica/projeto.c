#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Feito por : Lucas Peixoto Chaves
// Link do repositório no GitHub do projeto : https://github.com/lucaspeixotochv/Algoritmo-e-Programacao-Estruturada/

struct User
{
    int id;
    char name[50];
    char email[50];
    struct User *next;
};

typedef struct User User;

User *createUser(int id, const char *name, const char *email)
{
    User *newUser = (User *)malloc(sizeof(User));
    if (newUser != NULL)
    {
        newUser->id = id;
        strcpy(newUser->name, name);
        strcpy(newUser->email, email);
        newUser->next = NULL;
    }
    return newUser;
}

int generateId()
{
    srand(time(NULL));
    return rand();
}

void addUser(User **list, User *newUser)
{
    if (*list == NULL)
    {
        *list = newUser;
    }
    else
    {
        User *last = *list;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newUser;
    }
}

void listUsers(User *list)
{
    if (list == NULL)
    {
        printf("A lista de usuários está vazia.\n");
    }
    else
    {
        User *current = list;
        while (current != NULL)
        {
            printf("ID: %d\nNome: %s\nEmail: %s\n\n", current->id, current->name, current->email);
            current = current->next;
        }
    }
}

User *findUser(User *list, int id)
{
    User *current = list;
    while (current != NULL)
    {
        if (current->id == id)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void updateUser(User *user, const char *newName, const char *newEmail)
{
    strcpy(user->name, newName);
    strcpy(user->email, newEmail);
}

void removeUser(User **list, int id)
{
    User *current = *list;
    User *previous = NULL;

    while (current != NULL)
    {
        if (current->id == id)
        {
            if (previous == NULL)
            {
                *list = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void freeUsers(User *list)
{
    User *current = list;
    while (current != NULL)
    {
        User *next = current->next;
        free(current);
        current = next;
    }
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int getMenuOption()
{
    int option;
    printf("Selecione uma opção:\n");
    printf("1. Adicionar usuário\n");
    printf("2. Listar usuários\n");
    printf("3. Buscar usuário\n");
    printf("4. Atualizar usuário\n");
    printf("5. Remover usuário\n");
    printf("6. Sair\n");
    printf("Opção: ");
    scanf("%d", &option);
    printf("\n");
    clearInputBuffer();
    return option;
}

int main()
{
    User *list = NULL;
    int option;

    do
    {
        option = getMenuOption();
        switch (option)
        {
        case 1:
        {
            int id;
            char name[50];
            char email[50];

            id = generateId();

            printf("Digite o nome do usuário: ");
            fgets(name, 50, stdin);
            name[strcspn(name, "\n")] = '\0';

            printf("Digite o email do usuário: ");
            fgets(email, 50, stdin);
            email[strcspn(email, "\n")] = '\0';

            User *newUser = createUser(id, name, email);
            addUser(&list, newUser);
            printf("Usuário adicionado com sucesso.\n\n");
            break;
        }
        case 2:
            listUsers(list);
            break;
        case 3:
        {
            int id;
            printf("Digite o ID do usuário a ser buscado: ");
            scanf("%d", &id);
            clearInputBuffer();

            User *foundUser = findUser(list, id);
            if (foundUser != NULL)
            {
                printf("Usuário encontrado:\n");
                printf("ID: %d\nNome: %s\nEmail: %s\n\n", foundUser->id, foundUser->name, foundUser->email);
            }
            else
            {
                printf("Usuário não encontrado.\n\n");
            }
            break;
        }
        case 4:
        {
            int id;
            char newName[50];
            char newEmail[50];

            printf("Digite o ID do usuário a ser atualizado: ");
            scanf("%d", &id);
            clearInputBuffer();

            User *foundUser = findUser(list, id);
            if (foundUser != NULL)
            {
                printf("Digite o novo nome do usuário: ");
                fgets(newName, 50, stdin);
                newName[strcspn(newName, "\n")] = '\0';

                printf("Digite o novo email do usuário: ");
                fgets(newEmail, 50, stdin);
                newEmail[strcspn(newEmail, "\n")] = '\0';

                updateUser(foundUser, newName, newEmail);
                printf("Usuário atualizado com sucesso.\n\n");
            }
            else
            {
                printf("Usuário não encontrado.\n\n");
            }
            break;
        }
        case 5:
        {
            int id;
            printf("Digite o ID do usuário a ser removido: ");
            scanf("%d", &id);
            clearInputBuffer();

            removeUser(&list, id);
            printf("Usuário removido com sucesso.\n\n");
            break;
        }
        case 6:
            freeUsers(list);
            break;
        default:
            printf("Opção inválida. Tente novamente.\n\n");
            break;
        }
    } while (option != 6);

    printf("Programa encerrado.\n");

    return 0;
}
