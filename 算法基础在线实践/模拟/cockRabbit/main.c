/********************************
* ����ͬ������
* ����ද���� �� ���ٶ�����
*
* ���ߣ�jay.xu
* ���ڣ�2019-07-16
* ���룺�ܽ���N����������
* ��������ٶ����� ��ද����
*
* ˼·����1�����NΪ�������޴𰸣����0 0
*       ��2�����N��ż�����ܱ�4������������N/4ֻ���ӣ����N/2ֻ��
*       ��3�����N��ż���Ҳ��ܱ�4������������(N - 2)/4ֻ���Ӻ�1ֻ�������N/2ֻ��
********************************/


#include <stdio.h>

int main(void)
{
    int nCases, nFeets;
    int nMax, nMin;

    printf("��������������: \n");

    while(scanf("%d", &nCases) != EOF)
    {
        for(int i=0; i<nCases; i++)
        {
            printf("�����붯����ܽ���: \n");

            scanf("%d", &nFeets);

            if(nFeets % 4 == 0){
                nMax = nFeets / 4;
                nMin = nFeets / 2;

            }
            else if(nFeets % 2 == 0){
                nMax = nFeets / 4 + 1;
                nMin = nFeets / 2;
            }
            else{
                nMax = 0;
                nMin = 0;
            }

            printf("���ٵĶ�����: %d, ���Ķ�����: %d\n", nMax, nMin);
        }

        printf("\n\n��������������: \n");
    }

    return 0;
}
