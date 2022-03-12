#define _CRT_SECURE_NO_WARNINGS 1
/*
	48. 旋转图像
		给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
		- 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
*/

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
	//用i来控制圈数，最外层是第0圈，一共进行matrixSize/2-1圈
	for (int i = 0; i < matrixSize / 2; i++) {
		//用j对圈内元素的一排进行处理，从j开始，到本排倒数第二个元素截至
		for (int j = i; j < matrixSize - i - 1; j++) {
			//完成4次赋值
			int temp = matrix[i][j];
			matrix[i][j] = matrix[matrixSize - j - 1][i];
			matrix[matrixSize - j - 1][i] = matrix[matrixSize - i - 1][matrixSize - j - 1];
			matrix[matrixSize - i - 1][matrixSize - j - 1] = matrix[j][matrixSize - i - 1];
			matrix[j][matrixSize - i - 1] = temp;
		}
	}
	return;
}