class Node {
public:
    map<int,Node*> childrens;
    bool isEnd;
    Node() {
        isEnd = false;
        childrens.clear();
    }
};

class WordDictionary {
public:
    Node* dic;
    WordDictionary() {
        dic = new Node();
    }
    
    void addWord(string word) {
        Node* temp = dic;
        
        for(int i = 0; i < word.size(); i++) {
            int w = word[i] - 'a';
            if(temp->childrens.count(w) == 0) {
                temp->childrens[w] = new Node();
            }
            
            temp = temp->childrens[w];
        }
        
        temp->isEnd = true;
        
    }
    
    bool searchInNode(string word, Node* temp) {
        
        for(int i = 0; i < word.size(); i++) {
            if(word[i] == '.') {
                for(auto k : temp->childrens) {
                    if(searchInNode(word.substr(i+1), k.second))
                        return true;
                }
                
                return false;
            }else{
                int w = word[i] - 'a';
                if(temp->childrens.count(w) == 0)
                    return false;
                temp = temp->childrens[w];
            }
        }
        
        return temp->isEnd;
    }
    
    bool search(string word) {
        return searchInNode(word, dic);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
