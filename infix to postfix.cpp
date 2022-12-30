#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

class stack				//creating linked list node 
{
	char p;   // operator stack
	float r;   // operand stack
	stack *next;
	public:
	stack()
	{
		r = 0;
		next = NULL;
	}
	void setval(float x)
	{
		r = x;
	}
	float getval()
	{
		return r;
	}
	void setchar(char x)
	{
		p = x;
	}
	char getchar()
	{
		return p;
	}
	stack* getnext()
	{
		return next;
	}
	void setnext(stack *t)
	{
		next = t;
	}
};

class intopos   // operations
{
	stack *top;
	int j;
	char *post;
	char *in;
	public:
	intopos()					// default dynamic constructor
	{
		j = 0;
		in = new char[20];
		post = new char[20];
		top = NULL;

	}
	stack* gettop()             // to return topmost operator from the stack
	{
		return top;
	}
	void settop(stack *w)       // to set topmost operator in the stack
	{
		top = w;
	}
	void push(char x);
	char pop();
	void push1(float x);
	float pop1();
	void op();
	int icp(char x);
	int isp();
	void disp();
	void eva();
	void eva1();
};

void intopos::push(char x)			// to push operator into stack
{
	stack *nn;
	nn = new stack();
	nn->setchar(x);
	if(top == NULL)
	{
		settop(nn);
	}

	else
	{
		nn->setnext(gettop());
		settop(nn);
	}
}

char intopos::pop()					//to pop operator out of stack
{
	if(top == NULL)
	{
		cout<<"EMPTY";
		return '\0';
	}

	else
	{
		stack *t;
		t = gettop();
		settop(gettop()->getnext());
		char z = t->getchar();
		t->setnext(NULL);
		delete t;
		return z;
	}
}

int intopos::icp(char x)			//for incoming priority
{
	if(x == '(')
		return 4;

	else if(x == '+' || x == '-')
		return 1;

	else if(x == '*' || x == '/')
		return 2;

	else if(x == '^')
		return 4;

	else if(x == ')')
		return -1;

	else //if operand
		return -2;
}

int intopos::isp()				//for in Stack priority
{
	if(gettop() != NULL)   //i.e. if stack not empty
	{
		char x = gettop()->getchar();    //retrieve character from topmost node and store in x
		if(x == '(')
			return 0;

		else if(x == '+' || x == '-')
			return 1;

		else if(x == '*' || x == '/')
			return 2;

		else if(x == '^')
			return 3;

		else  //operand
			return -3;
	}

	else if(gettop() == NULL)
			return -4;
}

void intopos::op()	//to convert infix to postfix expression
{
	int a, b, l, v = 0;    //v is counter, l length of 								//expression
	char x;
	cout<<"\nLength of the expression : ";
	cin>>l;
	cout<<"\nEnter the infix expression: ";
	while(v < l)        //read infix expression
	{
		/*cout<<"\nCharacter "<<v + 1<<" : ";*/
		cin>>x;
		in[v] = x;
		v++;
	}
	in[v] = '\0';           // attach '\0' as end of string mark
	v = 0;
	while(v < l)
	{
		a = isp();          // assign instack priority to a
		b = icp(in[v]);     // assign incoming priority of operator to b
		if(b == -2)         // i.e. if operand, then copy in post
		{
			post[j] = in[v];
			j++;
		}

		else if(b == 4 || b == 2 || b == 1)   // if operator, then check priority
		{
			if(b > a)                           // if greater, the push in stack
			{
				push(in[v]);
			}
			else
			{
				while(b <= a)                   // if smaller or equal, the pop from stack
				{
					post[j] = pop();
					j++;
					a = isp();                  // call isp()till icp <= isp
				}
				push(in[v]);
			}
		}
		else if(b == -1)
		{
			while(gettop()->getchar() != '(')
			{
				post[j] = pop();
				j++;
			}
			char c = pop();                     // pop '(' also from stack
		}
		v++;                                    // read next char in infix expr.
	}
	while(gettop() != NULL)                     // at the end of infix expression, pop all contents from stack and add in postfix expr.
	{
		char c = pop();
		if(c != '(')
		{
			post[j] = c;
			j++;
		}
	}
}

