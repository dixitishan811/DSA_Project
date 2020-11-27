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
		cout<<"Current status of Queue :"<<endl;
		if(temp==NULL)
		{
		    cout<<"Empty"<<endl;
		    front=NULL;
		    rear=NULL;
		}
		else
		{
		    
		
		cout<<front->data<<endl;
		while(temp->next!=NULL)
		{   temp=temp->next;
		    cout<<temp->data<<endl;
		}
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
    cout<<"Enter number of accounts to be created : ";				// creating multiple accounts at once
    cin>>n;	
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Bad entry.Enter an integer: ";
        cin >> n;
    }


	if (n<=0)
	{
		cout<< "Enter integer number greater than 0:"<<endl;
		cin>>n;
	}

	
    for(int i=0;i<n;i++)
    {
	cout<<"Enter account holder name and the initial deposit amount in Account "<<i+1<<":"<<endl;
        int x;
        cin>>name;								// Account name
        cin>>x;									// Initial Deposit amount
        deposit.push_back(x);
        q.enQueue(name);
        dict.insert(std::pair<int,string>(rand()%1000000000,name));		// creates a randomized 9 digit acc no.
    }
	
    q.disp();
    
}
void delete_account(map<int,string>&dict,Queue&q)
    {
        string x;
	    cout<<"Enter the account name to be deleted  :"<<endl;
	    cin>>x;
	   for (auto itr = dict.begin(); itr != dict.end(); ++itr) 
    {   
        if(itr->second==x)
        {
            dict.erase(itr->first);
        }
    }
        QNode *prev;
        QNode *temp;
        temp=q.front;

       if(temp->data==x)
        {
            q.front=temp->next;
            free(temp);
        }
 
else if(temp == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    } 
    else
        {
            
        
        while(temp->next!=NULL)
		{   
		    
		    if((temp->next)->data==x)
		    {
		        prev=temp;
		        temp=temp->next;
		        
		    }
		    if(temp->data==x)
		    {   
		        
		        prev->next=temp->next;
		        cout<<temp->next;
		        free(temp);
		        break;
		    }
		    else
		    {
		        temp=temp->next;
		    }
		    
		}
        }
	q.disp();
    }
	
void dep(string name,int x,vector<int>&deposit,Queue &q)			// depositing money  
{   
    int  pop;
    cout<<"Do You Have an Account?\n";
    cout<<"1.YES \n2.NO\n";
    cin>>pop;
    if(pop==1) {
	cout<<"Enter The account holder's name : "; cin>>name;
	cout<<"Enter The amount to be deposited : "; cin>>x;
    int n=q.find(name);

deposit[n]+=x; }
if(pop==2)
{
    cout<<"Create An Account First:\n";
}
if(pop!=1&&pop!=2) {
    cout<<"In Appropriate Entry\n";
}
}
// void dep(string name,int x,vector<int>&deposit,Queue &q)			// depositing money  
// {   
// 	cout<<"Enter The account holder's name : "; cin>>name;
// 	cout<<"Enter The amount to be deposited : "; cin>>x;
//     int n=q.find(name);

// deposit[n]+=x;
// }

void withdraw(string name,int x,vector<int>&deposit,Queue &q)			// withdrawning money
{   
     int  poe;
    cout<<"Do You Have an Account?\n";
    cout<<"1.YES\n2.NO\n";
    cin>>poe;
    if(poe==1) {
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
    }
    if(poe==2) {
        cout<<"Create An Account First\n";
    }
    if(poe!=1&&poe!=2) {
        cout<<"In Appropriate Entry\n";
    }
	 //cout<<"Account no."<<'\t'<<"Account holder's name"<< '\t'<<"Balance"<<'\n';
	 
}


// void withdraw(string name,int x,vector<int>&deposit,Queue &q)			// withdrawning money
// {   
// 	cout<<"Enter The account holder's name : "; cin>>name;
// 	cout<<"01.current\n02.savings\n";
// 	int z;
// 	cin>>z;
// 	 int n=q.find(name);
// 	if(z=1)
// 	{
// 	cout<<"Enter The amount to be withdrawn : "; cin>>x;	
//         if(deposit[n]<x)
//         {
//         cout<<"N0 sufficient amount";
//         }
//         else
//         {
//         deposit[n]-=x;
//         }
// 	}
// 	else
// 	{
// 	cout<<"Enter The amount to be withdrawn : "; cin>>x;	
       
//         if(deposit[n]<x)
//         {
//         cout<<"N0 sufficient amount.\n";
//         }
//         else
//         {
//         deposit[n]-=x;
//         }
// 	}
// 	char e;
// 	cout<<"Do you want to know your balance?\n";
// 	cout<<" Y / N\n";
// 	cin>>e;
	
// 	if(e=='Y') 
// 	{
// 	  cout<<"Balance"<<'\n';
// 	  cout<<deposit[n]<<'\n';
// 	}
	
// 	 //cout<<"Account no."<<'\t'<<"Account holder's name"<< '\t'<<"Balance"<<'\n';
	 
// }

