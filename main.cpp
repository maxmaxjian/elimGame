#include <iostream>
#include <vector>
#include <algorithm>
//#include <iterator>
#include <cmath>

using std::vector;

// class myIterator : public std::iterator<std::bidirectional_iterator_tag, int>
// {
// public:
//   myIterator(const vector<int> & vec, const vector<int>::iterator & it)
//     : ref(vec), myIter(it){}

//   myIterator & operator--() {
//     if (myIter != ref.begin())
//       --myIter;
//     if (myIter != ref.begin())
//       --myIter;
//     return *this;
//   }

//   myIterator & operator++() {
//     if (myIter != ref.end())
//       ++myIter;
//     if (myIter != ref.end())
//       ++myIter;
//     return *this;
//   }

//   bool operator==(const myIterator & other) {
//     return myIter==other.myIter;
//   }

//   bool operator!=(const myIterator & other) {
//     return myIter != other.myIter;
//   }

//   int& operator*() {
//     return *myIter;
//   }

// private:
//   const vector<int> & ref;
//   vector<int>::iterator myIter;
// };

int count = 1;
int generator(){return count++;}

// class solution {
// public:
//   int lastRemaining(int n) {
//     vector<int> nums(n);
//     std::generate_n(nums.begin(),n,generator);
//     std::cout << "beginning:\n";
//     std::for_each(nums.begin(), nums.end(), [](int i){std::cout << i << " ";});
//     std::cout << std::endl;
      
//     vector<int> left(nums.size()/2);
//     myIterator first(nums, nums.begin()+1);
//     myIterator last(nums, nums.end());
//     std::copy(first, last, left.begin());
//     std::cout << "after first elimination:\n";
//     std::for_each(left.begin(), left.end(),[](int i){std::cout << i << " ";});

//     // std::reverse_copy(first, last, left.begin());
//     //       std::for_each(left.begin(), left.end(),[](int i){std::cout << i << " ";});
//     std::cout << std::endl;

//     // vector<int> left2(left.size()/2);
//     // myIterator fst(left, left.begin());
//     // myIterator lst(left, left.end());
//     // std::copy_backward(fst, lst, left2.end());
//     //             std::for_each(left2.begin(), left2.end(),[](int i){std::cout << i << " ";});
//     //             std::cout << std::endl;

//     vector<int> left2;
//     for (size_t i = 0; i < left.size(); ++i) {
//       if ((left.size()-i)%2 == 0) {
// 	left2.push_back(left[i]);
//       }
//     }
//     std::cout << "after second elimination:\n";
//     std::for_each(left2.begin(), left2.end(),[](int i){std::cout << i << " ";});
//     std::cout << std::endl;
//     return 0;
//   }
// };

// brute force solution
class solution {
public:
  int lastRemaining(int n) {
    vector<int> nums(n);
    std::generate_n(nums.begin(),n,generator);
    
    bool front = true;
    auto result = removeFrom(nums, front);
    while (result.size() > 1) {
      // if (!front)
      // 	std::cout << std::endl;
      // std::cout << "len = " << result.size() << std::endl;
      // print(result);
      result = removeFrom(result,front);
    }
    // std::cout << "len = " << result.size() << std::endl;
    // print(result);
    return result.front();
  }

private:
  vector<int> removeFrom(const vector<int> & nums, bool & front) {
    vector<int> result;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (front) {
	if (i%2 != 0)
	  result.push_back(nums[i]);
      }
      else {
	if ((nums.size()-i)%2 == 0)
	  result.push_back(nums[i]);
      }
    }
    front = !front;
    return result;
  }

  void print(const vector<int> & nums) {
    std::for_each(nums.begin(), nums.end(), [](int i){std::cout << i << " ";});
    std::cout << std::endl;
  }

public:
  int lastRemaining2(int n) {
    int first = (n%2 == 0) ? n : n-1;
    int p = 1;
    int second = first-int(pow(2,p));
    p++;

    while (numOfInts(second, int(pow(2,p)))>2) {
      if (numOfInts(second, int(pow(2,p)))%2==0) {
	first = second;
	p++;
      }
      else {
	first = second-int(pow(2,p));
	p++;
      }
      
      if (numOfInts(first, int(pow(2,p)))>1) {      
	second = first-int(pow(2,p));
	p++;
      }
      else
	return first;
    }

    return second;
  }

private:
  int numOfInts(int start, int step) {
    int num = 0;
    while (start > 0) {
      num++;
      start -= step;
    }
    return num;
  }
};

int main() {
  int n = 452;
  solution soln;
  int left = soln.lastRemaining(n);
  std::cout << "The last remaining is:\n";
  std::cout << left << std::endl;

  std::cout << soln.lastRemaining2(n) << std::endl;
}
