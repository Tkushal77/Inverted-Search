#include"inverted_search.h"

void update_database( Wlist *head[], Flist **f_head)
{
    char file_name[FNAME_SIZE];

    //prompt the user for file
    printf("Enter the filename : ");
    scanf("%s" , file_name);

    int empty = isFileEmpty(file_name);

	if(empty == FILE_NOT_AVAILABLE)
	{
	    //printf("FILE %s is not available\n" , argv[i]);
	    printf("ERROR : FILE %s is not available in your directory.\nSo,this FILE cannot be added to the file Linked List\n",file_name);
	    printf("ERROR : Please enter the file that is Existing in your directory\n");
	}
	else if(empty == FILE_EMPTY)
	{
	    printf("ERROR : FILE %s is not having any content\nSo, this FILE cannot be added to the file linked list\n", file_name);
	    //printf("Hence we are not adding it into file LL\n");
	}
	else
	{
	    int ret_val = to_create_list_of_files(f_head, file_name);

	    if(ret_val == SUCCESS) 
	    {
		printf("INFO : Success, FILE %s inserted into file linked list\n" , file_name);
	    }
	    else if(ret_val == REPEATATION)
	    {
		printf("ERROR : FILE %s is repeated. \nThis FILE cannot added into the file Linked List. \nPlease enter FILE with different file name\n" , file_name);
	    }
	    else
	    {
		printf("Failure\n");
	    }
	}

	int res = 1;

	while(*f_head != NULL)
    	{
	    if((strcmp((*f_head)->file_name , file_name)) == 0)
	    {
	        create_database(*f_head , head);
		  res = 0;
	    }
        *f_head =  (*f_head) -> link;
    	}

	if(res == 0)
	{
		printf("INFO : SUCCESS, The Data Base updated\n");
	}
	else
	{
		printf("ERROR : The Data Base is not updated\n");
	}
}