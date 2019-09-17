
bool is_palindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }
    int reverse_num = 0;
    while (x > reverse_num)
    {
        reverse_num = reverse_num * 10 + x % 10;
        x /= 10;
    }
    return x == reverse_num || x == reverse_num / 10;
}