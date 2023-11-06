#include "simpletrie.h"

using namespace std;

using namespace std;
void testTrie(TrieSimple* trie, vector<string> diccionario){
    for(string word : diccionario)
        trie->insert(word);
    cout<<trie->toString(" ")<<endl;
    cout<<trie->search("amor")<<endl;
    cout<<trie->search("rosa")<<endl;
    cout<<trie->count_nodes()<<endl;
    trie->remove("roma");
    cout<<trie->count_nodes()<<endl;
    trie->remove("amorcito");
    cout<<trie->count_nodes()<<endl;
    cout<<trie->toString(",")<<endl;

}
int main(){
    vector<string> diccionario = {"romano", "roma", "romario", "rosario", "rata",
    "amor", "amorfo", "amorcito", "amiga"};
    testTrie(new TrieSimple(), diccionario);
    return 0;
}
