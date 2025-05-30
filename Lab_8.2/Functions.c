#include "Header.h"

void del_Node(struct Node** head, int len)
{
    struct Node *current = *head;
    while (current != NULL)
    {
        int i = 0;
        if (len == current->count)
        {
            // ��ࠡ�⪠ ��᫥����� 㧫�
            if (current->next == NULL && current->prev != NULL)
                current->prev->next = NULL;

            // ��ࠡ�⪠ ��ࢮ�� 㧫�
            else if (current->prev == NULL && current->next != NULL)
            {
                current->next->prev = NULL;
                *head = current->next;
            }
            // ��ࠡ�⪠ �।���� 㧫� (��������� 㧫� ����� 㤠�塞��� 㧫�)
            else if (current->prev != NULL && current->next != NULL)
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            // ��ࠡ�⪠ �����⢥����� 㧫�
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
        // �᫨ �뫮 㤠�����, � ���� �஢���� ᤢ����� 㧥�
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
    printf("����� ������ ��ப� ������: %d\n", len);
    return len;
}
struct Node* get_list(char* input)
{
    // �����⥫� �� �஡�� � ��ப�
    char *token = strtok(input, " ");
    struct Node *head = NULL, *previous = NULL;
    
    while (token != NULL)
    {
        struct Node *current = (struct Node*)malloc(sizeof(struct Node));
        if (current == NULL)
            exit(1);

        // �����뢠�� ����� � ��������
        strncpy(current->word, token, SIZE - 1);
        current->count = strlen(current->word);

        current->next = NULL;
        current->prev = NULL;

        if (head == NULL)
            head = current;
        
        // ������ ��뢠��
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