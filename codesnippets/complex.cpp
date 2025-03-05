

class complex{

double real, img;
public:

complex():real{0}, img{0}{}
}
complex(double r, double i): real{r}, img{i}{}
static void add(complex c1, complex c2){
    return complex(c1.real+c2.real, c1.img+c2.img);
}

};