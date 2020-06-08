#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int min_num_steps[1000000];
vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> calc_step_sequence(int* array, int n)
{
    //starting from n -> /3, /2 & -1
    //store the index of the lowest value
    //until value reaches 1
    int plusx = 9999;
    int mul2 = 9999;
    int mul3 = 9999;
    int vector = 0;
    std::vector<int> sequence;
    sequence.push_back(n);
    while (n>1)
    {
        if (n % 3 == 0)
        {
          mul3 = array[n/3];
            vector = n/3;
        }
        
        if (n % 2 == 0)
        {
          mul2 = array[n/2];
            mul2 < mul3 ? vector = n/2: vector;
        }
        
        {
          plusx = array[n - 1];
            ((plusx < mul2) && (plusx < mul3)) ? vector = n-1: vector;
        }
        sequence.push_back(vector);
        n = vector;
        mul2 = mul3 = plusx = 9999;
    }
    
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

vector<int> optimal_sequence_DP(int number)
{
    std::vector<int> sequence;
    int num_steps = 0;
    min_num_steps[0] = 0;
    min_num_steps[1] = 0;
    min_num_steps[2] = 1;
    min_num_steps[3] = 1;
    for(int n = 4; n <= number; n++)
    {
        num_steps = 0;//min_num_steps[n-1] + 1;

        num_steps = min_num_steps[n-1] + 1;
        min_num_steps[n] = num_steps;
        if(n%3 == 0)
        {
            num_steps = min_num_steps[n/3];
        }
        else if (n%2 == 0)
        {
            num_steps = min_num_steps[n/2];
        }

        if (num_steps < min_num_steps[n-1])
        {
            min_num_steps[n] = num_steps + 1;
        }
    }
    sequence = calc_step_sequence(min_num_steps, number);
    return sequence;
}

int main_calc() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence_DP(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
    std::cout << std::endl;
    return 0;
}
