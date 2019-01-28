/*
	THE GENERIC CODE HAS BEEN IMPLEMENTED AND DESIGNED BY MANAS JOSHI.
	RUNNING THIS PROGRAM YOU CAN CREATE A BINARY SEARCH TREE AND OPERATE ON IT
	DATE: 11/1/19
	TIME: 1445Hrs

*/
/*---------------IMPORTING LIBRARIES------------*/
#include<iostream>								//importing iostream
#include"binarysearchtree.h"		
using namespace std;
/*---------------MAIN FUNCTION------------*/
int main()									
{
	int iChoice;		
	char cChoice,cwChoice;
	Cbinarysearchtree <int> b;
	do{

		cout<<"1.TO ADD NODE\n2.TO TRAVERSE PREORDER\n3.TO TRAVERSE INORDER\n4.TO TRAVERSE POSTORDER\n5.TO DELETE PARTICULAR ELEMENT\n6.TO SEARCH PARTICULAR ELEMENT\n7.TO GET MAX AND MIN ELEMENT\n8.TO GET THE HEIGHT OF TREE"<<endl;					//Displaying menu
		cin>>iChoice;
		while(iChoice !=1 &&iChoice !=2 &&iChoice !=3 &&iChoice !=4 &&iChoice !=5 &&iChoice !=6 &&iChoice !=7 &&iChoice !=8 )
		{
			cout<<"ENTER VALID CHOICE"<<endl;
			cin>>iChoice;
		}
		switch(iChoice)
		{
			case 1:														//TO ADD NODE
					do
					{	int iData;
						cout<<"ENTER THE DATA ";						//Asking the user to enter the data
							cin>>iData;
							b.insert(iData);	
							cout<<"WANT TO ADD SOME MORE ELEMENTS ?";
							cin>>cChoice;
					}while(cChoice=='y' ||cChoice=='Y');
					break;
			case 2:													//TO TRAVERSE PREORDER
					cout<<"PREORDER OF ELEMENTS"<<endl;
					b.preorder(b.nRoot);
					break;
			case 3:													//TO TRAVERSE INORDER
					cout<<"INORDER OF ELEMENTS"<<endl;
					b.inorder(b.nRoot);
					break;
			case 4:													//TO TRAVERSE POSTORDER
					cout<<"POSTORDER OF ELEMENTS"<<endl;
					b.postorder(b.nRoot);
					break;
			case 5:
					break;
			case 6:
					cout<<"ENTER DATA TO BE SEARCHED"<<endl;
					int iKey;
					cin>>iKey;	
					if(b.search(b.nRoot,iKey))
					cout<<iKey<<" FOUND";
					else 
					cout<<iKey<<" NOT FOUND";
					break;
			case 7:
					b.maxmin(b.nRoot);
					break;
	
			case 8:	cout<<b.height(b.nRoot);
					break;
			case 9:
					break;
		}
		cout<<"DO YOU WANT TO CONTINUE"<<endl;
		cin>>cwChoice;
	}while(cwChoice=='Y'||cwChoice=='y');
}
