// GCD: greatest common divisor
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a == b)
		return a;

	if (a > b)
		return gcd(a - b, b);

	return gcd(a, b - a);
}

// LCM: lowest common multiple
int lcm(int a, int b)
{
	if (a == 0 && b == 0)
	{
		std::cout << "A and B can't be both zero for this LCM algorithem.";
		return 0;
	}
	else
	{
		std::cout << (a * b) / gcd(a, b);
		return 0;
	}

}

// Power
int power(int x, int y) 
{
    int prod = 1;
    while (y > 0){
        if (y & 1){
            prod = prod * x;
        }
        x = x * x;
        y = y/2; 
    }
    return prod;
}

/*
    Powermod: Modular exponentation
        PowerMod[a,b,m] gives the remainder of a^b divided by m.
*/
int powermod(int a, int b, int m) //O(log n)
{
    int prod = 1;
    while (b > 0){
        if (b % 2 != 0){
            prod = (prod * a) % m;
        }
        a = a * a % m;
        b = b/2; 
    }
    return prod;
}

// Fermat
int fermat(int n, int k) {
    return powermod(n, k-2, k);
}

bool fermat2(int n, int k) {
    for (int i = 0; i < k; i++) {
        int a = rand() % n+1;

        if (powermod(a, n-1, n) != 1){
            return false; //not prime
        }
    }
  return true; //prime
}
  