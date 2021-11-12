#include <iostream>
using namespace std;

class node //node class
{
prviate:
	char data[20]; //word data
	node* pNext;   //next node
public:
	node()
	{
		memset(data, NULL, sizeof(data));
		pNext = NULL;
	}
	void SetData(char* str)
	{
		strcpy(data, str);
	}
	void SetNext(node* pNode)
	{
		pNext = pNode;
	}
	char* getData()
	{
		return data;
	}
	node* getNext()
	{
		return pNext;
	}
};

class list   //list class
{
private:
	node* pHead;   //Head node
	node* pTail;   //Tail node
public:
	list()
	{
		pHead = nullptr;
		pTail = nullptr;
	}
	void Insert(char* word) //function Insert
	{
		node* pNew = new node;
		pNew->SetData(word);
		pNew->SetNext(NULL);
		if(pHead == NULL)
		{
			pHead = pNew;
		}
		else
			pTail->SetNext(pNew);
		pTail = pNew;
	}
	void Print()   //function print
	{
		if(pHead == nullptr)
		{
			cout<<"No save word"<<endl;
		}
		else
		{
			node* pCurr = pHead;
			cout << pCurr->getData() << "->";
			while(pCurr->getNext() != NULL)
			{
				pCurr = pCurr->getNext();
				cout<<pCrr->getData()<<"->";
			}
		}
		cout << endl;
	}
	bool findoverlap(char *word)  //function findoverlap
	{
		node* ptr = pHead;
		bool isFind = false;
		int index = 0;
		while(ptr != NULL)
		{
			index++;
			if(strcmp(ptr->getData(), word) ==0)
			{
				return true;
			}
			ptr = ptr->getNext();
		}
	}
	bool wordchain(char* word)   //function wordchain
	{
		char str1[20];
		char str2[20];
		int lastnum = 0;

		strcpy(str1, pTail->getData());
		strcpy(str2, word);
		lastnum = strlen(str1)-1;
		if(str1[lastnum]==str2[0])
			return true;
		else
			return false;
	}
	void deletelist()         //function deletelist
	{
		node* ptr = pHead;
		while(ptr != nullptr)
		{
			pHead = ptr->getNext();
			delete ptr;
			ptr = pHead;
		}
		pTail = nullptr;
	}
};

int main(void)   //function main
{
	list wordL;
	int index = 0;
	char str[20];
	while(1)
	{
		cout<<"CMD(Word.exit)>> ";
		cin >> str;
		if(strcmp(str, "exit") ==0)
		{
			wordL.deletelist();
			return 0;
		}
		if(index == 0)
		{
			wordL.Insert(str);
			wordL.Print();
		}
		if(index >0)
		{
			if(wordL.wordchain(str) == true && wordL.findoverlap(str) == false)
			{
				wordL.Insert(str);
				wordL.Print();
			}
			else if(wordL.wordchain(str) == false)
			{
				cout << "Not chained" <<endl;
				wordL.Print();
			}
		}
		index++;
	}
}

