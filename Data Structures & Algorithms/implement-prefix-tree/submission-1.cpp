class PrefixTree {
private:
    struct Node{
        Node* child[26];
        bool end;

        Node(){
            end = false;
            for(int i = 0;i<26;i++){
                child[i] = NULL;
            }
        }
    };Node* root;
    
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* n = root;
        for(char c:word){
            int i = c - 'a';
            if(n->child[i] == NULL){
                n->child[i] = new Node();
            }
            n = n->child[i];
        }
        n->end = true;
    }
    
    bool search(string word) {
        Node* n = root;
        for(char c:word){
            int i = c-'a';
            if(n->child[i] == NULL) return false;
            n = n->child[i];
        }
        return n->end;
    }
    
    bool startsWith(string prefix) {
        Node* n = root;
        for(char c:prefix){
            int i = c-'a';
            if(n->child[i] == NULL) return false;
            n = n->child[i];
        }
        return true;
    }
};
