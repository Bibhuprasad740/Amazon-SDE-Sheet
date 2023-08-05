class Solution
{
public:
    int thirdLargest(int arr[], int n)
    {
        int largest = -1, second = -1, third = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > largest)
            {
                third = second;
                second = largest;
                largest = arr[i];
            }
            else if (arr[i] > second)
            {
                third = second;
                second = arr[i];
            }
            else if (arr[i] > third)
            {
                third = arr[i];
            }
        }
        return third;
    }
};