# FAT Simulation and Shell
Este trabalho é uma implementação de um simulador de um sistema de arquivos simples baseado em tabela de alocação de 16 bits (FAT) e um shell usado para realizar operações sobre este sistema de arquivos.

# Comandos Interpreatados #
* init - inicializar o fs com as estruturas de dados, format;
* load - carregar o fs do disco;
* ls - listar diretório;
* mkdir - criar diretório;
* create - criar arquivo;
* unlink - deletar arquivo ou diretório (deve estar vazio);
* write 'string' - escrever dados em um arquivo (overwrite);
* append 'string' - anexar dados em um arquivo;
* read - ler conteúdo
 
## Formato dos comandos: ##
* init
* load
* ls        /caminho/diretorio 
* mkdir     /caminho/diretorio
* create    /caminho/arquivo
* unlink    /caminho/{arquivo|diretorio}
* write    "string" /caminho/arquivo
* append   "string" /caminho/arquivo
* read      /caminho/arquivo

# Modo de compilar #
```
gcc -o virtual_file virtual_file.c -lm 
```

# Sistema operacional testado #

Linux Ubuntu 16.04.5 LTS

gcc (Ubuntu 6.4.0-17ubuntu1~16.04) 6.4.0 20180424  
Uso do programa hexdump (com o modo canonical) para realizar a depuração e visualização das estruturas de dados do sistema de arquivos virtual.

### Material Extra de Apoio ###
http://www.cse.scu.edu/~tschwarz/COEN252_09/Lectures/FAT.html?fbclid=IwAR15vgsRT1pJIwcxH_zxEHECgjoRbQVzDQVjXHfDSK-mn191JlsFq8krpVg

http://www.c-jump.com/CIS24/Slides/FAT/lecture.html?fbclid=IwAR3jkxH2PcFh1PCmToYUcGICjPjmdRh41SzNoj1H7gazDwSEMVR_x12ZKn4

http://www.tavi.co.uk/phobos/fat.html?fbclid=IwAR3r31vvt6IaA_X0XB6GHH4tESwH9apyMVYjVx32wy_rN9sFjXs344tYD0k

https://github.com/monpeco/real_time_bn/blob/master/lab5/File_systems.md?fbclid=IwAR1e1NiPnqKxY3_SnQMETfUcmWiij9WyyQi6UDHsm1Pi2kwmCjwO-iEzOaQ
