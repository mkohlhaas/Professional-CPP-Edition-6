class MyClass {
public:
  MyClass(int &ref) : m_ref{ref} {
    // body of constructor
  }

private:
  int &m_ref [[maybe_unused]];
};

int main() {
  int i{123};
  MyClass m{i};
}
