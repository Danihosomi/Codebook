// Cálcula a função de Mobius (é multiplicativa)
// 0 -> se tiver algum fator primo no número com potência >= 2
// 1 -> se for 1
// -1 -> se todos os primos que compuserem o número tiverem potência igual a 1
//
// Calcula tudo em O(nloglogn)
//

vi Sieve(int maior){
    vi menorp(maior+1,0); 
    for(int i=2;i<=maior;i++)
        if(!menorp[i])
            for(int j=i;j<=maior;j+=i)
                if(!menorp[j]) menorp[j] = i;

    return menorp;
}

vi MakeMobius(int maior){
    vi mobius(maior,0);
    vi menorp = Sieve(maior);

    for(int i=1;i<=maior;i++){
        if(i==1) mobius[i]=1;
        else{
            if(menorp[i/menorp[i]]==menorp[i]) mobius[i]=0;
            else mobius[i]=-1*mobius[i/menorp[i]];
        }
    }

    return mobius;
}