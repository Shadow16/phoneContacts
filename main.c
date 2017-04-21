#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <time.h>
#include <windows.h>
#include <unistd.h>
#define user1 "nestored"
#define pass1 "123"

int cont = 0;

void cls(){
    system("cls");
}

void insertData(fptr){
    char newuser[10], newpass[5];
    printf("Input username: ");
    scanf("%s", newuser);
    printf("Input password: ");
    scanf("%s", newpass);
        // while((ch=getchar())!=  EOF){

    fprintf(fptr, "\n%s,", newuser);
    fprintf(fptr, "%s,", newpass);

    fclose(fptr);

    menu();
}

void createFile(){
    FILE *fptr;
    fptr = fopen("users.csv", "ab");
    if(fptr == NULL){ // Si no existe archivo lo crea
        fptr = fopen("users.csv", "w");
        insertData(fptr);
    } else {
        insertData(fptr);
    }
}

void newUser(){
    system("cls");
    createFile();


}

void login(){
    cls();
    char user[10], pass[5];
    printf("\n\n\t\t\t USER: \t\t");
    scanf("%s", user);
    printf("\t\t\t PASSWORD: \t");
    scanf("%s", pass);

    if(strcmp(user, user1) == 0 && strcmp(pass, pass1) == 0){
        menu(user);
    } else {
        printf("\n\n\t TRY AGAIN!! ");
        cont += 1;
        Sleep(2000);
        if(cont >= 3){
            printf("\n\n\t\t INCORRECT USER AND PASSWORD!! \n\n");
            exit(1);
        } else {
            login();
        }
    }
}


void menu(user){

    int opc = 0;
    cls();
    printf("\n\n\t\t\t Welcome to my system! '%s'\n", user);
    printf("\n\t\t[1] Create database \t[2] Insert data \n\t\t[3] Update \t\t[4] Find contact \n\t\t[5] Delete \t\t[6] New user");
    printf("\n\n\t Press [0] to exit! ");
    scanf("%d", &opc);

    switch(opc){
    case 0:
        exit(EXIT_SUCCESS);
        break;
    case 1:
        cls();
        break;
    case 2:
        cls();
        break;
    case 3:
        cls();
        break;
    case 4:
        cls();
        break;
    case 5:
        cls();
        break;
    case 6:
        newUser();
        break;
    default:
        menu(user);
    }
}

int main(){
    login();
    // menu();
    return EXIT_SUCCESS;
}
