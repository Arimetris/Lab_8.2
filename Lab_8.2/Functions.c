#include "Header.h"

void del_Node(struct Node** head, int len)
{
    struct Node *current = *head;
    while (current != NULL)
    {
        int i = 0;
        if (len == current->count)
        {
            // Обработка последнего узла
            if (current->next == NULL && current->prev != NULL)
                current->prev->next = NULL;

            // Обработка первого узла
            else if (current->prev == NULL && current->next != NULL)
            {
                current->next->prev = NULL;
                *head = current->next;
            }
            // Обработка среднего узла (Склеиваем узлы вокруг удаляемого узла)
            else if (current->prev != NULL && current->next != NULL)
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            // Обработка единственного узла
            else
            {
                free(*head);
                *head = NULL;
                return;
            }

            struct Node* tmp = current;
            current = current->next;
            free(tmp);
            i++;
        }
        // Если было удаление, то нжно проверить сдвинутый узел
        if (i == 0)
            current = current->next;
    }
}
int Len_longest_word(struct Node* current)
{
    int len = current->count;

    while (current != NULL)
    {
        if (len < current->count)
            len = current->count;
        current = current->next;
    }
    printf("Самая большая строка длинны: %d\n", len);
    return len;
}
struct Node* get_list(char* input)
{
    // Указатель на пробел в строке
    char *token = strtok(input, " ");
    struct Node *head = NULL, *previous = NULL;
    
    while (token != NULL)
    {
        struct Node *current = (struct Node*)malloc(sizeof(struct Node));
        if (current == NULL)
            exit(1);

        // Записываем данные в структуру
        strncpy(current->word, token, SIZE - 1);
        current->count = strlen(current->word);

        current->next = NULL;
        current->prev = NULL;

        if (head == NULL)
            head = current;
        
        // Дважды связываем
        else
        {
            previous->next = current;
            current->prev = previous;
        }
        previous = current;
        token = strtok(NULL, " ");
    }
    return head;
}
void put_list(struct Node* current)
{
    while (current != NULL)
    {
        printf("(%d) ", current->count);
        printf("%s\n", current->word);
        current = current->next;
    }
}
void clear_list(struct Node** head)
{
    struct Node* current = *head;
    struct Node* next_node;

    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head = NULL;
}