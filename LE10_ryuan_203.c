#include <stdio.h>
#include <stdlib.h>
#define size 40

typedef struct
{
    int ID;
    char name[35];
} driver;

int main()
{
    char inbuf[size];
    int num, i;
    do
    {
        printf("Enter an integer to create an array between 2 to 5: \n");
        fgets(inbuf, size, stdin);
        sscanf(inbuf, "%d", &num);
        if (num < 2 || num > 5)
        {
            printf("Input wrong range. Please enter again!\n");
        }
    } while (num < 2 || num > 5);

    driver *driverInfo;
    driverInfo = (driver *)malloc(sizeof(driver) * num);

    for (i = 0; i < num; i++)
    {
        printf("Driver %d, Id: \n", (i + 1));
        fgets(inbuf, size, stdin);
        sscanf(inbuf, "%d", &driverInfo[i].ID);

        printf("Driver %d, name: \n", (i + 1));
        fgets(inbuf, size, stdin);
        sscanf(inbuf, "%[^\n]", driverInfo[i].name);
    }

    printf("Driver's Licenses: \n");
    for (i = 0; i < num; i++)
    {
        printf("%d, %s\n", driverInfo[i].ID, driverInfo[i].name);
    }

    free(driverInfo);
    return 0;
}