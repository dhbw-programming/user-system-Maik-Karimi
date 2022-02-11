#include "user_system.h"
#include <stdio.h>
#include <stdlib.h>
#include ".assignment/dhbw.h"
#include ".assignment/user_interface.h"

// AVAILABLE HERE: Function print_user(id, name, email) to print a single user
// Make sure to write empty functions for ALL functions in the header (also optional ones),
// otherwise the program will not compile

typedef struct users_tag  {
    char *name;
    char *email;
    user_id user_id;
}users;
int size = 0;

users *userlist;
void users_initialize_table(int x) {
    size = x;
 userlist = (users*) malloc(sizeof(users) * size);
 for(int i = 0; i<size ;i++) {
   userlist[i].name = NULL;  
 }
}


   



user_id users_add(char *name, char*email){
    int i = 0;
   while(userlist[i].name != NULL) {
    if(i >=size){
        return -1;
    }
    i++;
   } 
userlist[i].name = name;
userlist[i].email = email;
userlist[i].user_id = i;
return userlist[i]. user_id;
}

void users_printall(){
    for (int i = 0; userlist[i].name != NULL ; i++)
    {
        if(i < size) {
        print_user(userlist[i].user_id,userlist[i].name,userlist[i].email);

        }else {
            break;
        }
     
    }
    
}
char *users_get_name(user_id id){
   return userlist[id].name; 
}

void users_delete(user_id id){
 userlist[id].name = NULL;
 userlist[id].email = NULL;
}

void users_resize(int new_capacity) {

int x = new_capacity;
users *new_userlist = (users*) malloc(sizeof(users) * x);
 for(int i = 0; i<x ;i++) {
   new_userlist[i].name = NULL;  
 }
 for(int i = 0; i <size ; i++)
 {
    new_userlist[i] = userlist[i];
 }
 free(userlist);
 users_initialize_table(x);
 for(int i = 0; i <x ; i++)
 {
    userlist[i] = new_userlist[i];
 }
 free(new_userlist);
}


