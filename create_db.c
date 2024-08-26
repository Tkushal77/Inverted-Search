#include "inverted_search.h"
char *fname;   //decalring globally to access the name of the file
void create_database(Flist *f_head, Wlist *head[])
{
    //traverse through the file linked list
    while(f_head != NULL)
    {
	read_datafile(f_head , head , f_head->file_name);
	f_head = f_head->link;
    }
}
 Wlist *read_datafile(Flist *file, Wlist *head[], char *filename)
{
    int flag = 1;
    fname = filename;
    //opening the file in the read mood to the characters written inside the file

    FILE *fptr = fopen(filename , "r");

    //declarring an array to store words which is read from the file

    char word[WORD_SIZE];

    while(fscanf(fptr , "%s" , word) != EOF)
    {
	flag = 1;

	int index = tolower(word[0]) % 97;			//finding the index of each word scanned

	if(!(index >= 0 && index <= 25))
	{
	    index = 26;
	}

	if(head[index] != NULL)
	{
	    Wlist *temp = head[index];
	    //compare the each word_node list with new word
	    while(temp)
	    {
		if(!(strcmp(temp->word , word)))
		{
		    update_word_count(&temp, filename);
		    flag = 0;
		    break;
		}
		temp = temp->link;
	    }
	}
	if(flag == 1)
	{
		//called only when words are not repeated 
    		insert_at_last(&head[index] , word);   		
	}
    }
    printf("INFO : SUCCESSFULLY created the Data Base for the File : %s\n",filename);
}
int update_word_count(Wlist **head, char *filename) 
{

	Ltable *temp1 = (*head) -> Tlink;							// local pointer to assign the tlink address of the wordnode 
	while(temp1 != NULL)
	{
		if(strcmp(temp1 -> file_name , filename) == 0) 				//to check the word is present in the same file or not
		{
			temp1 -> word_count++;							//if present incrementing the word count
			return SUCCESS;
		}
		temp1 = temp1 -> table_link;
	}

	(*head) -> file_count++; 								//if it is different file then incrementing the file count of word node
	Ltable *new = malloc(sizeof(Ltable));						//creating the new linktable node by allocating the memory dynamically
	if(new == NULL)
	{ 
		return FAILURE;
	}
	new -> word_count = 1;									//updating the fields of the node
	strcpy(new -> file_name , fname);
	new -> table_link = NULL;

	Ltable *temp2 = (*head) -> Tlink;

	while(temp2 -> table_link != NULL)							//traversing till last node to perform the insert last operation
	{
		temp2 = temp2 -> table_link;
	}
	temp2 -> table_link = new;
	return SUCCESS;
}

