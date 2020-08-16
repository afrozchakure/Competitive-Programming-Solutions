boolean isPrime(int n){
	for(int x = 2; x ** x <= n; x++)
		if(n%x == 0){
			return false;
		}
}
return true;
