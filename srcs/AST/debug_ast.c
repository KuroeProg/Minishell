#include <stdio.h>
#include "../inc/minishell.h"

/*
** This code is not mine, it's just here for the debug.
*/
void print_ast(t_AST *node, int level) {
    if (!node) return;
    for (int i = 0; i < level; i++) printf("  ");
    
    switch (node->type) {
        case NODE_COMMAND:
            printf("Commande: ");
            for (int i = 0; node->argv[i] != NULL; i++)
                printf("%s ", node->argv[i]);
            printf("\n");
            break;
        case NODE_PIPE:
            printf("Opérateur: |\n");
            break;
        case NODE_AND:
            printf("Opérateur: &&\n");
            break;
        case NODE_OR:
            printf("Opérateur: ||\n");
            break;
        case NODE_REDIR_IN:
            printf("Redirection: < %s\n", node->filename);
            break;
        case NODE_REDIR_OUT:
            printf("Redirection: > %s\n", node->filename);
            break;
        case NODE_REDIR_APPEND:
            printf("Redirection: >> %s\n", node->filename);
            break;
    }
    
    print_ast(node->left, level + 1);
    print_ast(node->right, level + 1);
}
