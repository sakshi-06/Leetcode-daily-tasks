class MyHashSet {
public:
    ListNode* head;
    MyHashSet() {
        head= new ListNode(-1);
    }
    
    void add(int key) {
        ListNode* p=head;
        while(p->next!=nullptr)
        {
            if(p->val==key) return;
            p=p->next;
        }
        if(p->val==key) return ;
        ListNode* n=new ListNode(key);
        p->next=n;
    }
    
    void remove(int key) {
        ListNode* p=head;
        while(p->next!=NULL)
        {
            if(p->next->val==key)
            {
                break;
            }
            p=p->next;
        }
        if(p->next==NULL)
        {
            return;
        }
        ListNode* temp=p->next;
        p->next=temp->next;
        delete(temp);
    }
    
    bool contains(int key) {
        ListNode* p=head;
        while(p->next!=NULL)
        {
            if(p->next->val==key) return true;
            p=p->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */