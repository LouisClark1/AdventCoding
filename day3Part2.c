#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long long binStore2 = 0;
const int binNum = 12;
// const int binNum = 5;


int sumAColumn (int *arrayPointer, int colNum, int *arraySizePointer){
    int localBinNum = *arraySizePointer;
    int localFileLength = *(arraySizePointer+1);
    int arraySum = 0;

    for(int j=0;j<localFileLength;j++) {
        arraySum += *(arrayPointer + colNum + j * localBinNum);
        printf("array *arrayPointer %i\n", *(arrayPointer + colNum + j * localBinNum));
    }


    return arraySum;
}

long long binaryToDecimal(long long n)
{
    long long num = n;
    long long dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    long long base = 1;
 
    long long temp = num;
    while (temp) {
        long long last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}

int main(){
    FILE *pFile = NULL;
    char * fileName = "testData.txt";
    pFile = fopen(fileName,"r");
    if(!pFile){
        printf("failed to open %s\n", fileName);
        return -1;
    }

    int i = 1;
    int fileValue;
    while (fileValue != EOF){
        fileValue = fgetc(pFile);
        i++;
    }
    //================ this counts the size of the input file==========
    rewind(pFile);
    int dataRead;
    int rowNum = 0;
    int dataCounter = 0;
    while (dataRead != EOF){
        dataRead = fgetc(pFile);
        if (dataCounter%(binNum + 1) == 0){
            rowNum++;
        }
        dataCounter++;
    }
    //================= making array to hold the data=================
    int dataArray[rowNum][binNum];
    int * pDataArray = NULL;
    //     // pDataArray = (int*) memset(dataArray , 0, rowNum*binNum*sizeof(int) );
    // pDataArray = malloc( (rowNum * binNum) * sizeof(int) );
    pDataArray = dataArray[0];//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!this isn't in the previous version
    // if(!pDataArray){
    //     printf("FAIL");
    // }
    // free(pDataArray);

    //=================populating the data array with data================
    rewind(pFile);
    int rowNumCount = 0;
    dataCounter = 0;
    dataRead = 0;
    while (dataRead != EOF){
         if ( (dataCounter%(binNum + 1) == 0) && (dataCounter != 0)){
            rowNumCount++;
        }
        dataRead = fgetc(pFile);
        dataArray[rowNumCount][dataCounter%(binNum + 1)] = dataRead;
        dataCounter++;
    }

    fclose(pFile);
    pFile = NULL;

    //================string array to int array=========================
    int j;
    for(i=0; i < rowNum; i++) {
      for(j=0; j < binNum; j++) {
            char tempString[2] = {0, '\0'};
            tempString[0] = dataArray[i][j];
            dataArray[i][j] = atoi(tempString);
      }
    }
    //===================check for most commin first value=================
 
    int dataArraySize[2] = {binNum, rowNum};
    int *pDataArraySize = dataArraySize;
    int arrayColSum = sumAColumn(pDataArray,0, pDataArraySize);//col starts at 0
    int binChoice = 0;
    if(arrayColSum > dataArraySize[1]/2){
            printf("The choice is 1\n");
            binChoice = 1;
        }else{
            printf("The choice is 0\n");
        }
    //=======================count the size of the next array to make===========
    int newArrayLength;
    for(j=0;j<rowNum;j++) {
        if (dataArray[j][0] == binChoice){
            printf("data from loop %i & bin choice %i",dataArray[j][0], binChoice);
            // newArrayLength++;                
        }
    }
    // printf("New array length is %i", newArrayLength);
    
//==================================making new reduced arrays===============
    int tempRowNum, tempBinNum;

    // int dataArray[rowNum][binNum];
    // int * pDataArray = NULL;




    printf("\n\n\n It ran ok");

    return 0;
}