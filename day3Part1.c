#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


const int binNum = 12;
// const int binNum = 5;

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
    // pDataArray = (int*) memset(dataArray , 0, rowNum*binNum*sizeof(int) );
    pDataArray = malloc( (rowNum * binNum) * sizeof(int) );
    // pDataArray = dataArray[0];
    if(!pDataArray){
        printf("FAIL");
    }
    long long binStore2 = 0;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!defining this variable any lower in the programme breaks it all
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


    
    
    //===============summing the values of each position==================
    int arraySum[binNum];
    for(i=0; i<binNum; i++) {
      arraySum[i] = 0;
    }

    for(i=0; i<rowNum; i++) {
      for(j=0;j<binNum;j++) {
            arraySum[j] += dataArray[i][j];
      }
    }

    free(pDataArray);
    pDataArray = NULL;
    

    binStore2 = 0; ///!!!!!!!!!!!!!!!!!!!!!!!!!!!! CREATING THIS LONG BREAKS THE CREATION OF THE THE OTHER LONG
   
    long long binStore1 = 0;
    for ( i = 0; i < binNum; i++)
    {
        if(arraySum[binNum - i - 1] > rowNum/2){
            arraySum[binNum - i - 1] = 1;
            binStore1 += 1 * pow((double)10, (double)i);
            binStore2 += 0 * pow((double)10, (double)i);
        }else{
            arraySum[binNum - i - 1] = 0;
            binStore1 += 0 * pow((double)10, (double)i);
            binStore2 += 1 * pow((double)10, (double)i);
        }
    }

    //==================invert bin number

    printf("The binary result is %lld\n", binStore1);
    printf("The binary result is %lld\n", binStore2);
    printf("The decimal result is %lld\n", binaryToDecimal(binStore1));
    printf("The decimal result is %lld\n", binaryToDecimal(binStore2));
    printf("Their sum is %lld", binaryToDecimal(binStore1) * binaryToDecimal(binStore2));



 
    


    printf("\n\n\n");

    return 0;
}