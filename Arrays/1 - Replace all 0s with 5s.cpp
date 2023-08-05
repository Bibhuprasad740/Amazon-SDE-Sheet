int convertFive(int n)
{
    string num = to_string(n);

    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] == '0')
            num[i] = '5';
    }

    return stoi(num);
}