//A program to swap elements pair wise in a linked list using C++ program
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

//Create a new node
struct node* create_node(int x){
    struct node* temp= new node;
    temp->data=x;
    temp->next=NULL;
    return temp;
}

//Enter the node into the linked list
void push(node** head,int x){
    struct node* store=create_node(x);
    if(*head==NULL){
        *head =store;
        return;
    }
    struct node* temp=*head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=store;
}

//Reverse the linked list
struct node* swap(node* head){
	if(head==NULL){
		return NULL;
	}
	struct node* curr=head;
	while(curr && curr->next){
        int temp=curr->data;
        curr->data=curr->next->data;
        curr->next->data=temp;
        curr=curr->next->next;
	}
    return head;
}

//Print the list
void print(node* head){
	struct node* temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int main()
{
    struct node* l=NULL;
    push(&l,1);
    push(&l,2);
    push(&l,3);
    push(&l,4);
    push(&l,5);
    push(&l,6);
    cout<<"Before the swap operation"<<endl;
    print(l);
    l=swap(l);
    cout<<"\nAfter the swap operation"<<endl;
    print(l);
	
    return 0;
}
