#include <stdio.h>
#include <string.h>
#define sizeOfArray 5

void stringEncoder(char longText[79], char shortText[159]);
int passwordChecking(char password[]);
int isPasswordLengthValid(char password[]);
int isPasswordHasDigit(char password[]);
int isPasswordHasLowerCase(char password[]);
int isPasswordHasUpperCase(char password[]);
int isPasswordNoConsecutiveRepeat(char password[]);
int isExternalRowsAndColumnsMultipleBy5(int arr2D[sizeOfArray][sizeOfArray], int size);
int isMultipleOfFive(int number);

int main()
{
    char longText[79];
    char shortText[159];
    char password[12];
    printf("Please enter a word\n");
    stringEncoder(longText, shortText);
    printf("%s\n\n", shortText);

    printf("Please enter a password with the next following roles:\n");
    printf("1: The password should be between 6 to 11 characters.\n");
    printf("2: The password should included at least: one digit, one lowercase letter and one uppercase letter.\n");
    printf("1: The password should not contain the same character twice in a row.\n");

    gets(password);
    if(passwordChecking(password))
    {
        printf("Congratulation! Your password is valid.\n\n");
    }
    else {
        printf("Your password is not valid\n\n");
    }

    int arr2D[sizeOfArray][sizeOfArray];
    printf("Please enter 25 integers into the matrix:\n");
    for (int i = 0; i < sizeOfArray; ++i)
    {
        for (int j = 0; j < sizeOfArray; ++j)
        {
            scanf("%d", &arr2D[i][j]);
        }
    }
    if (isExternalRowsAndColumnsMultipleBy5(arr2D, sizeOfArray))
    {
        printf("Good job! All of your external rows and columns are multiples by 5!\n");
    }
    else
    {
        printf("Not all of your external rows and columns are multiples by 5.\n");
    }
    return 0;
}

void stringEncoder(char longText[79], char shortText[159])
{
    gets(longText);
    int counter = 1;
    int j = 0;
    int i = 0;
    for (i = 1; i < 79; ++i)
    {
        if(longText[i - 1] == longText[i])
        {
            counter++;
        }
        else
        {
            shortText[j] = longText[i - 1];
            char number = counter + '0';
            shortText[j + 1] = number;
            counter = 1;
            j = j + 2;
            if(longText[i] == '\0')
            {
                shortText[j] = '\0';
                break;
            }
        }
    }
}
int passwordChecking(char password[])
{
    if(isPasswordLengthValid(password) && isPasswordHasDigit(password) && isPasswordHasLowerCase(password) && isPasswordHasUpperCase(password) && isPasswordNoConsecutiveRepeat(password))
        return 1;
    return 0;
}

int isPasswordLengthValid(char password[])
{
    int length = strlen(password);
    if(length > 5 && length < 12)
    {
        return 1;
    }
    return 0;
}
int isPasswordHasDigit(char password[])
{
    int i = 0;
    for(i = 0; i < strlen(password); ++i)
    {
        if(password[i] >= '0' && password[i] <= '9')
        {
            return 1;
        }
    }
    return 0;
}

int isPasswordHasLowerCase(char password[]) {
    for(int i = 0; i < strlen(password); ++i)
    {
        if(password[i] >= 'a' && password[i] <= 'z')
        {
            return 1;
        }
    }
    return 0;
}
int isPasswordHasUpperCase(char password[])
{
    for(int i = 0; i < strlen(password); ++i)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
        {
            return 1;
        }
    }
    return 0;
}
int isPasswordNoConsecutiveRepeat(char password[])
{
    for (int i = 0; i < strlen(password); ++i)
        if(password[i] == password[i + 1])
        {
            return 0;
        }
    return 1;
}
int isExternalRowsAndColumnsMultipleBy5(int arr2D[][sizeOfArray], int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
            {
                if (!isMultipleOfFive(arr2D[i][j]))
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int isMultipleOfFive(int number)
{
    if (number % 5 == 0)
        return 1;
    return 0;
}