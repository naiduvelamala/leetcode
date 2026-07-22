class LRUCache {
public:
    class Node{
        public:
        int key,value;
        Node* prev;
        Node* next;

        Node(int k,int v)
        {
            key=k;
            value=v;
            prev=next=NULL;
        }
    };

    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    unordered_map<int,Node*>mp;
    int limit;

    void add(Node* newnode)
    {
        Node* oldnext=head->next;
        head->next=newnode;
        oldnext->prev=newnode;

        newnode->next=oldnext;
        newnode->prev=head;
    }

    void delNode(Node* oldnode)
    {
        Node* oldprev=oldnode->prev;
        Node* oldnext=oldnode->next;

        oldprev->next=oldnext;
        oldnext->prev=oldprev;
    }
    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        Node* ansNode=mp[key];
        int ans=ansNode->value;
        mp.erase(key);
        delNode(ansNode);

        add(ansNode);
        mp[key]=ansNode;

        return ans;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        { 
            Node *old=mp[key];
            delNode(old);
            mp.erase(key);
        }

        if(mp.size()==limit)
        {
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }
        Node* newnode=new Node(key,value);
        add(newnode);
        mp[key]=newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */