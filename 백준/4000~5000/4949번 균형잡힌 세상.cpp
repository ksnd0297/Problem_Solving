#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#pragma warning(disable: 4996)

using namespace std;

char str[101];

typedef struct stack {
	char data;
	struct stack* link;
}stack;

stack* top;

void push(char data) {
	stack* newNode = (stack*)malloc(sizeof(stack));
	newNode->data = data;
	newNode->link = top;
	top = newNode;
}

char pop() {
	if (top == NULL) return 0;
	stack* temp = top;
	char item;
	item = top->data;
	top = temp->link;
	free(temp);
	return item;
}

bool isEmpty() {
	if (top == NULL) return 0;
	else return 1;
}

int main() {
	char ch;
	
	while (1) {
		int i = 0;
		bool flag = false;
		top = NULL;
		do {
			scanf("%c", &ch);

			str[i] = ch; i++;
			if (ch == '(' || ch == '[') push(ch);
			else if (ch == ')') {
				if (pop() != '(') {
					flag = true;
				}
			}
			else if (ch == ']') {
				if (pop() != '[') {
					flag = true;
				}
			}
			
		} while (ch != '\n');
		if (str[0] == '.') return 0;


		if (flag || top != NULL) cout << "no" << endl;
		else cout << "yes" << endl;
	}
	return 0;
}