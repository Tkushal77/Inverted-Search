#include "inverted_search.h"

void search( Wlist *head , char *word)
{
    //check list is empty or not

    if(head == NULL)
    {
	printf("ERROR : Search is not possible because list is empty\n");
	return ;
    }

    //non empty
    //traverse through the Wlist
    while(head)
    {
	//compare each node word with new word
	if(!strcmp(head->word , word))
	{
    		printf("INFO : Word [%s] is present in %d file/s\n" , word , head->file_count);
	   	Ltable *Thead = head -> Tlink;

	  	while(Thead != NULL)
	  	{
			printf("INFO : In the file : [%s]  %d time/s \n" , Thead -> file_name , Thead -> word_count);
	     		Thead = Thead -> table_link;
	  	}
	  	printf("\n");
		return;
	}
	head = head -> link;
    }
    printf("ERROR : The word you entered was not found\n");
}