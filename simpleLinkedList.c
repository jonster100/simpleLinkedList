/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: #######
 *
 * Created on 27 October 2016, 09:06
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define titleArraySize 101
#define authorArraySize 61


typedef struct BookData {
    char title[titleArraySize];
    char author[authorArraySize];
    long int ISBN;
    struct BookData * nextData;
} book;


struct BookData* create_book(char t[titleArraySize],char a[authorArraySize],long int isbn,struct BookData * nb){
    struct BookData * newBook = malloc(sizeof(struct BookData));
    strcpy(newBook->title,t);
    strcpy(newBook->author,a);
    newBook->ISBN = isbn;
    newBook->nextData = nb;
    return newBook;
}

void print_book(struct BookData * book){
    printf("Author Name: %s\n",book->author);
    printf("Title Name: %s\n",book->title);
    printf("ISBN Code: %ld\n",book->ISBN);
    printf("\n");
}

struct BookData* create_book_io(){
    char * title[titleArraySize];
    char * author[authorArraySize];
    long int isbn;

    printf("Enter Title: ");
    scanf(" %[A-Za-z0-9 ]",&title);
    printf("Enter Author Name: ");
    scanf(" %[A-Za-z0-9 ]",&author);
    printf("Enter ISBN code: ");
    scanf("%ld",&isbn);
    return create_book(title,author,isbn,NULL);
}

void print_list(struct BookData * head){
    struct BookData * tempNode;
    tempNode = head;
    //int * count;
    if(tempNode->nextData !=NULL){
        print_book(tempNode);
        print_list(tempNode->nextData);
    } else {
        print_book(tempNode);
    }
}

void find_book_from_list(struct BookData * head){
    long int temp_isbn;
    printf("Enter ISBN of book you would like to find.\n");
    scanf("%ld",&temp_isbn);

    struct BookData * tempNode;
    tempNode = head;

    while(tempNode->nextData != NULL){
        if(tempNode->ISBN == temp_isbn){
            print_book(tempNode);
        }
        tempNode = tempNode->nextData;
    }
    if(tempNode->nextData == NULL){
        if(tempNode->ISBN == temp_isbn){
        print_book(tempNode);
        }
    }

}

void insert_book_to_list(struct BookData * insBook, struct BookData ** head){
    if (*head == NULL) {
        *head = insBook;
    }
    else if((*head)->ISBN > insBook->ISBN){
        insBook->nextData = *head;
        *head = insBook;
    }
    else {
        struct BookData * tempNode;
        tempNode = * head;
        while(tempNode->nextData !=NULL && tempNode->ISBN > insBook->ISBN){
            tempNode = tempNode->nextData;

            }
        insBook->nextData = tempNode->nextData;
        tempNode->nextData = insBook;
        }
    }

	
	void print_menu(){
    printf("\n");
    printf("1: Add a Book to list.\n");
    printf("2: Print list of Books.\n");
    printf("3: Findbook.\n");
    printf("Type 9 to end the session.\n");
    printf("\n");
}

int main(int argc, char** argv) {
    struct BookData * head = NULL;
    struct BookData * newB = NULL;
    long int test = 19;

    int read =0;
    while(read!=9){
    print_menu();
    scanf(" %d",&read);

    switch(read){
        case 1:
            newB = create_book_io();
            insert_book_to_list(newB,&head);
            break;
        case 2:
            print_list(head);
            /*printf(head->author);
            printf(head->nextData->author);
            printf(head->nextData->nextData->author);*/
            break;
        case 3:
            find_book_from_list(head);
            break;
    }

    }
    /*print_book(head);
    print_book(head->nextData);*/

    return (EXIT_SUCCESS);
}

