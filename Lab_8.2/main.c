#include "Header.h"
// ��ਠ�� 20
// ������ �� ���窨 �� ᠬ� ������ ᫮��
int main(void)
{
    struct Node* head = NULL;
    char input[SIZE], ch;
    int i = 0;
    setlocale(LC_ALL, "rus");
    fputs("������ ��ப� (������ '.' ��� '\\n' ��� �����襭�� �����): ", stdout);

    while ((ch = getchar()) != EOF && ch != '\n')
    {
        if (ch == '.')
            break;
        input[i++] = ch;
    }
    input[i] = '\0';

    if (strlen(input) == 0)
    {
        puts("������� ����� ��ப�");
        return 0;
    }

    head = get_list(input);    
    put_list(head);
    
    del_Node(&head, Len_longest_word(head));

    put_list(head);
    clear_list(&head);
    return 0;
}
