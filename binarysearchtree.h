//LICENSED TO MANAS SUNIL JOSHI
/*
	THIS IS A GENERIC CODE FOR CREATING A BINARY SEARCH TREE AND IMPLEMENT FOLLOWING FUNCTIONS:
	CREATION OF TREE
	TRAVERSING IN POST/PRE/IN ORDER
	SEARCHING A NODE
	GETTING HEIGHT OF TREE
	GETTING MAX & MIN ELEMENT PRESENT IN THE TREE
	
	
*/
/*---------------IMPORTING LIBRARIES------------*/
#include<iostream>								
#include"node.h"
using namespace std;
/*---------------TEMPLATE------------*/					
template <class t>								//declaring the class as a template
/*---------------ABSTRACT DATA TYPE------------*/
class Cbinarysearchtree							//declaring class binary search tree which is an abstract
{												//opening of class
	public:										//the data members and functions of the class can be accessed publicly				
	node<t> *nRoot;								//Creating the head node or parent node for the tree
	node<t>* create(t);							//a function that returns a node which is newly created
	bool insert(t);								//a function that inserts a new node
	bool search(node<t>* nRoot,t);				//a function that returns true or false in basis wether item is found or not	
	void preorder(node<t>*);					//a function to traverse the tree in preorder 
	void postorder(node<t>*);					//a function to traverse the tree in postorder
	//void del(t);								//a function to delete the data at a particular location
	void inorder(node<t>*);						//a function to traverse the tree in inorder
	void maxmin(node<t>*);
	int height(node<t> *nroot);
	Cbinarysearchtree()							//constructor to initalize the data members while object creation
	{											//opening of constructor
	nRoot=NULL;									//initiliazing the root to NULL
	}											//closing of constructor
};												//closing of class
template <class t>
/*---------------FUNCTION TO RETURN NEW NODE------------*/
node<t>* Cbinarysearchtree<t>::create(t tData)		//function defination
{												//opening of function
	node<t> *nNode=new node<t>;					//creating a new object of datatype node to be attached to the tree
	nNode->data=tData;								//Taking the data from user
	nNode->left=nNode->right=NULL;				//initializing its right and left part to NULL
	return nNode;								//returning the created node
}												//closing of function	
template <class t>
/*---------------FUNCTION TO INSERT NODE------------*/
bool Cbinarysearchtree<t>::insert(t tdata)		//function defination
{												//opening of function	
	node<t> *nTemp, *nNode=create(tdata);		//creating a temporary node to traverse and a nnode to store the returned node from create which will be used to link as the next node
	nTemp=nRoot;								//intialinzing the temp node to head for traversal
	if(nTemp==NULL)								//checking wether root is null or not
	{											//opening of if
		nRoot=nNode;							//if root is null then the new node is intialized as the root
	}											//closing of if
	else										//if root is not null
	{											//opening of else
		while(true)								//While is true because we want an infinte loop
		{										//opening of while 
			if(nTemp->data>	nNode->data)		//Checking wether the entered is greater than the data in previous node
			{									//opening of if
				if(nTemp->left==NULL)			//Checking wether the left side of node is empty or not
				{								//opening of if	
					nTemp->left=nNode;			//if its empty link the node
					break;						//done so lets exit the loop
				}								//closing of if
				else							//if left is not Null	
					nTemp=nTemp->left;			//GO to next left node present
			}									//closing of if
			else if(nTemp->data<nNode->data)	//Checking wether the entered is smaller than the data in previous node
			{									//opening of function
				if(nTemp->right==NULL)			//Checking wether the right side of node is empty or not
				{								//opening of function
					nTemp->right=nNode;			//if its empty link the node
					break;						//done so lets exit the loop
				}								//closing of if
				else							//if right is not Null	
				nTemp=nTemp->right;				//GO to next right node present
			}									//closing of elseif
		}										//closing of while
	}											//closing of else		
	return true;								//to end function
}												//closing of function
template <class t> 
/*---------------FUNCTION TO SEARCH A NODE IN TREE------------*/
bool Cbinarysearchtree<t>:: search(node<t>* nRoot, t key)
{												//opening of function
	node<t> *nTemp=nRoot;						//creating a temporary node to traverse
	do											//do -while to check wether the key exists at root node		
	{											//opening of dowhile
		if(key<nTemp->data)						//checking wether the key is smaller or not	
		{										//opening of if
			nTemp=nTemp->left;					//now key is smaller so we will go to left
		}										//closing of if
		else if(key>nTemp->data)				//checking wether the key is greater or not	
		{										//opening of elseif
			nTemp=nTemp->right;					//now key is greater so we will go to right
		}										//closing of elseif
		else if(nTemp->data==key)				//checking wether key is equal or not
			return true;						//now key is found so exit by returning true
	}while(nTemp!=NULL);						//until the last element we travel so until we dont find null we traverse
	return false;								//return false that denotes we havent found
}												//closing of function
template <class t> 
/*---------------FUNCTION TO TRAVERSE INORDER------------*/
void Cbinarysearchtree<t>::inorder(node<t> *nroot)
{												//opening of function
	if(nroot!=NULL)								//traversing to the null i.e. end of the tree
	{											//opening of if
		inorder(nroot->left);					//traversing and storing elements of left side in stack
		cout<<nroot->data<<"  ";				//displaying left
		inorder(nroot->right);					//traversing right
	}											//closing of if
}
template <class t>	
/*---------------FUNCTION TO TRAVERSE PREORDER------------*/
void Cbinarysearchtree<t>::preorder(node<t> *nroot)
{												//opening of function
	if(nroot!=NULL)								//traversing to the null i.e. end of the tree
	{											//opening of if
		cout<<nroot->data<<"  ";				//displaying 
		preorder(nroot->left);					//traversing and storing elements of left side in stack
		preorder(nroot->right);					//traversing right
	}											//closing of if
}												//closing of function
template <class t>
/*---------------FUNCTION TO TRAVERSE POSTORDER------------*/
void Cbinarysearchtree<t>::postorder(node<t> *nroot)
{												//opening of function
	if(nroot!=NULL)								//traversing to the null i.e. end of the tree
	{											//opening of if
		postorder(nroot->left);					//traversing and storing elements of left side in stack
		postorder(nroot->right);				//traversing right
		cout<<nroot->data<<"  ";				//displaying 
	}											//closing of if
}												//closing of function
template <class t> 
/*---------------FUNCTION TO DISPLAY MAX AND MIN------------*/
void Cbinarysearchtree<t>::maxmin(node<t> *nroot)
{												//opening of function
	node <t>*temp=nroot;						//intialinzing the temp node to head for traversal
	while(temp->left!=NULL)						//traversing to last left node
	{											//opening of while
		temp=temp->left;						//going to next left node
	}											//closing of while
	cout<<"MINIMUM ELEMENT IS "<<temp->data;	//Displaying minimum	
	temp=nroot;									//intialinzing the temp node to head for traversal
	while(temp->right!=NULL)					//traversing to last right node
	{											//opening of while
		temp=temp->right;						//going to next left node
	}											//closing of while
	cout<<"MAXIMUM ELEMENT IS "<<temp->data;	//Displaying maximum	
}												//closing of function
template <class t> 
/*---------------FUNCTION TO RETURN THE HEIGHT OF TREE------------*/
int Cbinarysearchtree<t>::height(node<t> *nroot)
{											
	if(nroot==NULL)								//if root is empty
	return 0;									//return height as 0
	else
	{											//opening of else	
		if(height(nroot->right)>height(nroot->left))//run until the last node
		return 1+height(nroot->right);
		return 1+height(nroot->left);
	}											//closing of if											
}												//closing of function
