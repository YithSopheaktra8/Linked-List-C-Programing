//
//  Linked List
//
//  Created by yithsopheaktra on 22/6/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
using namespace std;

struct NodeType{
    char info;
    struct NodeType *next;
};

struct NodeType *plist, *p, *ptr;

//	Function Header
void Initialize( struct NodeType *plist );
struct NodeType *Get_Node();
void Free_Node(struct NodeType *p);
struct NodeType *CreateList(struct NodeType *plist, int n);
void Traverse(struct NodeType *plist);
int CountNode(struct NodeType *plist);
void search_node(struct NodeType *plist, char Item);
struct NodeType *searchPostion(struct NodeType *plist, char item);
void sort(struct NodeType *plist);
void InsertBegin(struct NodeType *plist, char item);
void InsertAfter(struct NodeType *plist, char item);
void insertEnd(struct NodeType *plist, char item);
struct NodeType *InsertNode(struct NodeType *plist, char item);
struct NodeType *DeleteNode(struct NodeType *plist);


//	Main Function
int main() {
	
	int ch;
	int n;
	char item;
    
    cout << "\n\t\t\t\t Program With Linked List\n" << endl;
    cout << "\t\t\t Enter Number of Item you want to insert : "; cin >> n;
    Initialize(plist);
    plist = CreateList(plist,n);
    do{
    	system("cls");
    	cout << "\n\n\t\t\t\t Menu Program of linked list" << endl;
	    cout << "\t\t\t 1. Traverse Node(Show all Node)" << endl;
	    cout << "\t\t\t 2. Insert Node" << endl;
	    cout << "\t\t\t 3. Search Node" << endl;
	    cout << "\t\t\t 4. Sort Node" << endl;
	    cout << "\t\t\t 5. Delete Node" << endl;
	    cout << "\t\t\t 6. Exit Program" << endl;
    	cout << "\n\t\t\t\t Choose Option above : "; cin >> ch;
    	switch(ch)
    	{
    		case 1:
    			cout << "\n\t\t\t Output Info of all Linked List" << endl;
    			Traverse(plist);
    			break;
    		case 2:
    			cout << "\n\t\t\t Input info of node to Insert : "; cin >> item;
    			plist = InsertNode(plist,item);
    			break;
    		case 3:
    			cout << "\n\t\t\t Input info of node to Search Node: "; cin >> item;
    			search_node(plist,item);
    			break;
    		case 4:
    			sort(plist);
    			cout << "\n\t\t\t Sort Successfully";
    			break;
    		case 5:
    			cout << "\n\t\t\t Available Node to Delete\n" << endl;
    			plist = DeleteNode(plist);
    			break;
    		case 6:
    			exit(0);
    		default:
    			cout << "\n\t\t\t Invalid Option";
    			break;
		}
    	
    	cout << "\n\n\t\t Press [ESC] to exit or Press any key to continue : "; 
		  	
	}while(getch() != 27);
	
    return 0;
}


//	Function Body

void Initialize( struct NodeType *plist )
{
    plist = NULL;
}

struct NodeType *Get_Node()
{
    p =(struct NodeType*)malloc(sizeof(struct NodeType));
    return p;
}


void Free_Node(struct NodeType *p)
{
    free(p);
}


struct NodeType *CreateList(struct NodeType *plist, int n)
{
	struct NodeType *p, *ptr;
	char Item;
	int i;
	cout << "\n\t\t\t\t Enter Item : "; cin >> Item;
	p = Get_Node();
	p->info = Item;
	p->next = NULL;
	plist = p;
	ptr = plist;
	for(i = 2; i<=n; i++)
	{
		cout << "\n\t\t\t\t Enter Item : "; cin >> Item;
		p=Get_Node();
		p->info=Item;
		p->next =NULL;
		ptr->next = p;
		ptr = p;
	}
	return plist;
	
}


void Traverse(struct NodeType *plist)
{
	struct NodeType *ptr;
	ptr = plist;
	while(ptr != NULL)
	{
		cout << "\t\t" << ptr->info;
		ptr = ptr->next;
	}
}



int CountNode(struct NodeType *plist)
{
	int num = 0;
	struct NodeType *p;
	p = plist;
	while(p !=NULL)
	{
		num++;
		p = p->next;
	}
	
	return (num);
}


void search_node(struct NodeType *plist, char Item)
{
	struct NodeType *p;
	int found = 0;
	p = plist;
	while(p != NULL)
	{
		if(p->info == Item)
		{
			cout << "\n\t\t\t\tItem founded : " << p->info;
			found = 1;
		}
		p=p->next;	
	}
	if(found == 0)
	{
		cout << "\n\t\t\t\tItem Not Found!!!" << endl;
	}
}

struct NodeType *searchPostion(struct NodeType *plist, char item)
{
	struct NodeType *p;
	p = plist;
	while(p !=NULL)
	{
		if(p->info == item)
		{
			return p;
		}
		else
		{
			p = p->next;
		}
	}
	if(p == NULL)
		return NULL;
		
