#ifndef SortedArray_h
#define SortedArray_h

#include <iostream>
#include <ostream>

using namespace std;

struct SortedArray {
    long* data;
    
    long capacity;
    
    long count;

    SortedArray() {
        data = new long[1];
        
        capacity = 1;

        count = 0;
    }

    SortedArray(const SortedArray& other){
		capacity = other.capacity;
		count = other.count;
		data = new long[other.capacity];

		for (long i = 0; i < other.count; i++){
			data[i] = other.data[i];
		}
	}

    void operator=(const SortedArray& other){
		capacity = other.capacity;
		count = other.count;
		data = new long[other.capacity];

		for (long i = 0; i < other.count; i++){
			data[i] = other.data[i];
		}
    }

    long& operator[](long index) const {
        return data[index];
    }

	// Overloading the == operator. Now we can compare 
	// two ResizableArrays with the == operator
	bool operator==(const SortedArray rhs) const {
		// If the capacitys or counts are different, it's not a match
		if (capacity != rhs.capacity){
			return false;
		}
		if (count != rhs.count){
			return false;
		}

		// Assume the arrays match
		bool same = true;

		// And try to find a contradiction
		for (long i = 0; i < count; i++){
			if (data[i] != rhs.data[i]){
				return false;
			}
		}
		
		// Colud not get a contradiction
		return true;
	}

    //Best Case: Complexity is linear O(n). Array is already sorted and only have to compare each element once, and 
    //  the index of insertion is less than the size of the array.

    //Worst Case: Complexity is non-linear, n(n-1)/2, O(n^2). Array is unsorted 
    //  and have to compare each element starting from the back n minus however many elements are left unsorted, and 
    //  the index of insertion is greater than the size of the array.
    void insert(long index, long value) {
        if (index < capacity){
            for(long i = count; i > index; i--){
                data[i] = data[i-1];
            }

            data[index] = value;
            count++;

            if (count == capacity){
                long oldcapacity = capacity;
                
                capacity = capacity * 2;
                
                long* newArr = new long[capacity];
            
                for (long i = 0; i < oldcapacity; i++) {
                    newArr[i] = data[i];
                }
                
                delete[] data;
                
                data = newArr;
            }
        }
        else{
            long oldcapacity = capacity;

            while (index+1 >= capacity){
                capacity *=2;
            }

            if (capacity > oldcapacity){
                long* newArr = new long[capacity];
                
                for (long i = 0; i < oldcapacity; i++) {
                    newArr[i] = data[i];
                }
                
                delete[] data;
                
                data = newArr;
            }
            
            for (long i = count; i < index; i++){
                data[i] = 0;
            }
            
            data[index] = value;
            count = index + 1;
        }

        //sort array using insertion sort
        for (long i = 1; i < count; i++) {
            long j = i;

            while (j > 0 && data[j-1] > data[j]) {
                long temp = data[j];
                data[j] = data[j-1];
                data[j-1] = temp;
                j = j - 1;
            }
        }
    }

    //only using this for testing the insert function
    void append(long value){
        data[count] = value;
        count++;
        
        if (count == capacity){
            long oldcapacity = capacity;

            capacity = capacity * 2;

            long* newArr = new long[capacity];

            for (long i = 0; i < oldcapacity; i++) {
                newArr[i] = data[i];
            }
            
            delete[] data;
            
            data = newArr;
        }
    }

    ~SortedArray(){
        delete[] data;
	}
};

std::ostream& operator<<(std::ostream& os, const SortedArray& arr) {
    for (long i = 0; i < arr.count; i++){
		os << arr.data[i] << " ";
	}

    return os;
}

#endif