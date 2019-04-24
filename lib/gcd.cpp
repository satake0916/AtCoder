template<typename T>
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

template<typename T>
T extgcd(T a, T b, T& x, T& y){
    T g = a;
    x = 1;
    y = 0;
    if(b != 0){
        g = extgcd(b, a%b, y, x);
        y -= (a / b) * x;
    }
    return g;
}