#include <bits/stdc++.h>
using namespace std;

const unsigned ALPHA_SIZE = 26; // tamanio del alfabeto de letras minusculas

class TrieSimple
{
private:
    struct TrieNode
    {           
		TrieNode **children;//Usando arrays O(m)
        bool endWord; // indica si es final de una palabra
        int count;//para el remove

        TrieNode()
        {
			endWord = false;
			count = 0;
			children = new TrieNode*[ALPHA_SIZE];
			for(int i=0;i<ALPHA_SIZE;i++)
				children[i] = nullptr;
        }

         ~TrieNode()
        {
            for(int i = 0; i < ALPHA_SIZE; ++i) {
                delete children[i];
            }
            delete[] children;
        }
    };

    TrieNode *root;

    

public:
    TrieSimple() : root(nullptr) {  }
	
	void insert(string key)
    {
       if(root == nullptr)
		   root = new TrieNode();
	   TrieNode* temp = root;
	   int index;
	   for(int i=0;i<key.size();i++)
	   {
		 index = key[i] - 'a'; 
		 if(temp->children[index] == nullptr)
			 temp->children[index] = new TrieNode();
		 temp = temp->children[index];
	   }
	   temp->endWord = true;
    }
    
	bool search(string key){
	if(root == nullptr)
		return false;
    int index;
	TrieNode* temp = root;
	for(int i=0;i<key.size();i++){
		index = key[i] - 'a'; 
		if(temp->children[index] == nullptr)
			return false;
		temp = temp->children[index];
	}
	return temp->endWord;
  }	  
	


//     void remove(string key) {
//     if (root == nullptr) return; 

//     TrieNode* current = root;
//     for (char ch : key) {
//         int index = ch - 'a';
//         if (current->children[index] == nullptr) {
//             return;
//         }
//         current = current->children[index];
//     }

//     current->endWord = false;
// }

    TrieNode *remove(TrieNode *node, string key, int s = 0)
    {
        if (node == nullptr)
            return nullptr;

        if (s == key.size())
        {
            if (node->endWord)
                node->endWord = false;

            if (isEmpty(node))
            {
                delete node;
                node = nullptr;
            }

            return node;
        }

        int index = key[s] - 'a';
        node->children[index] = remove(node->children[index], key, s + 1);

        if (isEmpty(node) && node->endWord == false)
        {
            delete node;
            node = nullptr;
        }

        return node;
    }

    void remove(string key)
    {
        root = remove(root, key);
    }

    bool isEmpty(TrieNode *node)
    {
        for (int i = 0; i < ALPHA_SIZE; i++)
            if (node->children[i] != nullptr)
                return false;
        return true;
    }

    // imprimir ordenado linea por linea
    string toString(string sep)
    {
        return toString(root, sep, "");
    }
	
	int count_nodes(){
        return count_nodes(root);
    }

private:
	int count_nodes(TrieNode* node){
        if(node == nullptr) 
            return 0;
        int count = 1;
        for(int i=0;i<ALPHA_SIZE;i++)
            count += count_nodes(node->children[i]);
        return count;
    }
	
    string toString(TrieNode *node, string sep, string prefix)
    {
		if(node == nullptr)
			return "";
		string str = "";
		if(node->endWord)
			str += prefix + sep;
		for(int i=0;i<ALPHA_SIZE;i++)
		{
			if(node->children[i] != nullptr)						
				str += toString(node->children[i], sep, prefix + char('a' + i));			
		}
        return str;
    }
};
