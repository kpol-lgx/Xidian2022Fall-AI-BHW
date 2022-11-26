#include<bits/stdc++.h>
#define TEST
using namespace std;

struct octable{
	int table[3][3];
	int order;
	octable* father;
};

queue<octable> open_table;
queue<octable> close_table;

octable result_node;
int order_count = 0;

int beg_graph[3][3] = { {2, 8, 3},
						{1, 0, 4},
						{7, 6, 5} };

int end_graph[3][3] = { {1, 2, 3},
						{8, 0, 4},
						{7, 6, 5} };

bool equal_state(octable& n);
void swap_octable(octable*n, int i, int j, int swap_i, int swap_j);
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

#ifdef TEST1
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					cout << close_table.back().table[i][j] << ',';
				}
				cout << '\n';
			}
			cout << "============\n";
#endif

			bool find_node = expand_node(close_table.back()); // 扩展添加的节点

#ifdef TEST2
					if (!open_table.empty())
						cout << "NotEmpty!\n";
#endif

			if (find_node){
				print_path(result_node);
				cout << "Find!\n";
				break;
			}
		}
	}

	return 0;
}

bool equal_state(octable& n){
	for(int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (n.table[i][j] != end_graph[i][j]){
				return false;
			}
		}
	}
	print_path(n);
	return true;
}

void swap_octable(octable*n, int i, int j, int swap_i, int swap_j){
	n->table[i][j] = n->table[swap_i][swap_j];
	n->table[swap_i][swap_j] = 0;
	n->order = ++order_count;
}

bool expand_node(octable& n){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (n.table[i][j] == 0){
				if (i != 2){
					octable * right_swap = new octable;
					*right_swap = n;
					swap_octable(right_swap, i, j, i+1, j);

					right_swap->father = &n;
					open_table.push(*right_swap);

#ifdef TEST3
					if (!open_table.empty())
						cout << "NotEmpty!\n";
#endif

					if (equal_state(*right_swap)) return true;
				}
				if (i != 0){
					octable * left_swap = new octable;
				 	*left_swap = n;
					swap_octable(left_swap, i, j, i-1, j);
					
					left_swap->father = &n;
					open_table.push(*left_swap);

					if (equal_state(*left_swap)) return true;
				}

				if (j != 2){
					octable * up_swap = new octable;
					*up_swap = n;
					swap_octable(up_swap, i, j, i, j+1);

					up_swap->father = &n;
					open_table.push(*up_swap);

					if (equal_state(*up_swap)) return true;
				}
				if (j != 0){
					octable * down_swap = new octable;
					*down_swap = n;
					swap_octable(down_swap, i, j, i, j-1);

					down_swap->father = &n;
					open_table.push(*down_swap);

					if (equal_state(*down_swap)) return true;
				}

				break;
			}
		}
	}
	return false;
}

void print_path(octable& r){
	octable* temp = &r;
	while(true){
		// cout << temp->order << " -> ";
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				cout << temp->table[i][j] << ',';
			}

			if (i==2){
				cout << "	" << temp->order;
			}
			cout << '\n';
		}
		cout << "=============\n";
		if (temp->father){
			temp = temp->father;
		}else{
			break;
		}
	}
	return;
}

