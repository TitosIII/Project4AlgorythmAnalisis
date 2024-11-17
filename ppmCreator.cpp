#include<stdlib.h>
#include<stdio.h>

int main(){
    FILE* ptr;
    ptr = fopen("img/test.ppm", "wb");
    if(ptr == NULL){
        printf("Archivo no encontrado...\n");
        return -1;
    }

    fprintf(ptr, "P6 256 256 255\n");

    for(int r = 0; r < 256; r++){
        for(int b = 0; b < 256; b++){
            fputc(r, ptr);
            fputc(0, ptr);
            fputc(b, ptr);
        }
    }

    fclose(ptr);
    return 1;
}