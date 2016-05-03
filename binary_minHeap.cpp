/****************************************/
/**********BHUWAN BHASKAR MISHRA********/
/*Date :                        *******/
/*Program Name :                *******/

#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

template <typename type>
class heap
{
  public :
          void insert(type);
          type remove(int);
          inline int get_parent_index(int index) const
          {
            return (index-1)/2;
          }

          void display() const
          {
            copy(min_heap.begin(),min_heap.end(), ostream_iterator<type>(cout , " "));
          }

  private :
           vector<type> min_heap;
           // maintain heap property : complete tree with min val at root
           void sift_up(int) ;
           void sift_down(int);

};


template <typename type>
void heap<type> :: insert(type data)
{
  min_heap.push_back(data);
  int parent = get_parent_index(min_heap.size() - 1);

  if(min_heap.at(parent) <= data)
    return;

  int child = min_heap.size() - 1;
  while(parent != 0 && min_heap.at(parent) > min_heap.at(child) )
  {
    //swap(&min_heap.at(parent) , &min_heap.at(child));
    type temp = min_heap.at(parent);
    min_heap.at(parent) = min_heap.at(child);
    min_heap.at(child)  = min_heap.at(parent);
    child  = parent;
    parent = get_parent_index(child);  //keep on getting parents !!
  }
}

//two ops : sift up and sift down
template<typename type>
type heap<type> :: remove(int index)
{
  type sift_value = min_heap.back(); // take rightmost element at last level in heap
  min_heap.pop_back();

  min_heap.at(index) = sift_value;

  sift_up(index);
  sift_down(index);

  return sift_value;
}

//sift up
template<typename type>
void heap<type> :: sift_up(int child)
{
  int parent = get_parent_index(child);

  while(parent != 0 && min_heap.at(parent) > min_heap.at(child) )
  {
    //swap(&min_heap.at(parent) , &min_heap.at(child));
    type temp = min_heap.at(parent);
    min_heap.at(parent) = min_heap.at(child);
    min_heap.at(child)  = min_heap.at(parent);
    child  = parent;
    parent = get_parent_index(child);  //keep on getting parents !!
  }
}

template<typename type>
void heap<type> :: sift_down(int parent) // min_heapify()
{
  int left_child = 2*parent;
  int right_child = 2*parent + 1;
  int smallest = parent;
  if(left_child < min_heap.size() && min_heap.at(left_child) < min_heap.at(parent))
      smallest = left_child;
  if(right_child < min_heap.size() && min_heap.at(right_child) < min_heap.at(smallest))
      smallest = right_child;

  if(smallest != parent)
  {
    type temp = min_heap.at(parent);
    min_heap.at(parent) = min_heap.at(smallest);
    min_heap.at(smallest) = temp;

    sift_down(smallest);
  }

}

int main()
{
  heap<int> iHeap;
  iHeap.insert(10);
  iHeap.insert(15);
  iHeap.insert(30);
  iHeap.insert(40);
  iHeap.insert(50);
  iHeap.insert(100);
  iHeap.insert(400);

  iHeap.display();

  iHeap.remove(0);

  iHeap.display();
  return 0;
}
