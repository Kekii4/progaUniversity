#include <stdio.h>


const int SIZE_LINE = 5;
const int SIZE_ROW = 6;

int main(){

    printf("hello world!\n");

    int arr[SIZE_LINE][SIZE_ROW] = {{1, 0, 0, 0, 0, 0},
                                    {1, 0, 1, 1, 1, 0},
                                    {0, 0, 1, 0, 1, 0},
                                    {0, 0, 1, 1, 1, 0},
                                    {0, 0, 0, 0, 0, 0}};
    int numberOfRectangles = 0;

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

                    for (int byWidth = i; byWidth < relativeWidth; byWidth++){
                        for (int byLength = j; byLength < relativeLength; byLength++){
                            if (arr[byWidth][byLength] != 1){
                                boolFlag = 1;
                                break;
                            }

                            if (arr[byWidth][relativeLength] == 1){
                                boolFlag = 1;
                                break;
                            }

                            if (arr[relativeWidth][byLength] == 1){
                                boolFlag = 1;
                                break;
                            }    
                        }
                        if (boolFlag){
                            break;
                        }
                    }

                    if (!boolFlag){
                        numberOfRectangles++;
                    }
                }
            }
        }
    }

    printf("amount = %d\n", numberOfRectangles);

    return 0;
}