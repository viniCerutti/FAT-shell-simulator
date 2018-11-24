#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define CLUSTER_SIZE 1024
#define FAT_SIZE 4096
#define ROOT_NAME "root"
typedef struct{
	uint32_t size;
} dir_entry_t;

union data_cluster{
	dir_entry_t dir[CLUSTER_SIZE / sizeof(dir_entry_t)];
	uint8_t data[CLUSTER_SIZE];
};

uint16_t fat[FAT_SIZE];

void init(){

	FILE *ptr_myfile;

	ptr_myfile=fopen("fat.part","wb");

	if (!ptr_myfile){
		printf("Impossivel abrir o arquivo!");
		return;
	}

	union data_cluster boot_block;

	int i;
	for (i = 0; i < CLUSTER_SIZE; i++){
		boot_block.data[i] = 0xbb;
	}

	uint16_t fat_init[FAT_SIZE];

	// alocar endereço na fat para boot block
	fat_init[0] = 0xfffd; 

	// alocar endereço fat para a propria fat
	for (i = 1; i <= 8; i++){
		fat_init[i] = 0xfffe; 
	}

	// alocar endereço na fat para root block
	fat_init[9] = 0xffff;

	// para o restante dos endereços na fat
	for (i = 10; i < FAT_SIZE; i++){
		fat_init[i] = 0x0000; 
	}

	union data_cluster clusters;
	printf("teste");
	fwrite(&boot_block, sizeof(union data_cluster), 1, ptr_myfile);
	fwrite(&fat_init, sizeof(fat_init), 1, ptr_myfile);

	// salva no arquivos cluster root + outros clusters
	for (i = 0; i < 4086; i++){
		fwrite(&clusters, sizeof(union data_cluster), 1, ptr_myfile);
	}
	fclose(ptr_myfile);

}


void load (){
	FILE *ptr_myfile;

	ptr_myfile=fopen("fat.part","rb");

	if (!ptr_myfile){
		printf("Impossivel abrir o arquivo!");
		return;
	}

	union data_cluster boot_block;

	//carrega o boot_block para a memoria
	fread(&boot_block,sizeof(union data_cluster),1,ptr_myfile);
	int i;

	for (i = 0; i < CLUSTER_SIZE; i++){
		if (boot_block.data[i] != 0xbb){
			printf ("Problemas no endereços do boot_block");
			return;
		}

	}
	//carrega a fat para a memoria
	fread(&fat, sizeof(fat), 1, ptr_myfile);

	fclose(ptr_myfile);
}

void mkdir (char* directories){
	
}

void __loadfat__(){
	FILE *ptr_myfile;

	ptr_myfile=fopen("fat.part","rb");

	if (!ptr_myfile){
		printf("Impossivel abrir o arquivo!");
		return;
	}

	fseek(ptr_myfile,sizeof(union data_cluster),SEEK_SET);
	//carrega a fat para a memoria
	fread(&fat, sizeof(fat), 1, ptr_myfile);
	fclose(ptr_myfile);

	int i;

	for (i=0; i < FAT_SIZE; i++){
		printf("%d -> 0x%04x\n",i,fat[i]);
	}
}

int main()
{
   char teste[20] = "/root/home";
   __loadfat__();
   return 0;
}