#include<iostream>
#include<stack>
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

int value_press(char*arr);

int max_value(int*value, int start, int end);
int min_value(int*value, int start, int end);

void recovery_press(char*arr);

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
