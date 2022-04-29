#include <stdio.h>

const int SIZE_LINE = 5;
const int SIZE_ROW = 6;

int main(){

    int arr[SIZE_LINE][SIZE_ROW] = {{1, 0, 0, 0, 0, 0},
                                    {0, 1, 1, 1, 1, 0},
                                    {0, 1, 1, 1, 1, 0},
                                    {0, 1, 1, 1, 1, 0},
                                    {0, 0, 0, 1, 0, 0}};
    int numberRectangles = 0;

    int Width = 0;
    int Length = 0;

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

                    Width = i + 1;
                    Length = j + 1;

                    while (arr[Width][j] == 1){
                        if (arr[Width][j-1] == 1){
                            boolFlag = 1;
                            break;
                        }
                        Width++;
                    }
                    if (boolFlag){
                        continue;
                    }                   
                    
                    while (arr[i][Length] == 1){
                        if (arr[i-1][Length] == 1){
                            boolFlag = 1;
                            break;
                        }
                        Length++;
                    }
                    if (boolFlag){
                        continue;
                    }

                    if (arr[Width][Length] == 1){
                        continue;
                    }

                    for (int byWidth = i + 1; byWidth < Width; byWidth++){
                        if (arr[byWidth][Length] == 1){
                            boolFlag = 1;
                            break;
                        }

                        for (int byLength = j + 1; byLength < Length; byLength++){
                            if (arr[byWidth][byLength] != 1){
                                boolFlag = 1;
                                break;
                            }
                            if (byWidth == i + 1 && arr[Width][byLength] == 1){
                                boolFlag = 1;
                                break;
                            }    
                        }
                        if (boolFlag){
                            break;
                        }
                    }

                    if (!boolFlag){
                        numberRectangles++;
                    }
                }
            }
        }
    }

    printf("amount = %d\n", numberRectangles);

    return 0;
}