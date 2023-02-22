#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <cmath>


template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
	void heapify(int root);
	std::vector<T> data;
	int n;
	PComparator comp;
};

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) 
{
	n = m;
  comp = c;
}


template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() 
{
	
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) //push element into heap
{
  data.push_back(item);
  std::size_t index = data.size() - 1;
  while (index != 0) {  // loop through heap swapping parent and child until PComparator is no longer triggered
      std::size_t parent_index = floor((index - 1) / n);
      T& current = data[index];
      T& parent = data[parent_index];
      if (comp(parent, current)) // correct location found
			{
        break;
      }
      std::swap(current, parent);
      index = parent_index;
    }
}


template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const //return top value
{
  if(empty())
	{
  	throw std::out_of_range("heap is empty"); 
  }
  return data[0];
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::pop() // pop 'best' value and sort heap
{
  if(empty())
	{
		throw std::out_of_range("heap is empty"); //????
  }
  std::swap(data.front(), data.back());
  data.pop_back();
	heapify(0);  
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify(int root) //heapify to support pop function
{
    int best = root;
    for(int i = (n*root+1); i <= (n*root+n); i++) //iterate through all children and get the best fitted child index
    {
        if(i < (int)data.size() && comp(data[i], data[best]))
        {
            best = i;
        }
    }

    if (best != root) {
        std::swap(data[root], data[best]); // swap and repeat till no longer possible
        heapify(best);
    }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const // return true if empty
{
	if(data.size() == 0)	{ return true; }
	return false;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const // return heap size
{
	return data.size();
}

#endif

