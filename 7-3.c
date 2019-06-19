#include <iostream>
#include <vector>

/*
 the first line contains 3 numbers (all no more than 1000): 
 M (the maximum capacity of the stack), 
 N (the length of push sequence), and 
 K (the number of pop sequences to be checked).
*/



using namespace std;


bool check(int M,vector<int> &seq_arr){
    int n = seq_arr.size();
    int val,root;
    vector<int> left;
    vector<int> right;
    
    
    
    if(n <= 0){
        return false;
    }
    
    val = seq_arr[0];
    if(val > M){
        return false;
    }
    
    root = val;
    
    for(int i = 1;i < n;i++){
        val = seq_arr[i];
        if(val > n){
            return false;
        }
        if(val > root){
            right.push_back(val);
        }else if(val < root){
            left.push_back(val);
        }
    }
    
    int size = left.size();
    if(size > 0){
        int pre = left[0];
        
        for(int i = 1;i < size;i++){
            if(left[i] > pre){
                return false;
            }
            
            pre = left[i];
        }
    }
    
    
    size = right.size();
    
    if(size > 0){
        int pre = right[0];
        for(int i = 1;i < size;i++){
            if(right[i] < pre){
                return false;
            }
            pre = right[i];
        }
    }
    
		
    return true;
    
}


int main()
{
    int M,N,K;
    bool first = true;
    
    cin>>M;
    cin>>N;
    cin>>K;
    
    vector<int> seq_arr;
    
    for(int i = 0; i < K;i++){
        for(int j = 0;j < N;j++){
            int val;
            cin >> val;
            seq_arr.push_back(val);
        }
        bool ret = check(M,seq_arr);
        
        if(!first){
            cout << endl;
        }else{
            first = false;
        }
        
        if(ret){
            cout << "YES";
            
        }else{
            cout << "NO";
        }
        
        
        seq_arr.clear();
    }
    
    
    
    
}


