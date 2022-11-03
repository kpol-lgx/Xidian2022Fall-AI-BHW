#include<bits/stdc++.h>
using namespace std;

struct octable{
	int table[3][3];
	int order;
	octable* father;
};

queue<octable> open_table;
queue<octable> close_table;

octable result_node;

int beg_graph[3][3] = { {2, 8, 3},
						{1, 0, 4},
						{7, 6, 5} };

int end_graph[3][3] = { {1, 2, 3},
						{8, 0, 4},
						{7, 6, 5} };


bool expand_node(octable& n);
void print_path(octable& r);

int main(){
	octable start_node = {{	{2, 8, 3},
							{1, 0, 4},
							{7, 6, 5} }, 0, nullptr};
	open_table.push(start_node);

	while(true){
		if (open_table.empty()){
			cout << "Failed\n";
			break;
		}else{
			close_table.push(open_table.front()); // 从 open 表中添加一个点到 close
			open_table.pop(); // 删除添加的节点

			bool find_node = expand_node(close_table.back()); // 扩展添加的节点

			if (find_node){
				print_path(result_node);
				break;
			}
		}
	}

	return 0;
}

bool expand_node(octable& n){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (n.table[i][j] == 0){
				if (i == 0){
					;
				}else if (i == 2){
					;
				}else{
					;
				}
				
				if (j == 0){
					;
				}else if (j == 2){
					;
				}else{
					;
				}
			}
		}
	}

	return true;
}

void print_path(octable& r){
	octable* temp = &r;
	while(temp->father){
		cout << temp->order << " -> ";
		temp = temp->father;
	}
	return;
}

