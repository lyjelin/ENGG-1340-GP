#include <studio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int checkYN(char check)
{
    switch (check) {
        case 'y':
        	return 0;
        case 'Y':
            return 0;
            break;
        case 'n':
        	return 1;
        case 'N':
            return 1;
        default:
            printf("Error input default to EXIT the function!!\n");
            return 1;
    }
}

void AddRecord() 
{
     int triedCreating=0;
    char RecordString[140];
    int i=0;
    
    OPEN:
    	printf("\n");
    FILE *fp = fopen("customer.txt","a+");
    
    if(!fp)//if do not have file
    {
        exit(1);
    }
    int check=0;
    char YesAndNo;
    do
    {
    	printf("\nPlease read READ_ME.txt before inputing anything!\n");
        printf("Please enter the following details separated by commas:\n\n1)Movie Booking Number\t(####)\n2)Name of Customer \n3)Name of Movie \n4)Movie Schedule \t(DD/MM/YY)\n5)Time\t\t\t(24HR FORMAT/00:00)\n6)Number of Guests \n7)House Number \n8)Ticket Type \n9)Total Fee\n");
        fflush(stdin);
        gets(RecordString);
        
        fprintf(fp,"\n");
        while(RecordString[i] != '\0')
        {
            if(RecordString[i] == ',')
            {
                fprintf(fp,"\n");
                i++;
				continue;
                
            }
            fprintf(fp,"%c",RecordString[i]);
            i++;
        }
        
       i=0;
       printf("Add another record(y/n): ");
       fflush(stdin);
       scanf("%c",&YesAndNo);
       if(checkYN(YesAndNo))
           check=1;
    }while(!check);
    fclose(fp);
    
}



int DisplayAll(int skip){
	int firstTime=1;
    int triedCreating;
    int recordNumTwo = 0;
    int response;
    int check=0;
    char YesAndNo;
    
    
    struct record data[100];
    
    OPEN:
        printf("\n");
	FILE *fp = fopen("customer.txt","a+");   //open file
    if(!fp)
    {
        //try creating the file
        if(!triedCreating)
        {
        	triedCreating = 1;      //mark it has already tried creating it
            fclose(fopen("customer.txt","r"));
            goto OPEN;
        }
        //if fail to create
    fprintf(stderr,"Error opening file %i. Message: %s",errno,strerror(errno));
    exit(EXIT_FAILURE);
    }
    int z= 0;
    start:
    	
   	if (fgets(data[z].bookNum, 80, fp) == '\0'){
   		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300); 
		system("cls");
		printf("\n\nThere are currently %i record(s) in the database", recordNumTwo);
		printf("\n\n\n    !!!\n    PLEASE ADD RECORD(S) TO DATABASE BEFORE TRYING TO READ THEM\n    !!!\n");
		}
		
	else if (data[z].bookNum != '\0'){
		printf("Printing all available records:\n\n");
		rewind(fp);
		while(fgets(data[z].bookNum, 80, fp) != '\0'){
			printf("Booking number:\t\t%s", data[z].bookNum);
			fgets(data[z].name, 80, fp);
			printf("Customer name:\t\t%s", data[z].name);
			fgets(data[z].movie_name, 80, fp);
			printf("Movie name:\t\t%s", data[z].movie_name);
			fgets(data[z].movie_schedule, 80, fp);
			printf("Movie schedule:\t\t%s", data[z].movie_schedule);
			fgets(data[z].time, 80, fp);
			printf("Time:\t\t\t%s", data[z].time);
			fgets(data[z].numofGuests, 80, fp);
			printf("Number of guests:\t%s", data[z].numofGuests);
			fgets(data[z].houseNum, 80, fp);
			printf("House number:\t\t%s", data[z].houseNum);
			fgets(data[z].ticketType, 80, fp);
			printf("Ticket Type(s):\t\t%s", data[z].ticketType);
			fgets(data[z].totalFee, 80, fp);
			printf("Total Fees:\t\t$%s\n", data[z].totalFee);
			recordNumTwo++;
			z++;
			}
			printf("\nThe number of available records is %i\n", recordNumTwo);
	}
	if((recordNumTwo >= 5) && (firstTime == 1)){
		system("cls");
		printf("\nNumber of records is %i, are you sure you want to display this many records? (y/n) ", recordNumTwo);
		fflush(stdin);
		scanf("%c", &YesAndNo);
		if(!checkYN(YesAndNo)){
	       rewind(fp);
	       firstTime = 0;
	       recordNumTwo = 0;
	       system("cls");
	       goto start;
       	}
		
	}
	if (skip == 0){
		printf("\nExiting to main menu. Press <ENTER> to continue");
		fflush(stdin);getchar(); 
	}
	fclose(fp);
}

