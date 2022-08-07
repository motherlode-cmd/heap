#include <iostream>
#include <stdio.h>
/*
parent[i] = array[i/2]
left child[i] = array[i * 2]
right chilf[i] = arrray[i * 2 + 1]
*/
using namespace std;

class Binary_tree {
public:
	Binary_tree() {
		buffer_size = 3;
		array = new int[buffer_size];
		size = 0;
	}

	void sort_up(size_t i) {
		if(i >= 0 && array[i] > array[i/2]) {
			int temp = *(array + i);
			*(array + i) = *(array + i/2);
			*(array + i/2) = temp;
			sort_up(i/2);
		}
	}

	void sort_down(size_t i) {
		if(2 * i < size && array[i] < array[2 * i]) {
			int temp = *(array + i);
			*(array + i) = *(array + 2*i);
			*(array + 2 * i) = temp;
			sort_down(2 * i);
		}else if(2 * i + 1 < size && array[i] < array[2 * i + 1]) {
			int temp = *(array + i);
			*(array + i) = *(array + 1 + 2 * i);
			*(array + 1 + 2 * i) = temp;
			sort_down(2 * i + 1);
		}
	}

	void push_elem(int elem) {
		if(size == buffer_size) {
			int* new_array = new int[buffer_size * 2];
			buffer_size *= 2;
			for(size_t i = 0; i < size; i++) {
				new_array[i] = array[i];
			}
			delete[] array;
			array = new_array;
			printf("ssss %d\n" ,buffer_size);
		}
		array[size++] = elem;
		sort_up(size - 1);
	}
	void pop_elem() {
		array[0] = array[size - 1];
		array[size-1] = 0;
		size--;
		sort_down(0);
	}
	size_t get_size() {
		return size;
	}
	int get_max() {
		return array[0];
	}
	int hight() {
		size_t curr = 1;
		int hight = 0;
		while(curr <= size) {
			curr*=2;
			hight++;
		}
		return hight;
	}
	void print_tree() {
		printf("[");
		for(size_t i = 0; i < size; i++) {
			//printf("here ");
			printf(" %d ", array[i]);
		}
		printf("]\n");
	}

protected:
	size_t size;
	size_t buffer_size;
	int* array;
}; 

int main() {
	Binary_tree bin;
	//cout<<"here\n";
	bin.push_elem(1);
	bin.push_elem(2);
	bin.push_elem(3);
	bin.push_elem(-1);
		bin.push_elem(1);
	bin.push_elem(2);
	bin.push_elem(3);
	bin.push_elem(-1);
		bin.push_elem(1);
	bin.push_elem(2);
	bin.push_elem(3);
	bin.push_elem(-1);
	bin.pop_elem();
	bin.pop_elem();
	bin.pop_elem();
	printf("%d\n", bin.get_max());
	int counter = 0;
	printf("%d\n", bin.get_size());
	bin.print_tree();
	printf("%d\n", bin.hight());
	return 0;
} 
