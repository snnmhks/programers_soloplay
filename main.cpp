#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

/* 
아이디어는 최대횟수와 체킹리스트를 확인하는 것입니다.

카드 리스트 안의 모든 인자를 봐야하기 때문에 최대 카드리스트 길이만큼 반복작업을 해야합니다. 그러므로 브레이크 컨디션은
최대 횟수가 0이 될 때로 하였습니다. (작업을 한번 수행할 때마다 최대 횟수를 1씩 감소시켰습니다.)

체킹리스트는 순환위치까지 오는 것을 확인하기 위함과 다음 시작위치를 알아내기 위해 준비하였습니다.
체킹리스트의 인자는 0으로 초기화를 하고 길이는 카드 리스트만큼 준비합니다. 카드리스트의 n번째 인자를 서치했다면
체킹리스트의 n번째 인자는 1로 바꿉니다. 즉 체킹리스트의 인자가 1이면 같은 위치의 카드리스트 인자를 서치했다는 의미입니다.
순환을 하다가 체크리스트가 1인 인자를 만난다면 시작위치로 돌아왔기 때문에 그때 까지의 횟수를 저장하고 체크리스트의 인자가
0인 위치를 찾아서 다시 시작합니다.

최고 횟수와 그 다음 횟수는 대소 비교를 통해 저장하고 마지막으로 곱해서 리턴합니다.
*/
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
                NextNum = MostNum;
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
        cout << "count : " << count << endl;
    }
    cout << "MostNum : " << MostNum << ", NextNum : " << NextNum << endl;
    answer = MostNum * NextNum;
    free(CheckingList);
    return answer;
}

int main()
{
    int list[21] = {1,3,2,5,6,4,8,9,10,7,12,13,14,15,11,17,18,19,20,21,16};
    int s = solution(list,21);
    cout << s;
    int j;
    cin >> j;
}