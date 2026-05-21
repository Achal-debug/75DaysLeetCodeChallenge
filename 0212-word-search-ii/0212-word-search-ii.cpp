// Day 71 - 100 Days LeetCode Challenge
class TrieNode {
public:
    TrieNode* children[26];
    string word;
    TrieNode() {
        word = "";
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};
class Solution {
public:
    vector<string> result;
    void insert(string word, TrieNode* root){
        TrieNode* node = root;
        for(char c : word){
            int idx = c - 'a';
            if(node->children[idx] == NULL){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->word = word;
    }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node){
        char c = board[i][j];
        if(c == '#' || node->children[c - 'a'] == NULL){
            return;
        }
        node = node->children[c - 'a'];
        if(node->word != ""){
            result.push_back(node->word);
            node->word = "";
        }
        board[i][j] = '#';
        int rows = board.size();
        int cols = board[0].size();
        if(i > 0) dfs(board, i - 1, j, node);
        if(j > 0) dfs(board, i, j - 1, node);
        if(i < rows - 1) dfs(board, i + 1, j, node);
        if(j < cols - 1) dfs(board, i, j + 1, node);
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string word : words){
            insert(word, root);
        }
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                dfs(board, i, j, root);
            }
        }
        return result;
    }
};