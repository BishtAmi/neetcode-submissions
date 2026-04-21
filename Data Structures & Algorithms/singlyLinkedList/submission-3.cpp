class LinkedList {
int data;
LinkedList *next;    
public:
    LinkedList *root,*tail;
    int sz=0;
    LinkedList() {
     root=NULL;
     tail=NULL;  
    }

    int get(int index) {
         if(index>=sz) return -1;
         LinkedList *head=root;
         for(int i=0;i<index;i++)
         {
             head=head->next;
         }
         return head->data;
    }

    void insertHead(int val) {
         sz++;
         LinkedList *temp= new LinkedList;
         temp->data=val;
         if(root==NULL)
         {
            root=temp;
            temp->next=NULL;
            tail=root;
         }
         else 
         {
            temp->next=root;
            root=temp; 
         }
        LinkedList *head=root;
        cerr<<"head\n";
        while(head!=0)
        {
            cerr<<head->data<<" ";
            head=head->next;
        }
        cerr<<'\n';
    }
    
    void insertTail(int val) {
         sz++;
         LinkedList *temp= new LinkedList;
         temp->data=val;
         if(tail==NULL)
         {
            tail=temp;
            temp->next=NULL;
            root=temp;
         }
         else 
         {
            tail->next=temp;
            tail=temp; 
         }
        LinkedList *head=root;
        cerr<<"tail\n";
        while(head!=0)
        {
            cerr<<head->data<<" ";
            head=head->next;
        }
        cerr<<'\n';
    }

    bool remove(int index) {
        LinkedList *head=root;
        if(index==0&&sz>0)
        {
            head=root->next;
            root->next=NULL;
            root=head;
            sz--;
            return true;
        }
        if(index>=sz) return false;
        sz--;
        for(int i=0;i<index-1;i++)
        {
           head=head->next;
        }
        head->next=head->next->next;
        if(head->next==NULL) tail=head;
        head=root;
        cerr<<"remove\n";
        while(head!=0)
        {
            cerr<<head->data<<" ";
            head=head->next;
        }
        cerr<<'\n';
        return true; 
    }

    vector<int> getValues() {
        vector<int> ans;
        LinkedList *head=root;
        while(head!=0)
        {
            ans.push_back(head->data);
            head=head->next;
        }
        return ans;
    }
};
