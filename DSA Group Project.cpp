#include <iostream>
#include <stdlib.h>
#include<map>                                           // header files
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
        n++;                                            // increasing size of queue by 1
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
	void modify_account(map<int,string>&dict)                                      // Change account details
	{   
	    string x,c;
	    cout<<"Enter account name to be modified and the value it is to be modified to :"<<endl;
	    cin>>x;
	    cin>>c;
		QNode *temp;
		temp=front;
		if(!x.compare(temp->data))
		    {   
			temp->data=c;
		    }
    
		while(temp->next!=NULL)
		{  
		    temp=temp->next;
		
		    if(!x.compare(temp->data))
		    {   
			temp->data=c;
		    }
		}
		
	    for (auto itr = dict.begin(); itr != dict.end(); ++itr) 
    {   
        if(itr->second==x)
        {
            itr->second=c;
        }
        
    }
    
	}
	
	}; 

void write_account(vector<int>&deposit,Queue &q,map<int,string>&dict)		//create account
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
        dict.insert(std::pair<int,string>(rand()%1000000000,name));		// creates a randomized 9 digit acc no.
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
	cout<<"01.current\n02.savings\n";
	int z;
	cin>>z;
	 int n=q.find(name);
	if(z=1)
	{
	cout<<"Enter The amount to be withdrawn : "; cin>>x;	
        if(deposit[n]<x)
        {
        cout<<"N0 sufficient amount";
        }
        else
        {
        deposit[n]-=x;
        }
	}
	else
	{
	cout<<"Enter The amount to be withdrawn : "; cin>>x;	
       
        if(deposit[n]<x)
        {
        cout<<"N0 sufficient amount.\n";
        }
        else
        {
        deposit[n]-=x;
        }
	}
	char e;
	cout<<"Do you want to know your balance?\n";
	cout<<" Y / N\n";
	cin>>e;
	
	if(e=='Y') 
	{
	  cout<<"Balance"<<'\n';
	  cout<<deposit[n]<<'\n';
	}
	
	 //cout<<"Account no."<<'\t'<<"Account holder's name"<< '\t'<<"Balance"<<'\n';
	 
}

void display_all(map<int,string>&dict,vector<int>&deposit)			// View all Accounts
{
    int i=0;
    cout<<"Account no."<<'\t'<<"Account holder's name"<< '\t'<<"Balance"<<'\n';
    for (auto itr = dict.begin(); itr != dict.end(); ++itr,++i) 
    {
        cout << itr->first<< '\t'  << '\t'<<'\t'<<itr->second << '\t'<<deposit[i]<<'\n';
    }
}
void balance_enquiry(string name,int x,vector<int>&deposit,Queue &q) {
     cout<<"Enter The account holder's name : "; cin>>name;
     int n=q.find(name);
      cout<<"Balance"<<'\n';
       cout<<deposit[n]<<'\n';
     
     
    
}



	
	
//	https://www.onlinegdb.com/online_c++_compiler#tab-stdin

void intro()									// Intro Screen
{https://www.onlinegdb.com/online_c++_compiler#tab-stdin
	cout<<"\n  BANK";
	cout<<"\nMANAGEMENT";
	cout<<"\n  SYSTEM";
	cout<<"\n\n\n\nMADE BY: \n\t\tIshan Dixit\n\t\tPrasad Gole\n\t\tNiteesh Kumar\n\t\tSatwik Merla";
	cout<<"\n\nDSA Group Project";
	cin.get();
}
	
// Driver Program 
int main() 
{   
    Queue q;
    string name;
    map<int, string> dict;
    vector<int> deposit;
    intro();
    int n,x;
    char ch;
    int r;
    cout<<"01.Bank Manager\n02.Customer";
    cin>>r;
    if(r==2)
    { 
    cout<<"Welcome...!\nHow was your Day\n";
    
    do
	{
	  
	cout<<"MAIN MENU";
 	cout<<"\n01. NEW ACCOUNT";	
 	cout<<"\n02. DEPOSIT AMOUNT";
	cout<<"\n03. WITHDRAW AMOUNT";
	cout<<"\n04. BALANCE ENQUIRY";
	cout<<"\n05. MODIFY AN ACCOUNT";
	cout<<"\n06. EXIT";
	//cout<<"\n07. MODIFY AN ACCOUNT";	cout<<"\n08. EXIT";
	cout<<"\nSelect Your Option (1-8) ";
	cout<<endl;
	cin>>ch;
	system ("clear");

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
		case '4' :
		    balance_enquiry(name, x,deposit, q);
		    break;
		case '5':
			q.modify_account(dict);
			break;
		 case '6':
			cout<<"\nThanks for using bank management system";
			break;
		}
		
	}
	while(ch!='8');	
	}
	else if(r==1)
	{
	    string id = "2018A2PS0825H";
	    int p = 12345;
	    string y;
	    cout<<"Enter ID-";
	    cin>>y;
	    cout<<"\nEnter Passcode-";
	    int u;
	    cin>>u;
	    cout<<"\n";
	    if(y==id&&u==p)
	    {
	     do
	{
	  
	cout<<"MAIN MENU";
 	cout<<"\n01. NEW ACCOUNT";	
 	cout<<"\n02. DEPOSIT AMOUNT";
	cout<<"\n03. WITHDRAW AMOUNT";
	cout<<"\n04. BALANCE ENQUIRY";
	cout<<"\n05. MODIFY AN ACCOUNT";
	cout<<"\n06. Display All Account Details";
	
	//cout<<"\n07. MODIFY AN ACCOUNT";	cout<<"\n08. EXIT";
	cout<<"\nSelect Your Option (1-8) ";
	cout<<endl;
	cin>>ch;
	system ("clear");

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
	
		case '6':
			display_all(dict,deposit);
			break;
			
		case '5':
			q.modify_account(dict);
			break;
		case '4' :
		    balance_enquiry(name, x,deposit, q);
		    break;
		case '8':
			cout<<"\nThanks for using bank management system";
			break;
		case '9':
		    char k;
		    cout<<"You Have Pressed Emergency.Was It A Mistake?\n Y / N \n";
		    cin>>k;
		    if (k=='Y') 
		    {
		    cout<<"Police On The Way\n";
		    }
		    else
		    {
		    cout<<"Help Cancelled\n";    
		    }
		    
		}
	
	}
           	while(ch!='8'); 
	    }
	    else {
	        cout<<"Wrong Credentials\n"<<endl;
		break;
	    }
	
	}
    
}
