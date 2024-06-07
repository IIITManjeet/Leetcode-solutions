class Solution {
public:
    class TrieNode{
        public:
        bool end;
        vector<TrieNode*>child;
        TrieNode():child(26,nullptr){end=false;}
    };
    class Trie{
        private:TrieNode* root;
        public:
        Trie(){root=new TrieNode();}
        void insert(string word){
            TrieNode* cur=root;
            for(char c:word){
                if(cur->child[c-'a']==nullptr){
                    cur->child[c-'a']=new TrieNode();
                }
                cur=cur->child[c-'a'];
            }
            cur->end=true;
        }
        string shortestRoot(string word,int n){
            TrieNode* cur=root;
            for(int i=0;i<n;i++){
                char c=word[i];
                if(cur->child[c-'a']==nullptr)return word;
                cur=cur->child[c-'a'];
                if(cur->end)return word.substr(0,i+1);
            }
            return word;
        }
    };
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie dict;
        for(auto w:dictionary){
            dict.insert(w);
        } 
        istringstream s(sentence);
        string word,ans;
        while(getline(s,word,' '))ans+=dict.shortestRoot(word,word.size())+" "; 
        ans.pop_back();
        return ans; 
    }
};