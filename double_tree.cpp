#include <iostream>
#include <stdio.h>

using namespace std;
struct list {
	int value;
	struct list* mom;
	struct list* left;
	struct list* right;
};

class Binary_tree {
public:
	Binary_tree() {
		size = 0;
		head->mom = NULL;
		head->left = NULL;
		head->right = NULL;
	}
	void sort_up( struct list* new_elem) {
		struct list* current = new_elem;
		if(current->mom != NULL && current->value > current->mom->value) {
			int temp = current -> value;
			current->value = current->mom->value;
			current->mom->value = temp;
			current = current->mom;
			sort_up(current);
		}
		//printf("all");
	}
	void sort_down( struct list* new_elem) {
		struct list* current = new_elem;
		if(current->left != NULL && current->value < current->left->value) {
			int temp = current->value;
			current->value = current->left->value;
			current->left->value = temp;
			sort_down(current->left);
		}
		if(current->right != NULL && current->value < current->right->value) {
			int temp = current->value;
			current->value = current->right->value;
			current->right->value = temp;
			sort_down(current->right);
		}

	}
	int get_hight(int c, struct list* el) {
		if(el->left != NULL && el->right != NULL) {
			return max(get_hight(c+1, el->right), get_hight(c+1, el->left));
		}
		else if( el -> left != NULL) {
			return get_hight(c+1, el->left);
		} 
		else if( el ->right != NULL) {
			return get_hight(c+1, el->right);
		} else {
			return c;
		}
	}
	void push_elem(int elem) {
		struct list* current = head;
		if(size == 0) {
			head->value = elem;
		} else {
			while(current != NULL) {
				if(current->left == NULL) {
					struct list* new_elem = (struct list*)malloc(sizeof(struct list));
					new_elem->value = elem;
					new_elem->mom = current;
					new_elem->right = NULL;
					new_elem->left = NULL;
					current->left = new_elem;
					sort_up(new_elem);
					current = NULL;
				} else if(current->right == NULL) {
					struct list* new_elem = (struct list*)malloc(sizeof(struct list));
					new_elem->value = elem;
					new_elem->mom = current;
					new_elem->right = NULL;
					new_elem->left = NULL;
					current->right = new_elem;
					sort_up(new_elem);
					current = NULL;
				} else {
					if(get_hight(0, current->right) < get_hight(0, current->left)) {
						current = current->right;
					} else {
						current = current->left;
					}
				}
			}
		}
		size++;	
	}
	void pop_elem() {
		struct list* current = head;
		while(current->left != NULL || current->right != NULL) {
			if(current->left != NULL) {
				current = current->left;
			} else {
				current = current->right;
			}
		}
		head->value = current->value;
		current = NULL;
		size--;
		sort_down(head);
	}
	size_t get_size() {
		return size;
	}
	int get_max() {
		return head->value;
	}
	int hight() {
		return get_hight(0, head);
	}
	void print_tree() {
		struct list* current = head;
		while(current != NULL) {
			printf("%d\n",current->value);
			current = current->left;
		}
	}

protected:
	size_t size;
	struct list* head;

}; 

int main() {
	Binary_tree bin;
	//cout<<"here\n";
	bin.push_elem(1);
	bin.push_elem(2);
	bin.push_elem(3);
	bin.push_elem(-1);
//	bin.pop_elem();
//	bin.pop_elem();
	//bin.pop_elem();
	printf("%d\n", bin.get_max());
	int counter = 0;
	printf("%d\n", bin.get_size());
	//bin.print_tree();
	printf("%d\n", bin.hight());
}