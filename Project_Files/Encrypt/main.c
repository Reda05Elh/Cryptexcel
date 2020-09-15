#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void encrypt();

int main() {
    char buffer[1000] = {0};
    srand(time(NULL));
    printf("Drop your File here and tape enter : \n");
    fgets(buffer,1000,stdin);
    buffer[strcspn(buffer,"\n")] = 0;
    rename(buffer,"Data.xlsx");
    system("com.CMD");
    rename("Data.csv","TempData.txt");
    encrypt();
    remove("TempData.txt");
    rename("Data.xlsx",buffer);
    system("End.vbs");
    return 0;
}

void encrypt() {
    char key[50] = {0};
    int i;
    int x = rand()%50;
    char c = 0;
    FILE* ptrtemp = NULL;
    FILE* ptr = NULL;
    ptrtemp = fopen("TempData.txt","r");
    ptr = fopen("Crypted_Data","w");

    if ((ptrtemp == NULL)||(ptr == NULL)) {
        printf("File does not exists or error in opening!");
        exit(1);
    }

    while((c = fgetc(ptrtemp)) != EOF){
        c+=x;
        fputc(c,ptr);
    }
    fclose(ptr);
    fclose(ptrtemp);

    ptr = fopen("KEY","w");
    if (ptr == NULL){
        printf("ERREUR : KEY file does not been generated");
        exit(2);
    }

    fputc(x,ptr);
    for(i=1;i<50;i++){
        fprintf(ptr,"%c",i);
    }
    fclose(ptr);

}
