#include "inverted_search.h"

 char extern *fname;                                            //getting the file name through global variable
int insert_at_last(Wlist **head, data_t *data)
{
    //create a node

    Wlist *new = malloc(sizeof(Wlist));
    if(new == NULL)
    {
	    return FAILURE;
    }
       //update the node fields
    new -> file_count = 1;
    strcpy(new->word , data);
    new -> Tlink =  NULL;
    new -> link = NULL;

    //cal fun to update link table node
    update_link_table(&new);

    if(*head == NULL)                       //check WList is empty or not
    {
	    *head = new;
	    return SUCCESS;
    }

    Wlist *temp = (*head);                           //if the list is non empty

    while(temp -> link != NULL)                      //traverse through the list
    {
	    temp = temp -> link;
    }
    temp -> link = new;
    return SUCCESS;
}

int update_link_table(Wlist **head)
{
   
    Ltable *new = malloc(sizeof(Ltable));                   //create a new link table node by allocating the memory dynamically
    if(new == NULL)
    {
	    return FAILURE;
    }
    new -> word_count = 1;
    strcpy(new -> file_name , fname);
    new->table_link = NULL;

    (*head) -> Tlink = new;
    return SUCCESS;
}
