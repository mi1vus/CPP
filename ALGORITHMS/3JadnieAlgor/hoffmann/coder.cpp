/*
Задача на программирование: кодирование Хаффмана



По данной непустой строке s длины не более 104, состоящей из строчных букв латинского алфавита, постройте оптимальный беспрефиксный код. В первой строке выведите количество различных букв k, встречающихся в строке, и размер получившейся закодированной строки. В следующих k строках запишите коды букв в формате "letter: code". В последней строке выведите закодированную строку.
*/


#include <iostream>
#include <cstring> //strlen
#include <string>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <queue>
#include <vector>
#include <map>

using namespace std;

struct Node {
	int letter;
	int weigth;
};

struct Tree{   
    Tree* left;    
    Tree* right;
    Node val;
};
 
class CompareTree {
public:
    bool operator()(Tree* t1, Tree* t2)
    {
		return t1->val.weigth > t2->val.weigth;
    }
};

void buildDict(Tree& tree, map <char,vector<short> >& dict,vector<short>& code){
	if (tree.val.letter != 0 && dict.count((char)tree.val.letter) == 0)
	{
		dict.insert(make_pair((char)tree.val.letter,code));
		return;
	}

	vector<short>& codeL = *(new vector<short>(code));
	codeL.push_back(0);
	vector<short>& codeR = *(new vector<short>(code));
	codeR.push_back(1);
	//delete &code;

	if (tree.left != 0)
	{
		Tree& treeL = *tree.left;
		buildDict(treeL,dict,codeL);
	}
	if (tree.right != 0 )
	{
		Tree& treeR = *tree.right;
		buildDict(treeR,dict,codeR);
	}
}

int main()
{
	char * word = new char[10001];
    int letters[2][256];
	for (int i = 0; i < 256; ++i)
	{
	    letters[0][i] = 0;
	    letters[1][i] = 0;
	}
    char ch = getchar();
    int letSize = 0;
	int wordSize = 0;
    while(isalpha(ch) )
    {
		if (letters[1][(int)(ch - 'a')] == 0)
			++letSize;
        ++letters[1][(int)(ch - 'a')];
		word[wordSize] = ch;
		++wordSize;
		ch = getchar();
    }
	
	
    priority_queue<Tree*, vector<Tree*>, CompareTree> pq;
 	
//	cout << "word: " << wordSize << " lett: " << letSize << endl;

	for (int i = 0; i < 256; ++i)
	{
		if (letters[1][i] > 0)
		{
			Tree* n = new Tree();
			n->val = *(new Node());
			n->val.letter = (i + (int)'a');
			n->val.weigth = letters[1][i];
			n->left = n->right = 0;
			pq.push(n);
		}
	}	

	if (pq.size()==1)
	{
		Tree* n1 = new Tree(*pq.top());
		pq.pop();
		Tree* newTree = new Tree();
		newTree->val = *(new Node());
		newTree->val.letter = 0;
		newTree->val.weigth = n1->val.weigth;
		newTree->left = n1;
		newTree->right = 0;
		pq.push(newTree);
	}
    while (pq.size() > 1) {
    //   Tree n = pq.top();
    //   cout << (char)n.val.letter << " " << n.val.weigth << " " << ((double)(n.val.weigth)/(double)(wordSize)) << endl;
    //   pq.pop();
		Tree* n1 = new Tree(*pq.top());
		pq.pop();
		Tree* n2 = new Tree(*pq.top());
		pq.pop();
		Tree* newTree = new Tree();
		newTree->val = *(new Node());
		newTree->val.letter = 0;
		newTree->val.weigth = n1->val.weigth + n2->val.weigth;
		newTree->left = n1;
		newTree->right = n2;
		pq.push(newTree);
    }
	
	Tree& tree = *(new Tree(*pq.top()));
	map<char,vector<short> >& dict  = *(new map<char,vector<short> >());
	vector<short>& code = *(new vector<short>());
	
	buildDict(tree,dict,code);
	map<char,vector<short> >::iterator cur;

	int codeSize = 0;
	
	for(int j = 0; j < wordSize; ++j){
		vector<short> code = dict[word[j]];
		codeSize += code.size();
	}
    
	cout << letSize << " " << codeSize << endl;
	
	for (cur=dict.begin();cur!=dict.end();cur++)
	{
		cout << (*cur).first << ": ";
		vector<short> code = (*cur).second;
		for (int i = 0; i < code.size(); ++i)
			cout << code[i];
		cout << endl;
	}
	
	for(int j = 0; j < wordSize; ++j){
		vector<short> code = dict[word[j]];
		for (int i = 0; i < code.size(); ++i)
			cout << code[i];
	}
//	cout << endl;

//	system("pause");
	return 0;
}
