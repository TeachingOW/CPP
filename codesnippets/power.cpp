

double calc_power(int base,int exp){
    int product=1;
    for(int i=0;i<exp;i++){
        product*=base;
    }
    return product;
}

int power_2(int base, int exp){
    if(exp==1) return base;
    int p=power_2(base*base, exp/2)
    if(exp&1) p=p*base;
    return p;
}

double power (int base, int exp){
if(exp>=0)
    return calc_power(base,expr);
else 
    return 1/calc_power(base,-expr);
}