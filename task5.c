#include <stdio.h>

const int SIZE_LINE = 5;
const int SIZE_ROW = 6;

int main(){

    printf("hello world!\n");

    int arr[SIZE_LINE][SIZE_ROW] = {{1, 0, 0, 0, 0, 0},
                                    {1, 0, 0, 1, 1, 0},
                                    {0, 0, 0, 1, 1, 0},
                                    {0, 0, 0, 0, 0, 1},
                                    {0, 0, 0, 0, 0, 1}};
    int amountOfSquare = 0;

    int relativeWidth = 0;
    int relativeLength = 0;

    // int realWidth = 0;
    // int realLength = 0;

    int boolFlag;

    for (int i = 0; i < SIZE_LINE; i++){
        for(int j = 0; j < SIZE_ROW; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < SIZE_LINE; i++){
        for (int j = 0; j < SIZE_ROW; j++){
            
            boolFlag = 0;

            if (arr[i][j]){
                if (arr[i-1][j] != 1 && arr[i-1][j-1] != 1 && arr[i][j-1] != 1){

                    relativeWidth = i + 1;
                    relativeLength = j + 1;

                    while (arr[relativeWidth][j] == 1){
                        if (arr[relativeWidth][j-1] == 1){
                            boolFlag = 1;
                            break;
                        }
                        relativeWidth++;
                    }
                    if (boolFlag){
                        continue;
                    }                   
                   
                    // realWidth = relativeWidth - i;

                    while (arr[i][relativeLength] == 1){
                        if (arr[i-1][relativeLength] == 1){
                            boolFlag = 1;
                            break;
                        }
                        relativeLength++;
                    }
                    if (boolFlag){
                        continue;
                    }

                    if (arr[relativeWidth][relativeLength] == 1){
                        continue;
                    }

                    // realLength = relativeLength - j;

                    for (int onWidth = i; onWidth < relativeWidth; onWidth++){
                        for (int onLength = j; onLength < relativeLength; onLength++){
                            if (arr[onWidth][onLength] != 1){
                                boolFlag = 1;
                                break;
                            }

                            // if (relativeLength - onLength == 1){
                            //     if (arr[onWidth][relativeLength] == 1){
                            //         boolFlag = 1;
                            //         break;
                            //     }
                            // }

                            // if (relativeWidth - onWidth == 1){
                            //     if (arr[relativeWidth][onLength] == 1){
                            //         boolFlag = 1;
                            //         break;
                            //     }
                            // }

                            if (arr[onWidth][relativeLength] == 1){
                                boolFlag = 1;
                                break;
                            }

                            if (arr[relativeWidth][onLength] == 1){
                                boolFlag = 1;
                                break;
                            }
                            
                        }
                        if (boolFlag){
                            break;
                        }

                    }

                    if (!boolFlag){
                        amountOfSquare++;
                    }
                    
                }
            }
        }
    }


    // printf("real width = %d, real Length = %d\n", realWidth, realLength);
    // printf("relative width = %d, relative length = %d\n", relativeWidth, relativeLength);

    printf("amount = %d\n", amountOfSquare);


    return 0;
}