template <typename RetType, typename T1, typename T2> RetType addA(const T1 &t1, const T2 &t2)
{
    return t1 + t2;
}

template <typename RetType = long long, typename T1, typename T2> RetType addB(const T1 &t1, const T2 &t2)
{
    return t1 + t2;
}

int main()
{
    auto result1 [[maybe_unused]]{addA<long long, int, int>(1, 2)};
    auto result2 [[maybe_unused]]{addA<long long>(1, 2)};

    auto result [[maybe_unused]]{addB(1, 2)};
}