void intopos::disp()						// to display the both expressions
{
	cout<<"\nInfix expression is: "<<in<<endl;
	cout<<"\nPostfix expression is: ";
	for(int w = 0; w < j; w++)
	{
		cout<<post[w];
	}
	cout<<endl;
}

void intopos::push1(float x)        // to push operands in stack
{
	stack *nn;
	nn = new stack();
	nn->setval(x);
	if(top == NULL)
	{
		settop(nn);
	}

	else
	{
		nn->setnext(gettop());
		settop(nn);
	}
}

float intopos::pop1()             // to pop operands from stack
{
	if(gettop() == NULL)
	{
		cout<<"EMPTY";
		return 0;
	}

	else
	{
		stack *t;
		t = gettop();
		settop(gettop()->getnext());
		float z = t->getval();
		t->setnext(NULL);
		delete t;
		return z;
	}
}


void intopos::eva()    				//for evaluation after conversion from infix to postfix
{
	float e, f, u;
	int w = 0, b;
	while(w < j)
	{
		b = icp(post[w]);
		if(b == -2)                         // for operand, enter value of it
		{
			cout<<"\nEnter a value of "<<post[w]<<" : ";
			cin>>e;
			push1(e);                       // push in stack for operand stack
		}
		else if(b != -2)
		{
			if(b == 1)
			{
				if(post[w] == '+')
				{
					e = pop1();
					f = pop1();
					u = e+f;
					push1(u);
				}
				if(post[w] == '-')
				{
					e = pop1();
					f = pop1();
					u = (f-e);
					push1(u);
				}
			}
			else if(b == 2)
			{
				if(post[w] == '*')
				{
					e = pop1();
					f = pop1();
					u = (e*f);
					push1(u);
				}
				if(post[w] == '/')
				{
					e = pop1();
					f = pop1();
					u = (f/e);
					push1(u);
				}
			}
			else if(b == 4)
			{
				e = pop1();
				f = pop1();
				u = pow(e,f);
				push1(u);
			}
		}
		w++;
	}
	cout<<"\nThe value of the evaluated equation is "<<pop1();
}

void intopos::eva1()  						//for postfix evaluation
{
	float e, f, u;
	char *h;
	int w = 0, b, l;
	cout<<"\nEnter the length of the postfix expression : ";
	cin>>w;
	h = new char[20];
	cout<<"\nEnter the postfix expression: ";
	for(l = 0; l < w; l++)
	{
		cin>>h[l];
	}
	l = 0;
	while(l < w)
	{
		b = icp(h[l]);
		if(b == -2)
		{
			cout<<"\nEnter a value of "<<h[l]<<" : ";
			cin>>e;
			push1(e);
		}
		else if(b != -2)
		{
			if(b == 1)
			{
				if(h[l] == '+')
				{
					e = pop1();
					f = pop1();
					u = e+f;
					push1(u);
				}
				if(h[l] == '-')
				{
					e = pop1();
					f = pop1();
					u = (f-e);
					push1(u);
				}
			}
			else if(b == 2)
			{
				if(h[l] == '*')
				{
					e = pop1();
					f = pop1();
					u = (e*f);
					push1(u);
				}
				if(h[l] == '/')
				{
					e = pop1();
					f = pop1();
					u = (f/e);
					push1(u);
				}
			}
			else if(b == 4)
			{
				e = pop1();
				f = pop1();
				u = pow(e,f);
				push1(u);
			}
		}
		l++;
	}
	cout<<"\nThe value of the evaluated equation is "<<pop1();
}

int main()
{
	int d;  //choice
	char y;   // yes or no to continue
	do{
		cout<<"\nSelect an option\n1: Infix to postfix conversion\t2: Postfix evaluation\n";
		cin>>d;
		switch(d)
		{
			case 1:{
				intopos i1;
				i1.op();  // for conversion infix to postfix
				i1.disp();
				cout<<"\nDo you want to evaluate the postfix expression(Press y) : ";
				cin>>y;
				if(y == 'y' || y == 'Y')
				{
					i1.eva(); // evaluate postfix
				}
				break;
			}
			case 2:{
				intopos i2;
				i2.eva1();  // evaluated input postfix expression
				break;
			}
			default:{
				cout<<"\nThis option doesn't exist\n";
				break;
			}
		}
		cout<<"\nContinue(y/Y): ";
		cin>>y;
	}while(y == 'Y' || y == 'y');
	return 0;
}

