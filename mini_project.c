#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact
{
    char name[20];
    int phone;
};

// Function to dynamically add contacts
void addContact(struct contact **list, int *size, int *capacity)
{
    if (*size >= *capacity)
    {
        *capacity = (*capacity == 0) ? 2 : (*capacity * 2);
        *list = realloc(*list, *capacity * sizeof(struct contact));
    }

    printf("Enter name: ");
    scanf("%s", (*list)[*size].name);

    printf("Enter phone: ");
    scanf("%d", &(*list)[*size].phone);

    (*size)++;
    printf("Contact added successfully!\n");
}

// Function to display all contacts
void displayContacts(struct contact *list, int size)
{
    if (size == 0)
    {
        printf("No contacts available.\n");
        return;
    }

    printf("\nContact List:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s - %d\n", list[i].name, list[i].phone);
    }
}

// Function to search for a contact by name
void searchContact(struct contact *list, int size)
{
    char searchName[20];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < size; i++)
    {
        if (strcmp(list[i].name, searchName) == 0)
        {
            printf("Contact found: %s - %d\n", list[i].name, list[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

// Function to delete a contact by name
void deleteContact(struct contact **list, int *size)
{
    char deleteName[20];
    printf("Enter name to delete: ");
    scanf("%s", deleteName);

    for (int i = 0; i < *size; i++)
    {
        if (strcmp((*list)[i].name, deleteName) == 0)
        {
            for (int j = i; j < *size - 1; j++)
            {
                (*list)[j] = (*list)[j + 1];
            }
            (*size)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

int main()
{
    struct contact *list = NULL;
    int size = 0, capacity = 0;
    int choice, choice1;

    do
    {
        printf("\nContact List Application\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addContact(&list, &size, &capacity);
            break;
        case 2:
            deleteContact(&list, &size);
            break;
        case 3:
            searchContact(list, size);
            break;
        case 4:
            displayContacts(list, size);
            break;
        case 5:
            printf("Exiting...\n");
            free(list);
            return 0;
        default:
            printf("Invalid choice!\n");
        }

        printf("Do you want to continue? (yes=1/no=2): ");
        scanf("%d", &choice1);
    } while (choice1 == 1);

    free(list);
    return 0;
}