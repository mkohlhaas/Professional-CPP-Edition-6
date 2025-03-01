#include <charconv>
#include <cstddef>
#include <print>
#include <string>

using namespace std;

int main()
{
    const size_t BufferSize{50};

    {
        // to_chars() without structured binding.
        string out(BufferSize, ' '); // A string of BufferSize space characters.
        auto   result{to_chars(out.data(), out.data() + out.size(), 12345)};
        if (result.ec == errc{})
        {
            println("{}", out);      /* Conversion successful. */
        }
    }

    {
        // to_chars() with structured binding.
        string out(BufferSize, ' '); // A string of BufferSize space characters.
        auto [ptr, error]{to_chars(out.data(), out.data() + out.size(), 12345)};
        if (error == errc{})
        {
            println("{}", out);      /* Conversion successful. */
        }
    }

    {
        // Demonstrating perfect round-tripping.
        double value1{0.314};
        string out(BufferSize, ' '); // A string of BufferSize space characters.
        auto [ptr1, err1]{to_chars(out.data(), out.data() + out.size(), value1)};
        if (err1 == errc{})
        {
            println("{}", out);      /* Conversion successful. */
        }

        double value2;
        auto [ptr2, err2]{from_chars(out.data(), out.data() + out.size(), value2)};
        if (err2 == errc{})
        {
            if (value1 == value2)
            {
                println("perfect roundtrip");
            }
            else
            {
                println("no perfect roundtrip?!?");
            }
        }
    }
}
