#include "inverted_search.h"

 void display_database( Wlist *head[] )
{
    printf("*******************************************************************************************************\n");
    printf("%-15s %-20s %-15s %20s %10s\n","[index]" ,"[word]" ,"file_count file/s" ,"File: File_name" ,"word_count");
    printf("*******************************************************************************************************\n");

    for(int i = 0; i < 27; i++)
    {
	    if(head[i] != NULL)
	    {
	        print_word_count(head[i]);
            printf("\n");
	    }
    }
}
 int print_word_count(Wlist *head)
{
    //traverse through WList 
    while(head != NULL)
    {
        int space = 0;
		int index = tolower(head->word[0]) % 97;

		if(!(index >= 0 && index <= 25))
		{
			index = 26;
		}

	    printf("[%-d] %15s %20d  file/s" , index , head->word , head->file_count);
        printf("           ");
        Ltable *Thead = head->Tlink;	

       //traverse through Ltable node
       while(Thead != NULL)
       {
	        printf("   %s : %s %2d" ,"File" ,Thead->file_name , Thead->word_count);
	        Thead = Thead->table_link;
       }

       printf("\n");
       head = head->link;
    }
}