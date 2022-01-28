class Node {
public:
    vector<Node*> childrens;
    bool isEnd;
    Node() {
        isEnd = false;
        childrens = vector<Node*>(26, NULL);
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
            if(temp->childrens[w] == NULL) {
                temp->childrens[w] = new Node();
            }
            
            temp = temp->childrens[w];
        }
        
        temp->isEnd = true;
        
    }
    
    bool searchwithNode(string word, Node* temp) {
        if(word.size() == 0 && temp->isEnd == true)
            return true;
        
        if(word.size() == 0) 
            return false;
        
        vector<Node*> childrens = temp->childrens;
        if(word[0] == '.') {
            for(int i = 0; i < childrens.size(); i++) {
                if(childrens[i] != NULL) {
                    if(searchwithNode(word.substr(1), temp->childrens[i])) {
                        return true;
                    }
                }
            }
        }else{
            int w = word[0] - 'a';
            if(childrens[w] == NULL)
                return false;
            else
                return searchwithNode(word.substr(1), temp->childrens[w]);
        }
        
        return false;
    }
    
    bool search(string word) {
        Node* temp = dic;
        return searchwithNode(word, temp);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
