
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define int long long int
#define INF (1e11)
using namespace std;
using namespace __gnu_pbds;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
int mod = 1e9 + 7;
class heap{
    public: 
    int a[10000]; // set it equal to the max number of elements in the heap 
    int size=0;
    void insert(int num){
        size++;
        a[size]=num;
        int curr=size;
        int parent = a[size/2];
        while(parent < num  && curr>1){
            num= parent;
            swap(a[curr],a[curr/2]);
            curr=curr/2;
           if(curr>1) parent=a[curr/2];
        }
    }
    void print(){
        cout<<"ELEMENTS OF THE HEAP ARE"<<'\n';
        for(int i=1;i<=size;i++){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }
    void delete_root(){
        if(size==0){
            cout<<"NO ELEMENT TO DELETE!"<<'\n';
            return ; 
        }
        swap(a[1],a[size]);
        size--;
        int curr= 1;
        while(curr<=size){
            int left_ind = 2*curr;
            int right_ind= 2*curr +1;
             if( 2*curr <=size && a[2*curr]>a[curr]){
                swap(a[curr], a[2*curr]);
                curr= 2*curr;
             }
             else if(2*curr+1<=size && a[2*curr +1] >a[curr]){
                swap(a[curr], a[2*curr+1]);
                curr= 2*curr +1;
             }
             else{
                break;
             }
        }
    }
};
void heapify(int arr[], int n , int i){
    int largest= i;
    int left= 2*i;
    int right = 2*i+1;
    if(left<=n  && arr[left] > arr[largest]){
        largest=left;
        //swap(arr[left],arr[largest]);
        //heapify(arr,n,left);
    }
     if(right<=n && arr[right]>arr[largest]){
        largest=right;
        //swap(arr[right],arr[largest]);
       // heapify(arr,n,right);
     }
     if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
     }
     return ;
}
void heapsort(int arr[], int n){
    // first we have to  build a heap that wil take O(n) time 
    for(int i =n/2; i>=0;i--){
        heapify(arr,n,i);
    }
    int sz= n; 
    while(sz>1){
        swap(arr[1],arr[sz]);
        sz--;
        heapify(arr,sz,1);
    }
    return ; 

}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = 1;
//cin>>tt;
    while (tt-- > 0) { 
            //h1.delete_root();
           // h1.print();
            int arr[]= {0,10,20,30,25,5,40,35};
           // int n= sizeof(arr)/sizeof(arr[0]);
            heapsort(arr,7);
            for(int i=1;i<=7;i++){
                cout<<arr[i]<<' ';
            }

    }
}
        