	return NULL;	
}


void sort(struct NodeType *plist)
{
	struct NodeType *p, *ptr;
	char temp;
	for(p=plist; p != NULL; p=p->next)
	{
		for(ptr=p->next; ptr != NULL; ptr=ptr->next)
		{
			if(p->info < ptr->info)
			{
				temp = p->info;
				p->info = ptr->info;
				ptr->info = temp;
			}
		}
	}
	cout << "\n";
	Traverse(plist);
}


void InsertBegin(struct NodeType *plist, char item)
{
	struct NodeType *p;
	p = Get_Node();
	p->info = item;
	p->next = plist;
	plist = p;
}


void InsertAfter(struct NodeType *plist, char item)
{
	struct NodeType *ptr, *p;
	int count;
	int i = 1;
	int position;
	p =Get_Node();
	p->info = item;
	p->next = NULL;
	count = CountNode(plist);
	cout << "\n\t\t\t\tEnter Position to Insert : "; cin >> position;
	if(position > count)
	{
		printf("\n\t\t\t\tPosition Not Found!!!");
	}
	else{
		ptr = plist;
		while(i<position)
		{
			ptr = ptr->next;
			i++;
		}
		p->next=ptr->next;
		ptr->next = p;
	}
}

void insertEnd(struct NodeType *plist, char item)
{
	struct NodeType *ptr, *p;
	p = Get_Node();
	p->info = item;
	p->next = NULL;
	ptr = plist;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = p;
}

struct NodeType *InsertNode(struct NodeType *plist, char item)
{
	struct NodeType *p, *ptr;
	int ch;
	int i;
	int count;
	int position;
	p = Get_Node();
	p->info = item;
	p->next = NULL;
	if(plist == NULL)
	{
		plist = p;
	}
	else
	{
		cout << "\n\t\t\t 1. Insert Beginning" << endl;
		cout << "\t\t\t 2. Insert End" << endl;
		cout << "\t\t\t 3. Insert Position" << endl;
		cout << "\t\t\t Choose Option : "; cin >> ch;
		switch(ch)
		{
			case 1 :
				cout << "\n\t\t\tInsert at Beginning Node sucessfully" << endl;
				p->next = plist;
				plist = p;
				break;
			case 2:
				cout << "\n\t\t\tInsert at End Node sucessfully" << endl;
				ptr = plist;
				while(ptr->next != NULL)
				{
					ptr = ptr->next;
					
				}
				ptr->next = p;
				break;
			case 3:
				count = CountNode(plist);
				cout << "\n\t\t\t\tEnter position of Node : "; cin >> position;
				if(position > count)
				{
					cout << "\n\t\t\t\tPosition not Founded";
				}
				else{
					i = 1;
					ptr = plist;
					while(i < position)
					{
						ptr = ptr->next;
						i++;
					}
					p->next = ptr->next;
					ptr->next = p;
					
					cout << "\n\t\t\tInsert Postion of Node sucessfully " << endl;
				}
				break;
			default: 
				cout << "\n\t\t\t\tInvalid Value" << endl;
				break;		
		}

	}
	
	return plist;
}

struct NodeType *DeleteNode(struct NodeType *plist)
{
	struct NodeType *p1, *p2, *p3, *ptr;
	int count;
	int position;
	int i;
	int ch;
	
	if(plist == NULL)
	{
		cout << "\n\t\t\t\tNode not found!!!";
	}
	else
	{
		Traverse(plist);
		cout << "\n\n\t\t\t 1. Delete Beginning" << endl;
		cout << "\t\t\t 2. Delete End" << endl;
		cout << "\t\t\t 3. Delete Position" << endl;
		cout << "\t\t\t Choose Option : "; cin >> ch;
		switch(ch)
		{
			case 1 :
				cout << "\n\t\t\t\tDelete at Beginning Node" << endl;
				p1= plist;
				plist = plist->next;
				Free_Node(p1);
				break;
			case 2:
				cout << "\n\t\t\t\tDelete at End Node" << endl;
				p2 = plist;
				while(p2->next != NULL)
				{
					ptr = p2;
					p2 = p2->next;
				}
				ptr->next = p2->next;
				Free_Node(p2);
				break;
			case 3:
				count = CountNode(plist);
				cout << "\n\t\t\t\tEnter position of Node : "; cin >> position; fflush(stdin); cin.clear();
				if(position > count+1)
				{
					cout << "\n\t\t\t\tPosition not Founded";
				}
				else{
					i = 1;
					p3 = plist;
					while(i < position)
					{
						ptr = p3;
						p3 = p3->next;
						i++;
					}
					ptr->next = p3->next;
					Free_Node(p3);
				}
				break;
			default: 
				cout << "\n\t\t\t\tInvalid Value" << endl;	
				break;	
		}
		cout << "\n\t\t\t\t Node after Delete " << endl;
		Traverse(plist);
	}
	
	return plist;
	
}

