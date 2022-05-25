#include <stdio.h>
#include <math.h>
using namespace std;
void printad(long int l){
    int x, y, z, t;
    t = l & 255;
    l = l >> 8;
    z = l & 255;
    l = l >> 8;
    y = l & 255;
    x = l >> 8;
    printf("Addr-> %d.%d.%d.%d\n", x, y, z, t);
}
int main(){
    int x, y, z, t, n, sub;
    long int addr, subnet, antisub, fadr, ladr;
    printf("IPv4 Address: ");
    scanf("%d.%d.%d.%d/%d", &x, &y, &z, &t, &sub);
    printf("Number of subnets(power of 2): ");
    scanf("%d", &n);
    n = (int)log2(n);
    addr = x;
    addr = addr << 8;
    addr |= y;
    addr = addr << 8;
    addr |= z;
    addr = addr << 8;
    addr |= t;
    printf("IP:\n");
    printad(addr);
    subnet = pow(2, 32) - pow(2, 32 - sub - n);
    antisub = pow(2, 32 - sub - n) - 1;
    for (int i = 0; i < (int)pow(2,n); i++){
        printf("\n\nSubnet %d:\n", i+1);
        addr = addr >> 32 - sub;
        addr = addr << n;
        addr |= i;
        addr = addr << 32 - sub - n;
        fadr = addr & subnet;
        ladr = addr | antisub;
        printf(" -First:");
        printad(fadr);
        printf(" -Last:");
        printad(ladr);
        printf("Total addresses: %d\n", (int)pow(2, 32 - sub - n));
    }
    return 0;
}