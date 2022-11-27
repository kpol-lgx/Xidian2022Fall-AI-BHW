#include<iostream>
using namespace std;

const int N = 100; // 棋盘总的格子数

int valarry[400]; // 记录每种情况下棋盘的价值，当作栈处理
int top = 0; // 栈顶
int history[200]; // 记录下棋的每一步，用于恢复旧状态

struct state_press {
	// 使用 100 个 char 类型储存棋盘每个位置的状态
	// 0 空位置
	// & 我方棋子
	// % 敌方棋子
	char pos[N];
	int value;
};

int value_press(char*arr); // 对当前棋盘做价值评估

int max_value(int*value, int start, int end); // 取所有子节点价值最大的
int min_value(int*value, int start, int end); // 取所有子节点价值最小的

int expand_press(char*arr, int step){
	step++;

	if (step > 4){
		return value_press(arr);
	}

	char press = (step % 2) ? '&' : '%';

	int start = top;
	for (int i = 0; i < N; i++){
		if (arr[i] == 0){
			arr[i] = press; // 下棋
			valarry[top] = expand_press(arr, step);
			top++;
			arr[i] = 0; // 恢复
		}
	}

	int res = (step % 2) ? max_value(valarry, start, top): min_value(valarry, start, top);
	top = start;
	return res;
}

int main(){
	return 0;
}

int max_value(int*value, int start, int end){
	int res = value[start];
	for (int i = start + 1; i < end; i++){
		if (res < value[i]){
			res = value[i];
		}
	}
	return res;
}

int min_value(int*value, int start, int end){
	int res = value[start];
	for (int i = start + 1; i < end; i++){
		if (res > value[i]){
			res = value[i];
		}
	}
	return res;
}
