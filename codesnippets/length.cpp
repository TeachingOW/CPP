
    #include <iostream>
    using namespace std;
    int length(char str[]) {
        int i = 0;
        while (str[i] != '\0')i++;
        return i;
    }

    int length2(char* p) {
        int i = 0;
        if (p == NULL) return 0;
        while (*p != '\0') {
        i++; p++;
        }
        return i;
        }

        int length3(char* p) {
        char* tmp = p;
        if (tmp == NULL) return 0;
        while (*tmp != '\0') {
        tmp++;
        }
        return (tmp-p);
    }
    int main(){

    char s[]="this is an example";
    cout << length(s) <<'\n';
    cout << length2(s) <<'\n';
    cout << length3(s) <<'\n';
    }