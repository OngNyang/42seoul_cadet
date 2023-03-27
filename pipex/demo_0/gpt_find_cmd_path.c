#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* find_command_path(const char* command, char** envp) {
    char* path = NULL;
    char* env_path = NULL;

    /* Find the PATH environment variable */
    for (int i = 0; envp[i] != NULL; i++) {
        if (strncmp(envp[i], "PATH=", 5) == 0) {
            env_path = envp[i] + 5;
            break;
        }
    }

    if (env_path != NULL) {
        char* token = strtok(env_path, ":");
        while (token != NULL) {
            char buffer[1024];
            snprintf(buffer, sizeof(buffer), "%s/%s", token, command);
//------------------------------------------------------------
			printf("buffer : %s\n", buffer);
//------------------------------------------------------------
            /* Check if the file exists */
            if (access(buffer, F_OK) == 0) {
                /* Allocate memory and copy the command's path */
                path = malloc(strlen(buffer)+1);
                if (path != NULL) {
                    strcpy(path, buffer);
//------------------------------------------------------------
					printf("path : %s\n", path);
//------------------------------------------------------------
                    break;
                }
            }

            token = strtok(NULL, ":");
        }
    }

    return path;
}

int main(int argc, char** argv, char** envp) {
    char* path = find_command_path("cat", envp);

    if (path != NULL) {
        printf("cat path: %s\n", path);
        free(path);
    } else {
        printf("Failed to find cat path\n");
    }

    return 0;
}
