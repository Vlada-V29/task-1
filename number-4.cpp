#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>

using namespace std;

vector<int> my_sort(vector<int>);
int time_of_sort(void (*f)(vector<int>));
void fast_sort(vector<int>);
void slow_sort(vector<int>);

int main()
{
    cout << "Let's compare speed of sortings" << endl;
    cout << "Time of fast sort is " << time_of_sort(fast_sort) << " msc" << endl;
    cout << "Time of slow sort is " << time_of_sort(slow_sort) << " msc" << endl;
    cout << "Wow! This is the difference!" << endl;
    return 0;

}

int time_of_sort(void (*f)(vector<int> ))
{
    vector<int> vec(10000);
    for(int i = 0; i<vec.size(); i++)
        vec[i] = vec.size()-i;
    auto t_start = chrono::system_clock::now();
    f(vec);
    auto t_end = chrono::system_clock::now();
    auto result = std::chrono::duration_cast<chrono::milliseconds>(t_end - t_start);
    return result.count();
}

void fast_sort(vector<int> vec)
{
    sort(vec.begin(),vec.end());   
}

void slow_sort(vector<int> vec)
{
    for (int i = 0; i < vec.size() - 1; i++) 
        for (int j = 0; j < (vec.size() - i - 1); j++)
        { 
            if(vec[j] > vec[j+1])
            {
                swap(vec[j], vec[j+1]);
            }
        }
}