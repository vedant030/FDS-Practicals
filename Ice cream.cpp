#include<iostream>
using namespace std;
class sll
{
    struct node
    {
        int rn;
        node *next;
    }*start;
    public:
        sll()
        {
            start=NULL;
        }
        void create();
        void display();
        void both(sll obj2);
        //void neither(sll);
        //int compute();
        
};
void sll::create()
{	node *temp;
	node *curr;
	int prn;
	char name;
	int ans;
	do
	{
		temp = new node;
		temp->next=NULL;
		cout<<"\n Enter Roll Number :"<<endl;
		cin>>temp->rn;
		
		if (start==NULL)
		{
			start=temp;
			curr = temp;
		}
		else
		{
			curr->next = temp;
			curr = temp;
		}
		cout<<"Do you want to add a new node ? 1 for yes"<<endl;
		cin>>ans;
		
	}while(ans==1);
}
void sll::display()
{
    node *t;
	if(start==NULL)
	{
		cout<<"Class is empty"<<endl;
		return;
	}
	else
	{
		t = start;
		while(t!=NULL)
		{
			cout<<"\t"<<t->rn;
			t = t->next;
		}
		cout<<" NULL";
	}
}

void sll::both(sll obj2)
{
	node *temp1, *temp2;
	temp1=start;
	while(temp1!=NULL)
	{
		temp2=obj2.start;
		while(temp2!=NULL)
		{
			if((temp1->rn)==(temp2->rn))
			{
				cout<<"\n"<<temp1->rn;
				break;
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
}

/*int sll::compute()
{
	node *temp;
	int count=0;
	if(start==NULL)
	{
		cout<<"\nClub is empty"<<endl;
	}
	temp=start;	
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}*/

int main()
{
    sll obj1, obj2;
    int ch;
    do
	{
		cout<<"\n1.Create and Display\n2.Students who like both Ice-creams\n0. Exit\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				   cout<<"\n The Set of the students who like Vallia Ice-cream";
				   obj1.create();
			       obj1.display();
			       cout<<endl;
			       cout<<"\n The Set of the students who like Butterscotch Ice-cream";
			       obj2.create();
			       obj2.display();
				   break;
			case 2:
					cout<<"\n The stuents who like both Vanilla and Butterscotch Ice-cream are: ";
					obj1.both(obj2);
			  		break;
			//case 3:obj1.neither(obj2);
			  //     break;       
				   	   	   	   
		}
	}while(ch!=0);
cout<<"\nEnd of program"<<endl;				
	return 0;
}
