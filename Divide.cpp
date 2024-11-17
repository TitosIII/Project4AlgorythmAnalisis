#include<stdlib.h>
#include<stdio.h>

void rotate(char**, int, int, int);

int main(){
    FILE* ptr;
    ptr = fopen("img/test.ppm", "rb");
    if(ptr == NULL){
        printf("Archivo no encontrado...\n");
        return -1;
    }else{
        printf("Archivo obtenido.\n");
    }

    char buffer [16];

    for(char b : buffer){
        b = fgetc(ptr);
    }

    printf("%s", buffer);

    char R [256][256];
    char G [256][256];
    char B [256][256];

    int i = 0, j = 0;
    for(i = 0; i < 256; i++){
        for(j = 0; j < 256; j++){
            R[i][j] = fgetc(ptr);
            G[i][j] = fgetc(ptr);
            B[i][j] = fgetc(ptr);
        }
    }
    fclose(ptr);

    printf("Archivo procesado.\n");

    rotate((char**)R, 0, 0, 256);
    rotate((char**)G, 0, 0, 256);
    rotate((char**)B, 0, 0, 256);

    printf("Rotando imagen...\n");

    ptr = fopen("imgRotated.ppm", "wb");
    printf("Creando imagen.\n");
    fprintf(ptr, buffer);
    for(i = 0; i < 256; i++){
        for(j = 0; j < 256; j++){
            fputc(R[i][j], ptr);
            fputc(G[i][j], ptr);
            fputc(B[i][j], ptr);
        }
    }
    fclose(ptr);
    printf("Arcihivo creado.\n");
    return 1;
}

void rotate(char** array, int p, int q, int width){
    if(width == 1){
        return;
    }

    int size = width/2;

    char aux1;
    char aux2;

    rotate(array, p, q, size);
    rotate(array, p, p + size, size);
    rotate(array, p + size, q, size);
    rotate(array, p + size, p + size, size);

    int i,j;
    for(i = p; i < p + size; i++){
        for(j = q; j < q + size; j++){
            aux1 = array[i][j];
            aux2 = array[i + size][j + size];
            array[i][j] = array[i + size][j];
            array[i + size][j + size] = array[i][j + size];
            array[i + size][j] = aux1;
            array[i][j + size] = aux1;
        }
    }

}