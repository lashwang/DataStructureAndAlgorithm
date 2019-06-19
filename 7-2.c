#include <iostream>
#include <list>
#include <map>
#include <vector>


using namespace std;

typedef struct ListNode{
    int address;
    int data;
    int next;
    
    ListNode(int addr,int val,int next_addr) : address(addr),data(val),next(next_addr){}
    
    void print(){
        if(next == -1){
            printf("%05d %d %d",address,data,next);
        }else{
            printf("%05d %d %05d",address,data,next);
        }
        
    }
}ListNode;

// key - address
// value - ListNode
map<int,ListNode *> s_node_map;

list<ListNode *> s_link_list;
vector<ListNode *> out_put_vector;


void list_output(list<ListNode *> &hints){
    int first = true;
    
    for (auto it = hints.cbegin(); it != hints.cend(); it++){
        if(!first){
            cout<<endl;
        }else{
            first = false;
        }
        (*it)->print();
    }
}

void reverse(vector<ListNode *> &input,vector<ListNode *> &output){
     for (auto rit = input.crbegin(); rit != input.crend(); ++rit){
        output.push_back(*rit);
     }
}


void list_revert_n(list<ListNode *> &hints,int n){
    vector<ListNode *> temp_vector;
    int index = 0;
    for (auto it = hints.cbegin(); it != hints.cend(); it++){
        temp_vector.push_back(*it);
        index++;
        if(index%n == 0){
            reverse(temp_vector,out_put_vector);
            temp_vector.clear();
        }
    }
    
    if(!temp_vector.empty()){
        out_put_vector.insert( out_put_vector.end(), temp_vector.begin(), temp_vector.end() );
        temp_vector.clear();
    }
    
    int size = out_put_vector.size();
    ListNode *p = NULL;
    
    
    if(size <= 0 ){
        return;
    }
    
    for (auto rit = out_put_vector.crbegin(); rit != out_put_vector.crend(); ++rit){
        if(p == NULL){
            p = (*rit);
            p->next = -1;
        }else{
            (*rit)->next = p->address;
            p = (*rit);
        }
    }
    
    bool first = true;
    
    for (auto it = out_put_vector.cbegin(); it != out_put_vector.cend(); ++it){
        if(!first){
            cout<<endl;
        }else{
            first = false;
        }
        (*it)->print();
    }
    
    
    
}

int main()
{
    int head_addr;
    int list_size;
    int sub_size;
    
    cin >> head_addr;
    cin >> list_size;
    cin >> sub_size;
    
    for(int i = 0;i < list_size;i++){
        int addr,data,next;
        cin >> addr;
        cin >> data;
        cin >> next;
        s_node_map[addr] = new ListNode(addr,data,next);
    }
    
    int next = head_addr;
    
    while(next != -1){
        ListNode *pNode = s_node_map[next];
        s_link_list.push_back(pNode);
        next = pNode->next;
    }
    

    //list_output(s_link_list);
    list_revert_n(s_link_list,sub_size);
    
    
    return 0;
}