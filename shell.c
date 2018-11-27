#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main (){
	while (1){
        char input_str[400];
        memset(input_str,0,sizeof(input_str));
        fgets (input_str, sizeof(input_str), stdin);
		//printf("%s",input_str);

		if (strcmp(input_str,"init\n") == 0){

			printf("\nfunçao inicializar\n");

		}else if (strcmp(input_str,"load\n") == 0){

			printf("\nfunçao load\n");

        } else if (strcmp(input_str,"quit\n") == 0){
            exit(0);

        } else if (strcmp(input_str,"clear\n") == 0){
            system("clear");

		}else {
			char * token;

			token = strtok(input_str," "); // pega a primeira palavra  antes do espaço

			if(strcmp(input_str,"ls") == 0){

				printf("\nfuncao ls\n");

				char *path = strtok(NULL, " "); // apenas o caminho a ser utilizado
				printf("%s",path);

			}else if (strcmp(input_str,"mkdir") == 0){

				printf("\nfuncao mkdir\n");
				char *path = strtok(NULL, " "); // apenas o caminho a ser utilizado
				printf("%s",path);

			}else if (strcmp(input_str,"create") == 0){

				printf("\nfuncao create\n");
				char *path = strtok(NULL, " "); // apenas o caminho a ser utilizado
				printf("%s",path);

			}else if (strcmp(input_str,"unlink") == 0){

				printf("\nfuncao unlink\n");
				char *path = strtok(NULL, " "); // apenas o caminho a ser utilizado
				printf("%s",path);

			}else if (strcmp(input_str,"write") == 0){

				printf("\nfuncao write\n");

				char *string = strtok(NULL, " ");
				printf("\n%s\n",string);

				char *path = strtok(NULL, " ");
				printf("\n%s\n",path);

			} else if (strcmp(input_str,"append") == 0){

				printf("\nfuncao append\n");

				char *string = strtok(NULL, " "); 
				printf("\n%s\n",string);
				
				char *path = strtok(NULL, " ");
				printf("\n%s\n",path);

			} else if (strcmp(input_str,"read") == 0){

				printf("\nfuncao read\n");
				char *path = strtok(NULL, " "); // apenas o caminho a ser utilizado
				printf("%s",path);

			}else {
				printf ("\nComando nao encontrado!\n");
			}
		}
	}
}