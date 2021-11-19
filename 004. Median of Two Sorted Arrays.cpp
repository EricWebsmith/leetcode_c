#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArray(vector<int>& v){
    int n = v.size();
    int m1 = n / 2;
    int m2 = (n + 1) / 2 - 1;
    return (v[m1] + v[m2])/2.0;
}

double findMedianSortedArray(vector<int>& v, int start, int end){
    int n = end-start + 1;
    int m1 = start + n / 2;
    int m2 = start + (n + 1) / 2 - 1;
    return (v[m1] + v[m2])/2.0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
    int size1 = nums1.size();
    int size2 = nums2.size();
    int size = size1 + size2;
    if(size==0) { return 0; }

    if(size1==0){
        return findMedianSortedArray(nums2);
    }

    if(size2==0){
        return findMedianSortedArray(nums1);
    }

    int min1=0;
    int max1=size1-1;
    int min2=0;
    int max2=size2-1;

    while(min1<max1 && min2<max2){
        if(nums1[min1]<nums2[min2]){
            min1++;
        }
        else
        {
            min2++;
        }
        
        if(nums1[max1]<nums2[max2]){
            max2--;
        }
        else{
            max1--;
        }
    }

    int new_size1 = max1-min1+1;
    int new_size2 = max2-min2+1;

    if(new_size1==0){
        return findMedianSortedArray(nums2, min2, max2);  
    }

    if(new_size1==1){
        int i=min2;
        while(i<=max2 && nums2[i]<nums1[min1] ){
            i++;
        }
        nums2.insert(nums2.begin() + i, nums1[min1]);
        return findMedianSortedArray(nums2, min2, max2+1);     
    }

    if(new_size2==0){
        return findMedianSortedArray(nums1, min1, max1);  
    }

    if(new_size2==1){
        int i=min1;
        while(i<=max1 && nums1[i]<nums2[min2]){
            i++;
        }
        nums1.insert(nums1.begin() + i, nums2[min2]);
        return findMedianSortedArray(nums1, min1, max1+1);     
    }

    return 0;
}

void test(vector<int>& nums1, vector<int>& nums2, double expected){
    double actual = findMedianSortedArrays(nums1, nums2);
    cout << expected << "\t" << actual << endl;
}

int main(){
    cout << "j" << endl;
    vector<int> j1 = {1, 3};
    vector<int> j2 = {2};
    test(j1, j2, 2);

    cout << "b" << endl;
    vector<int> b1 = {1, 2};
    vector<int> b2 = {3, 4};
    test(b1, b2, 2.5);

    vector<int> i1 = {1};
    vector<int> i2 = {2, 3, 4, 5};
    test(i1, i2, 3);

    vector<int> h1 = {1, 2};
    vector<int> h2 = {1, 2, 3};
    test(h1, h2, 2);

    vector<int> f1 = {1, 2, 3};
    vector<int> f2 = {2, 3, 4};
    test(f1, f2, 2.5);

    vector<int> g1 = {1, 3};
    vector<int> g2 = {2, 7};
    test(g1, g2, 2.5);

    vector<int> a1 = {1, 3};
    vector<int> a2 = {2};
    test(a1, a2, 2);


    
    vector<int> c1 = {0, 0};
    vector<int> c2 = {0, 0};
    test(c1, c2, 0);
    
    vector<int> d1 = {};
    vector<int> d2 = {1};
    test(d1, d2, 1);
    
    vector<int> e1 = {2};
    vector<int> e2 = {};
    test(e1, e2, 2);
    

    
}