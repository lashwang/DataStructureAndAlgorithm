#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define DEBUG_LOG

void max_so_far(int a[],int length){
    int max_ending_here;
    int max_so_far;
    int index;
    int max_index_start,max_index_end;
    
    max_ending_here = max_so_far = a[0];
    max_index_start = max_index_end = 0;
    
    stack<int> max_index_stack;



#ifdef DEBUG_LOG    
    cout<<"x="<<a[0];
    cout<<",max_ending_here:"<<max_ending_here;
    cout<<",max_so_far:"<<max_so_far;
    cout<<",max_index_start:"<<max_index_start;
    cout<<",max_index_end:"<<max_index_end;
    cout<<endl;
#endif
    static int max_so_far_pre = max_so_far;
    
    for(index = 1;index < length;index++){
        int x = a[index];
        
        
        max_ending_here = max(x, max_ending_here + x);
        max_so_far = max(max_so_far, max_ending_here);
        
        if(max_ending_here == x){
            max_index_stack.push(index);
        }
        
        if(max_so_far > max_so_far_pre){
            max_index_start = max_index_stack.top();
            max_index_end = index;
        }
        
        max_so_far_pre = max_so_far;
#ifdef DEBUG_LOG
        cout<<"x="<<x;
        cout<<",max_ending_here:"<<max_ending_here;
        cout<<",max_so_far:"<<max_so_far;
        cout<<",max_index_start:"<<max_index_start;
        cout<<",max_index_end:"<<max_index_end;
        cout<<endl;
#endif
    }
    
    if(max_so_far < 0){
        max_so_far = 0;
        max_index_start = 0;
        max_index_end = length - 1;
    }
    
    cout<<max_so_far<<" ";
    cout<<max_index_start<<" ";
    cout<<max_index_end;
}

int main1()
{
    int a[] = {-1,-2,-3,-4};
    max_so_far(a,sizeof(a)/sizeof(int));
    
    return 0;
}


int main(){

    int N;
    vector<int> input_array;
    
    cin>>N;
    
    for(int i = 0;i < N;i++){
        int val;
        cin>>val;
        input_array.push_back(val);
    }
    
    max_so_far(&input_array[0],N);
    
    return 0;
}