void display_all(map<int,string>&dict,vector<int>&deposit)			// View all Accounts
{
    int i=0;
    cout<<"Account no."<<'\t'<<"Account holder's name"<< '\t'<<"Balance"<<'\n';
    for (auto itr = dict.begin(); itr != dict.end(); ++itr,++i) 
    {
        cout << itr->first<< '\t'  << '\t'<<'\t'<<itr->second << '\t'<<deposit[i]<<'\n';
    }
    cout<<endl;
}
// void balance_enquiry(string name,int x,vector<int>&deposit,Queue &q) {
//      cout<<"Enter The account holder's name : "; cin>>name;
//      int n=q.find(name);
//       cout<<"Balance"<<'\n';
//        cout<<deposit[n]<<'\n';    
// }


void balance_enquiry(string name,int x,vector<int>&deposit,Queue &q) {
     int  pov;
    cout<<"Do You Have An Account?\n";
    cout<<"1.YES\n2.NO\n";
    cin>>pov;
    if(pov==1) 
    {
     cout<<"Enter The account holder's name : "; cin>>name;
     int n=q.find(name);
      cout<<"Balance"<<"\n";
      cout<<deposit[n]<<"\n"; 
    }
    if(pov==2) {
        cout<<"Create AN Account First\n";
    }
    if(pov!=1&&pov!=2) {
        cout<<"In Appropriate Entry\n";
    }
}


void Total_Amount(map<int,string>&dict,vector<int>&deposit) 			//Total Amount with the bank (Only accessible to Manager)
	    {
	        int com;
	        cout<<"Do your Bank Has Accounts?"<<endl;
	        cout<<"01.Yes\n02.NO\n"<<endl;
	        cin>>com;
	        if(com==1) {
	         int i=0;
	         int m=0;
              cout<<"Accounts Balance:\n";
              for (auto itr = dict.begin(); itr != dict.end(); ++itr,++i) 
        {
              m=m+deposit[i];
        }
        cout<<m<<endl; }
        if(com==2) {
            cout<<"Please Create Accounts First"<<endl;
        }
        if(com!=1&&com!=2) {
            cout<<"In Appropiate Entry"<<endl;
        }
    
	    } 



void intro()									// Intro Screen
{
	cout<<"\n\t\t     BANK";
	cout<<"\n\t\t  MANAGEMENT";
	cout<<"\n\t\t    SYSTEM";
	cout<<"\n\n\t\tDSA Group Project";
	cout<<"\n\n\n\n\t   MADE BY: \n\t\tIshan Dixit\n\t\tPrasad Gole\n\t\tNiteesh Kumar\n\t\tSatwik Merla\n\n";
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
    int ch;
    int r;
    here:
    cout<<"01.Bank Manager\n02.Customer\n03.Exit\n";
    cin>>r;
	if (r!=1 && r!=2 && r!=3)
	{
		cout<<"Enter a option number as 1 or 2."<<endl;
		cin>>r;
	}
	if(r==3)
	{
	    cout<<"\nThanks for using bank management system";
	}
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
	cout<<"\nSelect Your Option (1-6) ";
	cout<<endl;
	cin>>ch;
	system ("clear");

		switch(ch)
		{
		case 1:
			write_account(deposit, q,dict);
			break;
		case 2:
			dep( name, x,deposit, q);
			break;
		case 3: 
			withdraw(name, x,deposit, q);
			break;
		case 4 :
		    	balance_enquiry(name, x,deposit, q);
		   	break;
		case 5:
			cout<<"Do you Have An Account\n";
		cout<<"01.Yes\n02.N0\n";
		int man;
		cin>>man;
		if(man==1) {
			q.modify_account(dict); 
			break; }
		if(man==2) {
		    cout<<"Create An Account First\n";
		    break;
		}
		if(man!=1&&man!=2) {
		    cout<<"In Appropriate Entry\n";
		    break;
		}
			break;
		case 6:
			cout<<"\nThanks for using bank management system"<<endl;
			goto here;
			break;
		case 0:
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
		    
		default :
		cout<<"In Appropriate Entry\n";
		}
		
	}
	while(ch!=6);	
	}
	else if(r==1)
	{
	    string id = "1234";
	    int p = 1234;
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
	cout<<"\n06. DELETE AN ACCOUNT";
	cout<<"\n07. Display All Account Details";
	cout<<"\n08. Display total Amount in Bank";
	cout<<"\n09. EXIT";
	cout<<"\nSelect Your Option (1-9) ";
	cout<<endl;
	cin>>ch;
	system ("clear");

		switch(ch)
		{
		case 1:
			write_account(deposit, q,dict);
			break;
		case 2:
			dep( name, x,deposit, q);
			break;
		case 3: 
			withdraw(name, x,deposit, q);
			break;
		case 4 :
		    balance_enquiry(name, x,deposit, q);
		    break;
		case 5:
			cout<<"Do you Have An Account\n";
			cout<<"01.Yes\n02.N0\n";
			int man;
			cin>>man;
			if(man==1) {
				q.modify_account(dict); 
				break; }
			if(man==2) {
			    cout<<"Create An Account First\n";
			    break;
			}
			if(man!=1&&man!=2) {
			    cout<<"In Appropriate Entry\n";
			    break;
			}

	    	case 6 :
		    delete_account(dict,q);
		    break;
		case 7:
			display_all(dict,deposit);
			break;

		case 8:
			Total_Amount(dict,deposit);
			break;
		case 0:
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
		    break;
		 case 9:
			cout<<"\nThanks for using bank management system"<<endl;
			goto here; 
			break;
		}
	
	}
           	while(ch!=9); 
	    }
	    else {
	        cout<<"Wrong Credentials\n"<<endl;
	
	    }
	
	}
}
