// Problem Statement:-Undo and Redo using queue.
// Implement an undo-redo feature for a text editor.
// Use two stacks: one for storing undo operations and another for redo operations.
// Implement functions for type(char c) (to add a character), undo(), and redo().
// Example:
// Type: abc → Undo: ab → Undo: a → Redo: ab


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct
{
    char text[MAX_SIZE];
    char undoStack[MAX_SIZE][MAX_SIZE];
    char redoStack[MAX_SIZE][MAX_SIZE];
    int undoTop;
    int redoTop;
} TextEditor;

void init(TextEditor *editor)
{
    editor->text[0] = '\0';
    editor->undoTop = -1;
    editor->redoTop = -1;
}

void type(TextEditor *editor, char data)
{
    if (strlen(editor->text) < MAX_SIZE - 1)
    {
        editor->undoTop++;
        strcpy(editor->undoStack[editor->undoTop], editor->text);
        int length = strlen(editor->text);
        editor->text[length] = data;
        editor->text[length + 1] = '\0';
        editor->redoTop = -1;
    }
}

void undo(TextEditor *editor)
{
    if (editor->undoTop >= 0)
    {
        editor->redoTop++;
        strcpy(editor->redoStack[editor->redoTop], editor->text);
        strcpy(editor->text, editor->undoStack[editor->undoTop]);
        editor->undoTop--;
    }
    else
    {
        printf("Nothing to undo!\n");
    }
}

void redo(TextEditor *editor)
{
    if (editor->redoTop >= 0)
    {
        editor->undoTop++;
        strcpy(editor->undoStack[editor->undoTop], editor->text);
        strcpy(editor->text, editor->redoStack[editor->redoTop]);
        editor->redoTop--;
    }
    else
    {
        printf("Nothing to redo!\n");
    }
}

void get_text(TextEditor *editor)
{
    printf("Current text: %s\n", editor->text);
}

int main()
{
    TextEditor editor;
    init(&editor);
    char choice;
    char input;
    printf("1. Adda character\n");
    printf("2. UNDO\n");
    printf("3. REDO\n");
    printf("0. Exit\n");
    do
    {
        printf("Choose your choice\n");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            printf("Enter a character: ");
            scanf(" %c", &input);
            type(&editor, input);
            break;
        case '2':
            undo(&editor);
            break;
        case '3':
            redo(&editor);
            break;
        case '0':
            printf("Existing\n");
            break;
        default:
            printf("Enter valid choice\n");
            break;
        }

        get_text(&editor);
    } while (choice != 0);

    return 0;
}

