#include <stdio.h>
void generateSpiralMatrix(int n) {
    int matrix[30][30];  // ���� n x n �Ķ�ά����
    int num = 1;       // �������������ʼ����
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        // ����������ϱ߽�
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;
        // ���ϵ�������ұ߽�
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;
        // ���ҵ�������±߽�
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }
        // ���µ��������߽�
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }
    // ��ӡ����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matrix[i][j]);  // ��ʽ�������ʹÿ������ռ�ݹ̶����
        }
        printf("\n");  // ÿ���һ�д�ӡ���з�
    }
}
int main() {
    int n;
    printf("���������Ĵ�С: ");
    scanf_s("%d", &n);  // ��ȡ�û�����
    generateSpiralMatrix(n);  // ���ú������ɲ���ӡ��������
    return 0;
}