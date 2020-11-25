//New code

*****************************************
#include <iostream>
#include <stdlib.h>
#include<map>
#include<vector>
#include <bits/stdc++.h> 
using namespace std;
struct QNode                                            // queue node
{ 
    string data; 					// node element value				 

    QNode* next; 					// next node in list
    QNode(string d) 					// constructor
    { 							
        data = d; 					// assigning value to Node 
        next = NULL; 					// initiallizing
    } 
}; 
  
struct Queue 						
{ 
    int n=0;
    QNode *front, *rear; 				// pointers to front and rear of Queue
    Queue() 						// constructor
    { 
        front = rear = NULL; 				// initializing
    } 
  
    void enQueue(string x) 				// Adding new node to Queue with value x
    { 
  
        // Create a new LL node 
        n++;
        QNode* temp = new QNode(x); 			// temporary node
  
        // If queue is empty, then 
        // new node is front and rear both 
        if (rear == NULL) { 
            front = rear = temp; 
            return; 
        } 
  
        // Add the new node at 
        // the end of queue and change rear 
        rear->next = temp; 
        rear = temp; 
    } 
  
    // Function to remove 
    // a key from given queue q 
	void deQueue() 					// Deletion or deQueuing
	{   n--;
	// If queue is empty, return NULL. 
	if (front == NULL) 
	    return; 

	// Store previous front and 
	// move front one node ahead 
	QNode* temp = front; 				// temporary node
	front = front->next; 

	// If front becomes NULL, then 
	// change rear also as NULL 
	if (front == NULL) 
	    rear = NULL; 

	delete (temp); 					// freeing memory
	} 
	int find(string x)				// finding particular node 
	    {   

		int cnt=0;
		QNode* temp;
		temp=front;
		if(!x.compare(temp->data))
		    {   

			return cnt;
		    }

		while(temp->next!=NULL)
		{  
		    temp=temp->next;
		    cnt++;
		    if(!x.compare(temp->data))
		    {   
			return cnt;
		    }
		}

		return -1;
	    }
	void disp()
	    {   
		QNode* temp;
		temp=front;
		cout<<front->data<<endl;
		while(temp->next!=NULL)
		{   temp=temp->next;
		    cout<<temp->data<<endl;
		}
	    }
	}; 

void write_account(vector<int>&deposit,Queue &q,map<string,int>&dict)		//create account
{   
    string name;								
    int n=0;									
    cout<<"Enter number of accounts to be created : ";
    cin>>n;									// creating multiple accounts at once
    cout<<"Enter account holder name and the initial deposit amount:"<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>name;								// Account name
        cin>>x;									// Initial Deposit amount
        deposit.push_back(x);
        q.enQueue(name);
        dict.insert(std::pair<string,int>(name,rand()%1000000000));		// creates a randomized 9 digit acc no.
    }
}

void dep(string name,int x,vector<int>&deposit,Queue &q)			// depositing money  
{   
	cout<<"Enter The account holder's name : "; cin>>name;
	cout<<"Enter The amount to be deposited : "; cin>>x;
    int n=q.find(name);

deposit[n]+=x;
}
	
void withdraw(string name,int x,vector<int>&deposit,Queue &q)			// withdrawning money
{   
	cout<<"Enter The account holder's name : "; cin>>name;
	cout<<"Enter The amount to be withdrawn : "; cin>>x;
    int n=q.find(name);
    deposit[n]-=x;
}

void display_all(map<string,int>&dict,vector<int>&deposit)			// View all Accounts
{
    int i=0;
    cout<<"Account holder's name"<<'\t'<<"Account no."<< '\t'<<"Balance"<<'\n';
    for (auto itr = dict.begin(); itr != dict.end(); ++itr,++i) 
    {
        cout << itr->first<< '\t'  << '\t'<<'\t'<<itr->second << '\t'<<deposit[i]<<'\n';
    }
}


void modify_account(string name, vector<int>&amount, Queue q)			// Change account details
{
	cout<<"Enter The account holder's name : "; cin>>name;
	cout<<"Enter The amount to be deposited : "; cin>>x;
  
	
	
	

void intro()									// Intro Screen
{
	cout<<"\n\n\n\t  BANK";
	cout<<"\n\n\tMANAGEMENT";
	cout<<"\n\n\t  SYSTEM";
	cout<<"\n\n\n\nMADE BY: \n\t\tIshan Dixit\n\t\tPrasad Gole\n\t\tNiteesh Kumar\n\t\tSatwik Merla";
	cout<<"\n\nDSA Group Project";
	cin.get();
}
	
// Driver Program 
int main() 
{   
    Queue q;
    string name;
    map<string, int> dict;
    vector<int> deposit;
    intro();
    int n,x;
    char ch;

    do
	{
	    
	    	system("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. BALANCE ENQUIRY";
		cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t08. EXIT";
		cout<<"\n\n\tSelect Your Option (1-8) ";
		cin>>ch;
		system("cls");
// 		cout<<"MAIN MENU";
// 		cout<<"\n01. NEW ACCOUNT";
// 		cout<<"\n02. DEPOSIT AMOUNT";
// 		cout<<"\n03. WITHDRAW AMOUNT";
// 		cout<<"\n04. BALANCE ENQUIRY";
// 		//cout<<"\n05. ALL ACCOUNT HOLDER LIST";
// 		//cout<<"\n06. CLOSE AN ACCOUNT";
// 		//cout<<"\n07. MODIFY AN ACCOUNT";
// 		cout<<"\n08. EXIT";
// 		cout<<"\nSelect Your Option (1-8) ";
// 		cout<<endl;
// 		cin>>ch;

		switch(ch)
		{
		case '1':
			write_account(deposit, q,dict);
			q.disp();
			break;
		case '2':
			dep( name, x,deposit, q);
			break;
		case '3': 

			withdraw(name, x,deposit, q);
			break;
	
		case '4':
			display_all(dict,deposit);
			break;
		 case '8':
			cout<<"\nThanks for using bank management system";
			break;
		}

	}while(ch!='8');
    
} 
*****************************************
