#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>



int QuantityOfStrs(char * str);

int QuanOfSymbInStr(char * str);

int SizeOfStr(char * str);

int AllStrsAndReplace(char *Str, size_t SizeOfFile, char FirstSymb, char SecondSymb, size_t *NumOfStrs);

void PrintText(char **ArrOfPtr, int QuantityOfStrs);

size_t LenFile(FILE * fp);

int compare(const void *str1, const void *str2);




int main()
{
    FILE * fp = fopen("Mockingbird.txt", "r");

    size_t SizeOfFile = LenFile(fp);

    char *Buff = (char*)(calloc(SizeOfFile, sizeof(char)));

    fread(Buff, sizeof(char), SizeOfFile, fp);

    size_t NumOfStrs = 0;

    size_t QuantityOfStrs = AllStrsAndReplace(Buff, SizeOfFile, '\n', '\0', &NumOfStrs);

    char **ArrOfPtr = (char**)(calloc(NumOfStrs, sizeof(char*)));

    size_t NumOfStr = 0;

    ArrOfPtr[0] = &Buff[0];

    size_t CntOfPtr = 1;

    for(NumOfStr = 1; NumOfStr < SizeOfFile; NumOfStr++)
    {
        if ((Buff[NumOfStr] == '\0') && ((NumOfStr) != (SizeOfFile-1)))
        {
            ArrOfPtr[CntOfPtr] = &(Buff[NumOfStr+1]);
            CntOfPtr++;
        }
    }

    /*int Sravn = 0;
    char * Swap = 0;

    for(NumOfStr = 0; NumOfStr < QuantityOfStrs - 1; NumOfStr++)
    {
        for(size_t NumOfStr_ = 0; NumOfStr_ < QuantityOfStrs - 1; NumOfStr_++)
        {
            Sravn = strcmp(ArrOfPtr[NumOfStr], ArrOfPtr[NumOfStr_]);
            if (Sravn < 0)
            {
                Swap = ArrOfPtr[NumOfStr_];
                ArrOfPtr[NumOfStr_] = ArrOfPtr[NumOfStr];
                ArrOfPtr[NumOfStr] = Swap;
            }
        }
    }      */



    qsort(ArrOfPtr, QuantityOfStrs, sizeof(char*), compare);

    PrintText(ArrOfPtr, QuantityOfStrs);


    free(Buff);
    free(ArrOfPtr);

    fclose(fp);

    return 0;


}



int compare(const void *str1, const void *str2)
    {
        char * str3 = *(char**)str1;
        char * str4 = *(char**)str2;
        return strcmp(str3, str4);
    }

void PrintText(char **ArrOfPtr, int QuantityOfStrs)
{
    for(int NumOfStr = 0; NumOfStr < QuantityOfStrs; NumOfStr++)
    {
        printf("%s\n", (ArrOfPtr[NumOfStr]));

    }
}



int QuanOfSymbInStr(char * str)
{
    int num = 0;

    int NumOfElem = 0;

    while(str[NumOfElem] != '\0')
    {
        if(str[NumOfElem] != ' ')
            num++;
        NumOfElem++;
    }

    return num;

}

int QuantityOfStrs(char * str)
{
    int colls = 0;

    for(size_t NumOfElem = 0; NumOfElem < strlen(str); NumOfElem++)
    {
        if(str[NumOfElem] == '\n')
        {
            colls++;
        }

    }
    return colls;
}



int AllStrsAndReplace(char *Str, size_t SizeOfFile, char FirstSymb, char SecondSymb, size_t *NumOfStrs)
{
    for (size_t NumOfStr = 0; NumOfStr < SizeOfFile; NumOfStr++)
    {
        if (Str[NumOfStr] == FirstSymb)
        {
            (*NumOfStrs)++;

            Str[NumOfStr] = SecondSymb;

        }
    }

    return *NumOfStrs;
}

size_t LenFile(FILE * fp)
{
    size_t SizeOfFile = 0;

    struct stat FileLen;

    fstat(fileno(fp), &FileLen);

    SizeOfFile = FileLen.st_size + 1;

    return SizeOfFile;

}