void modifyRecord()
{
	char Booking[4];
	int b;
	int z=0;
	int loopCount;
	char YesAndNo;
	struct record data[100];
	
	
	loop:
	printf("Display current records? (y/n) ");
	fflush(stdin);
	scanf("%c",&YesAndNo);
    if(!checkYN(YesAndNo)){
	    fflush(stdin);
		DisplayAll(1);	//display all available records while skipping certain parts of DisplayAll()
		fflush(stdin);	
		}
	
	printf("\nPlease enter the booking number that you want to modify: ");
	scanf("%s",&Booking);
	
	FILE *fileIn;
	fileIn = fopen("customer.txt","r");
	
	while(fgets(data[z].bookNum, 80, fileIn) != '\0'){   //Load all data in customer.txt into the struct array
			fgets(data[z].name, 80, fileIn);
			fgets(data[z].movie_name, 80, fileIn);
			fgets(data[z].movie_schedule, 80, fileIn);
			fgets(data[z].time, 80, fileIn);
			fgets(data[z].numofGuests, 80, fileIn);
			fgets(data[z].houseNum, 80, fileIn);
			fgets(data[z].ticketType, 80, fileIn);
			fgets(data[z].totalFee, 80, fileIn);
			z++;
			}
	fclose(fileIn);
	
	loopCount=z;
	

	
	int wantedLoop;
	int firstBookNum;
	int bookingInt;

	bookingInt=atoi(Booking);
	firstBookNum=atoi(data[0].bookNum);
	wantedLoop = bookingInt-firstBookNum;

	
	printf("\nEditing record number %s Please enter the following details:", data[wantedLoop].bookNum);
	fflush(stdin);
			
	printf("\n2)Name of Customer:\t");
	gets(data[wantedLoop].name);
	strcat(data[wantedLoop].name, "\n");
			
	printf("3)Name of Movie:\t");
	gets(data[wantedLoop].movie_name);
	strcat(data[wantedLoop].movie_name, "\n");
		
	printf("4)Movie Schedule:\t");
	gets(data[wantedLoop].movie_schedule);
	strcat(data[wantedLoop].movie_schedule, "\n");
			
	printf("5)Time:\t\t\t");
	gets(data[wantedLoop].time);
	strcat(data[wantedLoop].time, "\n");
			
	printf("6)Number of Guests:\t");
	gets(data[wantedLoop].numofGuests);
	strcat(data[wantedLoop].numofGuests, "\n");
			
	printf("7)House Number:\t\t");
	gets(data[wantedLoop].houseNum);
	strcat(data[wantedLoop].houseNum, "\n");
			
	printf("8)Ticket Type:\t\t");
	gets(data[wantedLoop].ticketType);
	strcat(data[wantedLoop].ticketType, "\n");
			
	printf("9)Total Fee:\t\t$");
	gets(data[wantedLoop].totalFee);
	strcat(data[wantedLoop].totalFee, "\n");

	
	
	FILE *fileOut;
	fileOut = fopen("customer_temp.txt", "w");
	
	for (z=0;z<loopCount; z++){
				fputs(data[z].bookNum, fileOut);
				fputs(data[z].name, fileOut);
				fputs(data[z].movie_name, fileOut);
				fputs(data[z].movie_schedule, fileOut);
				fputs(data[z].time, fileOut);
				fputs(data[z].numofGuests, fileOut);
				fputs(data[z].houseNum, fileOut);
				fputs(data[z].ticketType, fileOut);
				fputs(data[z].totalFee, fileOut);
		};	
	fclose(fileOut);
	printf("Succesfuly updated!");
	remove("customer.txt");
	rename("customer_temp.txt","customer.txt");
	fflush(stdin);getchar();
	
	printf("\nWould you like to modify another record? (y/n) ");
	fflush(stdin);
	scanf("%c",&YesAndNo);
	if(!checkYN(YesAndNo)){
	    	goto loop;	
		}
	else{
		printf("Exiting to main menu.");
		fflush(stdin);getchar();
	}
}




