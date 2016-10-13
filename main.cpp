
class myInterator {
public:
  myIterator(const vector<int>::iterator & it) : myIter(it){}

  myIterator & operator--() {
    --myIter;
    --myIter;
    return myIter;
  }

  myIterator & operator++() {
    ++myIter;
    ++myIter;
    return myIter;
  }

  bool operator==(const vector<int>::iterator & other) {
    return myIter==other;
  }

  int& operator*() {
    return *myIter;
  }

private:
  vector<int>::iterator myIter;
};

class solution {
public:
  int lastRemaining(int n) {
    
  }
};
