#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

// cards_len은 배열 cards의 길이입니다.
int solution(int cards[], size_t cards_len) {
    int answer = 0;
    int* CheckingList = (int*)malloc(sizeof(int)*cards_len);
    for (int i = 0; i < cards_len; i++)
    {
        CheckingList[i] = 0;
    }
    int MaxNum = cards_len;
    int MostNum = 0;
    int NextNum = 0;
    int index = 0;
    int count = 0;

    while (1)
    {
        if (CheckingList[index] == 0)
        {
            CheckingList[index] = 1;
            MaxNum--;
            count++;
            index = cards[index]-1;
        }
        else if (CheckingList[index] == 1)
        {
            index++;
            if (count > MostNum)
            {
                MostNum = count;
            }
            else if (count > NextNum)
            {
                NextNum = count;
            }
            count = 0;
            if (MaxNum <= 0)
            {
                break;
            }
        }
        cout << "index : " << index << endl;
    }
    cout << "MostNum : " << MostNum << ", NextNum : " << NextNum << endl;
    answer = MostNum * NextNum;
    free(CheckingList);
    return answer;
}

int main()
{
    int list[10] = {2,3,1,4,5,6,7,8,10,9};
    int s = solution(list,10);
    cout << s;
}