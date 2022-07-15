#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TrieNode
{
    bool isTerminal;
    TrieNode* nextChars[26];

    TrieNode()
    {
        // for(auto &node : nextChars)
        // {
        //     node = nullptr;
        // }
        for(int i = 0; i < 26; i++)
            nextChars[i] = nullptr;
        isTerminal = false;
    }

    // ~TrieNode()
    // {
    //     for(auto node : nextChars)
    //     {
    //         delete node;
    //     }
    // }
};

class WordDictionary {
    
public:
    WordDictionary() {
        root = new TrieNode;    
    }
    
    void addWord(string word) {
        TrieNode* iterNode = root;
        for(auto i = word.begin(); i != word.end(); i++)
        {
            if(iterNode->nextChars[*i - 'a'] == nullptr)
            {
                iterNode->nextChars[*i - 'a'] = new TrieNode;
            }
            iterNode = iterNode->nextChars[*i - 'a'];
        }
        
        iterNode->isTerminal = true;
        return;
    }
    
    // change to recursive first, then it will get easier.
    bool search(string word) {
        if(previouslyTrue.find(word) != previouslyTrue.end())
            return true;
        bool found = search(word, word.begin(), root);
        if(found)
        {
            previouslyTrue.insert(word);
        }
        return found;
    }

    bool search(const string& word, string::const_iterator i, TrieNode* iterNode)
    {
        if(i == word.end())
        {
            if(iterNode->isTerminal)
                return true;
            return false;
        }

        if(*i == '.')
        {
            bool foundAnywhere = false;
            for(const auto &node : iterNode->nextChars)
            {
                if(node != nullptr && search(word, std::next(i), node))
                {
                    foundAnywhere = true;
                    break;
                }
            }

            return foundAnywhere;
        }

        if(iterNode->nextChars[*i - 'a'] == nullptr)
            return false;
        return search(word, std::next(i), iterNode->nextChars[*i - 'a']);
    }
    
private:
    TrieNode* root;
    unordered_set<string> previouslyTrue;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */