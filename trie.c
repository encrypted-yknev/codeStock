#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define size 26
struct trieNode {
    bool isEnd;
    struct trieNode *children[size];
};
typedef struct trieNode trie;

trie * createNode() {
    trie *node = (trie *)malloc(sizeof(trie));
    int i;
    for(i=0;i<size;i++) 
        node->children[i]=NULL;
    
    node->isEnd=false;
    return node;
}

void insertNodes(trie *trie,char *str)  {
    int i,len=strlen(str),idx;
    for(i=0; i<len; i++)    {
        idx=str[i]-'a';
        if(!trie->children[idx])  {
            trie->children[idx]=createNode();
        }
        trie=trie->children[idx];
    }
    trie->isEnd=true;
}

bool searchNode(trie *node,char *key)   {
    int idx,i,len=strlen(key);
    
    for(i=0; i<len; i++)    {
        idx=key[i]-'a';
        if(!node->children[idx])
            return false;
        node=node->children[idx];
    }
    return (node->isEnd);
}
int main() {
	char *str[]={"try","trie","trim","cat","cater","walk","wait","waiter"};
	trie *node=createNode();
	int i,len=sizeof(str)/sizeof(*str);
	for(i=0; i<len; i++)    {
	    insertNodes(node,str[i]);
	}
	if(searchNode(node,"waiter"))
	    printf("Present in the trie");
	else
	    printf("Not present in the trie");
	return 0;
}
