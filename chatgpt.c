/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:21:35 by nteechar          #+#    #+#             */
/*   Updated: 2024/07/24 16:50:20 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_COUNT 64

void sigint_handler(int sig) {
    // Handle Ctrl+C
    printf("\nmini-shell: use 'exit' to quit\n");
    printf("mini-shell> ");
    fflush(stdout);
}

void execute_command(char **args) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("mini-shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Forking error
        perror("mini-shell");
    } else {
        // Parent process
        wait(NULL);
    }
}

int main() {
    char *input = NULL;
    char *args[MAX_ARG_COUNT];
    size_t len = 0;
    ssize_t read;

    // Set up signal handler for Ctrl+C
    signal(SIGINT, sigint_handler);

    while (1) {
        printf("mini-shell> ");
        read = getline(&input, &len, stdin);
        if (read == -1) {
            // Handle EOF (Ctrl+D)
            printf("\nmini-shell: use 'exit' to quit\n");
            break;
        }

        // Remove trailing newline
        input[read - 1] = '\0';

        // Split input into arguments
        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL) {
            args[++i] = strtok(NULL, " ");
        }

        // Handle built-in commands
        if (args[0] != NULL) {
            if (strcmp(args[0], "exit") == 0) {
                break;
            } else if (strcmp(args[0], "cd") == 0) {
                if (args[1] == NULL) {
                    fprintf(stderr, "mini-shell: expected argument to \"cd\"\n");
                } else {
                    if (chdir(args[1]) != 0) {
                        perror("mini-shell");
                    }
                }
            } else {
                execute_command(args);
            }
        }
    }

    free(input);
    return 0;
}
