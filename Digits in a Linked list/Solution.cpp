#include<iostream>
#include<vector>
#include<conio.h>

class Linked_list {
public:
	struct node
	{
		int val;
		node* next=nullptr;
		node(int val) :val(val) {};
	};
	std::vector<node*> ptr_list;
	node* make_LL(std::vector<int> vec);
};

class solution : public Linked_list  {
private:
	
	std::vector<int> num1;
	std::vector<int> num2;
	std::vector<int> num3;
	int store = 0;
	int final_num = 0;
public:

	solution(std::vector<int> num1, std::vector<int> num2) :num1(num1), num2(num2) {};
	node* start_n1 = make_LL(num1);
	node* start_n2 = make_LL(num2);
	node* new_number_list();

};


Linked_list::node* Linked_list::make_LL(std::vector<int> vec)
{
	ptr_list.push_back(new Linked_list::node(vec[0]));
	for (int i = 1; i < vec.size(); i++) {
		ptr_list.push_back(new Linked_list::node(vec[i]));
		ptr_list[i - 1]->next = ptr_list[i];
	}
	return ptr_list[0];
}

solution::node* solution::new_number_list()	//Solution of the problem
{
	while (start_n1 != nullptr || start_n2 != nullptr) {
		if (start_n1 == nullptr) { final_num = start_n2->val + store; }
		else if (start_n2 == nullptr) { final_num = start_n1->val + store; }
		else { final_num = start_n1->val + start_n2->val + store; }
		if (final_num / 10 == 0) { num3.push_back(final_num); store = 0; }
		else { store = final_num / 10; num3.push_back(final_num % 10); }
		start_n1 = start_n1->next; start_n2 = start_n2->next;
	}
	if (store != 0) { num3.push_back(store); }
	return make_LL(num3);
}
