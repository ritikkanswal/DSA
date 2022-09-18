// https://leetcode.com/problems/implement-trie-prefix-tree/


//Time Complexity : O(n) n->word length
//Space Complexity : O(26*n) n->maximum word length

class Trie {
public:
    /** Initialize your data structure here. */
    
    Trie *children[26]={};
    bool isEnd;
    Trie() {
         isEnd=false;
    }
    
    /** Inserts a word into the trie. */
    //Time Complexity : O(n) n->word length
    //Space Complexity : O(26*n) n->maximum word length
    void insert(string word) {
        Trie *node=this;
        for(int i=0;i<word.size();i++)
        {
            if(node->children[word[i]-'a']==NULL)
                node->children[word[i]-'a']=new Trie();
            node=node->children[word[i]-'a'];
        }
        node->isEnd=true;
        
    }
    
    /** Returns if the word is in the trie. */
    //Time Complexity : O(n) n->word length
    //Space Complexity : O(1)
    bool search(string word) {
         Trie *node=this;
        for(int i=0;i<word.size();i++)
        {
            if(node->children[word[i]-'a']==NULL)
                return false;
            node=node->children[word[i]-'a'];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    //Time Complexity : O(n) n->word length
    //Space Complexity : O(1)
    bool startsWith(string prefix) {
        Trie *node=this;
        for(int i=0;i<prefix.size();i++)
        {
            if(node->children[prefix[i]-'a']==NULL)
                return false;
            node=node->children[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */