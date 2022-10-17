#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

/* 
���̵��� �ִ�Ƚ���� üŷ����Ʈ�� Ȯ���ϴ� ���Դϴ�.

ī�� ����Ʈ ���� ��� ���ڸ� �����ϱ� ������ �ִ� ī�帮��Ʈ ���̸�ŭ �ݺ��۾��� �ؾ��մϴ�. �׷��Ƿ� �극��ũ �������
�ִ� Ƚ���� 0�� �� ���� �Ͽ����ϴ�. (�۾��� �ѹ� ������ ������ �ִ� Ƚ���� 1�� ���ҽ��׽��ϴ�.)

üŷ����Ʈ�� ��ȯ��ġ���� ���� ���� Ȯ���ϱ� ���԰� ���� ������ġ�� �˾Ƴ��� ���� �غ��Ͽ����ϴ�.
üŷ����Ʈ�� ���ڴ� 0���� �ʱ�ȭ�� �ϰ� ���̴� ī�� ����Ʈ��ŭ �غ��մϴ�. ī�帮��Ʈ�� n��° ���ڸ� ��ġ�ߴٸ�
üŷ����Ʈ�� n��° ���ڴ� 1�� �ٲߴϴ�. �� üŷ����Ʈ�� ���ڰ� 1�̸� ���� ��ġ�� ī�帮��Ʈ ���ڸ� ��ġ�ߴٴ� �ǹ��Դϴ�.
��ȯ�� �ϴٰ� üũ����Ʈ�� 1�� ���ڸ� �����ٸ� ������ġ�� ���ƿԱ� ������ �׶� ������ Ƚ���� �����ϰ� üũ����Ʈ�� ���ڰ�
0�� ��ġ�� ã�Ƽ� �ٽ� �����մϴ�.

�ְ� Ƚ���� �� ���� Ƚ���� ��� �񱳸� ���� �����ϰ� ���������� ���ؼ� �����մϴ�.
*/
// cards_len�� �迭 cards�� �����Դϴ�.
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