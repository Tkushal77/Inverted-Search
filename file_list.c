#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1 , empty ;
    while(argv[i] != NULL)
    {
	empty = isFileEmpty(argv[i]);

	if(empty == FILE_NOT_AVAILABLE)
	{
	    //printf("FILE %s is not available\n" , argv[i]);
	    printf("ERROR : FILE %s is not available in your directory.\nSo,this FILE cannot be added to the file Linked List\n",argv[i]);
	    printf("ERROR : Please enter the file that is Existing in your directory\n");
	    i++;
	    continue;
	}
	else if(empty == FILE_EMPTY)
	{
	    printf("ERROR : FILE %s is not having any content\nSo, this FILE cannot be added to the file linked list\n", argv[i]);
	    //printf("Hence we are not adding it into file LL\n");
	    i++;
	    continue;
	}
	else
	{
	    int ret_val = to_create_list_of_files(f_head, argv[i]);

	    if(ret_val == SUCCESS) 
	    {
		printf("INFO : Success, FILE %s inserted into file linked list\n" , argv[i]);
	    }
	    else if(ret_val == REPEATATION)
	    {
		printf("ERROR : FILE %s is repeated. \nThis FILE cannot added into the file Linked List. \nPlease enter FILE with different file name\n" , argv[i]);
	    }
	    else
	    {
		printf("Failure\n");
	    }
	    i++;
	    continue;
	}
    }
}

//fun() is to check for file availability and to check for content
int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename , "r");							//to open the particular file using the file pointer 
    if(fptr == NULL)										//to check the file is opened or not
    {
	if(errno == ENOENT)
	{
	    return FILE_NOT_AVAILABLE;
	}
    }

    fseek(fptr , 0 , SEEK_END);								//checking the contents of the file using file pointer
    if(ftell(fptr) == 0)									//to check the file is having the content or not
    {
	return FILE_EMPTY;
    }
}

 int to_create_list_of_files(Flist **f_head, char *name)
{
    //check for duplicancy 
    //inserting the new file to the file linked list 
    Flist *new = malloc(sizeof(Flist));
    if(new == NULL)
    {
	return FAILURE;
    }
    strcpy(new -> file_name, name);
    new -> link = NULL;

    if((*f_head) == NULL)
    {
	(*f_head) = new;
	return SUCCESS;
    }

    Flist *prev ,*temp = (*f_head);
    while(temp != NULL)
    {
	if(!strcmp(temp -> file_name , name))
	{
		return REPEATATION;
	}
	prev = temp;
	temp = temp -> link;
    }
    prev -> link = new;
    return SUCCESS;
}





















