// Day 45 - 75 Days LeetCode Challenge
class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isEnd = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;

        for(char c : word){
            int idx = c - 'a';

            if(node->children[idx] == NULL){
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        node->isEnd = true;
    }

    bool searchHelper(string word, int index, TrieNode* node){

        if(index == word.size()){
            return node->isEnd;
        }

        char c = word[index];

        if(c != '.'){
            int idx = c - 'a';
            if(node->children[idx] == NULL) return false;

            return searchHelper(word, index + 1, node->children[idx]);
        }

        for(int i = 0; i < 26; i++){
            if(node->children[i] != NULL){
                if(searchHelper(word, index + 1, node->children[i])){
                    return true;
                }
            }
        }

        return false;
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};