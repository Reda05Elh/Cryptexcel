#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decrypt();

int main()
{
    char file[1000] = {0};
    char key[1000] = {0};
    printf("Drop your Encrypted File here and press ENTER\n");
    fgets(file,1000,stdin);
    file[strcspn(file,"\n")] = 0;
    system("cls");
    printf("Drop your key here and press ENTER\n");
    fgets(key,1000,stdin);
    key[strcspn(key,"\n")] = 0;
    rename(file,"Encrypted_file");
    rename(key,"key");
    decrypt();
    rename("TempData.txt","Data.csv");
    system("com.cmd");
    remove("key");
    remove("Data.csv");
    remove("Encrypted_file");
    system("End.vbs");


    return 0;
}

void decrypt(){
    char buffer[100] = {0};
    int x =0;
    char c;
    FILE* ptr = NULL;
    FILE* ptrtemp = NULL;
    ptr = fopen("key","r");

    if (ptr == NULL ){
        printf("Key not founded!");
        exit(0);
    }
    c = fgetc(ptr);
    x = (int)(c);
    fclose(ptr);
    ptr = fopen("Encrypted_file","r");
    ptrtemp = fopen("TempData.txt","w");

    if ((ptr == NULL) || ptrtemp == NULL){
        printf("ERREUR ");
        exit(1);
    }
    while((c = fgetc(ptr)) != EOF){
        fputc(c-x,ptrtemp);
    }
    fclose(ptr);
    fclose(ptrtemp);

    }

