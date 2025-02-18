struct Employee {
  char firstInitial;
  char lastInitial;
  int employeeNumber;
  int salary{75'000};
};

int main() {
  // Initialize all data members
  Employee anEmployee1 [[maybe_unused]]{.firstInitial = 'J',
                                        .lastInitial = 'D',
                                        .employeeNumber = 42,
                                        .salary = 80'000};

  // Initialize all data members, except employeeNumber
  Employee anEmployee2 [[maybe_unused]]{
      .firstInitial = 'J', .lastInitial = 'D', .salary = 80'000};

  // Initialize all data members, except employeeNumber, and salary
  Employee anEmployee3
      [[maybe_unused]]{.firstInitial = 'J', .lastInitial = 'D'};
}
