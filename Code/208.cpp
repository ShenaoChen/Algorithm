// 二维数组实现
class Trie {
public:
    int son[100010][26], cnt[100010], idx;
    Trie() {
        memset(son, 0, sizeof(son));
        memset(cnt, 0, sizeof(cnt));
        idx = 0;
    }
    
    void insert(string word) {
        int p = 0;
        int n = word.size();
        for(int i = 0; i < n; i++){
            int u = word[i] - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p]++;
    }
    
    bool search(string word) {
        int p = 0;
        int n = word.size();
        for(int i = 0; i < n; i++){
            int u = word[i] - 'a';
            if(!son[p][u]) return false;
            p = son[p][u];
        }
        return cnt[p];
    }
    
    bool startsWith(string prefix) {
        int p = 0;
        int n = prefix.size();
        for(int i = 0; i < n; i++){
            int u = prefix[i] - 'a';
            if(!son[p][u]) return false;
            p = son[p][u];
        }
        return true;
    }
};

// 指针实现
class Trie {
public:
    Trie(){
        son.resize(26);
        isEnd = false;
    }
    void insert(string word) {
        auto p = this;
        int n = word.size();
        for(int i = 0; i < n; i++){
            int u = word[i] - 'a';
            if(p->son[u] == nullptr)
                p->son[u] = new Trie;
            p = p->son[u];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        auto p = searchPrefix(word);
        return p != nullptr && p->isEnd == true;
    }
    
    bool startsWith(string prefix) {
        return searchPrefix(prefix) != nullptr;
    }
private:
    vector<Trie*> son;
    bool isEnd;
    Trie* searchPrefix(string prefix){
        auto p = this;
        int n = prefix.size();
        for(int i = 0; i < n; i++){
            int u = prefix[i] - 'a';
            if(p->son[u] == nullptr)
                return nullptr;
            p = p->son[u];
        }
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
