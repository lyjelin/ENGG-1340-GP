
int main()
{
    Start:
    printf("\n\n--<Basic functions>--\n");
    printf("\n1. Add New Movie Ticketin Record(s):\n");
    printf("\n2. Display All Movie Ticketing Records:\n");
    printf("\n3. Modify Movie Ticketing Record(s):\n");
    printf("\n4. Search Movie Ticketing Record(s):\n");
    printf("\n5. Delete Movie Ticketing Record(s):\n");
	printf("\n6. Checking Movie Schedule(s):\n");
	printf("\n7. Add a comment on a Movie:\n");
    printf("\n8. Display newest comment:\n");
	printf("\n\n0: Exit function");
    
    //user chooses part
    
	printf("\nWhat is  your option <1-8>? ");
    int choose;//for user to choose funtion,use in switch
    int recordNum; //var for the current number of records
    int check=0; //var that allows breaking out of do while loops with checkYN()
    char record[150]; //string that allows for the display of records using displayRecord()
    
    do
    {
    	fflush(stdin);
        scanf("%d",&choose);
    
        switch (choose) {
        case 1:
            system("cls");
            AddRecord();
            system("cls");
            goto Start;
        case 2:
            system("cls");
            DisplayAll(0);
            system("cls");
            goto Start;
        case 3:
            system("cls");
            modifyRecord();
