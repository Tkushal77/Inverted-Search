#include "inverted_search.h"
/*
Name : T KUSHAL
Date : 04-08-2024
Description : INVERTED SEARCH PROJECT
ID : 24004_037
*/

int main(int argc , char *argv[])
{

    system("clear");

    Wlist *head[27] = {NULL};

    //validating  CLA
    if(argc <= 1)
    {
	    printf("Please Enter the valid number of arguments\n");
	    printf("For example Slist.exe file1.txt file2.txt......\n");
	    return 0;
    }

    //create file linked list

    //declare a file head pointer

    Flist *f_head = NULL;

    //validate the files

    file_validation_n_file_list(&f_head , argv);

    if(f_head == NULL)
    {
	    printf("ERROR : The process got terminated\n");
	    return 0;
    }

    int choice;
    char user_option;
    printf("*****************************************************\n");
    printf("   >>>>>>>>>>>>> 'INVERTED SEARCH'  <<<<<<<<<<<<<    \n");
    printf("*****************************************************\n");
    
    do
    {
        printf("\nSelect your choice among following options : \n");
        printf("1. Create DATABASE\n2. Display Database\n3. Update DATABASE\n4. Search\n5. Save Database\n6. Exit\n");

        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                create_database(f_head , head);
                break;
            case 2:
                display_database(head);
                break;
            case 3:
                update_database(head , &f_head);
                break;
            case 4:
                char word[WORD_SIZE];
                //prompt the user to enter the search word
                printf("Enter the word that need to be searched : ");
                scanf("%s" , word);

                int index = tolower(word[0]) % 97;                                  //finding the index of the entered word
                if(!(index >= 0 && index <= 25))
                {
                    index = 26;
                }
                search(head[index] , word);         

                break;
            case 5:
                save_database(head);

                break;
            case 6 :
                return 0;
            default:
                printf("Please enter the correct choice...!");
        }
        printf("\nDo you want to continue?\n");
		printf("Enter y/Y to continue or n/N to discontinue : ");
        scanf(" %c", &user_option);
    }while(user_option == 'y' || user_option == 'Y');

}