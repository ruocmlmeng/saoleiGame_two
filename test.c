#include "game.h"
//������Ϸ��ʼ�Ĳ˵�
void menu()
{
    printf("******************************\n");
    printf("********  1.play   ***********\n");
    printf("********  0.exit   ***********\n");
    printf("******************************\n");
}

//��ʼ��Ϸ�ĺ���
void game()
{
    char mine[ROWS][COLS] = {0};
    char show[ROWS][COLS] = {0};

    //��ʼ������
    InitBoard(mine,ROWS,COLS,'0');
    InitBoard(show,ROWS,COLS,'*');
    //չʾ����
    // DisPlayBoard(mine,ROW,COL);
    // DisPlayBoard(show,ROW,COL);
    //��ʼ����
    SetMine(mine,ROW,COL);
    DisPlayBoard(mine,ROW,COL);

    //��ʼ����-�����߼�
    FindMine(mine,show,ROW,COL);
    // DisPlayBoard(show,ROW,COL);


}
int main()
{
    //������������ĳ�ʼ������
    srand((unsigned int )time(NULL));
    int input = 0;
    do
    {
        menu();
        printf("���������ѡ��:>");
        scanf("%d",&input);
        switch (input)
        {
            case 1:
                //��ʼ��Ϸ�ĺ���
                game();
                break;
            case 0:
                printf("�˳���Ϸ\n");
                break;
            default:
                printf("�����������������\n");
                break;
        }
    } while (input);

    return 0;
}
//����ʵ�ֵ��ǻ�������
//������չ
//1.����׵Ĺ���
//2.չ��һƬ�Ĺ���
//  �Ų�x,y�����ʱ��:
//  1.�����겻����
//  2.��������Χû����
//  3.������û�ñ��Ų��