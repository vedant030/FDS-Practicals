#include <iostream>
using namespace std;
const int MAX = 50;
class queue
{
int front, rear;
int data[MAX];
public:
queue()
 {
front = -1;
rear = -1;
 }
void create()
 {
int n, i;
cout << "\nEnter no. of elements you want to enter in queue : ";
cin >> n;
front++;
cout << "\nEnter the elements : ";
for (i = 0; i < n; i++)
 {
cin >> data[i];
 }
rear = i - 1;
 }
void enqueue(int x)
 {
if (rear == MAX - 1)
 {
cout << "\n\tQUEUE OVERFLOWN !!!";
 }
else
 {
if (front == -1)
 {
data[++front] = x;
rear = front;
 }
else
 {
data[++rear] = x;
 }
 }
 }
void dequeue()
 {
int item = data[front];
cout << "\n\tDeleted item : " << item;
front++;
 }
void dislay()
 {
cout << "\n\tQueue contains : ";
for (int i = front; i <= rear; i++)
 {
cout << data[i] << " ";
 }
 }
};
int main()
{
queue q;
int ch = 0;
do
 {
cout << "\n\n-----------------MENU OF OPERATIONS-------------------";
cout << "\n\n1. Create\n2. Insert\n3. Delete\n4. Display\n 5.Exit";
cout << "\n\nEnter your choice : ";
cin >> ch;

switch (ch)
 {
case 1:
q.create();
break;
case 2:
int x;
cout << "\n\tEnter element to insert : ";
cin >> x;
q.enqueue(x);
break;
case 3:
q.dequeue();
break;
case 4:
q.dislay();
break;
case 5:
cout << "\n\tEXITING...";
break;
 }
 } while (ch != 5);
}