void searchRecord()
{      
       int z ; 
       int searchmbkn;
       char search[100];
       char yorno,yorno1;
       struct record data[100];	
       do{	
       	fflush(stdin);
              FILE *fp;
	          fp = fopen("customer.txt","r");
	           printf("\nPlease enter the booking number that you want to search: ");
	            scanf("%d",&searchmbkn);
	            
	       while(fgets(data[z].bookNum, 80, fp) != '\0'){   //Load all data in customer.txt into the struct array
			fgets(data[z].name, 80, fp);
			fgets(data[z].movie_name, 80, fp);
			fgets(data[z].movie_schedule, 80, fp);
			fgets(data[z].time, 80, fp);
			fgets(data[z].numofGuests, 80, fp);
			fgets(data[z].houseNum, 80, fp);
			fgets(data[z].ticketType, 80, fp);
			fgets(data[z].totalFee, 80, fp);
			z++;
			}
	fclose(fp);
	
       	    printf("\nMovie Booking Number:\t%s", data[searchmbkn-1].bookNum);
			printf("\nCustomer name:\t\t%s", data[searchmbkn-1].name);
			printf("\nMovie name:\t\t%s", data[searchmbkn-1].movie_name);
			printf("\nMovie schedule:\t\t%s", data[searchmbkn-1].movie_schedule);
			printf("\nTime:\t\t\t%s", data[searchmbkn-1].time);
			printf("\nNumber of guests:\t%s", data[searchmbkn-1].numofGuests);
			printf("\nHouse number:\t\t%s", data[searchmbkn-1].houseNum);
			printf("\nTicket Type(s):\t\t%s", data[searchmbkn-1].ticketType);
			printf("\nTotal Fees:\t\t$%s\n", data[searchmbkn-1].totalFee);

		    fflush(stdin);
		    printf("\nSearch another Movie Ticketing record? (y/n)");
    	    scanf("%c",&yorno);
            }while(yorno=='y');

}
void deleteRecord()
{
    int booking;
    int i=0;
    int z;
    FILE *fp1,*fp2;
    struct record data[100];
    char yesorno;
	char enter,YesAndNo;
	
    do{
		printf("Display current records? (y/n) ");
		fflush(stdin);
		scanf("%c",&YesAndNo);
    	if(!checkYN(YesAndNo)){
	    fflush(stdin);
		DisplayAll(1);	
		fflush(stdin);	
	
    printf("Please enter the booking number you want to delete:");
    scanf("%d",booking);
    
    fp1=fopen("customer.txt","r");
    if(!fp1){
    	exit(1);
	}
	while(fgets(data[z].bookNum, 80, fp1) != '\0'){   //Load all data in customer.txt into the struct array
			fgets(data[z].name, 80, fp1);
			fgets(data[z].movie_name, 80, fp1);
			fgets(data[z].movie_schedule, 80, fp1);
			fgets(data[z].time, 80, fp1);
			fgets(data[z].numofGuests, 80, fp1);
			fgets(data[z].houseNum, 80, fp1);
			fgets(data[z].ticketType, 80, fp1);
			fgets(data[z].totalFee, 80, fp1);
			z++;
			}
    
	fp2=fopen("text.txt","w");
	for(i=0;i<100;i++){
    if(i==booking-1)
		continue;
	else{
    	fputs(data[i].name,fp2);
		fputs(data[i].movie_name,fp2);
		fputs(data[i].movie_schedule,fp2);
		fputs(data[i].time,fp2);
		fputs(data[i].numofGuests,fp2);
		fputs(data[i].houseNum,fp2);
		fputs(data[i].ticketType,fp2);
		fputs(data[i].totalFee,fp2);
	}    }                    
	fclose(fp1);
	fclose(fp2);
	printf("\nRecord deleted sucessfully!");
	remove("customer.txt");
	rename("text.txt","customer.txt");
	printf("\nDo you want to delete another record(y/n):");
	scanf("%c%c",&yesorno,&enter);
    }else{
	yesorno='n';
	}
	}while(yesorno=='y');
}



