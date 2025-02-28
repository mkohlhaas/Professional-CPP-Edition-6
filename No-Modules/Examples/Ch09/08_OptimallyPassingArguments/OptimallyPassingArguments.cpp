#include <print>
#include <utility>
#include <vector>

using namespace std;

class DataHolder
{
  public:
    // void setData(const vector<int>& data) { m_data = data; }
    // void setData(vector<int>&& data) { m_data = move(data); }
    void setData(vector<int> data)
    {
        m_data = std::move(data);
    }

  private:
    vector<int> m_data;
};

int main()
{
    vector myData{11, 22, 33};

    std::println("Vector size: {}", myData.size());
    std::println("{}, {}, {}", myData[0], myData[1], myData[2]);

    DataHolder wrapper;
    wrapper.setData(myData);

    std::println("Vector size: {}", myData.size());
    std::println("{}, {}, {}", myData[0], myData[1], myData[2]);

    wrapper.setData({22, 33, 44});
}
