#include <stdio.h>
void generateSpiralMatrix(int n) {
    int matrix[30][30];  // 创建 n x n 的二维数组
    int num = 1;       // 用于填充矩阵的起始数字
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        // 从左到右填充上边界
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;
        // 从上到下填充右边界
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;
        // 从右到左填充下边界
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }
        // 从下到上填充左边界
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }
    // 打印矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matrix[i][j]);  // 格式化输出，使每个数字占据固定宽度
        }
        printf("\n");  // 每完成一行打印换行符
    }
}
int main() {
    int n;
    printf("请输入矩阵的大小: ");
    scanf("%d", &n);  // 读取用户输入
    generateSpiralMatrix(n);  // 调用函数生成并打印螺旋矩阵
    return 0;
}