void Movie_Info()
{
	char MovOp[80];
	int i;
	int count=0;
	int input, target;
	struct Info data[10];
	char YesAndNo;
	
	FILE *fileIn;
	
	fileIn = fopen("movie.txt","r");
	if (fileIn == NULL)
	{
		printf("Error in opening file!");
		exit(1);
	}
	while(fgets(data[count].order, 80, fileIn) != '\0')
		{
			fgets(data[count].MovieName, 80, fileIn);
			fgets(data[count].Time, 80, fileIn);
			count++;
		}
			
	printf("Welcome to Movie Schedule Checking site!\n");
	printf("---------------------------------------\n");
	loop:
	printf("\nPlease type a movie name to find out the schedule: \n");
	printf("1)Avengers:Endgame 2)Fantastic Beasts: The Crime of Grindelwald 3)The Chronicles of Narnia: The Voyage of the Dawn Trader 4)Harry Potter and The Deathly Hollows: Part2 5)Captain Marvel 6)Beauty and the Beast 7)Midnight Sun \n");
	scanf("%d",&input);
	
	for (i=0; i<count; i++)
	{
		target = atoi(data[i].order);
		
		if (input==target)
		{
			printf("Name of the Movie:\t%sSchedule:\t\t%s",data[i].MovieName,data[i].Time);
			break;
		}
	}
	fflush(stdin); getchar();
	
	printf("\nWould you like to check another schedule? (y/n) ");
	fflush(stdin);
	scanf("%c",&YesAndNo);
	if(!checkYN(YesAndNo)){
	    	goto loop;	
		}
	else{
		printf("Exiting to main menu.");
		fflush(stdin);getchar();
	fclose(fileIn);
	}
}
void Addcomment()
{
	FILE *commentfp;
	commentfp=fopen("comment.txt","a+");
	struct data info;
	int i=0;
	if(commentfp==NULL){
		printf("The COMMENT CORNER will open soon!^.^");
		exit(0);
	}
	shuu:
	printf("Welcome to the COMMENT CORNER!\n");
	printf("==============================\n");
	
		printf("Please share your views on the movies!>.0\n\n");
		printf("Movie name:");
		fflush(stdin);
		gets(info.filmname);
		printf("Score<1-10>:");
		gets(info.starcount);
		printf("Comment:");
		gets(info.comment);
		fprintf(commentfp,"%s",info.filmname);
		fprintf(commentfp,"\n%s",info.starcount);
		fprintf(commentfp,"\n%s",info.comment);
		fclose(commentfp);
	 	printf("\nExit to main menu.");
		fflush(stdin);getchar();
}
void Displaycomment()
{
	FILE *commentfp;
	struct data info;
	char chr;
	int z=0;
	printf("\t\t\tDisplay Newest Movie Comment \t\t\t\t");
	printf("\t\t----------------------------------------------\n");
	commentfp=fopen("comment.txt","r");
	
		fscanf(commentfp, "%s",&info.filmname);
		printf("Filename:\t\t%s", info.filmname);
		fscanf(commentfp, "%s",&info.starcount);
		printf("\nStar count:\t\t%s", info.starcount);
		fscanf(commentfp, "%s",&info.comment);
		printf("\ncomment:\t\t%s\n", info.comment);
			
	fclose(commentfp);
	printf("\nExit to main menu.");
	fflush(stdin);getchar();
}

