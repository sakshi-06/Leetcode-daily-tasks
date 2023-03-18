class BrowserHistory {
public:
    struct dll{
      string url;
        struct dll* next;
        struct dll* prev;
        dll(string url)
        {
            this->url=url;
            next=nullptr;
            prev=nullptr;
        }
    };
    dll* curr;
    BrowserHistory(string homepage) {
        curr=new dll(homepage);
    }
    
    void visit(string url) {
        dll* temp = new dll(url);
        curr->next = temp;
        temp->prev = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        while(curr->prev!=nullptr && steps-- >0){
            curr = curr->prev;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(curr->next!=nullptr && steps-- >0){
            curr = curr->next;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */