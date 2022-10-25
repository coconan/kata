#include <stdio.h>
#define MAX 100005
int a[MAX];
int visit[MAX];

//ʵ������dfs��˼�룬����ֱ������dfs�ĵݹ鷽ʽ�������ϲ������úá�����ȻPATOJ�ϲ��Է������߶���AC-,-��
int getLink(int x) {
    int count = 0;
    while (!visit[x]) {
        visit[x] = 1;
        ++ count;
        x = a[x];
    }
    return count;
}

int main() {
    int n, res = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; ++ i) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; ++ i) {
        int count = getLink(i);
        //���count == 1�������������Ҫ�ƶ������üӵ�res�ϣ�
        //���count == 0���������λ�õ����Ѿ������ʹ���ͬ�����ü��롣
        if (count != 1 && count != 0) {
            //����ٶ�0���������link�У����ǣ����ȵý�0swap�����link�У�
            //�ٽ���swap����������Ҫ+1. ��Ϊ��������������{0, 2, 1}��
            //getLink(1)����2����swap����������Ҫ��0��1������2��������
            //�õ�{2, 0, 1}��Ȼ��0��2�����õ�{2, 1, 0}���ٽ�0��2�����õ������
            res += count + 1;
        }
    }

    //֮ǰ�������У���ÿ��link�ļ��㣬������0����link�С����0��������0��λ�ã�
    //��ô������һ��link�ļ����ǰ�����0�ġ���0��link�кͲ���link�У�swap��Ŀ���2.
    //���Ǹ��������-2.
    if (a[0] != 0) {
        res -= 2;
    }

    printf("%d\n", res);

    return 0;
}
