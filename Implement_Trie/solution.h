#include <string>
#include <unordered_map>
using namespace std;

struct TrieNode
{
    bool isTerminal = false;
    unordered_map<char, TrieNode*> nextChars;
};

class Trie {
public:
    Trie() {
        root = new TrieNode;
    }

    void insert(string word) {
        TrieNode* iterNode = root;
        for(auto i = word.begin(); i != word.end(); i++)
        {
            if(iterNode->nextChars.find(*i) == iterNode->nextChars.end())
            {
                iterNode->nextChars[*i] = new TrieNode;
            }
            iterNode = iterNode->nextChars[*i];
        }
        
        iterNode->isTerminal = true;
        return;
    }
    
    bool search(string word) {
        TrieNode* iterNode = root;
        for(auto i = word.begin(); i != word.end(); i++)
        {
            if(iterNode->nextChars.find(*i) == iterNode->nextChars.end())
            {
                return false;
            }
            iterNode = iterNode->nextChars[*i];
        }

        if(iterNode->isTerminal)
            return true;
        else
            return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* iterNode = root;
        for(auto i = prefix.begin(); i != prefix.end(); i++)
        {
            if(iterNode->nextChars.find(*i) == iterNode->nextChars.end())
            {
                return false;
            }
            iterNode = iterNode->nextChars[*i];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */