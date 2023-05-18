// Complexidade O(N^3)
// Itera sobre todas as submasks de uma mask de 0 até (1<<n)

for(int mask=0;mask<(1<<n);mask++){
    for(int sub=mask;sub;sub=((sub-1)&mask)){
        // Submask de Mask
    }
}