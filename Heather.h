#include <studio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
using namespace std;

struct record{
  char bookNum[80];
  char name[80];
  char movie_name[80];
  char time[80];
  char numofGuests[80];
  char houseNum[80];
  char ticketType[80];
  char totalFee[80];
  };

struct data{
	char filmname[30];
	char starcount[2];
	char comment[200];
};
struct Info
{
	char order[80];
	char MovieName[80];
	char Time[80];	
};

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
