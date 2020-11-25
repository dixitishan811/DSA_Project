//New code

*****************************************
#include <iostream>
#include <stdlib.h>
#include<map>
#include<vector>
#include <bits/stdc++.h> 
using namespace std;
struct QNode 
{ 
    string data; 

    QNode* next; 
    QNode(string d) 
    { 
        data = d; 
        next = NULL; 
    } 
}; 
  
struct Queue 
{ 
    int n=0;
    QNode *front, *rear; 
    Queue() 
    { 
        front = rear = NULL; 
    } 
  
    void enQueue(string x) 
    { 
  
        // Create a new LL node 
        n++;
        QNode* temp = new QNode(x); 
  
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
	void deQueue() 
	{   n--;
	// If queue is empty, return NULL. 
	if (front == NULL) 
	    return; 

	// Store previous front and 
	// move front one node ahead 
	QNode* temp = front; 
	front = front->next; 

	// If front becomes NULL, then 
	// change rear also as NULL 
	if (front == NULL) 
	    rear = NULL; 

	delete (temp); 
	} 
	int find(string x)
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

void write_account(vector<int>&deposit,Queue &q,map<string,int>&dict)
{   
    string name;
    int n;
    cout<<"Enter number of accounts to be created : ";
    cin>>n;
    cout<<"Enter account holder name and the initial deposit amount:"<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>name;
        cin>>x;
        deposit.push_back(x);
        q.enQueue(name);
        dict.insert(std::pair<string,int>(name,rand()%1000000000));
    }
}

void dep(string name,int x,vector<int>&deposit,Queue &q)
{   
	cout<<"Enter The account holder's name : "; cin>>name;
	cout<<"Enter The amount to be deposited : "; cin>>x;
    int n=q.find(name);

deposit[n]+=x;
}
	
void withdraw(string name,int x,vector<int>&deposit,Queue &q)
{   
	cout<<"Enter The account holder's name : "; cin>>name;
	cout<<"Enter The amount to be withdrawn : "; cin>>x;
    int n=q.find(name);
    deposit[n]-=x;
}

void display_all(map<string,int>&dict,vector<int>&deposit)
{
    int i=0;
    cout<<"Account holder's name"<<'\t'<<"Account no."<< '\t'<<"Balance"<<'\n';
    for (auto itr = dict.begin(); itr != dict.end(); ++itr,++i) 
    {
        cout << itr->first<< '\t'  << '\t'<<'\t'<<itr->second << '\t'<<deposit[i]<<'\n';
    }
}


void modify_account(string name, vector<int>&amount, Queue q)
{
	cout<<"Enter The account holder's name : "; cin>>name;
	cout<<"Enter The amount to be deposited : "; cin>>x;
  
// Driver Program 
int main() 
{   
    Queue q;
    string name;
    map<string, int> dict;
    vector<int> deposit;
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
