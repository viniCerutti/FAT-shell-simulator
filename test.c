#include <stdio.h>
#include <stdint.h>
typedef struct{
	uint32_t size;
} dir_entry_t;

union data_cluster{
	dir_entry_t dir[20 / sizeof(dir_entry_t)];
	uint8_t data[20];
};

int main()
{
   union data_cluster test;
   printf("Hello world!");

   dir_entry_t dir;

	int counter;
	FILE *ptr_myfile;

	//ptr_myfile=fopen("test.bin","wb");
	ptr_myfile=fopen("test.bin","rb");
	if (!ptr_myfile)
	{
		printf("Unable to open file!");
		return 1;
	}
		//fwrite(&test, sizeof(union data_cluster), 1, ptr_myfile);
		fread(&test,sizeof(union data_cluster),1,ptr_myfile);
		printf("%d\n", test.dir[0].size);
	fclose(ptr_myfile);

   return 0;
}