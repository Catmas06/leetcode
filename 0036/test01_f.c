#define _CRT_SECURE_NO_WARNINGS 1
/*
	36.有效的数独
		请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
		- 数字 1-9 在每一行只能出现一次。
		- 数字 1-9 在每一列只能出现一次。
		- 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

*/
#include<stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
	int* temp = (int*)malloc(sizeof(int) * 9);
	//对每一行进行判断
	for (int i = 0; i < boardSize; i++) {
		//初始化辅助字符数组
		for (int t = 0; t < boardSize; t++) {
			temp[t] = 0;
		}
		for (int j = 0; j < boardSize; j++) {
			if (board[i][j] != '.') {
				temp[board[i][j] - '1']++;
				//一行内同一个元素出现超过一次
				if (temp[board[i][j] - '1'] > 1)
					return false;
			}
		}
	}
	//对每一列进行判断
	for (int i = 0; i < boardSize; i++) {
		//初始化辅助字符数组
		for (int t = 0; t < boardSize; t++) {
			temp[t] = 0;
		}
		for (int j = 0; j < boardSize; j++) {
			if (board[j][i] != '.') {
				temp[board[i][j] - '1']++;
				//一行内同一个元素出现超过一次
				if (temp[board[i][j] - '1'] > 1)
					return false;
			}
		}
	}
	//对每个九宫格判断
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			//每对一个宫处理前，先将辅助数组重置
			for (int t = 0; t < boardSize; t++) {
				temp[t] = 0;
			}
			for (int k = 0; k < 3; k++) {
				for (int m = 0; m < 3; m++) {
					if ((board[k + 3 * i][m + 3 * j]) != '.') {
						temp[board[k + 3 * i][m + 3 * j] - '1']++;
						if (temp[board[k + 3 * i][m + 3 * j] - '1'] > 1)
							return false;
					}
				}
			}
		}
	}
	return true;
}