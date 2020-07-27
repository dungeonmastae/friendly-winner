#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//this program is the implementation of linked list with structures that has erase function which lagged in the former
struct person{
    char name[20];
    char number[10];
    struct person *link;
};
struct person *head,*temp,*newnode;
int number_of_person=0;
void add();
void check();
void menu();
void erase();

int main()
{
    menu();
}
void menu()
{
    int query;
    printf("\n1.add\t  2.remove\t 3.check \t 4.edit \n");
    printf("\nenter your query\n");
    scanf("%d",&query);
    switch(query){
    case 1:
        add();
        break();
    case 2:
        erase();
        break();
    case 3:
        check();
        break();
    case 4:
        edit();
        break();
    default:
        printf("undefined query , try again\n\n");
        menu();
    }
}
void add(){
    static int i=0;
    if(i==0){
    head=NULL;
    }
    temp=(struct person*)malloc(sizeof(struct person));
    printf("enter the name\n");
    scanf("%s",temp->name);
    printf("enter the number\n");
    scanf("%s",temp->number);
    if(head==NULL){
        head=newnode=temp;
    }
    else {
        newnode->link=temp;
        newnode=temp;
    }
    i++;
    number_of_person=i;
    menu();
}
void check(){
    char name1[20];
    temp=head;
    int k=0;
    printf("enter the name\n");
    scanf("%s",name1);
    while(strcmp(name1,temp->name)){
        temp=temp->link;
    }

    printf("name: %s \n number: %s",temp->name,temp->number);

    menu();
}
void edit(){
    char name1[20];
    int num;
    temp=head;
    printf("\nenter your name\n");
    scanf("%s",name1);
    while(strcmp(name1,temp->name)){
        temp=temp->link;
    }
    printf("\nyou want to change 1.name or 2.number\n");
    scanf("%d",&num);
        if(num==1){
          printf("enter new name\n");
          scanf("%s",temp->name);
    }
    else if(num==2){
        printf("enter new number\n");
        scanf("%s",temp->number);
    }
    menu();
}
void erase(){
    char name1[20];
    newnode=temp=head;
    printf("enter the name you want to delete\n");
    scanf("%s",name1);
    while(strcmp(name1,temp->name)){
        newnode=temp;
        temp=temp->link;
    }
    newnode->link=temp->link;
    free(temp);
    menu();
}
