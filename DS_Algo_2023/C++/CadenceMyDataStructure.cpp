1. Structure design
	1. Insert an element - insert an integer at the end
	2. Return any element of data structure
	3. Delete elem at given position
	4. Give the last inserted elem
	

5, 13, 22
Delete -->22 (last inserted elem)
Delete(1st elem)--> Delete 5
13 last elem
Insert 37, 93
13, 37, 93


class myDataStructure
{
public:
int ds[100];
int* ds;
myDataStructure next*;
int top;


myDataStructure()
{
//ds=new myDataStructure(NULL);
ds=new[100];
next=NULL;
top=-1;
}

void insert(int x)
{
	top=top+1;
	ds[top] = x;	
}

void delete(int pos)
{
	for(int i=pos+1; i<100;i++) ->O(n)
		ds[i-1]=ds[i];
	
	int* tempptr=&ds[pos];
	int* nextptr=&ds[pos+1];
	int* prevptr=&ds[pos-1];
	
	prevptr->next = nextptr;
	delete tempptr;
	
}

int lastInserted()
{
return (ds[top]);
}

int returnAnyElem()
{
if(top==-1)
{
cout<<"Underflow";
return -1;
}
return (ds[0]);

}