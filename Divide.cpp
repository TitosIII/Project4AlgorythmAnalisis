#include<stdlib.h>
#include<stdio.h>

void rotate(unsigned char*, int, int, int, int);

int main(){
    FILE* ptr;
    ptr = fopen("img/test.ppm", "rb");
    if(ptr == NULL){
        printf("Archivo no encontrado...\n");
        return -1;
    }else{
        printf("Archivo obtenido.\n");
    }

    char buffer[16];
    fgets(buffer, sizeof(buffer), ptr);
    printf("%s\n", buffer);
    

    unsigned char R [256][256];
    unsigned char G [256][256];
    unsigned char B [256][256];

    int i, j;
    for(i = 0; i < 256; i++){
        for(j = 0; j < 256; j++){
            R[i][j] = fgetc(ptr);
            G[i][j] = fgetc(ptr);
            B[i][j] = fgetc(ptr);
        }
    }
    fclose(ptr);

    printf("Archivo procesado.\n");

    printf("Rotando imagen...\n");

    ptr = fopen("imgRotated.ppm", "wb");
    printf("Creando imagen.\n");
    fprintf(ptr, "P6 256 256 255\n");
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

void rotate(unsigned char* array, int p, int q, int width, int maxWidth){
    if(width == 1){
        return;
    }

    int size = width/2;

    char aux1;
    char aux2;

    rotate(array, p, q, size, maxWidth);
    rotate(array, p, q + size, size, maxWidth);
    rotate(array, p + size, q, size, maxWidth);
    rotate(array, p + size, q + size, size, maxWidth);

    int i,j;
    for(i = p; i < p + size; i++){
        for(j = q; j < q + size; j++){
            aux1 = *(array + i * maxWidth + j);
            aux2 = *(array + (i + size) * maxWidth + j + size);
            *(array + i * maxWidth + j) = *(array + i * maxWidth + j + size);
            *(array + (i + size) * maxWidth + j + size) = *(array + (i + size) * maxWidth + j);
            *(array + i * maxWidth + j + size) = aux2;
            *(array + (i + size) * maxWidth + j) = aux1;
        }
    }
}
